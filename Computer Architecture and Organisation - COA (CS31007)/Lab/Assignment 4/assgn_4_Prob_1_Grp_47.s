#Assignment No: 4
#Problem No: 1
#Semester: Autumn 2019
#Group No: 47
#Name: Anshul Choudhary (17CS10005)
#Name: Ayush Kumar (17CS10007)

.data
msg_input1: .asciiz "Enter 8 numbers "
sorted_arr: .asciiz "Array in descending order is: "
white: .asciiz " "
.align 2
array: .space 32

.text
.globl main 
	main:
		#input
		la $a0, msg_input1
		li $v0, 4
		syscall

		li $t1,1  				#initializing $t1(i) to 1
		la $t3, array			#loading address of array in $t3

		Input_Loop: 			#Loop to take input from the user

	        li $v0, 5 			#read in user input
	        syscall

	        move $t0, $v0 		#moving input value to $t0

	        addi $t1, $t1, 1 	#increasing $t1(i) by 1

	        sw $t0,($t3) 		#storing entered value at array[i]
	        addi $t3,$t3,4 		#increasing address of $t3 to access next address

	        bne  $t1,9,Input_Loop #get user input up to 8 times

	    li $a0, 8 				#set count arg (length of array)
		la $a1, array 		#load address of array in $a1 
		li $t0, 0
		jal InsertionSort

		printloop: 				#printing sorted array loop
			la $a1, array 		#load address of array in $a1 
			li $t0, 0
			move $t0, $a0		#$t0 = $a0
			la $a0, sorted_arr 	##load address of array in $a0 
			li $v0, 4
			syscall

		ploop: 
			ble $t0, $zero, exit 	#Check if loop has run 8 times 
			lw $a0, ($a1)
			li $v0, 1 				# get word at current address 
			syscall         		# print word

			addi $a1, $a1, 4 		#increment current word address by 4 
			sub  $t0, $t0, 1    	#decrease value of $t0

			la $a0, white      		#print white space
			li $v0, 4
			syscall 				#print 
			j ploop 					#jump to loop

		InsertionSort:				
			beq $t0, $a0, printloop 	#Check if loop has run 8 times
			move $t1, $t0 				#$t1=$t0
			move $t2, $a1				#assigning current address to $t2
			move $t3, $a1
			jal loop


		loop: 			
			beq $t1, $a0, swapPos 		#if inner loop has reached last position

			lw $t5, ($t2) 				#load current max
			lw $t6, ($t3) 				#load current value

			bgt $t5, $t6 , store 		#if t5 > t6 store

			addi $t2, $t2, 4 			#increase t2
			addi $t1, $t1, 1 			#increase inner loop
			j loop

		store:
			move $t3, $t2 				#store address of numbers to be exchanged
			
			addi $t2, $t2, 4 			#increase t2
			addi $t1, $t1, 1 			#increase innerloop
			j loop
							

		swapPos: 
			lw  $t5, ($a1) 			# $t5 = ($a1)
			lw  $t6, ($t3)			# $t6 = ($t3) 
			sw  $t6, ($a1) 				# ($a1) = $t6
			sw  $t5, ($t3) 				# ($t3) = $t5
			addi $t0, $t0, 1			#increase outer loop
			addi $a1, $a1, 4			#increase a1 by 4
			j InsertionSort


		exit: 
			li $v0, 10  			# exit code
			syscall 