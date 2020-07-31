.PHONY: all  clean

all: os.img
	cp os.img /mnt/c/Users/z1052/
os.img: bootloader.efi kernel.bin startup.nsh

	dd if=/dev/zero of=os.img bs=512 count=93750
	parted os.img -s -a minimal mklabel gpt
	parted os.img -s -a minimal mkpart EFI FAT32 2048s 93716s
	parted os.img -s -a minimal toggle 1 boot

	dd if=/dev/zero of=/tmp/fat32_part.img bs=512 count=91669
	mformat -i /tmp/fat32_part.img -h 32 -t 32 -n 64 -c 1

	mcopy -i /tmp/fat32_part.img bootloader.efi ::
	mcopy -i /tmp/fat32_part.img kernel.bin ::
	mcopy -i /tmp/fat32_part.img startup.nsh ::

	dd if=/tmp/fat32_part.img of=os.img bs=512 count=91669 seek=2048 conv=notrunc

bootloader.efi:
	gcc -c bootloader/bootloader.c -o bootloader.o -fno-stack-protector -fpic -fshort-wchar -mno-red-zone -DEFI_FUNCTION_WRAPPER
	ld bootloader.o /usr/lib/crt0-efi-x86_64.o -o bootloader.so -nostdlib -znocombreloc -T /usr/lib/elf_x86_64_efi.lds -shared -Bsymbolic -L /usr/lib -l:libgnuefi.a -l:libefi.a 
	objcopy bootloader.so bootloader.efi -j .text -j .sdata -j .data -j .dynamic -j .dynsym -j .rel -j .rela  -j .reloc -O efi-app-x86_64

kernel.bin: head.o kernel.o
	ld head.o kernel.o -o kernel.elf -T kernel/kernel.lds -b elf64-x86-64  
	objcopy kernel.elf kernel.bin -I elf64-x86-64 -S -R .eh_frame -R .comment -O binary 

head.o: kernel/head.asm
	as kernel/head.asm -o head.o --64

kernel.o: kernel/kernel.c
	gcc -c kernel/kernel.c -o kernel.o -mcmodel=large -fno-builtin -m64 

clean:
	rm *.o *.so *.elf *.efi *.bin *.img
