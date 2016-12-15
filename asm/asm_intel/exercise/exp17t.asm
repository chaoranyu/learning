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
assume cs:code,ds:data
data segment
	db 'abcdefghijklmnopqrstuvwxyz1234567890'
data ends
code	segment 'code'			;定义代码段
start:	mov ax,data
	mov es,ax
	mov bx,0			;es:bx指向存储读出数据或写入数据的内存区

	mov ah,1			;0表示读，1表示写
	mov dx,0			;要读写的LBA
	int 7ch
		
	mov ax,4c00h
	int 21h				;利用功能调用返回DOS
code	ends				;代码段结束
	end start
					;汇编结束，同时指明程序起始点
