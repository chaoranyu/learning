;----------------------------------------------------------
;版权信息：
;作者信息：
;编制日期：
;程序功能：
;
;
;使用方法：
;
;入口信息：
;
;出口信息：
;
;版本信息：
;----------------------------------------------------------
;修改信息：（对应版本，修改日期，修改者，修改原因，修改位置）
;-----------------------------------------------------------
assume cs:code,ds:data

data segment
	a db 1,2,3,4,5,6,7,8
	b dw 0
	c dw a,b
data ends

code	segment 'code'			;定义代码段
start:	nop
screen:	jmp short set
	table dw sub1,sub2
;	table dw sub1-offset screen,sub2-offset screen
;	table dw sub1-screen,sub2-screen

set:	mov ax,1
sub1:	mov ax,2
sub2:	mov ax,3

	mov ax,4c00h
	int 21h				;利用功能调用返回DOS

s:	nop
s1:	mov dx,10h
	dw 234h
	ret

code	ends				;代码段结束
	end start
					;汇编结束，同时指明程序起始点
