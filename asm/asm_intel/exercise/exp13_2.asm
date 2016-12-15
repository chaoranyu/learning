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
	mov si,offset lp
	mov ax,0
	mov es,ax
	mov di,200h
	mov cx,offset lpend - offset lp
	cld
	rep movsb
	
	mov ax,0
	mov es,ax
	mov word ptr es:[7ch*4],200h
	mov word ptr es:[7ch*4+2],0

	mov ax,4c00h
	int 21h				;利用功能调用返回DOS

lp:	push bp
	mov bp,sp
	dec cx
	jcxz lpret
	add [bp+2],bx
lpret:	pop bp
	iret
	mov ax,4c00h
	int 21h

lpend:	nop

codesg	ends				;代码段结束
	end start
					;汇编结束，同时指明程序起始点