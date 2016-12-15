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

code	segment				;定义代码段
;	setscreen菜单
;	(1)清屏
;	(2)设置前景色
;	(3)设置背景色
;	(4)向上滚动一行

screen:	jmp short set
	table dw sub1+200h,sub2+200h,sub3+200h,sub4+200h

set:	push bx
	cmp ah,3
	ja screenret
	mov bl,ah
	mov bh,0
	add bx,bx

	call word ptr table[bx]+200h

screenret:
	pop bx
	iret

;========================================
sub1:	push bx
	push cx
	push es
	mov bx,0b800h
	mov es,bx
	mov bx,0
	mov cx,2000
sub1s:	mov byte ptr es:[bx],' '
	add bx,2
	loop sub1s
	pop es
	pop cx
	pop bx
	ret

;========================================
sub2:	push bx
	push cx
	push es
	mov bx,0b800h
	mov es,bx
	mov bx,1
	mov cx,2000
sub2s:	and byte ptr es:[bx],11111000b
	or es:[bx],al
	add bx,2
	loop sub2s
	pop es
	pop cx
	pop bx
	ret

;========================================
sub3:	push ax
	push bx
	push cx
	push es
	mov cl,4
	shl al,cl
	mov bx,0b800h
	mov es,bx
	mov bx,1
	mov cx,2000
sub3s:	and byte ptr es:[bx],10001111b
	or es:[bx],al
	add bx,2
	loop sub3s
	pop es
	pop cx
	pop bx
	pop ax
	ret

;========================================
sub4:	push cx
	push si
	push di
	push ds
	push es
	mov si,0b800h
	mov ds,si
	mov es,si
	mov si,160
	mov di,0
	cld
	mov cx,24
sub4s:	push cx
	mov cx,160
	rep movsb
	pop cx
	loop sub4s

	mov cx,80
	mov si,0
sub4s1:	mov byte ptr [si],' '
	add si,2
	loop sub4s1

	pop es
	pop ds
	pop di
	pop si
	pop cx
	ret

screenend:
	nop

;========================================
start:	mov ax,cs
	mov ds,ax
	mov si,offset screen
	mov ax,0
	mov es,ax
	mov di,200h
	mov cx,offset screenend - offset screen
	cld
	rep movsb

	mov ax,0
	mov ds,ax
	mov word ptr ds:[7ch*4],200h
	mov word ptr ds:[7ch*4+2],0h

	mov ax,4c00h
	int 21h

code	ends				;代码段结束
	end start			;汇编结束，同时指明程序起始点
