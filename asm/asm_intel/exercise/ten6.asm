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
	dw 8 dup (0)
data ends

codesg	segment				;定义代码段

start:	mov ax,data
	mov ss,ax
	mov sp,16
	mov word ptr ss:[0],offset s
	mov ss:[2],cs
	call dword ptr ss:[0]
	nop
s:	mov ax,offset s
	sub ax,ss:[0ch]
	mov bx,cs
	sub bx,ss:[0eh]

	mov ax,4c00h
	int 21h				;利用功能调用返回DOS

codesg	ends				;代码段结束
	end start
					;汇编结束，同时指明程序起始点