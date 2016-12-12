#swaptest.s - An example of using BSWAP instruction
.section .text
.global _start
_start:
	movl $0x12345678, %ebx
	bswap %ebx
	movl $1, %eax
	movl $0, %ebx
	int $0x80
