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
assume cs:code
;assume ds:data
;data segment
;	db '123456789'
;data ends
code	segment 'code'			;定义代码段
start:	mov ax,0b800h
	;mov ax,data
	mov es,ax
	mov bx,0

	mov al,8
	mov ch,0
	mov cl,1
	mov dh,0
	mov dl,0
	mov ah,3
	int 13h
		
	mov ax,4c00h
	int 21h				;利用功能调用返回DOS
code	ends				;代码段结束
	end start
					;汇编结束，同时指明程序起始点
