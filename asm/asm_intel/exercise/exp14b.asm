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

code	segment				;定义代码段
time db "yy/mm/dd hh:mm:ss",'$'
cmos db 9,8,7,4,2,0
start:	mov ax,cs
	mov ds,ax
	mov si,0
	mov bx,0
	mov cx,6
 
a:	push cx
	mov al,cmos[bx]
	out 70h,al
	in al,71h

	mov ah,al
	mov cl,4
	shr al,cl		;be careful of low byte and high byte
	and ah,0fh
	add ax,3030h
	mov [si],ax

	add si,3
	inc bx
	pop cx
	loop a

;名称：BIOS中断(int 10h)
;功能：(ah)=2置光标到屏幕指定位置、(ah)=9在光标位置显示字符
;参数：(al)=字符、(bh)=页数、(dh)=行号、(dl)=列号
;      (bl)=颜色属性、(cx)=字符重复个数
	mov ah,2
	mov bh,0
	mov dh,12
	mov dl,31
	int 10h

;名称：DOS中断(int 21h)
;功能：(ah)=9显示用'$'结束的字符串、(ah)=4ch程序返回
;参数：ds:dx指向字符串、(al)=返回值
	mov dx,0
	mov ah,9
	int 21h
;结束
	mov ax,4c00h
	int 21h				;利用功能调用返回DOS
code	ends				;代码段结束
	end start
					;汇编结束，同时指明程序起始点
