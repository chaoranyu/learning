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
assume cs:codesg,ds:data

data segment
	db 3,2,1,0
data ends

codesg	segment				;定义代码段
start:	mov ax,data
	mov ds,ax
	mov bx,0
s:	mov cl,[bx]
	mov ch,0
	jcxz ok
	inc bx
	jmp short s
ok:	mov dx,bx
	mov ax,4c00h
	int 21h				;利用功能调用返回DOS

codesg	ends				;代码段结束
	end start
					;汇编结束，同时指明程序起始点