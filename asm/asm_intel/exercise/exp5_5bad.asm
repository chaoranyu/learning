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
assume cs:code

a	segment				;定义数据段
	db 1,2,3,4,5,6,7,8
a	ends

b	segment				;定义数据段
	db 1,2,3,4,5,6,7,8
b	ends

c	segment				;定义堆栈段
	db 0,0,0,0,0,0,0,0				;堆栈段有16字（32字节）空间
c	ends				;堆栈段结束

code	segment				;定义代码段

start:	mov ax,c			;建立SS段地址
	mov ss,ax
	mov sp,28h

	mov ax,a			;建立DS段地址
	mov ds,ax

	mov ax,b
	mov es,ax

	mov cx,8
s:	mov bx,cx
	sub bx,1
	mov al,[bx]
	add al,es:[bx]
	push al
	loop s
	
	mov ax,4c00h
	int 21h				;利用功能调用返回DOS

code	ends				;代码段结束
end start
					;汇编结束，同时指明程序起始点
