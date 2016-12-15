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

data segment				;定义数据段
	db '1975','1976','1977','1978','1979','1980','1981','1982'
	db '1983','1984','1985','1986','1987','1988','1989','1990'
	db '1991','1992','1993','1994','1995'
	;以上时表示21年的21个字符串

	dd 16,22,382,1356,2390,8000,16000,24486,50065,97479,140417,197514
	dd 345980,590827,803530,1183000,1843000,2759000,3753000,4649000,5937000
	;以上是表示21年公司总收入的21个dword型数据

	dw 3,7,9,13,28,38,130,220,476,778,1001,1442,2258,2793,4037,5635,8226
	dw 11542,14430,15257,17800
	;以上是表示21年公司雇员人数的的21个word型数据
data	ends

table segment
	db 21 dup('year summ ne ?? ')
table ends

stack segment
	dw 0,0,0,0,0,0,0,0
stack ends

codesg	segment				;定义代码段

start:	mov ax,data
	mov ds,ax

	mov ax,table
	mov es,ax

	mov ax,stack
	mov ss,ax
	mov sp,10h

	mov bx,0
	mov cx,21
	mov si,0
	mov di,0

s:	mov al,[si]
	mov es:[bx],al
	mov al,[si].1
	mov es:[bx].1,al
	mov al,[si].2
	mov es:[bx].2,al
	mov al,[si].3
	mov es:[bx].3,al

	mov ax,[si+84]
	mov es:[bx].5,ax
	mov dx,[si+86]
	mov es:[bx].7,dx

	mov cx,[di+168]
	mov es:[bx].10,cx

	div cx
	mov es:[bx].13,ax

	pop cx
	add si,4
	add di,2
	add bx,16
	loop s

	mov ax,4c00h
	int 21h				;利用功能调用返回DOS

codesg	ends				;代码段结束
	end start
					;汇编结束，同时指明程序起始点