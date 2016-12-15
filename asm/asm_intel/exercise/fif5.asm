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

code	segment				;定义代码段
start:	mov ax,stack
	mov ss,ax
	mov sp,128

	push cs
	pop ds

	mov ax,0
	mov es,ax

	mov si,offset int9
	mov di,204h
	mov cx,offset int9end - offset int9
	cld
	rep movsb

	;将原来的int 9终端例程的入口地址保存在0:200单元中
	push es:[9*4]
	pop es:[200h]
	push es:[9*4+2]
	pop es:[202h]

	;在中断向量表中设置新的int 9终端例程的入口地址
	cli
	mov word ptr es:[9*4],204h
	mov word ptr es:[9*4+2],0
	sti

	mov ax,4c00h
	int 21h

	;以下为新的int9中断例程------
int9:	push ax
	push bx
	push cx
	push es

	in al,60h

	;对int指令进行模拟
	pushf
	call dword ptr cs:[200h]	;当此中断例程执行时(CS)=0

	cmp al,3bh			;F1~F10的扫描码为3B~44
	jne int9ret

	mov ax,0b800h
	mov es,ax
	mov bx,1
	mov cx,2000
s:	inc byte ptr es:[bx]
	add bx,2
	loop s

int9ret:
	pop es
	pop cx
	pop bx
	pop ax
	iret

int9end:
	nop

code	ends				;代码段结束
	end start			;汇编结束，同时指明程序起始点
