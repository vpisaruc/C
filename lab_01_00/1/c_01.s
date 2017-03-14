	.file	"c_01.c"
	.section	.rodata
	.align 8
.LC0:
	.string	"Enter lenghts of the base and hight of the trapezoid: "
.LC1:
	.string	"%f%f%f"
	.align 8
.LC4:
	.string	"Perimeter of trapezoid is : %f \n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movl	$.LC0, %edi
	movl	$0, %eax
	call	printf
	leaq	-16(%rbp), %rcx
	leaq	-20(%rbp), %rdx
	leaq	-24(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC1, %edi
	movl	$0, %eax
	call	__isoc99_scanf
	movss	-24(%rbp), %xmm0
	movss	-20(%rbp), %xmm1
	subss	%xmm1, %xmm0
	movss	.LC2(%rip), %xmm1
	divss	%xmm1, %xmm0
	cvtss2sd	%xmm0, %xmm0
	movsd	.LC3(%rip), %xmm1
	call	pow
	movsd	%xmm0, -40(%rbp)
	movss	-16(%rbp), %xmm0
	cvtss2sd	%xmm0, %xmm0
	movsd	.LC3(%rip), %xmm1
	call	pow
	addsd	-40(%rbp), %xmm0
	call	sqrt
	addsd	%xmm0, %xmm0
	cvtsd2ss	%xmm0, %xmm3
	movss	%xmm3, -12(%rbp)
	movss	-24(%rbp), %xmm1
	movss	-20(%rbp), %xmm0
	addss	%xmm1, %xmm0
	addss	-12(%rbp), %xmm0
	cvtss2sd	%xmm0, %xmm0
	movl	$.LC4, %edi
	movl	$1, %eax
	call	printf
	movl	$0, %eax
	movq	-8(%rbp), %rsi
	xorq	%fs:40, %rsi
	je	.L3
	call	__stack_chk_fail
.L3:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.section	.rodata
	.align 4
.LC2:
	.long	1073741824
	.align 8
.LC3:
	.long	0
	.long	1073741824
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.4) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
