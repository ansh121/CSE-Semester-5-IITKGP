.data
msg_input: .asciiz "Enter two numbers (positive number): "
error: .asciiz "No is invalid\n"
ans: .asciiz "GCD is: "


.text
.globl main 
	main:
		la $a0, msg_input
		li $v0, 4
		syscall

		#input
		li $v0, 5
		syscall
		move $t0, $v0

		li $v0, 5
		syscall
		move $t1, $v0

		#validation
		bgt  $zero, $t0, error_msg
		bgt  $zero, $t1, error_msg

		#calculation

		beq $t0, $zero, case1

		Loop:
			#if t0>t1
			bgt $t0, $t1, sub1
			#else
			bge $t1, $t0, sub2


    func:
    	#end Function
    	la $a0, ans
		li $v0, 4
		syscall

		li $v0, 1
		move $a0, $t0
		syscall

		#exit
		li $v0, 10
        syscall

	sub1:
		#if t0>t1
		sub $t0, $t0, $t1
		beq  $t1, $zero, func
		j Loop

	sub2:
		#else
		sub $t1, $t1, $t0
		beq  $t1, $zero, func
		j Loop

    case1:
    	#base case if(t0==0)
    	la $a0, ans
		li $v0, 4
		syscall

		li $v0, 1
		move $a0, $t1
		syscall

		li $v0, 10
        syscall

    error_msg:
    	#if -ve numbers are given
     	la $a0, error
     	li $v0 ,4
     	syscall

        li $v0, 10
        syscall
