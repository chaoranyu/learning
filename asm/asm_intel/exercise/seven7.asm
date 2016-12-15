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
assume cs:codesg,ds:datasg

datasg	segment				;定义数据段
	db 'welcome to masm!'
	db '                '
datasg	ends

codesg	segment				;定义代码段

start:	mov ax,datasg
	mov ds,ax
	mov si,0

	mov cx,8
s:	mov ax,0[si]
	mov 16[si],ax
	add si,2
	loop s

	mov ax,4c00h
	int 21h				;利用功能调用返回DOS

codesg	ends				;代码段结束
	end start
					;汇编结束，同时指明程序起始点