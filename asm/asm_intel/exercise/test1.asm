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

data segment				;定义数据段
	dd 12345678h
data	ends

codesg	segment				;定义代码段

start:	mov ax,data
	mov ds,ax
	mov bx,0
	mov [bx],word ptr 0
	mov [bx+2],seg codesg
	jmp dword ptr ds:[0]
	mov ax,4c00h
	int 21h				;利用功能调用返回DOS

codesg	ends				;代码段结束
	end start
					;汇编结束，同时指明程序起始点