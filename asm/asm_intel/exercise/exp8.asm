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

codesg	segment				;定义代码段
	
	mov ax,4c00h
	int 21h

start:	mov ax,0
s:	nop
	nop

	mov di,offset s
	mov si,offset s2
	mov ax,cs:[si]
	mov cs:[di],ax

s0:	jmp short s

s1:	mov ax,0
	mov ax,4c00h
	int 21h				;利用功能调用返回DOS

s2:	jmp short s1
	nop

codesg	ends				;代码段结束
	end start
					;汇编结束，同时指明程序起始点