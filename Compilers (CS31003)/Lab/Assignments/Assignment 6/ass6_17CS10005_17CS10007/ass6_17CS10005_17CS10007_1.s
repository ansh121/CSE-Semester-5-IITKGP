	.section	.rodata
.LC0:
	.string "\n\n\n********* Multiplying two numbers a and b *********\n"
.LC1:
	.string "a = "
.LC2:
	.string "b = "
.LC3:
	.string "Product = "
.LC4:
	.string "\n"
  # function printInt start
  # function printStr start
  # function readInt start
  # function main start
#--loacl var offset: 4 -4
#--loacl var offset: 4 -8
#--loacl var offset: 4 -12
#--loacl var offset: 4 -16
#--loacl var offset: 4 -20
#--loacl var offset: 4 -24
#--loacl var offset: 4 -28
#--loacl var offset: 8 -36
#--loacl var offset: 4 -40
#--loacl var offset: 8 -48
#--loacl var offset: 4 -52
#--loacl var offset: 4 -56
#--loacl var offset: 4 -60
#--loacl var offset: 4 -64
#--loacl var offset: 4 -68
#-68
##ptra
##ptrb
##ptrp
##ptrprintStr
##ptr.LC0
##ptr.LC1
##ptrreadInt
##ptrt0
##ptr.LC2
##ptrt1
##ptr.LC3
##ptrprintInt
##ptrt2
##ptr.LC4
##ptrt3
##ptrretVal
	.globl	main
	.type	main, @function
main:
	pushq	%rbp
	movq	%rsp, %rbp
	subq	$96,	%rsp
  # param .LC0
	movq	$.LC0,	%rdi
  # call printStr 1
	call	printStr
  # param .LC1
	movq	$.LC1,	%rdi
  # call printStr 1
	call	printStr
  # t0= &p
	leaq	-12(%rbp),	%rax
	movq	%rax,	-36(%rbp)
  # param t0
	movq	-36(%rbp),	%rdi
  # call readInt 1
	call	readInt
  # a = readInt
	movl	%eax,	-4(%rbp)
  # param .LC2
	movq	$.LC2,	%rdi
  # call printStr 1
	call	printStr
  # t1= &p
	leaq	-12(%rbp),	%rax
	movq	%rax,	-48(%rbp)
  # param t1
	movq	-48(%rbp),	%rdi
  # call readInt 1
	call	readInt
  # b = readInt
	movl	%eax,	-8(%rbp)
  # param .LC3
	movq	$.LC3,	%rdi
  # call printStr 1
	call	printStr
  # a*b
	movl	-4(%rbp),	%eax
	imull	-8(%rbp),%eax
	movl	%eax,	-60(%rbp)
  # param t2
	movq	-60(%rbp),	%rdi
  # call printInt 1
	call	printInt
  # param .LC4
	movq	$.LC4,	%rdi
  # call printStr 1
	call	printStr
  # t3 = 0
	movl	$0,	-68(%rbp)
  # return t3
	movq	-68(%rbp),	%rax
	leave
	ret
  # function main end
	leave
	ret
	.size	main,	.-main
