	.file	"assgn1.c"
	.section	.rodata
	.align 8
.LC0:
	.string	"Enter the dimension of a square matrix: "
.LC1:
	.string	"%d"
	.align 8
.LC2:
	.string	"Enter the first matix (row-major): "
	.align 8
.LC3:
	.string	"Enter the second matix (row-major): "
.LC4:
	.string	"\nThe result matrix:"
.LC5:
	.string	"%d "
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
	subq	$4832, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movl	$.LC0, %edi
	movl	$0, %eax
	call	printf
	leaq	-4828(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC1, %edi
	movl	$0, %eax
	call	__isoc99_scanf
	movl	$.LC2, %edi
	movl	$0, %eax
	call	printf
	movl	-4828(%rbp), %eax
	leaq	-4816(%rbp), %rdx
	movq	%rdx, %rsi
	movl	%eax, %edi
	call	ReadMat
	movl	$.LC3, %edi
	movl	$0, %eax
	call	printf
	movl	-4828(%rbp), %eax
	leaq	-3216(%rbp), %rdx
	movq	%rdx, %rsi
	movl	%eax, %edi
	call	ReadMat
	movl	-4828(%rbp), %eax
	leaq	-1616(%rbp), %rcx
	leaq	-3216(%rbp), %rdx
	leaq	-4816(%rbp), %rsi
	movl	%eax, %edi
	call	MatMult
	movl	$.LC4, %edi
	call	puts
	movl	$0, -4824(%rbp)
	jmp	.L2
.L5:
	movl	$0, -4820(%rbp)
	jmp	.L3
.L4:
	movl	-4820(%rbp), %eax
	movslq	%eax, %rcx
	movl	-4824(%rbp), %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	salq	$2, %rax
	addq	%rdx, %rax
	salq	$2, %rax
	addq	%rcx, %rax
	movl	-1616(%rbp,%rax,4), %eax
	movl	%eax, %esi
	movl	$.LC5, %edi
	movl	$0, %eax
	call	printf
	addl	$1, -4820(%rbp)
.L3:
	movl	-4828(%rbp), %eax
	cmpl	%eax, -4820(%rbp)
	jl	.L4
	movl	$10, %edi
	call	putchar
	addl	$1, -4824(%rbp)
.L2:
	movl	-4828(%rbp), %eax
	cmpl	%eax, -4824(%rbp)
	jl	.L5
	movl	$0, %eax
	movq	-8(%rbp), %rcx
	xorq	%fs:40, %rcx
	je	.L7
	call	__stack_chk_fail
.L7:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.globl	ReadMat
	.type	ReadMat, @function
ReadMat:
.LFB1:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movl	%edi, -20(%rbp)
	movq	%rsi, -32(%rbp)
	movl	$0, -8(%rbp)
	jmp	.L9
.L12:
	movl	$0, -4(%rbp)
	jmp	.L10
.L11:
	movl	-8(%rbp), %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	salq	$2, %rax
	addq	%rdx, %rax
	salq	$4, %rax
	movq	%rax, %rdx
	movq	-32(%rbp), %rax
	addq	%rax, %rdx
	movl	-4(%rbp), %eax
	cltq
	salq	$2, %rax
	addq	%rdx, %rax
	movq	%rax, %rsi
	movl	$.LC1, %edi
	movl	$0, %eax
	call	__isoc99_scanf
	addl	$1, -4(%rbp)
.L10:
	movl	-4(%rbp), %eax
	cmpl	-20(%rbp), %eax
	jl	.L11
	addl	$1, -8(%rbp)
.L9:
	movl	-8(%rbp), %eax
	cmpl	-20(%rbp), %eax
	jl	.L12
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	ReadMat, .-ReadMat
	.section	.rodata
	.align 8
.LC6:
	.string	"\nThe transpose of the second matrix:"
	.text
	.globl	TransMat
	.type	TransMat, @function
TransMat:
.LFB2:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movl	%edi, -20(%rbp)
	movq	%rsi, -32(%rbp)
	movl	$0, -12(%rbp)
	jmp	.L14
.L17:
	movl	$0, -8(%rbp)
	jmp	.L15
.L16:
	movl	-12(%rbp), %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	salq	$2, %rax
	addq	%rdx, %rax
	salq	$4, %rax
	movq	%rax, %rdx
	movq	-32(%rbp), %rax
	addq	%rax, %rdx
	movl	-8(%rbp), %eax
	cltq
	movl	(%rdx,%rax,4), %eax
	movl	%eax, -4(%rbp)
	movl	-12(%rbp), %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	salq	$2, %rax
	addq	%rdx, %rax
	salq	$4, %rax
	movq	%rax, %rdx
	movq	-32(%rbp), %rax
	leaq	(%rdx,%rax), %rcx
	movl	-8(%rbp), %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	salq	$2, %rax
	addq	%rdx, %rax
	salq	$4, %rax
	movq	%rax, %rdx
	movq	-32(%rbp), %rax
	addq	%rax, %rdx
	movl	-12(%rbp), %eax
	cltq
	movl	(%rdx,%rax,4), %edx
	movl	-8(%rbp), %eax
	cltq
	movl	%edx, (%rcx,%rax,4)
	movl	-8(%rbp), %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	salq	$2, %rax
	addq	%rdx, %rax
	salq	$4, %rax
	movq	%rax, %rdx
	movq	-32(%rbp), %rax
	leaq	(%rdx,%rax), %rcx
	movl	-12(%rbp), %eax
	cltq
	movl	-4(%rbp), %edx
	movl	%edx, (%rcx,%rax,4)
	addl	$1, -8(%rbp)
.L15:
	movl	-8(%rbp), %eax
	cmpl	-12(%rbp), %eax
	jl	.L16
	addl	$1, -12(%rbp)
.L14:
	movl	-12(%rbp), %eax
	cmpl	-20(%rbp), %eax
	jl	.L17
	movl	$.LC6, %edi
	call	puts
	movl	$0, -12(%rbp)
	jmp	.L18
.L21:
	movl	$0, -8(%rbp)
	jmp	.L19
.L20:
	movl	-12(%rbp), %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	salq	$2, %rax
	addq	%rdx, %rax
	salq	$4, %rax
	movq	%rax, %rdx
	movq	-32(%rbp), %rax
	addq	%rax, %rdx
	movl	-8(%rbp), %eax
	cltq
	movl	(%rdx,%rax,4), %eax
	movl	%eax, %esi
	movl	$.LC5, %edi
	movl	$0, %eax
	call	printf
	addl	$1, -8(%rbp)
.L19:
	movl	-8(%rbp), %eax
	cmpl	-20(%rbp), %eax
	jl	.L20
	movl	$10, %edi
	call	putchar
	addl	$1, -12(%rbp)
.L18:
	movl	-12(%rbp), %eax
	cmpl	-20(%rbp), %eax
	jl	.L21
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	TransMat, .-TransMat
	.globl	VectMult
	.type	VectMult, @function
VectMult:
.LFB3:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	%edi, -20(%rbp)
	movq	%rsi, -32(%rbp)
	movq	%rdx, -40(%rbp)
	movl	$0, -4(%rbp)
	movl	$0, -8(%rbp)
	jmp	.L23
.L24:
	movl	-8(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-32(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %edx
	movl	-8(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rcx
	movq	-40(%rbp), %rax
	addq	%rcx, %rax
	movl	(%rax), %eax
	imull	%edx, %eax
	addl	%eax, -4(%rbp)
	addl	$1, -8(%rbp)
.L23:
	movl	-8(%rbp), %eax
	cmpl	-20(%rbp), %eax
	jl	.L24
	movl	-4(%rbp), %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3:
	.size	VectMult, .-VectMult
	.globl	MatMult
	.type	MatMult, @function
MatMult:
.LFB4:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$56, %rsp
	.cfi_offset 3, -24
	movl	%edi, -36(%rbp)
	movq	%rsi, -48(%rbp)
	movq	%rdx, -56(%rbp)
	movq	%rcx, -64(%rbp)
	movq	-56(%rbp), %rdx
	movl	-36(%rbp), %eax
	movq	%rdx, %rsi
	movl	%eax, %edi
	call	TransMat
	movl	$0, -24(%rbp)
	jmp	.L27
.L30:
	movl	$0, -20(%rbp)
	jmp	.L28
.L29:
	movl	-24(%rbp), %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	salq	$2, %rax
	addq	%rdx, %rax
	salq	$4, %rax
	movq	%rax, %rdx
	movq	-64(%rbp), %rax
	leaq	(%rdx,%rax), %rbx
	movl	-20(%rbp), %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	salq	$2, %rax
	addq	%rdx, %rax
	salq	$4, %rax
	movq	%rax, %rdx
	movq	-56(%rbp), %rax
	addq	%rdx, %rax
	movq	%rax, %rsi
	movl	-24(%rbp), %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	salq	$2, %rax
	addq	%rdx, %rax
	salq	$4, %rax
	movq	%rax, %rdx
	movq	-48(%rbp), %rax
	addq	%rdx, %rax
	movq	%rax, %rcx
	movl	-36(%rbp), %eax
	movq	%rsi, %rdx
	movq	%rcx, %rsi
	movl	%eax, %edi
	call	VectMult
	movl	%eax, %edx
	movl	-20(%rbp), %eax
	cltq
	movl	%edx, (%rbx,%rax,4)
	addl	$1, -20(%rbp)
.L28:
	movl	-20(%rbp), %eax
	cmpl	-36(%rbp), %eax
	jl	.L29
	addl	$1, -24(%rbp)
.L27:
	movl	-24(%rbp), %eax
	cmpl	-36(%rbp), %eax
	jl	.L30
	nop
	addq	$56, %rsp
	popq	%rbx
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE4:
	.size	MatMult, .-MatMult
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.11) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
