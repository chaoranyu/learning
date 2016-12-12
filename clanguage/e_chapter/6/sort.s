	.file	"sort.c"
	.comm	lineptr,20000,32
	.section	.rodata
.LC0:
	.string	"error: input too big to sort"
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
	subl	$32, %esp
	movl	$5000, 4(%esp)
	movl	$lineptr, (%esp)
	call	readlines
	movl	%eax, 28(%esp)
	cmpl	$0, 28(%esp)
	js	.L2
	movl	28(%esp), %eax
	subl	$1, %eax
	movl	%eax, 8(%esp)
	movl	$0, 4(%esp)
	movl	$lineptr, (%esp)
	call	qsort
	movl	28(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$lineptr, (%esp)
	call	writelines
	movl	$0, %eax
	jmp	.L3
.L2:
	movl	$.LC0, (%esp)
	call	puts
	movl	$1, %eax
.L3:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.globl	readlines
	.type	readlines, @function
readlines:
.LFB1:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$1048, %esp
	movl	8(%ebp), %eax
	movl	%eax, -1036(%ebp)
	movl	%gs:20, %eax
	movl	%eax, -12(%ebp)
	xorl	%eax, %eax
	movl	$0, -1024(%ebp)
	jmp	.L5
.L9:
	movl	-1024(%ebp), %eax
	cmpl	12(%ebp), %eax
	jge	.L6
	movl	-1020(%ebp), %eax
	movl	%eax, (%esp)
	call	alloc
	movl	%eax, -1016(%ebp)
	cmpl	$0, -1016(%ebp)
	jne	.L7
.L6:
	movl	$-1, %eax
	jmp	.L10
.L7:
	movl	-1020(%ebp), %eax
	subl	$1, %eax
	movb	$0, -1012(%ebp,%eax)
	leal	-1012(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	-1016(%ebp), %eax
	movl	%eax, (%esp)
	call	strcpy
	movl	-1024(%ebp), %eax
	leal	1(%eax), %edx
	movl	%edx, -1024(%ebp)
	leal	0(,%eax,4), %edx
	movl	-1036(%ebp), %eax
	addl	%eax, %edx
	movl	-1016(%ebp), %eax
	movl	%eax, (%edx)
.L5:
	movl	$1000, 4(%esp)
	leal	-1012(%ebp), %eax
	movl	%eax, (%esp)
	call	getLine
	movl	%eax, -1020(%ebp)
	cmpl	$0, -1020(%ebp)
	jg	.L9
	movl	-1024(%ebp), %eax
.L10:
	movl	-12(%ebp), %ecx
	xorl	%gs:20, %ecx
	je	.L11
	call	__stack_chk_fail
.L11:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE1:
	.size	readlines, .-readlines
	.globl	writelines
	.type	writelines, @function
writelines:
.LFB2:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	$0, -12(%ebp)
	jmp	.L13
.L14:
	movl	-12(%ebp), %eax
	leal	0(,%eax,4), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movl	(%eax), %eax
	movl	%eax, (%esp)
	call	puts
	addl	$1, -12(%ebp)
.L13:
	movl	-12(%ebp), %eax
	cmpl	12(%ebp), %eax
	jl	.L14
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE2:
	.size	writelines, .-writelines
	.globl	getLine
	.type	getLine, @function
getLine:
.LFB3:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	$0, -12(%ebp)
	jmp	.L16
.L18:
	movl	-12(%ebp), %edx
	movl	8(%ebp), %eax
	addl	%eax, %edx
	movl	-16(%ebp), %eax
	movb	%al, (%edx)
	addl	$1, -12(%ebp)
.L16:
	movl	12(%ebp), %eax
	subl	$1, %eax
	cmpl	-12(%ebp), %eax
	jle	.L17
	call	getchar
	movl	%eax, -16(%ebp)
	cmpl	$-1, -16(%ebp)
	je	.L17
	cmpl	$10, -16(%ebp)
	jne	.L18
.L17:
	cmpl	$10, -16(%ebp)
	jne	.L19
	movl	-12(%ebp), %eax
	leal	1(%eax), %edx
	movl	%edx, -12(%ebp)
	movl	%eax, %edx
	movl	8(%ebp), %eax
	addl	%eax, %edx
	movl	-16(%ebp), %eax
	movb	%al, (%edx)
.L19:
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
.LFE3:
	.size	getLine, .-getLine
	.globl	qsort
	.type	qsort, @function
qsort:
.LFB4:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	12(%ebp), %eax
	cmpl	16(%ebp), %eax
	jl	.L22
	jmp	.L21
.L22:
	movl	16(%ebp), %eax
	movl	12(%ebp), %edx
	addl	%edx, %eax
	movl	%eax, %edx
	shrl	$31, %edx
	addl	%edx, %eax
	sarl	%eax
	movl	%eax, 8(%esp)
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	swap
	movl	12(%ebp), %eax
	movl	%eax, -12(%ebp)
	movl	12(%ebp), %eax
	addl	$1, %eax
	movl	%eax, -16(%ebp)
	jmp	.L24
.L26:
	movl	12(%ebp), %eax
	leal	0(,%eax,4), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movl	(%eax), %edx
	movl	-16(%ebp), %eax
	leal	0(,%eax,4), %ecx
	movl	8(%ebp), %eax
	addl	%ecx, %eax
	movl	(%eax), %eax
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	strcmp
	testl	%eax, %eax
	jns	.L25
	addl	$1, -12(%ebp)
	movl	-16(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	-12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	swap
.L25:
	addl	$1, -16(%ebp)
.L24:
	movl	-16(%ebp), %eax
	cmpl	16(%ebp), %eax
	jle	.L26
	movl	-12(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	swap
	movl	-12(%ebp), %eax
	subl	$1, %eax
	movl	%eax, 8(%esp)
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	qsort
	movl	-12(%ebp), %eax
	leal	1(%eax), %edx
	movl	16(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	%edx, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	qsort
.L21:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE4:
	.size	qsort, .-qsort
	.globl	swap
	.type	swap, @function
swap:
.LFB5:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$16, %esp
	movl	12(%ebp), %eax
	leal	0(,%eax,4), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movl	(%eax), %eax
	movl	%eax, -4(%ebp)
	movl	12(%ebp), %eax
	leal	0(,%eax,4), %edx
	movl	8(%ebp), %eax
	addl	%eax, %edx
	movl	16(%ebp), %eax
	leal	0(,%eax,4), %ecx
	movl	8(%ebp), %eax
	addl	%ecx, %eax
	movl	(%eax), %eax
	movl	%eax, (%edx)
	movl	16(%ebp), %eax
	leal	0(,%eax,4), %edx
	movl	8(%ebp), %eax
	addl	%eax, %edx
	movl	-4(%ebp), %eax
	movl	%eax, (%edx)
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE5:
	.size	swap, .-swap
	.local	allocbuf
	.comm	allocbuf,10000,32
	.data
	.align 4
	.type	allocp, @object
	.size	allocp, 4
allocp:
	.long	allocbuf
	.text
	.globl	alloc
	.type	alloc, @function
alloc:
.LFB6:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	$allocbuf+10000, %edx
	movl	allocp, %eax
	subl	%eax, %edx
	movl	%edx, %eax
	cmpl	8(%ebp), %eax
	jl	.L29
	movl	allocp, %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movl	%eax, allocp
	movl	allocp, %eax
	movl	8(%ebp), %edx
	negl	%edx
	addl	%edx, %eax
	jmp	.L30
.L29:
	movl	$0, %eax
.L30:
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE6:
	.size	alloc, .-alloc
	.globl	afree
	.type	afree, @function
afree:
.LFB7:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	cmpl	$allocbuf, 8(%ebp)
	jb	.L31
	cmpl	$allocbuf+10000, 8(%ebp)
	jae	.L31
	movl	8(%ebp), %eax
	movl	%eax, allocp
.L31:
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE7:
	.size	afree, .-afree
	.ident	"GCC: (Ubuntu 4.8.2-19ubuntu1) 4.8.2"
	.section	.note.GNU-stack,"",@progbits
