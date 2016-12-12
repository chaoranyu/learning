#inttest.s - An example of using signed integers
.section .data
data:
	.int -45
.section .text
.global _start
_start:
	movl $-345, %ecx
	mov $-1, %ax
	movzx %ax, %edx
	movl data, %ebx
	movl $1, %eax
	int $0x80
