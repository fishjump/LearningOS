cmake_minimum_required(VERSION 3.5)

set(PROJECT_NAME "LearningOS")

add_subdirectory("bootloader")
add_subdirectory("kernel")

add_custom_target(MakeImage ALL
                    COMMAND dd if=/dev/zero of=os.img bs=512 count=93750
                    COMMAND parted os.img -s -a minimal mklabel gpt
                    COMMAND parted os.img -s -a minimal mkpart EFI FAT32 2048s 93716s
                    COMMAND parted os.img -s -a minimal toggle 1 boot
                
                    COMMAND dd if=/dev/zero of=/tmp/fat32_part.img bs=512 count=91669
                    COMMAND mformat -i /tmp/fat32_part.img -h 32 -t 32 -n 64 -c 1
                
                    COMMAND mcopy -i /tmp/fat32_part.img bootloader.efi ::
                    COMMAND mcopy -i /tmp/fat32_part.img kernel.bin ::
                    COMMAND mcopy -i /tmp/fat32_part.img /home/superfish/os/startup.nsh ::
                
                    COMMAND dd if=/tmp/fat32_part.img of=os.img bs=512 count=91669 seek=2048 conv=notrunc
                    COMMAND cp os.img /mnt/c/Users/z1052/)