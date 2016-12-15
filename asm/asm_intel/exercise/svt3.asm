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
data segment
	db 128 dup (0)
data ends

code	segment				;定义代码段
start:	;mov ax,data
	;mov ds,ax
	;mov si,0
	mov dh,12
	mov dl,20

	call getstr

	mov ax,4c00h
	int 21h

getstr:	push ax

getstrs:
	mov ah,0
	int 16h
	cmp al,20h
	jb nochar		;ASCII码小于20h，说明不是字符
	mov ah,0
	call charstack		;字符入栈
	mov ah,2
	call charstack		;显示栈中的字符
	jmp getstrs

nochar:	cmp ah,0eh		;退格键的扫描码
	je backspace
	cmp ah,1ch		;Enter键的扫描码
	je enter
	jmp getstrs

backspace:
	mov ah,1
	call charstack		;字符出栈
	mov ah,2
	call charstack		;显示栈中的字符
	jmp getstrs

enter:	mov al,0
	mov ah,0
	call charstack		;0入栈
	mov ah,2
	call charstack		;显示栈中的字符
	pop ax
	ret

;==============================================
charstack:
	jmp charstart
	table dw charpush,charpop,charshow
	top dw 0			; 栈顶

charstart:
	push bx
	push dx
	push di
	push es

	cmp ah,2
	ja sret
	mov bl,ah
	mov bh,0
	add bx,bx
	jmp word ptr table[bx]

charpush:
	mov bx,top
	mov [si][bx],al
	inc top
	jmp sret

charpop:
	cmp top,0
	je sret
	dec top
	mov bx,top
	mov al,[si][bx]
	jmp sret

charshow:
	mov bx,0b800h
	mov es,bx
	mov al,160
	mov ah,0
	mul dh
	mov di,ax
	add dl,dl
	mov dh,0
	add di,dx

	mov bx,0
charshows:
	cmp bx,top
	jne noempty
	mov byte ptr es:[di],' '
	jmp sret
noempty:
	mov al,[si][bx]
	mov es:[di],al
	mov byte ptr es:[di+2],' '
	inc bx
	add di,2
	jmp charshows

sret:	pop es
	pop di
	pop dx
	pop bx
	ret

code	ends				;代码段结束
	end start			;汇编结束，同时指明程序起始点
