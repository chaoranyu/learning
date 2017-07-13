	.file	"const-test.c"
	.globl	a
	.data
	.align 4
	.type	a, @object
	.size	a, 4
a:
	.long	3
	.section	.rodata
.LC0:
	.string	"hello, world"
.LC1:
	.string	"a: %p\nb: %p\nc: %p\ns: %p\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	$9, -4(%rbp)
	movq	$.LC0, -16(%rbp)
	movq	-16(%rbp), %rax
	movq	%rax, %rcx
	movl	$b.2179, %edx
	movl	$a, %esi
	movl	$.LC1, %edi
	movl	$0, %eax
	call	printf
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.data
	.align 4
	.type	b.2179, @object
	.size	b.2179, 4
b.2179:
	.long	6
	.ident	"GCC: (GNU) 4.8.5 20150623 (Red Hat 4.8.5-11)"
	.section	.note.GNU-stack,"",@progbits
