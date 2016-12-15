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
	db 10 dup (0)
data ends

codesg	segment				;定义代码段

start:	mov ax,12666
	mov bx,data
	mov ds,bx
	mov si,0
	call dtoc

	mov dh,8			;行号(取值范围0~24)
	mov dl,3			;列号(取值范围0~79)
	mov cl,2			;颜色
	call show_str

	mov ax,4c00h
	int 21h				;利用功能调用返回DOS

dtoc:	push ax
	push bx
	push cx
	push dx
	push si
	push di
	mov bx,10
	mov di,0

div1:	mov dx,0
	div bx
	add dx,30h
	push dx
	inc di
	mov cx,ax
	jcxz save
	jmp short div1

save:	mov cx,di

save1:	pop dx
	mov [si],dl
	inc si
	loop save1
	mov dl,0
	mov [si],dl

	pop di
	pop si
	pop dx
	pop cx
	pop bx
	pop ax
	ret

show_str:push ax
	push bx
	push cx
	push si

	mov ax,0b800h
	mov es,ax
	mov al,160
	mul dh
	mov bx,ax
	mov al,2
	mul dl
	add bx,ax
	mov ah,cl
	mov ch,0

set:	mov cl,[si]
	jcxz ok
	mov es:[bx],cl
	mov es:[bx].1,ah

	inc si
	add bx,2
	jmp short set

ok:	pop si
	pop cx
	pop bx
	pop ax
	ret

codesg	ends				;代码段结束
	end start
					;汇编结束，同时指明程序起始点