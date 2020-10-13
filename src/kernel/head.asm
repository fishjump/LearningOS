.section .text

.globl _start

_start:
	mov	%ss,	%ax
	mov	%ax,	%ds
	mov	%ax,	%es
	mov	%ax,	%fs
	mov	%ax,	%ss
	mov	$0x7e00,	%esp

	movq	$0x101000,	%rax
	movq	%rax,		%cr3

	lgdt	GDT_POINTER(%rip)

	lidt	idtTableDescriptor(%rip)

	mov	$0x10,	%ax
	mov	%ax,	%es
	mov	%ax,	%fs
	mov	%ax,	%gs
	mov	%ax,	%ss
	mov	$0x7e00,	%rsp
	
	movq	switch_seg(%rip),	%rax

	pushq	$0x08
	pushq	%rax
	
	lretq

/*		64-bit mode code		*/

switch_seg:
	.quad	entry64

entry64:
	movq	$0x10,	%rax
	movq	%rax,	%ds
	movq	%rax,	%es
	movq	%rax,	%gs
	movq	%rax,	%ss
	
	movq	$0xffff800000007e00,	%rsp		/* rsp address */

	movq	go_to_kernel(%rip),	%rax		/* movq address */
	pushq	$0x08
	pushq	%rax

	lretq

go_to_kernel:
	.quad	kernelMain
	
/*		init page		*/
.align 8

.org	0x1000

__PML4E:
	.quad	0x102003
	.fill	255,8,0
	.quad	0x102003
	.fill	255,8,0

.org	0x2000

__PDPTE:
	.quad	0x103003
	.fill	1,8,0
	.quad	0x104003
	.fill	509,8,0

.org	0x3000

__PDE:
	.quad	0x00000083	
	.quad	0x00200083
	.quad	0x00400083
	.quad	0x00600083
	.quad	0x00800083
	.quad	0xe0a00083
	.quad	0xe0c00083
	.quad	0xe0e00083
	.quad	0xe1000083	 
	.quad	0xe1200083
	.quad	0xe1400083
	.quad	0xe1600083
	.quad	0xe1800083
	.fill	499,8,0

.org	0x4000
__PDE_2:
	.quad 	0x80000083
	.quad 	0x80200083
	.quad 	0x80400083
	.fill	509,8,0



/*		GDT_Table		*/



.section .data

.globl GDT_Table

GDT_Table:
	.quad	0x0000000000000000			/*0	NULL descriptor		       	00*/
	.quad	0x0020980000000000			/*1	KERNEL	Code	64-bit	Segment	08*/
	.quad	0x0000920000000000			/*2	KERNEL	Data	64-bit	Segment	10*/
	.quad	0x0020f80000000000			/*3	USER	Code	64-bit	Segment	18*/
	.quad	0x0000f20000000000			/*4	USER	Data	64-bit	Segment	20*/
	.quad	0x00cf9a000000ffff			/*5	KERNEL	Code	32-bit	Segment	28*/
	.quad	0x00cf92000000ffff			/*6	KERNEL	Data	32-bit	Segment	30*/
	.fill	10,8,0					/*8 ~ 9	TSS (jmp one segment <7>) in long-mode 128-bit 40*/
GDT_END:

GDT_POINTER:
GDT_LIMIT:	.word	GDT_END - GDT_Table - 1
GDT_BASE:	.quad	GDT_Table
