#calltest.s - An example of using the CALL isntruction
.section .data
output:
	.asciz "This is section %d\n"
.section .text
.global _start
_start:
	pushl $1
	pushl $output
	call printf
	add $8, %esp		# should clear up stack
	call overhere
	pushl $3
	pushl $output
	call printf
	add $8, %esp		# should clear up stack
	pushl $0
	call exit
overhere:
	pushl %ebp
	movl %esp, %ebp
	pushl $2
	pushl $output
	call printf
	add $8, %esp		# should clear up stack
	movl %ebp, %esp
	popl %ebp
	ret
