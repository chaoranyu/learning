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
	db 'word',0
	db 'unix',0
	db 'wind',0
	db 'good',0
data ends

codesg	segment				;定义代码段

start:	mov ax,data
	mov ds,ax
	mov bx,0			;ds:si指向第一组word单元

	mov cx,4
s:	mov si,bx
	call capital
	add bx,5
	loop s

	mov ax,4c00h
	int 21h				;利用功能调用返回DOS

capital:push cx
	push si

change:	mov cl,[si]
	mov ch,0
	jcxz ok
	and byte ptr [si],11011111b
	inc si
	jmp short change

ok:	pop si
	pop cx
	ret

codesg	ends				;代码段结束
	end start
					;汇编结束，同时指明程序起始点