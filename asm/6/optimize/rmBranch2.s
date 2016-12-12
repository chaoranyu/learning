.section .text
.globl _start
_start:
	
loop:
	cmp data(, %edi, 4), %eax
	je part2
	call function1
	inc %edi
	cmpl $10, %edi
	jnz loop
	jmp end
part2:
	call function2
	inc %edi
	cmpl $10, %edi
	jnz loop
end:
