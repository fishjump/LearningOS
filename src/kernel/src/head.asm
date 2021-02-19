.section .text

.globl _start

_start:
    mov    %ss,    %ax
    mov    %ax,    %ds
    mov    %ax,    %es
    mov    %ax,    %fs
    mov    %ax,    %ss
    mov    $0x7e00,    %esp

    movq    $0x101000,    %rax
    movq    %rax,        %cr3

    /* defined in kernel/system/memory/gdt/gdt.hpp */
    lgdt    gdtTableDescriptor(%rip)

    /* defined in kernel/system/interrupt/idt/idt.hpp */
    lidt    idtDescriptor(%rip)

    mov    $0x10,    %ax
    mov    %ax,    %es
    mov    %ax,    %fs
    mov    %ax,    %gs
    mov    %ax,    %ss
    mov    $0x7e00,    %rsp
    
    movq    entry64Addr(%rip),    %rax

    pushq    $0x08
    pushq    %rax
    
    lretq

entry64:
    movq    $0x10,    %rax
    movq    %rax,    %ds
    movq    %rax,    %es
    movq    %rax,    %gs
    movq    %rax,    %ss
    
    movq    $0xffff800000007e00,    %rsp

    movq    kernelMainAddr(%rip),    %rax
    pushq    $0x08
    pushq    %rax

    lretq

entry64Addr:
    .quad    entry64

kernelMainAddr:
    .quad    kernelMain
    
/*        init page        */
.align 8

.org    0x1000

__PML4E:
    .quad    0x102003
    .fill    255,8,0
    .quad    0x102003
    .fill    255,8,0

.org    0x2000

__PDPTE:
    .quad    0x103003
    .quad    0x104003
    .quad    0x105003
    .fill    509,8,0

.org    0x3000

__PDE:
    .quad    0x00000083    
    .quad    0x00200083
    .quad    0x00400083
    .quad    0x00600083
    .quad    0x00800083
    .quad    0xe0a00083
    .quad    0xe0c00083
    .quad    0xe0e00083
    .quad    0xe1000083     
    .quad    0xe1200083
    .quad    0xe1400083
    .quad    0xe1600083
    .quad    0xe1800083
    .fill    499,8,0

.org    0x4000
__PDE_3:
    .fill    512,8,0

.org    0x5000
__PDE_4:
    .quad    0x80000083
    .quad    0x80200083
    .quad    0x80400083
    .fill    381,8,0
    .quad    0xb0000083
    .quad    0xb0200083
    .quad    0xb0400083
    .quad    0xb0600083
    .quad    0xb0800083
    .quad    0xb0a00083
    .quad    0xb0c00083
    .quad    0xb0e00083
    .quad    0xb1000083
    .quad    0xb1200083
    .quad    0xb1400083
    .quad    0xb1600083
    .quad    0xb1800083
    .quad    0xb1a00083
    .quad    0xb1c00083
    .quad    0xb1e00083
    .quad    0xb2000083
    .fill    111,8,0
