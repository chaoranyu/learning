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
	db 'Welcome to masm','$'
data ends

codesg segment
start:	mov ah,2
	mov bh,0
	mov dh,5
	mov dl,12
	int 10h

	mov ax,data
	mov ds,ax
	mov dx,0
	mov ah,9
	int 21h

	mov ax,4c00h
	int 21h

codesg	ends				;代码段结束
	end start
					;汇编结束，同时指明程序起始点