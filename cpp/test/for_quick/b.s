	.file	"b.cpp"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$48, %esp
	movl	$10, %eax
	movl	%eax, -44(%ebp)
	movl	$0, -48(%ebp)
	jmp	.L2
.L3:
	addl	$1, -48(%ebp)
.L2:
	movl	-48(%ebp), %eax
	cmpl	-44(%ebp), %eax
	jl	.L3
	movl	$0, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 4.8.2-19ubuntu1) 4.8.2"
	.section	.note.GNU-stack,"",@progbits
