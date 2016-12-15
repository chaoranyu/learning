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
code	segment 'code'			;定义代码段
boot:	jmp read
;===================================
;直接定址表
;===================================
table	dw reset,startsys,clock,setclock

m0	db '***main menu***',0
m1	db '1) reset pc    ',0
m2	db '2) start system',0
m3	db '3) clock       ',0
m4	db '4) set clock   ',0
m5	db 'Please choice: ',0
menu	dw m0,m1,m2,m3,m4,m5

time	db 'YY/MM/DD hh:mm:ss',0
cmos	db 9,8,7,4,2,0

hint	db 'press F1 to change the color, press Esc to return',0
hint1	db 'Please input: YY/MM/DD hh:mm:ss',0			
char	db '  /  /     :  :  ',0
	db 0,1,3,4,6,7,9,10,12,13,15,16
;=========== read ==================
read:	mov ax,0h
	mov es,ax
	mov bx,7e00h

	mov ax,boot_end-boot			;offset????
	mov dx,0
	mov cx,512
	div cx
	cmp dx,0
	jne read0
	sub al,1

read0:	mov ch,0
	mov cl,2
	mov dh,0
	mov dl,0
	mov ah,2
	int 13h

	mov ax,7c0h
	push ax
	mov ax,showmenu-boot
	push ax
	retf

;===================================
showmenu:
	call screen
	push cs
	pop ds
	mov dh,10
	mov dl,30
	mov bx,0

	mov cx,6
showmenu0:
	push cx
	mov cl,2
	mov si,menu[bx]
	call showstr
	inc dh
	add bx,2
	pop cx
	loop showmenu0

getinput:
	mov ah,0
	int 16h
	cmp al,'1'
	jb showmenu
	cmp al,'4'
	ja  showmenu

	sub al,31h
	mov bl,al
	mov bh,0
	add bx,bx
	call table[bx]

	jmp showmenu

;========== 1)reset pc =============
reset:	mov ax,0FFFFh
	push ax
	mov ax,0
	push ax
	retf

;========== 3)clock ================
clock:	push ax
	push bx
	push cx
	push dx
	push ds
	push si

	call screen
	push cs
	pop ds
	mov si,offset hint
	mov dh,0
	mov dl,0
	mov cl,2
	call showstr

	mov cx,2
clockread:
	mov si,offset time
	mov bx,0
	push cx
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

	pop cx
	mov ax,0
	in al,60h		;study ?????
	cmp al,3bh
	je ccolor
	cmp al,1
	je  clockret
	jmp showtime

color_1:
	mov cx,1		; 0为黑色
	jmp showtime
	
ccolor:
	cmp cx,7
	je color_1
	inc cx

showtime:
	mov si,offset time
	mov dh,12
	mov dl,30
	call showstr
	jmp clockread

clockret:
	pop si
	pop ds
	pop dx
	pop cx
	pop bx
	pop ax
	ret
;========== 4)set clock=============
setclock:
	push ax
	push bx			;save 
	push cx
	push dx
	push ds
	push si
	push di
	mov bx,0
	mov di,offset char

set0:	call screen
	push cx
	push cs
	pop ds
	mov si,offset hint1
	mov dh,11
	mov dl,24
	mov cl,2
	call showstr
	mov si,offset char
	mov dh,12
	mov dl,38
	call showstr

	pop cx
	mov ah,0
	int 16h
	cmp ah,1			; Esc: exit and go upper menu
	je  setret
	cmp cx,12			; when input time ok, press any key confirm(except ESC)
	je setok
	cmp ah,1ch			; press enter
	je setret
	cmp al,'0'
	jb set0
	cmp al,'9'	
	ja set0

	cmp bx,1
	je setbx
	mov [di],al
	add di,1
	mov bx,1
	inc cx
	jmp set0
setbx:	mov [di],al
	add di,2
	mov bx,0
	inc cx
	jmp set0

setok:	mov bx,0
	mov si,offset char
	mov cx,6
set1:	push cx
	mov al,cmos[bx]
	out 70h,al
	mov ah,[si]			;ascii 2 BCD
	mov al,[si].1			;ascii 2 BCD
	sub ax,3030h
	mov cl,4
	shl ah,cl
	add al,ah
	out 71h,al
	inc bx
	add si,3
	pop cx
	loop set1

	mov si,offset char
	mov cx,6
clear:	mov [si],'  '
	add si,3
	loop clear

setret:	pop di
	pop si
	pop ds
	pop dx
	pop cx
	pop bx
	pop ax
	ret
	
;=========== screen func ===========
screen:	jmp sub1

;-----------------------------------
;sub1 cls screen
;-----------------------------------
sub1:	push bx
	push cx
	push es
	mov bx,0b800h
	mov es,bx
	mov bx,0
	mov cx,2000
sub1s:	mov byte ptr es:[bx],' '
	add bx,2
	loop sub1s
	pop es
	pop cx
	pop bx
	ret

;============= showstr =============
showstr:
	push ax
	push bx
	push cx
	push es
	push si
	mov ax,0b800h
	mov es,ax
	mov ax,160
	mul dh
	mov bx,ax
	mov ax,2
	mul dl
	add bx,ax

	mov al,cl
	mov cl,0
show0:	mov ch,[si]
	jcxz show1
	mov es:[bx],ch
	mov es:[bx+1],al
	inc si
	add bx,2
	jmp show0

show1:	pop si
	pop es
	pop cx
	pop bx
	pop ax
	ret

;==============call getstr sample===
	mov dh,12
	mov dl,20
	call getstr

;============== getstr =============
getstr:	push ax

getstrs:
	mov ah,0
	int 16h
	cmp al,20h
	jb nochar		;ASCII码小于20h，说明不是字符
	mov ah,0
	call charstack		;字符入栈
	mov ah,2
	call charstack		;显示栈中的字符
	jmp getstrs

nochar:	cmp ah,0eh		;退格键的扫描码
	je backspace
	cmp ah,1ch		;Enter键的扫描码
	je enter
	jmp getstrs

backspace:
	mov ah,1
	call charstack		;字符出栈
	mov ah,2
	call charstack		;显示栈中的字符
	jmp getstrs

enter:	mov al,0
	mov ah,0
	call charstack		;0入栈
	mov ah,2
	call charstack		;显示栈中的字符
	pop ax
	ret

;============ charstack ============
charstack:
	jmp short charstart
	ctable dw charpush,charpop,charshow
	top dw 0			; 栈顶

charstart:
	push bx
	push dx
	push di
	push es

	cmp ah,2
	ja sret
	mov bl,ah
	mov bh,0
	add bx,bx
	jmp word ptr ctable[bx]

charpush:
	mov bx,top
	mov [si][bx],al
	inc top
	jmp sret

charpop:
	cmp top,0
	je sret
	dec top
	mov bx,top
	mov al,[si][bx]
	jmp sret

charshow:
	mov bx,0b800h
	mov es,bx
	mov al,160
	mov ah,0
	mul dh
	mov di,ax
	add dl,dl
	mov dh,0
	add di,dx

	mov bx,0
charshows:
	cmp bx,top
	jne noempty
	mov byte ptr es:[di],' '
	jmp sret
noempty:
	mov al,[si][bx]
	mov es:[di],al
	mov byte ptr es:[di+2],' '
	inc bx
	add di,2
	jmp charshows

sret:	pop es
	pop di
	pop dx
	pop bx
	ret

;========== 2)start system =========
startsys:
	call screen
	mov ax,0
	mov es,ax
	mov bx,7c00h
	
	mov al,1
	mov ch,0
	mov cl,1
	mov dh,0
	mov dl,80h					;C disk
	mov ah,2
	int 13h

	mov ax,0
	push ax
	mov ax,7c00h
	push ax
	retf
	

;============ boot code end ========
boot_end:	nop

;============ setup code ===========
start:	push cs
	pop es
	mov bx,offset boot

	mov ax,offset boot_end - offset boot
	mov dx,0
	mov cx,512
	div cx
	cmp dx,0
	je s0
	add al,1

s0:	mov ch,0
	mov cl,1
	mov dh,0
	mov dl,0
	mov ah,3
	int 13h

	mov ax,4c00h
	int 21h

code	ends				;代码段结束
	end start
					;汇编结束，同时指明程序起始点
