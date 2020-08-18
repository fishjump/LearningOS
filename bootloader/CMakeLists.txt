cmake_minimum_required(VERSION 3.5)

set(PROJECT_NAME "bootloader")

set(SOURCE_FILE "${CMAKE_CURRENT_SOURCE_DIR}/bootloader.c")

set(OBJECT_FILE "${CMAKE_BINARY_DIR}/bootloader.o")
set(SHARED_OBJECT_FILE "${CMAKE_BINARY_DIR}/bootloader.so")
set(EFI_FILE "${CMAKE_BINARY_DIR}/bootloader.efi")

set(LIBS ${OBJECT_FILE} /usr/lib/crt0-efi-x86_64.o /usr/lib/libgnuefi.a /usr/lib/libefi.a)

set(C_FLAGS -std=c11 -fno-stack-protector -fpic -fshort-wchar -mno-red-zone -DEFI_FUNCTION_WRAPPER)
set(LD_FLAGS -nostdlib -znocombreloc -T /usr/lib/elf_x86_64_efi.lds -shared -Bsymbolic)
set(OBJCP_FLAGS -j .text -j .sdata -j .data -j .dynamic -j .dynsym -j .rel -j .rela  -j .reloc -O efi-app-x86_64)

project (${PROJECT_NAME})

add_custom_target(Complie ALL 
                    COMMAND gcc -c ${SOURCE_FILE} -o ${OBJECT_FILE} ${C_FLAGS}
                    COMMENT "[Complie] ${SOURCE_FILE} to ${OBJECT_FILE}")

add_custom_target(Link ALL 
                    DEPENDS Complie
                    COMMAND ld ${LIBS} -o ${SHARED_OBJECT_FILE} ${LD_FLAGS}
                    COMMENT "[Link] ${OBJECT_FILE} to ${SHARED_OBJECT_FILE}")

add_custom_target(ObjCp ALL 
                    DEPENDS Link
                    COMMAND objcopy ${SHARED_OBJECT_FILE} ${EFI_FILE} ${OBJCP_FLAGS}
                    COMMENT "[ObjectCopy] ${SHARED_OBJECT_FILE} to ${EFI_FILE}")
                    
add_custom_target(Clean ALL 
                    DEPENDS ObjCp
                    COMMAND rm ${OBJECT_FILE} ${SHARED_OBJECT_FILE}
                    COMMENT "[Clean] Delete ${OBJECT_FILE} ${SHARED_OBJECT_FILE}")