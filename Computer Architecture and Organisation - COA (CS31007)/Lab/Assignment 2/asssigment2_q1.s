.data
msg_input1: .asciiz "Enter 8 numbers (ascending order ): "
error1: .asciiz "Numbers not in ascending order\n"
msg_input2: .asciiz "Enter number to search : "
error2: .asciiz "Number not found!\n"
found: .asciiz "Number found at index: "
.align 2
myarray: .space 32

.text
.globl main 
	main:
		#input
		la $a0, msg_input1
		li $v0, 4
		syscall

		li $t1,1
		la $t3, myarray

		Input_Loop:

	        li $v0, 5 #read in user input
	        syscall

	        move $t0, $v0
	        #beq  $t0, -31, endloop

	        addi $t1, $t1, 1

	        sw $t0,($t3)
	        addi $t3,$t3,4

	        bne  $t1,9,Input_Loop #get user input up to 20 times 

	    li $t1,1
		la $t2, myarray
		add $t3, $t2, 4

	    checkloop:
	        lw $t4, 0($t2)
	        lw $t5, 0($t3)

	        #li $v0, 1
	        #move $a0, $t4
			#syscall

	        bgt $t4, $t5, error

	        addi $t1, $t1, 1
	        add $t2, $t2, 4
	        add $t3, $t3, 4

	        bne  $t1,8,checkloop #get user input up to 20 times

	    la $a0, msg_input2
		li $v0, 4
		syscall

		li $v0, 5
		syscall
		move $t7, $v0

	    la $s0, myarray
	    add $t0, $zero, $zero
	    addi $t1, $t0, 7

	    Binary_Search:
	    	bgt $t0, $t1, Not_found

	    	#li $v0, 1
	        #move $a0, $t0
			#syscall

	    	add $t2, $t1, $t0
	    	srl $t2, $t2, 1

	    	sll $t5, $t2, 2
	    	add $t5, $t5, $s0

	    	lw $t4, ($t5)

	    	beq $t4, $t7, equal
	    	bgt $t4, $t7, shiftleft
	    	bgt $t7, $t4, shiftright

	    li $v0, 10
	    syscall

	    Not_found:
	    	la $a0, error2
			li $v0, 4
			syscall

			j exit

	   	shiftleft:
	   		addi $t1, $t2, -1
	   		j Binary_Search

	   	shiftright:
	   		addi $t0, $t2, 1
	   		j Binary_Search

	   	equal:
	   		la $a0, found
			li $v0, 4
			syscall

			addi $t2, $t2, 1
			li $v0, 1
	        move $a0, $t2
			syscall

			j exit

	    exit:
	    	li $v0, 10
	        syscall

	    error:
	    	la $a0, error1
			li $v0, 4
			syscall

			j exit
