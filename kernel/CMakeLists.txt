cmake_minimum_required(VERSION 3.5)

set(PROJECT_NAME "kernel")

set(KERNEL_LDS_FILE "${CMAKE_CURRENT_SOURCE_DIR}/kernel.lds")
set(KERNEL_SOURCE_FILE "${CMAKE_CURRENT_SOURCE_DIR}/kernel.cpp")
set(HEAD_SOURCE_FILE "${CMAKE_CURRENT_SOURCE_DIR}/head.asm")

set(KERNEL_OBJECT_FILE "${CMAKE_BINARY_DIR}/kernel.o")
set(HEAD_OBJECT_FILE "${CMAKE_BINARY_DIR}/head.o")
set(ELF_FILE "${CMAKE_BINARY_DIR}/kernel.elf")
set(BIN_FILE "${CMAKE_BINARY_DIR}/kernel.bin")

set(LIBS ${HEAD_OBJECT_FILE} ${KERNEL_OBJECT_FILE})

set(CXX_FLAGS -std=c++17 -mcmodel=large -fno-builtin -m64)
set(ASM_FLAGS --64)
set(LD_FLAGS -T ${KERNEL_LDS_FILE} -b elf64-x86-64)
set(OBJCP_FLAGS -I elf64-x86-64 -S -R .eh_frame -R .comment -O binary )

project (${PROJECT_NAME})

add_custom_target(KernelComplie ALL 
                    COMMAND g++ -c ${KERNEL_SOURCE_FILE} -o ${KERNEL_OBJECT_FILE} ${CXX_FLAGS}
                    COMMAND as ${HEAD_SOURCE_FILE} -o ${HEAD_OBJECT_FILE} ${ASM_FLAGS}
                    COMMENT "[Complie] ${SOURCE_FILE} to ${OBJECT_FILE}, ${HEAD_SOURCE_FILE} to ${HEAD_OBJECT_FILE}")

add_custom_target(KernelLink ALL 
                    DEPENDS KernelComplie
                    COMMAND ld ${LIBS} -o ${ELF_FILE} ${LD_FLAGS}
                    COMMENT "[Link] ${LIBS} to ${SHARED_OBJECT_FILE}")

add_custom_target(KernelObjCp ALL 
                    DEPENDS KernelLink
                    COMMAND objcopy ${ELF_FILE} ${BIN_FILE} ${OBJCP_FLAGS}
                    COMMENT "[ObjectCopy] ${ELF_FILE} to ${BIN_FILE}")
                    
add_custom_target(KernelClean ALL 
                    DEPENDS KernelObjCp
                    COMMAND rm ${KERNEL_OBJECT_FILE} ${HEAD_OBJECT_FILE} ${ELF_FILE}
                    COMMENT "[Clean] Delete ${KERNEL_OBJECT_FILE} ${HEAD_OBJECT_FILE} ${ELF_FILE}")