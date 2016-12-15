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

codesg segment
start:	mov ax,cs
	mov ds,ax
	mov si,offset do0
	mov ax,0
	mov es,ax
	mov di,200h
	mov cx,offset do0end - offset do0
	cld
	rep movsb
	
;	mov ax,0
;	mov es,ax
	mov word ptr es:[0*4],200h
	mov word ptr es:[0*4+2],0

	mov ax,4c00h
	int 21h				;利用功能调用返回DOS

do0:	jmp short do0start
	db "divide error!"
	
do0start:
	mov ax,cs
	mov ds,ax
	mov si,202h

	mov ax,0b800h
	mov es,ax
	mov di,12*160+34*2

	mov cx,13
s:	mov al,[si]
	mov es:[di],al
	;mov es:[di],byte ptr 3		;test
	inc si
	add di,2
	loop s

	mov ax,4c00h
	int 21h

do0end:	nop

codesg	ends				;代码段结束
	end start
					;汇编结束，同时指明程序起始点