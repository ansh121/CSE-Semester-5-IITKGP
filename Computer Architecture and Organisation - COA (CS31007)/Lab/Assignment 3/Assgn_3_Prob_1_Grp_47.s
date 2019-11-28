#Assignment No: 3
#Problem No: 1
#Semester: Autumn 2019
#Group No: 47
#Name: Anshul Choudhary (17CS10005)
#Name: Ayush Kumar (17CS10007)

.data
string: .asciiz "Enter string 123JHGFED"
msg1: .asciiz "Converted string is : "
msg2: .asciiz "\n"
msg3: .asciiz "Entered string is : "

.align 2                

.text
.globl main 
	main:
		la $s0, string 		#moving address of string to $s0
		move $t1, $s0		#coping $s0 to $t1 so as to modify the value of address

		#Printing initial string
		la $a0, msg3
		li $v0, 4
		syscall

		la $a0, string
		li $v0, 4
		syscall

		la $a0, msg2
		li $v0, 4
		syscall

		#Loop to modify string
		j Loop1

	Loop1:
		lb $t2, ($t1) 		#loading current byte to $t2

		beq $t2, 0, exit 	#if $t2 is end of string jump to exit to print the string

		bge $t2,'A', if1	#check if $t2 is >= 'A' ; if true, jump to if1 to check further conditions

		addi $t1, $t1, 1 	#move to next byte

		j Loop1				#continue loop

	if1:
		blt $t2, 'Z', if2 	#check if $t2 is <= 'Z'; if true, jump to if2 to change its value

		addi $t1, $t1, 1	#move to next byte
		j Loop1				#continue loop

	if2:
		addi $t2, $t2, 32 	#converting uppercase to lowercase
		sb $t2, ($t1) 		#modify current byte in string

		addi $t1, $t1, 1 	#move to next byte
		j Loop1				#continue loop

	exit:
		la $a0, msg1		#print modified string and exit
		li $v0, 4
		syscall

		la $a0, string
		li $v0, 4
		syscall

		li $v0, 10
    	syscall