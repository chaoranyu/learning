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
assume cs:code,ds:data,ss:stack

data	segment				;定义数据段
	dw 0123h,0456h,0789h,0abch,0defh,0fedh,0cbah,0987h
data	ends

stack	segment				;定义堆栈段
	dw 0,0,0,0,0,0,0,0		;堆栈段有16字（32字节）空间
stack	ends				;堆栈段结束

code	segment				;定义代码段

start:	mov ax,stack			;建立SS段地址
	mov ss,ax
	mov sp,10h

	mov ax,data			;建立DS段地址
	mov ds,ax

	push ds:[0]
	push ds:[2]
	pop ds:[2]
	pop ds:[0]
		
	mov ax,4c00h
	int 21h				;利用功能调用返回DOS

code	ends				;代码段结束
end start
					;汇编结束，同时指明程序起始点
