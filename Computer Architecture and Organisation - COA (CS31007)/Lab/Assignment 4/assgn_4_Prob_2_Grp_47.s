#Assignment No: 4
#Problem No: 2
#Semester: Autumn 2019
#Group No: 47
#Name: Anshul Choudhary (17CS10005)
#Name: Ayush Kumar (17CS10007)


#We are finding saddle point by finding maximum of each row and comapring it with minimum of each columns
#and minimum of each row and comparing it with maximum of each column

.data
msg_input1: .asciiz "Enter 4 x 4 matrix (positive numbers) : \n"
msg_input2: .asciiz "Saddle points are : "
error: .asciiz "No saddle points.\n"
white: .asciiz " "
.align 2
twoDarray: .space 64
row: .space 16
rowmin: .space 16
column: .space 16
colmin: .space 16

.text
.globl main 
	main:
		#input
		la $a0, msg_input1
		li $v0, 4
		syscall

		li $t1,1  				#initializing $t1(i) to 1
		la $t3, twoDarray			#loading address of array in $t3

		Input_Loop: 			#Loop to take input from the user

	        li $v0, 5 			#read in user input
	        syscall

	        move $t0, $v0 		#moving input value to $t0

	        addi $t1, $t1, 1 	#increasing $t1(i) by 1

	        sw $t0,($t3) 		#storing entered value at array[i]
	        addi $t3,$t3,4 		#increasing address of $t3 to access next address

	        bne  $t1,17,Input_Loop #get user input up to 8 times

	    la $a0, twoDarray
	    li $t0, 0
	    la $a1, row
	    li $t4, -1
	    sw $t4, ($a1)
	    li $t2, 0
	    lw $a2, ($a0)

	    li $t5, 4


	    #Finding maximum of each row
	    rowmaxloop:
	    	beq $t0, 16, assign1 	#check for the end of araay if true go for finding row minimums
	    	lw $t3, ($a0)			#load current value 

	    	bgt $t3, $a2, update 	#check if current is greater than maximum	
	    	beq $t3, $a2, inccount 	#check if cuurent is equal to maximum(Not unique)

	    	addi $t0, $t0, 1 		#increase count
	    	addi $a0, $a0, 4		#go to next address

	    	div $t0, $t5 			#check if t0 is divisible by 4
	    	mfhi $t6 				#store remainder in $t6
	    	beq $t6, $zero, update2 	#if remainder is 0 update value in row(Storing maximum value)
	    	j rowmaxloop 			#check for another row

	    	inccount:				#if current value is equal to maximum increase count 
	    		addi $t2, $t2, 1 	#increase count
	    		addi $t0, $t0, 1 	#increase loop count
	    		addi $a0, $a0, 4	#go to next value in array

	    		div $t0, $t5      	#check if t0 is divisible by 4
	    		mfhi $t6			#store remainder in $t6
	    		beq $t6, 0, update2 	#if remainder is 0 update value in row(Storing maximum value)
	    		j rowmaxloop 		#check for another row


	    	update2: 				#update value in row(Storing maximum)
	    		beq $t2, 1, store 	#if unique then store
	    		lw $a2, ($a0) 		#else load next value
	    		li $t2, 0 			#make count to 0
	    		addi $a1, $a1, 4 	#increse a1(row storinf maximum)
	    		li $t4, -1 			#initialise t4 as 1
	    		sw $t4, ($a1) 		#value at a1 = -1

	    		j rowmaxloop 		#start loop again for next row

	    	store:
	    		sw $a2, ($a1) 		#store value in a1
	    		lw $a2, ($a0) 		#load next value
	    		li $t2, 0			#make count to 0
	    		addi $a1, $a1, 4 	#increse a1(row storinf maximum)
	    		li $t4, -1 			#initialise t4 as 1
	    		sw $t4, ($a1) 		#value at a1 = -1
 
	    		j rowmaxloop 		#start loop again for next row

	    	update: 				#update current maximum
	    		move $a2, $t3 		#$a2 = $t3(current value)
	    		li $t2, 1 			#make count to 1

	    		addi $t0, $t0, 1 	#incrase loop count
	    		addi $a0, $a0, 4 	#go to next address

	    		div $t0, $t5 		#check if t0(loop count) is divisible by 4
	    		mfhi $t6 			#store remainder in $t6
	    		beq $t6, 0, update2 	#if remainder is 0 update value in row(Storing maximum value)
	    		j rowmaxloop 		#check for another row



	    #Finding Minimum of each row      #Everything is same except for the value comapring condition
	    assign1:
	    la $a0, twoDarray 
	    li $t0, 0
	    la $a1, rowmin
	    li $t4, -1
	    sw $t4, ($a1)
	    li $t2, 0
	    lw $a2, ($a0)

	    li $t5, 4

	    rowminloop:
	    	beq $t0, 16, assign2 		#check if last array value is checked if true go for finding column maximum
	    	lw $t3, ($a0)

	    	bgt $a2, $t3, update1
	    	beq $t3, $a2, inccount1

	    	addi $t0, $t0, 1
	    	addi $a0, $a0, 4

	    	div $t0, $t5
	    	mfhi $t6
	    	beq $t6, $zero, update21
	    	j rowminloop

	    	inccount1:
	    		addi $t2, $t2, 1
	    		addi $t0, $t0, 1
	    		addi $a0, $a0, 4

	    		div $t0, $t5
	    		mfhi $t6
	    		beq $t6, 0, update21 
	    		j rowminloop


	    	update21:
	    		beq $t2, 1, store1
	    		lw $a2, ($a0)
	    		li $t2, 0
	    		addi $a1, $a1, 4
	    		li $t4, -1
	    		sw $t4, ($a1)

	    		j rowminloop

	    	store1:
	    		sw $a2, ($a1)
	    		lw $a2, ($a0)
	    		li $t2, 0
	    		addi $a1, $a1, 4
	    		li $t4, -1
	    		sw $t4, ($a1)

	    		j rowminloop

	    	update1:
	    		move $a2, $t3
	    		li $t2, 1

	    		addi $t0, $t0, 1
	    		addi $a0, $a0, 4

	    		div $t0, $t5
	    		mfhi $t6
	    		beq $t6, 0, update21
	    		j rowminloop




	    #Finding maximum of each column 		#Everything is same except for checking the values columnwise.
	    assign2:
	    	la $a0, twoDarray
		    li $t0, 0
		    la $a1, column
		    li $t4, -1
		    li $t2, 0
		    lw $a2, ($a0)
	    	li $t5, 0

	    columnmax:
	    	beq $t0,4,assign3 		 # if all 4 columns are checked go for finding column minimums
	    	li $t2, 0
	    	lw $a2, ($a0)
	    	li $t5,0
	    	sw $t4, ($a1)
	    	move $a3,$a0 
	    compare:
	    	beq $t5,4,update211
	    	lw $t3,($a3)
	    	bgt $t3, $a2, update11
	    	beq $t3, $a2, inccount11
	    	addi $t5,$t5,1
	    	addi $a3,$a3,16
	    	j compare

	    update11:
	    	move $a2, $t3
	    	li $t2,1
	    	addi $t5,$t5,1
	    	addi $a3,$a3,16
	    	j compare

	    inccount11:
	    	addi $t2,$t2,1
	    	addi $t5,$t5,1
	    	addi $a3,$a3,16
	    	j compare
	    update211:
	    	beq $t2,1,store11
	    	addi $t0,$t0,1
	    	addi $a0,$a0,4
	    	addi $a1,$a1,4
	    	j columnmax

	    store11:
	    	sw $a2,($a1)
	    	addi $t0,$t0,1
	    	addi $a0,$a0,4
	    	addi $a1,$a1,4
	    	j columnmax



	    #finding minimum of each column 				#Everything is same except value comparing conditions
	    assign3:
	    	la $a0, twoDarray
		    li $t0, 0
		    la $a1, colmin
		    li $t4, -1
		    li $t2, 0
		    lw $a2, ($a0)
	    	li $t5, 0

	    columnmin:
	    	beq $t0,4,compare1
	    	li $t2, 0
	    	lw $a2, ($a0)
	    	li $t5,0
	    	sw $t4, ($a1)
	    	move $a3,$a0 
	    compare_c_min:
	    	beq $t5,4,update2_c_min
	    	lw $t3,($a3)
	    	bgt $a2, $t3, update_c_min
	    	beq $t3, $a2, inccount_c_min
	    	addi $t5,$t5,1
	    	addi $a3,$a3,16
	    	j compare_c_min

	    update_c_min:
	    	move $a2, $t3
	    	li $t2,1
	    	addi $t5,$t5,1
	    	addi $a3,$a3,16
	    	j compare_c_min

	    inccount_c_min:
	    	addi $t2,$t2,1
	    	addi $t5,$t5,1
	    	addi $a3,$a3,16
	    	j compare_c_min
	    update2_c_min:
	    	beq $t2,1,store_c_min
	    	addi $t0,$t0,1
	    	addi $a0,$a0,4
	    	addi $a1,$a1,4
	    	j columnmin

	    store_c_min:
	    	sw $a2,($a1)
	    	addi $t0,$t0,1
	    	addi $a0,$a0,4
	    	addi $a1,$a1,4
	    	j columnmin



	    #compare each row and each column

	    compare1:							#compare each element of row maximum to every column minimum
	    	la $a0, msg_input2				#output message
			li $v0, 4
			syscall

		    li $t6, 0						#flag to check if any saddle point is present, if not print error

	    	li $t0, 0						#loop1 counter
	    	la $a0, row 					#address of first element rowmax array
	    	la $a1, colmin 					#address of first element colmin array

	    	loop1:							#outer loop
	    		beq $t0, 4, compare2 		#loop end condition
	    		lw $t2, ($a0) 				#load current value of row element
	    		move $a2, $a1 				#load address of colmin array
	    		li $t1, 0					#loop2 counter
	    		
	    		loop2:						#inner loop
	    			lw $t3, ($a2)			#load first value of colmin elememt
	    			beq $t3, $t2, printans 	#if values are equal, print it
	    			addi $t1, $t1, 1 		#increase loop2 counter
	    			addi $a2, $a2, 4		#move to next element address of colmin
	    			bne $t1, 4, loop2		#loop end condition

	    		addi $t0, $t0, 1			#increase loop1 counter
	    		addi $a0, $a0, 4			#move to next element address of row
	    		j loop1						#back to outerloop

	    	printans:						#print ans if found
	    		beq $t3, -1, sp_case 		#if element value is -1 then either its not max in row or min in column
	    		li $t6, 1					#flal=1 to check there is atleast one saddle point, o.w. error
	    		move $t5, $a0				#save current address of $a0
	    		move $a0, $t3				#print saddle point
				li $v0, 1 					 
				syscall
				la $a0, white 				#print while space
				li $v0, 4
				syscall
				move $a0, $t5 				#restore $a0

			sp_case:

				addi $t1, $t1, 1 			#increase loop2 counter
    			addi $a2, $a2, 4	 		#move to next element address
    			bne $t1, 4, loop2			#if loop2 not ended go to loop 2

    			addi $t0, $t0, 1			#increase loop1 counter
	    		addi $a0, $a0, 4			#move to the next element address of row
    			j loop1 					#back to loop 1


    	compare2:							#exactly same as compare 1. Only row is now rowmin and colmin is now column
	    	li $t0, 0
	    	la $a0, rowmin
	    	la $a1, column

	    	loop3:
	    		beq $t0, 4, check2
	    		lw $t2, ($a0)
	    		move $a2, $a1
	    		li $t1, 0
	    		
	    		loop4:
	    			lw $t3, ($a2)
	    			beq $t3, $t2, printans2
	    			addi $t1, $t1, 1
	    			addi $a2, $a2, 4
	    			bne $t1, 4, loop4

	    		addi $t0, $t0, 1
	    		addi $a0, $a0, 4
	    		j loop3

	    	printans2:
	    		beq $t3, -1, sp_case2
	    		li $t6, 1
	    		move $t5, $a0
	    		move $a0, $t3
				li $v0, 1 				
				syscall
				la $a0, white
				li $v0, 4
				syscall
				move $a0, $t5

			sp_case2:

				addi $t1, $t1, 1
    			addi $a2, $a2, 4
    			bne $t1, 4, loop4

    			addi $t0, $t0, 1
	    		addi $a0, $a0, 4
    			j loop3




		  	check2:						#condition to check if saddle points were there of not, if not print error
		   		beq $t6, 1, exit		#if present, exit
			   	la $a0, error 			#else print error
				li $v0, 4
				syscall

			exit: 						#exit call
	    		li $v0, 10
	    		syscall
