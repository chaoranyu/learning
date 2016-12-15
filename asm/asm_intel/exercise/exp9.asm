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

data segment
	db 'welcome to masm!'
data ends

codesg	segment				;定义代码段

start:	mov ax,data
	mov ds,ax
	mov bx,0

	mov ax,0b800h
	mov es,ax
	mov si,0

	mov cx,16
s:	mov ax,[bx]
	mov ah,2h
	mov es:[si].720h,ax

	mov ah,24h
	mov es:[si].7c0h,ax

	mov ah,71h
	mov es:[si].860h,ax

	inc bx
	add si,2
	loop s

	mov ax,4c00h
	int 21h				;利用功能调用返回DOS

codesg	ends				;代码段结束
	end start
					;汇编结束，同时指明程序起始点