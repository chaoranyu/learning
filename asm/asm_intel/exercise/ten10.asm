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
assume cs:codesg

data segment
	dw 1,2,3,4,5,6,7,8
	dd 0,0,0,0,0,0,0,0
data ends

codesg	segment				;定义代码段

start:	mov ax,data
	mov ds,ax
	mov si,0			;ds:si指向第一组word单元
	mov di,16			;ds:di指向第二组dword单元

	mov cx,8
s:	mov bx,[si]
	call cube
	mov [di],ax
	mov [di].2,dx
	add si,2
	add di,4
	loop s

	mov ax,4c00h
	int 21h				;利用功能调用返回DOS

cube:	mov ax,bx
	mul bx
	mul bx
	ret

codesg	ends				;代码段结束
	end start
					;汇编结束，同时指明程序起始点