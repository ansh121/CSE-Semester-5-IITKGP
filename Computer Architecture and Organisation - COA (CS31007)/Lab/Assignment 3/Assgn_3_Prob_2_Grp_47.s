#Assignment No: 3
#Problem No: 2
#Semester: Autumn 2019
#Group No: 47
#Name: Anshul Choudhary (17CS10005)
#Name: Ayush Kumar (17CS10007)

.data
msg_input1: .asciiz "Entre starting address: "
msg_input2: .asciiz "Enter size of array : "
msg_input3: .asciiz "Enter window size : "
msg_input4: .asciiz "Enter values of the array : \n"
msg_input5: .asciiz "Window averages are : "
msg_input6: .asciiz " "

.align 2
myarray: .space 100

.text
.globl main 
	main: 

		#input size of array
		la $a0, msg_input2
		li $v0, 4
		syscall

		li $v0, 5
		syscall
		move $t1, $v0		# $t1 contain size of the array

		#enter window size
		la $a0, msg_input3
		li $v0, 4
		syscall

		li $v0, 5
		syscall
		move $t2, $v0		# $t2 contain value of window size

		#enter values of array
		la $a0, msg_input4
		li $v0, 4
		syscall

		la $s0, myarray
		move $t3, $s0

		li $t4, 0
		jal Loop  			#Moving to take the values in array

		#Loop2				#Loop to add first w elements 
		move $t3, $s0
		move $t5, $s0

		li $t4, 0
		li $t6, 0
		jal Loop2

		#Loop3				#Loop to calculate window averages
		addi $t4, $t4, -1
		jal Loop3

		#printing Loop  	#loop to print averages
		la $a0, msg_input5
		li $v0, 4
		syscall

		sub $t1, $t1, $t2
		li $t4, 0
		move $t3, $s0
		jal Loop4

		#Exit
		li $v0, 10
	    syscall

		Loop: 				#loop to take the value of array and to store in myarray
			addi $t4, $t4, 1

			li $v0, 5
			syscall
			sw $v0, ($t3)

			addi $t3, $t3, 4

			bgt $t1, $t4, Loop

			jr $ra

		Loop2: 				#Loop to add first w elements
			addi $t4, $t4, 1

			lw $t7, ($t3)
			add $t6, $t6, $t7

			addi $t3, $t3, 4

			bgt $t2, $t4, Loop2

			jr $ra

		Loop3: 				#Loop to calculate window averages
			addi $t4, $t4, 1

			lw $t7, ($t5)
			div $t6, $t2

			mflo $s1
			sw $s1, ($t5)

			sub $t6, $t6, $t7

			lw $t7, ($t3)
			addi $t3, $t3, 4

			add $t6, $t6, $t7
			addi $t5, $t5, 4

			bgt $t1, $t4, Loop3

			jr $ra

		Loop4:				#loop to print averages
			addi $t4, $t4, 1

			lw $a0, ($t3)
			li $v0, 1
			syscall

			la $a0, msg_input6
			li $v0, 4
			syscall

			addi $t3, $t3, 4

			bge $t1, $t4, Loop4

			jr $ra

		exit:
			li $v0, 10
	    	syscall

