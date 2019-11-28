.data
msg_input: .asciiz "Enter the argument (positive number): "
error: .asciiz "No is invalid\n"
ans: .asciiz "Febonacci Number is: "


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

		#validation
		bge  $zero, $t0, error_msg

		#variable initialisation
		move $t1, $t0
		sub $t1, $t1, 2

		li $t2, 1
		li $t3, 1
		li $t4, 1

		bge $zero, $t1, basecase

		Loop:						#fibonacci function loop
			add $t4, $t2, $t3
			move $t2, $t3
			move $t3, $t4
			sub $t1, $t1, 1

			bgt  $t1, $zero, Loop

		la $a0, ans
		li $v0, 4
		syscall

		li $v0, 1
		move $a0, $t4
		syscall

		li $v0, 10
        syscall

    basecase:
    	la $a0, ans
		li $v0, 4
		syscall

		li $v0, 1
		move $a0, $t4
		syscall

		li $v0, 10
        syscall

    error_msg:
     	la $a0, error
     	li $v0 ,4
     	syscall

        li $v0, 10
        syscall

    Exit:
        li $v0, 10
        syscall