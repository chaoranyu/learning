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
sseg	segment stack			;定义堆栈段
	dw 512 dup(?)
					;堆栈段有512字（1024字节）空间
sseg	ends				;堆栈段结束
;
dseg	segment				;定义数据段

dseg	ends
;
code	segment 'code'			;定义代码段
	assume cs:code,ds:dseg
	assume ss:sseg
start:	mov ax,0ffffh			;建立DS段地址
	mov ds,ax
	mov bx,0
	mov dx,0
	mov cx,12

s:	mov al,[bx]
	mov ah,0
	add dx,ax
	add bx,1
	loop s
		
	mov ax,4c00h
	int 21h				;利用功能调用返回DOS
code	ends				;代码段结束
	end start
					;汇编结束，同时指明程序起始点
