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
start:	mov ah,0
	int 16h

	mov ah,1
	cmp al,'r'
	je red
	cmp al,'g'
	je green
	cmp al,'b'
	je blue
	jmp short sret

red:	shl ah,1
green:	shl ah,1
blue:	mov bx,0b800h
	mov es,bx
	mov bx,1
	mov cx,2000
s:	and byte ptr es:[bx],11111000b
	or es:[bx],ah
	add bx,2
	loop s

sret:	mov ax,4c00h
	int 21h

code	ends				;代码段结束
	end start			;汇编结束，同时指明程序起始点
