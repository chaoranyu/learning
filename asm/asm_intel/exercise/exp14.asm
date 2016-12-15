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
start:	mov bx,0b800h
	mov es,bx
	mov bx,160*12+31*2
	mov di,0
	mov dx,9
 
date:	mov al,dl
	out 70h,al
	in al,71h

	mov ah,al
	mov cl,4
	shr ah,cl
	and al,00001111b

	add ah,30h
	add al,30h

	mov es:[bx+di],ah
	mov es:[bx+di].2,al

	dec dl
	add di,6
	cmp di,18
	je hour
	jmp short date

hour:	mov dx,4
 
s1:	mov al,dl
	out 70h,al
	in al,71h

	mov ah,al
	mov cl,4
	shr ah,cl
	and al,00001111b

	add ah,30h
	add al,30h

	mov es:[bx+di],ah
	mov es:[bx+di].2,al

	sub dl,2
	add di,6
	cmp di,36
	je spec
	jmp short s1

spec:	mov al,'/'
	mov es:[bx].4,al
	mov es:[bx].10,al
	mov al,':'
;	mov es:[bx].16,al
	mov es:[bx].22,al
	mov es:[bx].28,al

	mov ax,4c00h
	int 21h				;利用功能调用返回DOS
code	ends				;代码段结束
	end start
					;汇编结束，同时指明程序起始点
