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
assume cs:codesg,ds:dseg

dseg	segment				;定义数据段
	db 'BaSiC'
	db 'iNfOrMaTiOn'
dseg	ends

codesg	segment				;定义代码段

start:	mov ax,dseg
	mov ds,ax

	mov bx,0
	mov cx,5
s:	mov al,[bx]
	and al,0dfh
	mov [bx],al
	inc bx
	loop s

	mov bx,5
	mov cx,11
s0:	mov al,[bx]
	or al,020h
	mov [bx],al
	inc bx
	loop s0
	
	mov ax,4c00h
	int 21h				;利用功能调用返回DOS
codesg	ends				;代码段结束
	end start
					;汇编结束，同时指明程序起始点