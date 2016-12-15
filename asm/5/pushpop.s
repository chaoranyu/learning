#pushpop.s - An example of using the PUSH and POP instructions
.section .data
data:
	.int 125

.section .text
.global _start
_start:
	movl $24420, %ecx
	movw $350, %bx
	movl $100, %eax  #not movb
	pushl %ecx
	pushw %bx
	pushl %eax
	pushl data
	pushl $data

	popl %eax
	popl %eax
	popl %eax
	popw %ax
	popl %eax
	movl $0, %eax
	movl $1, %ebx
	int $0x80
