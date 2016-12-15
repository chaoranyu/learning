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

stack segment
	db 128 dup (0)
stack ends

data segment
	dw 0,0
data ends

code	segment				;定义代码段
start:	mov ax,stack
	mov ss,ax
	mov sp,128

	mov ax,data
	mov ds,ax

	mov ax,0
	mov es,ax

	;将原来的int 9终端例程的入口地址保存在ds:0、ds:2单元中
	push es:[9*4]
	pop ds:[0]
	push es:[9*4+2]
	pop ds:[2]

	;在中断向量表中设置新的int 9终端例程的入口地址
	cli
	mov word ptr es:[9*4],offset int9
	mov es:[9*4+2],cs
	sti

	mov ax,0b800h
	mov es,ax
	mov ah,'a'
s:	mov es:[160*12+40*2],ah
	call delay
	inc ah
	cmp ah,'z'
	jna s

	mov ax,0
	mov es,ax

	push ds:[0]
	pop es:[9*4]
	push ds:[2]
	pop es:[9*4+2]

	mov ax,4c00h
	int 21h

delay:	push ax
	push dx
	mov ax,0
	mov dx,4000h
s1:	sub ax,1
	sbb dx,0
	cmp ax,0
	jne s1
	cmp dx,0
	jne s1
	pop dx
	pop ax
	ret

	;以下为新的int9中断例程------
int9:	push ax
	push bx
	push es

	in al,60h

	;对int指令进行模拟
	pushf
;	pushf
;	pop bx
;	and bh,11111100b
;	push bx
;	popf
	call dword ptr ds:[0]		;调用原来的int 9中断例程

	cmp al,1
	jne int9ret

	mov ax,0b800h
	mov es,ax
	inc byte ptr es:[160*12+40*2+1]	;将属性值加1，改变颜色
int9ret:
	pop es
	pop bx
	pop ax
	iret
code	ends				;代码段结束
	end start
					;汇编结束，同时指明程序起始点
