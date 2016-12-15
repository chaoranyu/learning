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
code	segment 'code'			;定义代码段
start:	mov ax,cs
	mov ds,ax
	mov si,offset s
	mov ax,0
	mov es,ax
	mov di,200h
	mov cx,offset send - offset s
	cld
	rep movsb

	cli
	mov word ptr es:[7ch*4],200h
	mov word ptr es:[7ch*4+2],0
	sti

	mov ax,4c00h
	int 21h

s:	push ax
	push cx
	push dx
	
	cmp ah,0
	je read
	cmp ah,1
	je write
	ja sret
	cmp dx,2879
	ja sret

common:	push ax
	mov ax,dx
	mov dx,0
	mov cx,1440
	div cx
	push ax		;save磁头号（面）
	mov ax,dx
	mov dl,18
	div dl
	mov ch,al	;磁道号
	inc ah
	mov cl,ah	;扇区号
	pop ax
	mov dh,al	;磁头号（面）

	pop ax
	mov al,1	;读或写1个扇区
	mov dl,0	;驱动器号
	int 13h

sret:	pop dx
	pop cx
	pop ax
	iret

read:	mov ah,2
	jmp short common

write:	mov ah,3
	jmp short common
	
send:	nop

code	ends				;代码段结束
	end start
					;汇编结束，同时指明程序起始点
