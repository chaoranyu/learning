#jumptest.s - An example of the jmp instructions
.section .text
.global _start
_start:
	mov $1, %eax
	jmp overthere
	mov $10, %ebx
	int $0x80
overthere:
	mov $20, %ebx
	int $0x80
