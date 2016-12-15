assume cs:code				
code segment				
;===============================================================				
;功能：将代码写入0面0道1扇区				
;入口参数：				
;	(ah)=int 13h的功能号(2表示读扇区，3表示写扇区)			
;	(al)=写入的扇区数			
;	(ch)=磁道号			
;	(cl)=扇区号			
;	(dh)=磁头号(面号)			
;	(dl)=驱动器号    软区从0开始，0：软驱A，1：软驱B			
;                        硬盘从80h开始，80h：硬盘C，81h：硬盘D				
;	es:bx指向将写入磁盘的数据或指向接收从扇区读入数据的内存区			
;返回参数：				
;	操作成功：(ah)=0，(al)=写入的扇区数			
;	操作失败：(ah)=出错代码			
;===============================================================				
start:				
	mov ax,floppyend-floppy			
	mov dx,0			
	mov bx,512			
	div bx		;商ax为所需的扇区数	
	inc al		;写入的扇区数(为余数加扇区)	
				
	push cs			
	pop es			
	mov bx,offset floppy	;es:bx指向要被写入的内存单元		
				
	mov ch,0	;磁道号		
	mov cl,1	;扇区号		
	mov dl,0	;驱动器号，软盘A		
	mov dh,0	;磁头号(面号)		
	mov ah,3	;int 13h的功能号(3表示写扇区)		
	int 13h		;将代码写入0面0道1扇区	
				
	mov ax,4c00h			
	int 21h			
				
floppy:				
	jmp read			
;===============================================================				
;直接定址表				
;===============================================================				
table	dw function1-floppy,function2-floppy			
	dw function3-floppy,function4-floppy			
				
menu	db '***main Menu***',0			
	db '1) reset pc    ',0			
	db '2) start system',0			
	db '3) clock       ',0			
	db '4) set clock   ',0			
	db 'Please Choose: ',0			
				
time	db 'YY/MM/DD hh:mm:ss',0			
cmos	db 9,8,7,4,2,0			
hint	db 'press F1 to change the color, press Esc to return',0			
				
hint1	db 'Please input: YY/MM/DD hh:mm:ss',0			
char	db '  /  /     :  :  ',0			
				
;===============================================================				
;功能：将0面0道2扇区的内容写入0:7e00h				
;入口参数：				
;	(ah)=int 13h的功能号(2表示读扇区)			
;	(al)=写入的扇区数			
;	(ch)=磁道号			
;	(cl)=扇区号			
;	(dh)=磁头号(面号)			
;	(dl)=驱动器号    软区从0开始，0：软驱A，1：软区B			
;                        硬盘从80h开始，80h：硬盘C，81h：硬盘D				
;	es:bx指向将写入磁盘的数据			
;返回参数：				
;	操作成功：(ah)=0，(al)=写入的扇区数			
;	操作失败：(ah)=出错代码			
;===============================================================				
read:				
	mov ax,floppyend-floppy			
	mov dx,0			
	mov bx,512			
	div bx		;商ax为所需的扇区数	
	inc al			
				
	mov bx,0			
	mov es,bx			
	mov bx,7e00h	;es:bx指向要读入的内存单元		
				
	mov ch,0	;磁道号		
	mov cl,2	;扇区号		
	mov dl,0	;驱动器号		
	mov dh,0	;磁头号(面号)		
	mov ah,2	;int 13h的功能号(2表示读扇区)		
	int 13h		;读取0面0道2扇区的内容到0:7e00h处	
			;(第二扇区从512/200h开始)	
				
	mov ax,7c0h			
	push ax		;push cs	
	mov ax,showmenu-floppy			
	push ax		;push ip	
	retf		;jmp showmenu	
				
;***************************************************************				
;显示主菜单，调用show_str、clean子程序				
;***************************************************************				
showmenu:				
	call clean	;清屏		
	push cs			
	pop ds			
	mov si,menu-floppy			
	mov dh,8			
	mov dl,30			
	mov cx,6			
showmenu0:				
	push cx			
	mov cl,2			
	call show_str			
	add si,16			
	inc dh			
	pop cx			
	loop showmenu0			
				
;===============================================================				
;接收键盘输入，跳转相应功能程序段				
;调用BIOS用来提供读取键盘缓冲区功能的中断例程int 16h，				
;将读取的扫描码送入ah，ASCII码送入al				
;===============================================================				
go:	mov ax,0			
	int 16h			
	cmp al,'1'			
	jb showmenu			
	cmp al,'4'			
	ja showmenu			
				
	sub al,31h			
	mov bl,al			
	mov bh,0			
	add bx,bx			
	add bx,3	;计算相应子程序在table中的位移		
	call word ptr cs:[bx]			
				
	jmp showmenu			
				
;***************************************************************				
;功能1：重新启动计算机				
;***************************************************************				
function1:				
	mov ax,0ffffh			
	push ax			
	mov ax,0			
	push ax			
	retf		;jmp ffff:0	
				
;***************************************************************				
;功能3：进入时钟程序				
;***************************************************************				
function3:				
	push ax			
	push bx			
	push cx			
	push dx			
	push si			
	push ds			
	push es			
	call clean	;清屏		
	mov dh,0	;行号		
	mov dl,0	;列号		
	mov cl,2			
	mov si,offset hint-floppy			
	call show_str	;显示提示信息		
;===============================================================				
;名称：clock				
;功能：动态显示当前日期、时间				
;===============================================================				
	mov cx,2	;显示颜色		
clock:	mov bx,offset cmos-floppy			
	mov si,offset time-floppy			
	push cx			
	mov cx,6			
clock0:	push cx			
	mov al,[bx]			
	out 70h,al	;将al送入地址端口70h		
	in al,71h	;从数据端口71h处读出单元内容		
	mov ah,al			
	mov cl,4			
	shr al,cl	;右移4位		
	and ah,0fh	;al分成两个表示BCD码值的数据		
	add ax,3030h	;BCD码+30h=10进制数对应的ASCII码		
	mov [si],ax	;ASCII码写入time段		
	inc bx			
	add si,3			
	pop cx			
	loop clock0			
;---------------------------------------------------------------				
;按下F1键后，改变显示颜色				
;按下Esc键后，返回主菜单，其他键照常处理				
;---------------------------------------------------------------				
	mov al,0			
	in al,60h			
	pop cx		;显示颜色	
	cmp al,3bh	;和F1的扫描码3bh比较		
	je colour			
	cmp al,1	;和esc的扫描码01h比较		
	je clockend			
	jmp show_clock			
col_1:	mov cx,1	;cl∈[1,7]，0为黑色		
	jmp show_clock			
colour:	cmp cx,7			
	je col_1			
	inc cx			
show_clock:				
	mov dh,12	;行号		
	mov dl,30	;列号		
	mov si,offset time-floppy			
	call show_str			
	jmp clock	;循环显示CMOS		
clockend:				
	pop es			
	pop ds			
	pop si			
	pop dx			
	pop cx			
	pop bx			
	pop ax			
	ret			
				
;***************************************************************				
;功能4：设置时间				
;***************************************************************				
function4:				
	push ax			
	push bx			
	push cx			
	push dx			
	push si			
	call clean			
				
	mov dh,8	;行号		
	mov dl,30	;列号		
	mov cl,2			
	mov si,offset hint1-floppy			
	call show_str	;显示提示信息		
				
	add dh,1	;行号		
	add dl,14	;列号		
	mov si,offset char-floppy	;ds:si指向字符栈空间		
	call show_str	;显示输入格式		
	mov di,0			
	call getstrs			
	call witein			
	call cleanchar			
	pop si			
	pop dx			
	pop cx			
	pop bx			
	pop ax			
	ret			
				
;===============================================================				
;清除char内输入数据，还原环境				
;===============================================================				
cleanchar:				
	push cx			
cleanchar1:				
	mov cx,di			
	jcxz cleanchar2			
	call charpop			
	jmp cleanchar1			
cleanchar2:				
	pop cx			
	ret			
				
;===============================================================				
;ASCII=>BCD，写入CMOS				
;===============================================================				
witein:				
	push si			
	mov cx,6			
	mov bx,offset cmos-floppy			
wite:	push cx			
	mov al,[bx]			
	out 70h,al	;将al送入地址端口70h		
	mov ax,[si]			
	sub ah,30h	;10进制数对应的ASCII码-30h=BCD码		
	sub al,30h			
	mov cl,4			
	shl al,cl	;左移4位		
	add al,ah	;al为8位BCD码		
	out 71h,al	;从数据端口71h处写入单元内容		
	add si,3			
	inc bx			
	pop cx			
	loop wite			
	pop si			
	ret			
;===============================================================				
;子程序：接收数字输入				
;参数说明：di=char栈顶(字符地址、个数记录器)				
;===============================================================				
getstrs:				
	push ax			
	push bx			
getstr:	mov ax,0			
	int 16h			
	cmp ah,0eh		;退格键的扫描码	
	je backspace			
	cmp ah,1ch		;Enter键的扫描码	
	je enter1			
	cmp al,'0'			
	jb getstr			
	cmp al,'9'			
	ja getstr			
	cmp di,16		;限制输入个数	
	ja enter1			
	call charpush		;字符入栈	
	call show_str		;显示栈中字符	
	jmp getstr			
backspace:				
	call charpop		;字符出栈	
	call show_str		;显示栈中字符	
	jmp getstr			
enter1:	call show_str		;显示栈中字符	
	pop bx			
	pop ax			
	ret			
;===============================================================				
;子程序：数字的入栈。				
;参数说明：ds:si指向char栈空间；(al)=入栈字符；				
;===============================================================				
charpush:				
	mov bx,di			
	mov [si][bx],al			
	inc di			
	cmp di,2			
	je adds			
	cmp di,5			
	je adds			
	cmp di,8			
	je adds			
	cmp di,11			
	je adds			
	cmp di,14			
	je adds			
	ret			
adds:	inc di			
	ret			
				
;===============================================================				
;子程序：数字的出栈。				
;参数说明：ds:si指向char栈空间；(al)=入栈字符；				
;===============================================================				
charpop:cmp di,0				
	je sret			;栈顶为0(无字符)，结束
	cmp di,3			
	je subs			
	cmp di,6			
	je subs			
	cmp di,9			
	je subs			
	cmp di,12			
	je subs			
	cmp di,15			
	je subs			
	dec di			
	mov bx,di			
	mov al,' '			
	mov [si][bx],al			
	ret			
subs:	sub di,2			
	mov bx,di			
	mov al,' '			
	mov [si][bx],al			
	ret			
sret:	ret			
				
;===============================================================				
;名称：show_str子程序				
;功能：在指定的位置，用指定的颜色，显示一个用0结束的字符串。				
;参数：(dh)=行号(取值范围0~24)；				
;      (dl)=列号(取值范围0~79)；				
;      (cl)=颜色；				
;      ds:si指向字符串的首地址。				
;返回：无。				
;===============================================================				
show_str:				
	push ax			
	push bx			
	push cx			
	push dx			
	push si			
	push es			
	mov ax,0b800h			
	mov es,ax			
	mov ax,160			
	mul dh			
	mov bx,ax	;bx=160*dh		
	mov ax,2			
	mul dl		;ax=dl*2	
	add bx,ax	;mov bx,(160*dh+dl*2)设置es:bx指向显存首地址		
	mov al,cl	;把颜色cl赋值al		
	mov cl,0			
show0:	mov ch,[si]			
	jcxz show1	;(ds:si)=0时，转到show1执行		
	mov es:[bx],ch			
	mov es:[bx].1,al			
	inc si		;ds:si指向下一个字符地址	
	add bx,2	;es:bx指向下一个显存地址		
	jmp show0			
show1:	pop es			
	pop si			
	pop dx			
	pop cx			
	pop bx			
	pop ax			
	ret			
				
;===============================================================				
;名称：clean子程序				
;功能：清屏				
;===============================================================				
clean:	push bx			
	push cx			
	push es			
	mov bx,0b800h			
	mov es,bx			
	mov bx,0			
	mov cx,2000			
clean0:	mov byte ptr es:[bx],' '			
	add bx,2			
	loop clean0			
	pop bx			
	pop cx			
	pop es			
	ret			
				
;***************************************************************				
;功能2：引导现有的操作系统				
;***************************************************************				
;===============================================================				
;功能2实现引导现有的操作系统，代码需要将硬盘的0面0道1扇区读入0:7c00，				
;会覆盖从软盘读到0:7c00的第一个扇区，所以功能2代码不能写在第一个扇区				
;===============================================================				
function2:				
	call clean			
	mov ax,0			
	mov es,ax			
	mov bx,7c00h			
				
	mov al,1	;读取的扇区数		
	mov ch,0	;磁道号		
	mov cl,1	;扇区号		
	mov dl,80h	;驱动器号		
	mov dh,0	;磁头号(面号)		
	mov ah,2	;int 13h的功能号(2表示读扇区)		
	int 13h		;读取0面0道1扇区的内容到0:7c00h处	
				
	mov ax,0			
	push ax		;push cs	
	mov ax,7c00h			
	push ax		;push ip	
	retf		;jmp 0:7c00h	
				
floppyend:nop				
				
code ends 				