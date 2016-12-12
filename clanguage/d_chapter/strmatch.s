	.file	"strmatch.c"
	.globl	pattern
	.data
	.type	pattern, @object
	.size	pattern, 5
pattern:
	.string	"ould"
	.section	.rodata
.LC0:
	.string	"%s"
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
	subl	$1024, %esp
	movl	%gs:20, %eax
	movl	%eax, 1020(%esp)
	xorl	%eax, %eax
	movl	$0, 16(%esp)
	jmp	.L2
.L3:
	movl	$pattern, 4(%esp)
	leal	20(%esp), %eax
	movl	%eax, (%esp)
	call	strindex
	testl	%eax, %eax
	js	.L2
	leal	20(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$.LC0, (%esp)
	call	printf
	addl	$1, 16(%esp)
.L2:
	movl	$1000, 4(%esp)
	leal	20(%esp), %eax
	movl	%eax, (%esp)
	call	getline2
	testl	%eax, %eax
	jg	.L3
	movl	16(%esp), %eax
	movl	1020(%esp), %edx
	xorl	%gs:20, %edx
	je	.L5
	call	__stack_chk_fail
.L5:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.globl	getline2
	.type	getline2, @function
getline2:
.LFB1:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	$0, -12(%ebp)
	jmp	.L7
.L9:
	movl	-12(%ebp), %eax
	leal	1(%eax), %edx
	movl	%edx, -12(%ebp)
	movl	%eax, %edx
	movl	8(%ebp), %eax
	addl	%eax, %edx
	movl	-16(%ebp), %eax
	movb	%al, (%edx)
.L7:
	subl	$1, 12(%ebp)
	cmpl	$0, 12(%ebp)
	jle	.L8
	call	getchar
	movl	%eax, -16(%ebp)
	cmpl	$-1, -16(%ebp)
	je	.L8
	cmpl	$10, -16(%ebp)
	jne	.L9
.L8:
	cmpl	$10, -16(%ebp)
	jne	.L10
	movl	-12(%ebp), %eax
	leal	1(%eax), %edx
	movl	%edx, -12(%ebp)
	movl	%eax, %edx
	movl	8(%ebp), %eax
	addl	%eax, %edx
	movl	-16(%ebp), %eax
	movb	%al, (%edx)
.L10:
	movl	-12(%ebp), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movb	$0, (%eax)
	movl	-12(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE1:
	.size	getline2, .-getline2
	.globl	strindex
	.type	strindex, @function
strindex:
.LFB2:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$16, %esp
	movl	$0, -12(%ebp)
	jmp	.L13
.L19:
	movl	-12(%ebp), %eax
	movl	%eax, -8(%ebp)
	movl	$0, -4(%ebp)
	jmp	.L14
.L16:
	addl	$1, -8(%ebp)
	addl	$1, -4(%ebp)
.L14:
	movl	-4(%ebp), %edx
	movl	12(%ebp), %eax
	addl	%edx, %eax
	movzbl	(%eax), %eax
	testb	%al, %al
	je	.L15
	movl	-8(%ebp), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movzbl	(%eax), %edx
	movl	-4(%ebp), %ecx
	movl	12(%ebp), %eax
	addl	%ecx, %eax
	movzbl	(%eax), %eax
	cmpb	%al, %dl
	je	.L16
.L15:
	cmpl	$0, -4(%ebp)
	jle	.L17
	movl	-4(%ebp), %edx
	movl	12(%ebp), %eax
	addl	%edx, %eax
	movzbl	(%eax), %eax
	testb	%al, %al
	jne	.L17
	movl	-12(%ebp), %eax
	jmp	.L18
.L17:
	addl	$1, -12(%ebp)
.L13:
	movl	-12(%ebp), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movzbl	(%eax), %eax
	testb	%al, %al
	jne	.L19
	movl	$-1, %eax
.L18:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE2:
	.size	strindex, .-strindex
	.ident	"GCC: (Ubuntu 4.8.2-19ubuntu1) 4.8.2"
	.section	.note.GNU-stack,"",@progbits
