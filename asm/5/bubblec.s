	.file	"bubblec.c"
	.section	.rodata
.LC0:
	.string	"%d\t"
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
	andl	$-16, %esp
	subl	$80, %esp
	movl	$105, 40(%esp)
	movl	$235, 44(%esp)
	movl	$61, 48(%esp)
	movl	$315, 52(%esp)
	movl	$134, 56(%esp)
	movl	$221, 60(%esp)
	movl	$53, 64(%esp)
	movl	$145, 68(%esp)
	movl	$117, 72(%esp)
	movl	$5, 76(%esp)
	movl	$9, 24(%esp)
	jmp	.L2
.L6:
	movl	$0, 28(%esp)
	jmp	.L3
.L5:
	movl	28(%esp), %eax
	movl	40(%esp,%eax,4), %edx
	movl	28(%esp), %eax
	addl	$1, %eax
	movl	40(%esp,%eax,4), %eax
	cmpl	%eax, %edx
	jle	.L4
	movl	28(%esp), %eax
	movl	40(%esp,%eax,4), %eax
	movl	%eax, 36(%esp)
	movl	28(%esp), %eax
	addl	$1, %eax
	movl	40(%esp,%eax,4), %edx
	movl	28(%esp), %eax
	movl	%edx, 40(%esp,%eax,4)
	movl	28(%esp), %eax
	leal	1(%eax), %edx
	movl	36(%esp), %eax
	movl	%eax, 40(%esp,%edx,4)
.L4:
	addl	$1, 28(%esp)
.L3:
	movl	28(%esp), %eax
	cmpl	24(%esp), %eax
	jl	.L5
	subl	$1, 24(%esp)
.L2:
	cmpl	$0, 24(%esp)
	jg	.L6
	movl	$0, 32(%esp)
	jmp	.L7
.L8:
	movl	32(%esp), %eax
	movl	40(%esp,%eax,4), %eax
	movl	%eax, 4(%esp)
	movl	$.LC0, (%esp)
	call	printf
	addl	$1, 32(%esp)
.L7:
	cmpl	$9, 32(%esp)
	jle	.L8
	movl	$10, (%esp)
	call	putchar
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 4.8.2-19ubuntu1) 4.8.2"
	.section	.note.GNU-stack,"",@progbits
