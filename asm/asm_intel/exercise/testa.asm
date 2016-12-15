assume cs:code				
code segment				
;===============================================================				
;���ܣ�������д��0��0��1����				
;��ڲ�����				
;	(ah)=int 13h�Ĺ��ܺ�(2��ʾ��������3��ʾд����)			
;	(al)=д���������			
;	(ch)=�ŵ���			
;	(cl)=������			
;	(dh)=��ͷ��(���)			
;	(dl)=��������    ������0��ʼ��0������A��1������B			
;                        Ӳ�̴�80h��ʼ��80h��Ӳ��C��81h��Ӳ��D				
;	es:bxָ��д����̵����ݻ�ָ����մ������������ݵ��ڴ���			
;���ز�����				
;	�����ɹ���(ah)=0��(al)=д���������			
;	����ʧ�ܣ�(ah)=�������			
;===============================================================				
start:				
	mov ax,floppyend-floppy			
	mov dx,0			
	mov bx,512			
	div bx		;��axΪ�����������	
	inc al		;д���������(Ϊ����������)	
				
	push cs			
	pop es			
	mov bx,offset floppy	;es:bxָ��Ҫ��д����ڴ浥Ԫ		
				
	mov ch,0	;�ŵ���		
	mov cl,1	;������		
	mov dl,0	;�������ţ�����A		
	mov dh,0	;��ͷ��(���)		
	mov ah,3	;int 13h�Ĺ��ܺ�(3��ʾд����)		
	int 13h		;������д��0��0��1����	
				
	mov ax,4c00h			
	int 21h			
				
floppy:				
	jmp read			
;===============================================================				
;ֱ�Ӷ�ַ��				
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
;���ܣ���0��0��2����������д��0:7e00h				
;��ڲ�����				
;	(ah)=int 13h�Ĺ��ܺ�(2��ʾ������)			
;	(al)=д���������			
;	(ch)=�ŵ���			
;	(cl)=������			
;	(dh)=��ͷ��(���)			
;	(dl)=��������    ������0��ʼ��0������A��1������B			
;                        Ӳ�̴�80h��ʼ��80h��Ӳ��C��81h��Ӳ��D				
;	es:bxָ��д����̵�����			
;���ز�����				
;	�����ɹ���(ah)=0��(al)=д���������			
;	����ʧ�ܣ�(ah)=�������			
;===============================================================				
read:				
	mov ax,floppyend-floppy			
	mov dx,0			
	mov bx,512			
	div bx		;��axΪ�����������	
	inc al			
				
	mov bx,0			
	mov es,bx			
	mov bx,7e00h	;es:bxָ��Ҫ������ڴ浥Ԫ		
				
	mov ch,0	;�ŵ���		
	mov cl,2	;������		
	mov dl,0	;��������		
	mov dh,0	;��ͷ��(���)		
	mov ah,2	;int 13h�Ĺ��ܺ�(2��ʾ������)		
	int 13h		;��ȡ0��0��2���������ݵ�0:7e00h��	
			;(�ڶ�������512/200h��ʼ)	
				
	mov ax,7c0h			
	push ax		;push cs	
	mov ax,showmenu-floppy			
	push ax		;push ip	
	retf		;jmp showmenu	
				
;***************************************************************				
;��ʾ���˵�������show_str��clean�ӳ���				
;***************************************************************				
showmenu:				
	call clean	;����		
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
;���ռ������룬��ת��Ӧ���ܳ����				
;����BIOS�����ṩ��ȡ���̻��������ܵ��ж�����int 16h��				
;����ȡ��ɨ��������ah��ASCII������al				
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
	add bx,3	;������Ӧ�ӳ�����table�е�λ��		
	call word ptr cs:[bx]			
				
	jmp showmenu			
				
;***************************************************************				
;����1���������������				
;***************************************************************				
function1:				
	mov ax,0ffffh			
	push ax			
	mov ax,0			
	push ax			
	retf		;jmp ffff:0	
				
;***************************************************************				
;����3������ʱ�ӳ���				
;***************************************************************				
function3:				
	push ax			
	push bx			
	push cx			
	push dx			
	push si			
	push ds			
	push es			
	call clean	;����		
	mov dh,0	;�к�		
	mov dl,0	;�к�		
	mov cl,2			
	mov si,offset hint-floppy			
	call show_str	;��ʾ��ʾ��Ϣ		
;===============================================================				
;���ƣ�clock				
;���ܣ���̬��ʾ��ǰ���ڡ�ʱ��				
;===============================================================				
	mov cx,2	;��ʾ��ɫ		
clock:	mov bx,offset cmos-floppy			
	mov si,offset time-floppy			
	push cx			
	mov cx,6			
clock0:	push cx			
	mov al,[bx]			
	out 70h,al	;��al�����ַ�˿�70h		
	in al,71h	;�����ݶ˿�71h��������Ԫ����		
	mov ah,al			
	mov cl,4			
	shr al,cl	;����4λ		
	and ah,0fh	;al�ֳ�������ʾBCD��ֵ������		
	add ax,3030h	;BCD��+30h=10��������Ӧ��ASCII��		
	mov [si],ax	;ASCII��д��time��		
	inc bx			
	add si,3			
	pop cx			
	loop clock0			
;---------------------------------------------------------------				
;����F1���󣬸ı���ʾ��ɫ				
;����Esc���󣬷������˵����������ճ�����				
;---------------------------------------------------------------				
	mov al,0			
	in al,60h			
	pop cx		;��ʾ��ɫ	
	cmp al,3bh	;��F1��ɨ����3bh�Ƚ�		
	je colour			
	cmp al,1	;��esc��ɨ����01h�Ƚ�		
	je clockend			
	jmp show_clock			
col_1:	mov cx,1	;cl��[1,7]��0Ϊ��ɫ		
	jmp show_clock			
colour:	cmp cx,7			
	je col_1			
	inc cx			
show_clock:				
	mov dh,12	;�к�		
	mov dl,30	;�к�		
	mov si,offset time-floppy			
	call show_str			
	jmp clock	;ѭ����ʾCMOS		
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
;����4������ʱ��				
;***************************************************************				
function4:				
	push ax			
	push bx			
	push cx			
	push dx			
	push si			
	call clean			
				
	mov dh,8	;�к�		
	mov dl,30	;�к�		
	mov cl,2			
	mov si,offset hint1-floppy			
	call show_str	;��ʾ��ʾ��Ϣ		
				
	add dh,1	;�к�		
	add dl,14	;�к�		
	mov si,offset char-floppy	;ds:siָ���ַ�ջ�ռ�		
	call show_str	;��ʾ�����ʽ		
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
;���char���������ݣ���ԭ����				
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
;ASCII=>BCD��д��CMOS				
;===============================================================				
witein:				
	push si			
	mov cx,6			
	mov bx,offset cmos-floppy			
wite:	push cx			
	mov al,[bx]			
	out 70h,al	;��al�����ַ�˿�70h		
	mov ax,[si]			
	sub ah,30h	;10��������Ӧ��ASCII��-30h=BCD��		
	sub al,30h			
	mov cl,4			
	shl al,cl	;����4λ		
	add al,ah	;alΪ8λBCD��		
	out 71h,al	;�����ݶ˿�71h��д�뵥Ԫ����		
	add si,3			
	inc bx			
	pop cx			
	loop wite			
	pop si			
	ret			
;===============================================================				
;�ӳ��򣺽�����������				
;����˵����di=charջ��(�ַ���ַ��������¼��)				
;===============================================================				
getstrs:				
	push ax			
	push bx			
getstr:	mov ax,0			
	int 16h			
	cmp ah,0eh		;�˸����ɨ����	
	je backspace			
	cmp ah,1ch		;Enter����ɨ����	
	je enter1			
	cmp al,'0'			
	jb getstr			
	cmp al,'9'			
	ja getstr			
	cmp di,16		;�����������	
	ja enter1			
	call charpush		;�ַ���ջ	
	call show_str		;��ʾջ���ַ�	
	jmp getstr			
backspace:				
	call charpop		;�ַ���ջ	
	call show_str		;��ʾջ���ַ�	
	jmp getstr			
enter1:	call show_str		;��ʾջ���ַ�	
	pop bx			
	pop ax			
	ret			
;===============================================================				
;�ӳ������ֵ���ջ��				
;����˵����ds:siָ��charջ�ռ䣻(al)=��ջ�ַ���				
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
;�ӳ������ֵĳ�ջ��				
;����˵����ds:siָ��charջ�ռ䣻(al)=��ջ�ַ���				
;===============================================================				
charpop:cmp di,0				
	je sret			;ջ��Ϊ0(���ַ�)������
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
;���ƣ�show_str�ӳ���				
;���ܣ���ָ����λ�ã���ָ������ɫ����ʾһ����0�������ַ�����				
;������(dh)=�к�(ȡֵ��Χ0~24)��				
;      (dl)=�к�(ȡֵ��Χ0~79)��				
;      (cl)=��ɫ��				
;      ds:siָ���ַ������׵�ַ��				
;���أ��ޡ�				
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
	add bx,ax	;mov bx,(160*dh+dl*2)����es:bxָ���Դ��׵�ַ		
	mov al,cl	;����ɫcl��ֵal		
	mov cl,0			
show0:	mov ch,[si]			
	jcxz show1	;(ds:si)=0ʱ��ת��show1ִ��		
	mov es:[bx],ch			
	mov es:[bx].1,al			
	inc si		;ds:siָ����һ���ַ���ַ	
	add bx,2	;es:bxָ����һ���Դ��ַ		
	jmp show0			
show1:	pop es			
	pop si			
	pop dx			
	pop cx			
	pop bx			
	pop ax			
	ret			
				
;===============================================================				
;���ƣ�clean�ӳ���				
;���ܣ�����				
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
;����2���������еĲ���ϵͳ				
;***************************************************************				
;===============================================================				
;����2ʵ���������еĲ���ϵͳ��������Ҫ��Ӳ�̵�0��0��1��������0:7c00��				
;�Ḳ�Ǵ����̶���0:7c00�ĵ�һ�����������Թ���2���벻��д�ڵ�һ������				
;===============================================================				
function2:				
	call clean			
	mov ax,0			
	mov es,ax			
	mov bx,7c00h			
				
	mov al,1	;��ȡ��������		
	mov ch,0	;�ŵ���		
	mov cl,1	;������		
	mov dl,80h	;��������		
	mov dh,0	;��ͷ��(���)		
	mov ah,2	;int 13h�Ĺ��ܺ�(2��ʾ������)		
	int 13h		;��ȡ0��0��1���������ݵ�0:7c00h��	
				
	mov ax,0			
	push ax		;push cs	
	mov ax,7c00h			
	push ax		;push ip	
	retf		;jmp 0:7c00h	
				
floppyend:nop				
				
code ends 				