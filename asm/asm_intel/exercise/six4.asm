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
	dw 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
					;堆栈段有16字（32字节）空间
sseg	ends				;堆栈段结束
;
dseg	segment				;定义数据段
	dw 0123h,0456h,0789h,0abch,0defh,0fedh,0cbah,0987h
dseg	ends
;
code	segment 'code'			;定义代码段
	assume cs:code,ds:dseg
	assume ss:sseg
start:	mov ax,sseg			;建立SS段地址
	mov ss,ax
	mov sp,20h

	mov ax,dseg			;建立DS段地址
	mov ds,ax
	mov bx,0
	mov cx,8

s:	push,[bx]
	add bx,2
	loop s

	mov bx,0
	mov cx,8

s0:	pop,[bx]
	add bx,2
	loop s0
		
	mov ax,4c00h
	int 21h				;利用功能调用返回DOS
code	ends				;代码段结束
	end start
					;汇编结束，同时指明程序起始点
