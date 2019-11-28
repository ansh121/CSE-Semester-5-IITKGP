	.file	"ass1_17CS10005.c"	
	.text
	.section	.rodata					
	.align 8						
.LC0:								#label for f-string , 1st printf
	.string	"Enter the dimension of a square matrix: "
.LC1:								#label for f-string , 1st scanf
	.string	"%d"
	.align 8						# align with 8-byte boundary
.LC2:								# Label of f-string, 2nd printf
	.string	"Enter the first matix (row-major): "
	.align 8						# align with 8-byte boundary
.LC3:								# 3rd printf of main function
	.string	"Enter the second matix (row-major): "
.LC4:								#4th printf of main func 
	.string	"\nThe result matrix:"
.LC5:								# printf for loop in main func 
	.string	"%d "
	.text							
	.globl	main						
	.type	main, @function					# main is a function type
main:								
.LFB0:
	.cfi_startproc
	pushq	%rbp						# Save old base pointer 
	.cfi_def_cfa_offset 16					
	.cfi_offset 6, -16					
	movq	%rsp, %rbp					# rbp<-rsp, setting new stack base pointer (q for quadword)
	.cfi_def_cfa_register 6					
	subq	$4832, %rsp					# Create space for local array and variables
	movq	%fs:40, %rax					 
	movq	%rax, -8(%rbp)					
	xorl	%eax, %eax					# eax=0
	leaq	.LC0(%rip), %rdi				# Load address of  string of 1st printf
	movl	$0, %eax					# eax = 0
	call	printf@PLT					# Calls the printf function to print the 1st printf statement in C(i.e. in .LC0)
	leaq	-4828(%rbp), %rax				
	movq	%rax, %rsi					
	leaq	.LC1(%rip), %rdi			# Load address to store parameter
	movl	$0, %eax					# eax = 0
	call	__isoc99_scanf@PLT				# get the input of dimension of matrix
	leaq	.LC2(%rip), %rdi				# Load address of string of 2nd printf 
	movl	$0, %eax					# eax=0
	call	printf@PLT					# print the 2nd printf statement
	movl	-4828(%rbp), %eax			# copy address of int n to eax
	leaq	-4816(%rbp), %rdx			# copy address of mat A to rdx
	movq	%rdx, %rsi					# prepare function passing arguments
	movl	%eax, %edi					
	call	ReadMat						# function to take input for A
	leaq	.LC3(%rip), %rdi				# Load address of string of 3rd printf
	movl	$0, %eax					# eax=0
	call	printf@PLT					# print the 3rd printf statement
	movl	-4828(%rbp), %eax			# copy address of int n to eax
	leaq	-3216(%rbp), %rdx			# copy address of mat B to rdx
	movq	%rdx, %rsi					# prepare function passing arguments
	movl	%eax, %edi					
	call	ReadMat						# function to take inputs for Mat B
	movl	-4828(%rbp), %eax			# n # prepare function passing arguments	
	leaq	-1616(%rbp), %rcx			# C	
	leaq	-3216(%rbp), %rdx			# B	
	leaq	-4816(%rbp), %rsi			# A	
	movl	%eax, %edi					# copy eax to edi, 1st argument of MatMult
	call	MatMult						# calls MatMult function to calculate C
	leaq	.LC4(%rip), %rdi			# Load address of string of 4th printf
	call	puts@PLT					# prints string
	movl	$0, -4824(%rbp)				# i=0
	jmp	.L2								# jump to .L2
.L5:
	movl	$0, -4820(%rbp)				# j=0
	jmp	.L3								# jump to .L3
.L4:
	movl	-4820(%rbp), %eax			# get j
	movslq	%eax, %rcx					# convert j to long 
	movl	-4824(%rbp), %eax			# get i
	movslq	%eax, %rdx					# convert i to long
	movq	%rdx, %rax					# get i
	salq	$2, %rax					# rax<<2 or rax=4*i
	addq	%rdx, %rax					# rax+=rdx, rax=rax+i = 5*i
	salq	$2, %rax					# rax<<2 or rax=4*rax=20*i
	addq	%rcx, %rax					# rax=rax+j, rax=20*i+j, rax=j in ith row
	movl	-1616(%rbp,%rax,4), %eax	# eax=address(Mat C)+4*(20*i+j)
	movl	%eax, %esi					# esi=C[i][j]
	leaq	.LC5(%rip), %rdi			# load address of "%d"
	movl	$0, %eax					# eax=0
	call	printf@PLT					# printf ("%d", C[i][j])
	addl	$1, -4820(%rbp)				# j++
.L3:
	movl	-4828(%rbp), %eax			# get n
	cmpl	%eax, -4820(%rbp)			# compare n & j
	jl	.L4								# if j<n, jump to .L4
	movl	$10, %edi					# edi=10, ascii=10 for "\n"
	call	putchar@PLT					# printf("\n")
	addl	$1, -4824(%rbp)				# i++
.L2:
	movl	-4828(%rbp), %eax			# get n
	cmpl	%eax, -4824(%rbp)			# cmp n & i
	jl	.L5								# if i<n , jump to .L5
	movl	$0, %eax					# eax=0
	movq	-8(%rbp), %rcx				# get j
	xorq	%fs:40, %rcx				
	je	.L7								# jump to .L7 if 0
	call	__stack_chk_fail@PLT
.L7:
	leave								# clear stack
	.cfi_def_cfa 7, 8
	ret									# return
	.cfi_endproc						# end program
.LFE0:
	.size	main, .-main
	.globl	ReadMat	
	.type	ReadMat, @function			
ReadMat:
.LFB1:
	.cfi_startproc						
	pushq	%rbp						# save old base pointer
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp					# tempoart stack pointer
	.cfi_def_cfa_register 6
	subq	$32, %rsp					# creating space for local array and variables 
	movl	%edi, -20(%rbp)				#prepare function arguments
	movq	%rsi, -32(%rbp)				
	movl	$0, -8(%rbp)				# i=0
	jmp	.L9								# jump to .L9
.L12:
	movl	$0, -4(%rbp)				# j=0
	jmp	.L10							# jump to .L10
.L11:
	movl	-8(%rbp), %eax				# eax=i
	movslq	%eax, %rdx					# rdx=SignExtend(eax)
	movq	%rdx, %rax					# rax=i
	salq	$2, %rax					# rax<<2, rax=4*i
	addq	%rdx, %rax					# rax=rax+rdx, rax=5*i
	salq	$4, %rax					# rax<<4, rax=80*i, address of row[i][0]
	movq	%rax, %rdx					# rdx=rax
	movq	-32(%rbp), %rax				# rax=address of Mat
	addq	%rax, %rdx					# rdx=rdx+rax
	movl	-4(%rbp), %eax				# eax=j
	cltq								# rax=signExtend(eax)
	salq	$2, %rax					# rax=4*rax
	addq	%rdx, %rax					# rax=rdx+rax, address of next integer i.e. jth int int ith row
	movq	%rax, %rsi					# rsi=rax
	leaq	.LC1(%rip), %rdi			# load address of "%d"
	movl	$0, %eax					# eax=0
	call	__isoc99_scanf@PLT			# scanf("%d",&data[i][j])
	addl	$1, -4(%rbp)				# j++
.L10:
	movl	-4(%rbp), %eax				# eax=j
	cmpl	-20(%rbp), %eax				# compare n & j
	jl	.L11							# jump to .L11 if j<n
	addl	$1, -8(%rbp)				# i++
.L9:
	movl	-8(%rbp), %eax				# eax=i
	cmpl	-20(%rbp), %eax				# compare n & i
	jl	.L12							# if i<n, jump to .L12
	nop
	leave								# clear stack
	.cfi_def_cfa 7, 8
	ret							
	.cfi_endproc						
.LFE1:
	.size	ReadMat, .-ReadMat
	.section	.rodata					
	.align 8
.LC6:
	.string	"\nThe transpose of the second matrix:"		# string of printf statement in TransMat
	.text
	.globl	TransMat
	.type	TransMat, @function				
TransMat:
.LFB2:
	.cfi_startproc						# TransMat starts
	pushq	%rbp						# save old base pointer
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp					# rbp=rsp
	.cfi_def_cfa_register 6
	subq	$32, %rsp					# create space for local variables
	movl	%edi, -20(%rbp)				# save function arguments before call
	movq	%rsi, -32(%rbp)				
	movl	$0, -12(%rbp)				# i=0
	jmp	.L14							# jump to .L14
.L17:
	movl	$0, -8(%rbp)				# j=0
	jmp	.L15							# jump to .L15
.L16:
	movl	-12(%rbp), %eax				# eax=i
	movslq	%eax, %rdx					# rdx=SignExtend(eax)
	movq	%rdx, %rax					# rax=rdx
	salq	$2, %rax					# rax<<2, rax=4*i
	addq	%rdx, %rax					# rax=rax+rdx, rax=5*i
	salq	$4, %rax					# rax<<4,rax=80*i, address of eg-> arr[i][0]
	movq	%rax, %rdx					# rdx=rax
	movq	-32(%rbp), %rax				# rax=address of Mat data
	addq	%rax, %rdx					# rdx=rdx+rax
	movl	-8(%rbp), %eax				# eax=j
	cltq								# rax=signExtend(eax)
	movl	(%rdx,%rax,4), %eax			# eax=rdx+4*j
	movl	%eax, -4(%rbp)				# t=data[i][j]
	movl	-8(%rbp), %eax				# eax=j
	movslq	%eax, %rdx					# rdx=signExtend(eax)
	movq	%rdx, %rax					# rax=rdx
	salq	$2, %rax					# rax=4*j
	addq	%rdx, %rax					# rax=rax+rdx,rax=5*j
	salq	$4, %rax					# rax=80*j
	movq	%rax, %rdx					# rdx=rax
	movq	-32(%rbp), %rax				# rax=address of Mat data
	leaq	(%rdx,%rax), %rsi			# rsi=rdx+rax=data[j]
	movl	-12(%rbp), %eax				# eax=i
	movslq	%eax, %rdx					# rdx=signExtend(eax)
	movq	%rdx, %rax					# rax=rdx
	salq	$2, %rax					# rax=4*i
	addq	%rdx, %rax					# rax=5*i
	salq	$4, %rax					# rax=80*i
	movq	%rax, %rdx					# rdx=rax
	movq	-32(%rbp), %rax				# rax=address of Mat data
	leaq	(%rdx,%rax), %rcx			# rcx=rdx+rax=data[i]
	movl	-12(%rbp), %eax				# eax=i
	cltq								# rax=signExtend(eax)
	movl	(%rsi,%rax,4), %edx			# edx=rsi+4*i, edx=data[j][i]
	movl	-8(%rbp), %eax				# eax=j
	cltq								# rax=signExtend(eax)
	movl	%edx, (%rcx,%rax,4)			# rcx+4*j=edx, data[i][j]=data[j][i]
	movl	-8(%rbp), %eax				# eax=j
	movslq	%eax, %rdx					# rdx=signExtend(eax)
	movq	%rdx, %rax					# rax=rdx
	salq	$2, %rax					# rax=4*j
	addq	%rdx, %rax					# rax=rax+rdx=5*j
	salq	$4, %rax					# rax=80*j
	movq	%rax, %rdx					# rdx=rax
	movq	-32(%rbp), %rax				# rax=address of Mat data
	leaq	(%rdx,%rax), %rcx			# rcx=data[j]
	movl	-12(%rbp), %eax				# eax=i
	cltq								# rax=signExtend(eax)
	movl	-4(%rbp), %edx				# edx=t
	movl	%edx, (%rcx,%rax,4)			# rcx+4*i=edx, data[j][i]=data[i][j]
	addl	$1, -8(%rbp)				# j++
.L15:
	movl	-8(%rbp), %eax				# eax=j
	cmpl	-12(%rbp), %eax				# compare i & j
	jl	.L16							# jump to .L16 if j<i
	addl	$1, -12(%rbp)				# i++
.L14:
	movl	-12(%rbp), %eax				# eax=i
	cmpl	-20(%rbp), %eax				# compare n & i
	jl	.L17							# jump to .L17 if i<n
	leaq	.LC6(%rip), %rdi			# load address of .LC6
	call	puts@PLT					# printf("\nThe transpose of the second matrix:\n")
	movl	$0, -12(%rbp)				# i=0
	jmp	.L18							# jump to .L18
.L21:
	movl	$0, -8(%rbp)				# j=0
	jmp	.L19							# jump to .L19
.L20:
	movl	-12(%rbp), %eax				# eax=i
	movslq	%eax, %rdx					# rdx=signExtend(eax)
	movq	%rdx, %rax					# rax=rdx
	salq	$2, %rax					# rax=4*i
	addq	%rdx, %rax					# rax=5*i
	salq	$4, %rax					# rax=80*i
	movq	%rax, %rdx					# rdx=rax
	movq	-32(%rbp), %rax				# rax=address of Mat data
	addq	%rax, %rdx					# rdx=data[i]
	movl	-8(%rbp), %eax				# eax=j
	cltq								# rax=signExtend(eax)
	movl	(%rdx,%rax,4), %eax			# eax=data[i][j]
	movl	%eax, %esi					# esi=eax
	leaq	.LC5(%rip), %rdi			# rdi="%d "
	movl	$0, %eax					# eax=0
	call	printf@PLT					# printf("%d ",data[i][j])
	addl	$1, -8(%rbp)				# j++
.L19:
	movl	-8(%rbp), %eax				# eax=j
	cmpl	-20(%rbp), %eax				# compare n & j
	jl	.L20							# jump to .L20 if j<n
	movl	$10, %edi					# edi="\n"
	call	putchar@PLT					# printf("\n")
	addl	$1, -12(%rbp)				# i++
.L18:
	movl	-12(%rbp), %eax				# eax=i
	cmpl	-20(%rbp), %eax				# compare n & i
	jl	.L21							# jump to .L21 if i<n
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
	.cfi_startproc						# VectMult starts
	pushq	%rbp						# save old base pointer
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp					# rbp=rsp
	.cfi_def_cfa_register 6
	movl	%edi, -20(%rbp)				# prepare arguments before function call
	movq	%rsi, -32(%rbp)				
	movq	%rdx, -40(%rbp)				
	movl	$0, -4(%rbp)				# result=0
	movl	$0, -8(%rbp)				# i=0
	jmp	.L23							# jump to .L23
.L24:
	movl	-8(%rbp), %eax				# eax=i
	cltq								# rax=signExtend(eax)
	leaq	0(,%rax,4), %rdx			# rdx=4*i
	movq	-32(%rbp), %rax				# rax=address of Mat firstMat
	addq	%rdx, %rax					# rax=firstMat + 4*i
	movl	(%rax), %edx				# edx=firstMat[i]
	movl	-8(%rbp), %eax				# eax=i
	cltq								# rax=signExtend(eax)
	leaq	0(,%rax,4), %rcx			# rcx=4*i
	movq	-40(%rbp), %rax				# rax=address of Mat secondMat
	addq	%rcx, %rax					# rax=secondMat+4*i
	movl	(%rax), %eax				# eax=secondMat[i]
	imull	%edx, %eax					# eax=edx*eax
	addl	%eax, -4(%rbp)				# result=result+eax
	addl	$1, -8(%rbp)				# i++
.L23:
	movl	-8(%rbp), %eax				# eax=i
	cmpl	-20(%rbp), %eax				# compare n & i
	jl	.L24							# jump to .L24 if i<n
	movl	-4(%rbp), %eax				# eax=result , return value
	popq	%rbp						# rbp=pop()
	.cfi_def_cfa 7, 8
	ret									
	.cfi_endproc						
.LFE3:
	.size	VectMult, .-VectMult
	.globl	MatMult
	.type	MatMult, @function			
MatMult:
.LFB4:
	.cfi_startproc						# MatMult starts
	pushq	%rbp						# save old base pointer
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp					# rbp=rsp
	.cfi_def_cfa_register 6
	pushq	%rbx						# save callee address
	subq	$56, %rsp					# create space for local variables
	.cfi_offset 3, -24
	movl	%edi, -36(%rbp)				# save function arguments before call
	movq	%rsi, -48(%rbp)				
	movq	%rdx, -56(%rbp)					
	movq	%rcx, -64(%rbp)					
	movq	-56(%rbp), %rdx				# rdx=address of secondMat
	movl	-36(%rbp), %eax				# eax=n
	movq	%rdx, %rsi					# rsi=rdx
	movl	%eax, %edi					# edi=eax
	call	TransMat					# calls TransMat
	movl	$0, -24(%rbp)				# i=0
	jmp	.L27							# jump to .L27
.L30:
	movl	$0, -20(%rbp)				# j=0
	jmp	.L28							# jump to .L28
.L29:
	movl	-20(%rbp), %eax				# eax=j
	movslq	%eax, %rdx					# rdx=signExtend(eax)
	movq	%rdx, %rax					# rax=rdx
	salq	$2, %rax					# rax=4*j
	addq	%rdx, %rax					# rax=5*j
	salq	$4, %rax					# rax=80*j
	movq	%rax, %rdx					# rdx=rax
	movq	-56(%rbp), %rax				# rax=address of secondMat
	addq	%rdx, %rax					# rax=rax+rdx, rax=secondMat[j]
	movq	%rax, %rsi					# rsi=rax
	movl	-24(%rbp), %eax				# eax=i
	movslq	%eax, %rdx					# rdx=signExtend(eax)
	movq	%rdx, %rax					# rax=rdx
	salq	$2, %rax					# rax=4*i
	addq	%rdx, %rax					# rax=5*i
	salq	$4, %rax					# rax=80*i
	movq	%rax, %rdx					# rdx=rax
	movq	-48(%rbp), %rax				# rax=address of firstMat
	addq	%rdx, %rax					# rax=firstMat[i]
	movq	%rax, %rcx					# rcx=rax
	movl	-24(%rbp), %eax				# eax=i
	movslq	%eax, %rdx					# rdx=signExtend(eax)
	movq	%rdx, %rax					# rax=rdx
	salq	$2, %rax					# rax=4*i
	addq	%rdx, %rax					# rax=5*i
	salq	$4, %rax					# rax=80*i
	movq	%rax, %rdx					# rdx=rax
	movq	-64(%rbp), %rax				# rax=address of M
	leaq	(%rdx,%rax), %rbx			# rbx=rdx+rax, rbx=M[i]
	movl	-36(%rbp), %eax				# eax=n
	movq	%rsi, %rdx					# rdx=rsi
	movq	%rcx, %rsi					# rsi=rcx
	movl	%eax, %edi					# edi=eax
	call	VectMult					# calls VectMult
	movl	%eax, %edx					# edx=eax, return value from VectMult
	movl	-20(%rbp), %eax				# eax=j
	cltq								# rax=signExtend(eax)
	movl	%edx, (%rbx,%rax,4)			#  M[i][j]=edx
	addl	$1, -20(%rbp)				# j++
.L28:
	movl	-20(%rbp), %eax				# eax=j
	cmpl	-36(%rbp), %eax				# compare n & j
	jl	.L29							# jump to .L29 if j<n
	addl	$1, -24(%rbp)				# i++
.L27:
	movl	-24(%rbp), %eax				# eax=i
	cmpl	-36(%rbp), %eax				# compare n & i
	jl	.L30							# jump to .L30 if i<n
	nop
	addq	$56, %rsp					# rsp=rsp+56
	popq	%rbx						# rbx=pop(), callee address (in main())
	popq	%rbp						# rbp=pop(), old base pointer
	.cfi_def_cfa 7, 8
	ret							
	.cfi_endproc						
.LFE4:
	.size	MatMult, .-MatMult
	.ident	"GCC: (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0"
	.section	.note.GNU-stack,"",@progbits
