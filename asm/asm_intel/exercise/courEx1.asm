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
assume cs:codesg,ds:data,es:table

table segment				;定义数据段
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
table	ends

data segment
	db 40 dup(' ')
	db 0
data ends

codesg segment
start:	mov ax,data
	mov ds,ax
	mov si,0

	mov ax,table
	mov es,ax

	mov bx,0
	mov si,0
	mov bp,0
	mov di,0
	mov cx,21
	
s:	push cx
	mov ax,es:[bp]
	mov ds:[0],ax
	mov ax,es:[bp+2]
	mov ds:[2],ax

	mov ax,es:[bp+84]
	mov dx,es:[bp+86]
	mov si,10
	call dtoc

	mov cx,es:[di+168]
	call divdw
	mov si,30
	call dtoc

	mov ax,es:[di+168]
	mov dx,0
	mov si,20
	call dtoc

	mov dh,8			;行号(取值范围0~24)
	mov dl,3			;列号(取值范围0~79)
	mov cl,2			;颜色
	mov si,0
	mov ax,di
	mov bl,2
	div bl
	add dh,al
	call show_str

	add bp,4
	add di,2
	inc dh
	pop cx
	loop s

	mov ax,4c00h
	int 21h				;利用功能调用返回DOS

dtoc:	push ax
	push bx
	push cx
	push dx
	push si
	push di
	mov di,0

div1:	mov cx,10
	call divdw
	add cx,30h
	push cx
	inc di
	mov cx,ax
	add cx,dx 
	jcxz save
	jmp short div1

save:	mov cx,di

save1:	pop dx
	mov [si],dl
	inc si
	loop save1
	;mov dl,0
	;mov [si],dl

	pop di
	pop si
	pop dx
	pop cx
	pop bx
	pop ax
	ret

divdw:	push ax

	mov ax,dx
	mov dx,0
	div cx
	mov bx,ax

	pop ax
	div cx
	mov cx,dx
	mov dx,bx
	ret

show_str:push ax			;将ds:si指向空间的内容写入屏幕缓存，并显示
	push bx
	push cx
	push si
	push es

	mov ax,0b800h
	mov es,ax
	mov al,160
	mul dh
	mov bx,ax
	mov al,2
	mul dl
	add bx,ax
	mov ah,cl
	mov ch,0

set:	mov cl,[si]
	jcxz ok
	mov es:[bx],cl
	mov es:[bx].1,ah

	inc si
	add bx,2
	jmp short set

ok:	pop es
	pop si
	pop cx
	pop bx
	pop ax
	ret

codesg	ends				;代码段结束
	end start
					;汇编结束，同时指明程序起始点