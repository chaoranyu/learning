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
assume cs:codesg,ss:stacksg,ds:datasg

stacksg segment
	dw 0,0,0,0,0,0,0,0
stacksg ends

datasg	segment				;定义数据段
	db '1. display      '
	db '2. brows        '
	db '3. replace      '
	db '4. modify       '
datasg	ends

codesg	segment				;定义代码段

start:	mov ax,stacksg
	mov ss,ax
	mov sp,10h

	mov ax,datasg
	mov ds,ax
	mov bx,0

	mov cx,4
s0:	push cx
	mov si,0
	mov cx,4

s:	mov al,[bx+si+3]
	and al,11011111b
	mov [bx+si+3],al
	inc si
	loop s

	pop cx
	add bx,16
	loop s0

	mov ax,4c00h
	int 21h				;利用功能调用返回DOS

codesg	ends				;代码段结束
	end start
					;汇编结束，同时指明程序起始点