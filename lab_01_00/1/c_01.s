	.file	"c_01.c"
	.intel_syntax noprefix
	.def	__main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
	.align 8
.LC0:
	.ascii "Enter lenghts of the base and hight of the trapezoid: \0"
.LC1:
	.ascii "%f%f%f\0"
	.align 8
.LC4:
	.ascii "Perimeter of trapezoid is : %f \12\0"
	.text
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
	push	rbp
	.seh_pushreg	rbp
	mov	rbp, rsp
	.seh_setframe	rbp, 0
	sub	rsp, 96
	.seh_stackalloc	96
	movaps	XMMWORD PTR -32[rbp], xmm6
	.seh_savexmm	xmm6, 64
	movaps	XMMWORD PTR -16[rbp], xmm7
	.seh_savexmm	xmm7, 80
	.seh_endprologue
	call	__main
	lea	rcx, .LC0[rip]
	call	printf
	lea	rcx, -44[rbp]
	lea	rdx, -40[rbp]
	lea	rax, -36[rbp]
	mov	r9, rcx
	mov	r8, rdx
	mov	rdx, rax
	lea	rcx, .LC1[rip]
	call	scanf
	movss	xmm1, DWORD PTR -36[rbp]
	movss	xmm0, DWORD PTR -40[rbp]
	addss	xmm0, xmm1
	cvtss2sd	xmm6, xmm0
	movss	xmm0, DWORD PTR -36[rbp]
	movss	xmm1, DWORD PTR -40[rbp]
	subss	xmm0, xmm1
	movss	xmm1, DWORD PTR .LC2[rip]
	divss	xmm0, xmm1
	cvtss2sd	xmm0, xmm0
	movsd	xmm1, QWORD PTR .LC3[rip]
	call	pow
	movapd	xmm7, xmm0
	movss	xmm0, DWORD PTR -44[rbp]
	cvtss2sd	xmm0, xmm0
	movsd	xmm1, QWORD PTR .LC3[rip]
	call	pow
	addsd	xmm0, xmm7
	call	sqrt
	addsd	xmm0, xmm0
	addsd	xmm0, xmm6
	movq	rax, xmm0
	mov	rdx, rax
	mov	QWORD PTR -56[rbp], rdx
	movsd	xmm0, QWORD PTR -56[rbp]
	movapd	xmm1, xmm0
	mov	rdx, rax
	lea	rcx, .LC4[rip]
	call	printf
	mov	eax, 0
	movaps	xmm6, XMMWORD PTR -32[rbp]
	movaps	xmm7, XMMWORD PTR -16[rbp]
	add	rsp, 96
	pop	rbp
	ret
	.seh_endproc
	.section .rdata,"dr"
	.align 4
.LC2:
	.long	1073741824
	.align 8
.LC3:
	.long	0
	.long	1073741824
	.ident	"GCC: (Rev1, Built by MSYS2 project) 6.3.0"
	.def	printf;	.scl	2;	.type	32;	.endef
	.def	scanf;	.scl	2;	.type	32;	.endef
	.def	pow;	.scl	2;	.type	32;	.endef
	.def	sqrt;	.scl	2;	.type	32;	.endef
