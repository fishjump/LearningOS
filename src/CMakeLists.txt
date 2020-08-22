cmake_minimum_required(VERSION 3.5)

set(PROJECT_NAME "LearningOS")

set(UEFI_STARTUP_SH "${CMAKE_CURRENT_SOURCE_DIR}/startup.nsh")

set(OS_IMAGE_FILE "${CMAKE_BINARY_DIR}/os.img")
set(BIN_FILE "${CMAKE_BINARY_DIR}/kernel.bin")
set(EFI_FILE "${CMAKE_BINARY_DIR}/bootloader.efi")
set(TMP_FAT32_FILE "/tmp/fat32_part.img")
set(OUTPUT_PATH "/mnt/c/Users/z1052/")

project (${PROJECT_NAME})

add_subdirectory("bootloader")
add_subdirectory("kernel")

add_custom_target(Parted ALL
                    COMMAND dd if=/dev/zero of=${OS_IMAGE_FILE} bs=512 count=93750
                    COMMAND parted ${OS_IMAGE_FILE} -s -a minimal mklabel gpt
                    COMMAND parted ${OS_IMAGE_FILE} -s -a minimal mkpart EFI FAT32 2048s 93716s
                    COMMAND parted ${OS_IMAGE_FILE} -s -a minimal toggle 1 boot
                    COMMENT "[${PROJECT_NAME}] Create ${OS_IMAGE_FILE} and part it")
                
add_custom_target(Format ALL
                    DEPENDS Parted
                    COMMAND dd if=/dev/zero of=${TMP_FAT32_FILE} bs=512 count=91669
                    COMMAND mformat -i ${TMP_FAT32_FILE} -h 32 -t 32 -n 64 -c 1
                    COMMENT "[${PROJECT_NAME}] Create ${TMP_FAT32_FILE} with fat32 format")

add_custom_target(Copy ALL
                    DEPENDS Format
                    COMMAND mcopy -i ${TMP_FAT32_FILE} ${EFI_FILE} ::
                    COMMAND mcopy -i ${TMP_FAT32_FILE} ${BIN_FILE} ::
                    COMMAND mcopy -i ${TMP_FAT32_FILE} ${UEFI_STARTUP_SH} ::
                    COMMENT "[${PROJECT_NAME}] Copy ${EFI_FILE} ${BIN_FILE} ${UEFI_STARTUP_SH} into ${TMP_FAT32_FILE}")

add_custom_target(MakeImage ALL  
                    DEPENDS  Copy            
                    COMMAND dd if=${TMP_FAT32_FILE} of=${OS_IMAGE_FILE} bs=512 count=91669 seek=2048 conv=notrunc
                    COMMENT "[${PROJECT_NAME}] Copy ${TMP_FAT32_FILE} to ${OS_IMAGE_FILE}")

add_custom_target(Output ALL
                    DEPENDS  MakeImage    
                    COMMAND cp ${OS_IMAGE_FILE} ${OUTPUT_PATH}
                    COMMENT "[${PROJECT_NAME}] Copy ${OS_IMAGE_FILE} to ${OUTPUT_PATH}")