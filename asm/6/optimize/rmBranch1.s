.section .text
.globl _start
_start:
	
loop:
	cmp data(, %edi, 4), %eax
	je part2
	call function1
	jmp looptest
part2:
	call function2
looptest:
	inc %edi
	cmpl $10, %edi
	jnz loop
