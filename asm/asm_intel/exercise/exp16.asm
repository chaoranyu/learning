;----------------------------------------------------------
;��Ȩ��Ϣ��
;������Ϣ��
;�������ڣ�
;�����ܣ�
;
;
;ʹ�÷�����
;
;�����Ϣ��
;
;������Ϣ��
;
;�汾��Ϣ��
;----------------------------------------------------------
;�޸���Ϣ������Ӧ�汾���޸����ڣ��޸��ߣ��޸�ԭ���޸�λ�ã�
;-----------------------------------------------------------
assume cs:code

code	segment				;��������
start:	mov ax,cs
	mov ds,ax
	mov si,offset screen
	mov ax,0
	mov es,ax
	mov di,200h
	mov cx,offset screenend - offset screen
	cld
	rep movsb

	mov ax,0
	mov ds,ax
	mov word ptr ds:[7ch*4],200h
	mov word ptr ds:[7ch*4+2],0h

	mov ax,4c00h
	int 21h

;	setscreen�˵�
;	(1)����
;	(2)����ǰ��ɫ
;	(3)���ñ���ɫ
;	(4)���Ϲ���һ��

screen:	jmp short set
;wrong;	table dw sub1,sub2,sub3,sub4
	table dw sub1-offset screen+200h,sub2-offset screen+200h,sub3-offset screen+200h,sub4-offset screen+200h
;	table dw sub1-screen+200h,sub2-screen+200h,sub3-screen+200h,sub4-screen+200h

set:	push bx
	cmp ah,3
	ja screenret
	mov bl,ah
	mov bh,0
	add bx,bx
	sub bx,offset screen
	call word ptr table[bx+200h]
;	call word ptr table[bx]+200h
;wrong?	call word ptr table[bx+200h]-offset screen

screenret:
	pop bx
	iret

;------------------------------------------
;sub1 cls screen
;------------------------------------------ 
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

;------------------------------------------
;sub2 fcolor al=0,1,2,3,4,5,6,7
;------------------------------------------ 
sub2:	push bx
	push cx
	push es
	mov bx,0b800h
	mov es,bx
	mov bx,1
	mov cx,2000
sub2s:	and byte ptr es:[bx],11111000b
	or es:[bx],al
	add bx,2
	loop sub2s
	pop es
	pop cx
	pop bx
	ret

;--------------------------------------------
;sub3 bcolor al=0,1,2,3,4,5,6,7
;-------------------------------------------- 
sub3:	push ax
	push bx
	push cx
	push es
	mov cl,4
	shl al,cl
	mov bx,0b800h
	mov es,bx
	mov bx,1
	mov cx,2000
sub3s:	and byte ptr es:[bx],10001111b
	or es:[bx],al
	add bx,2
	loop sub3s
	pop es
	pop cx
	pop bx
	pop ax
	ret

;----------------------------------------------
;sub4 copy backline
;---------------------------------------------- 
sub4:	push cx
	push si
	push di
	push ds
	push es
	mov si,0b800h
	mov ds,si
	mov es,si
	mov si,160
	mov di,0
	cld
	mov cx,24
sub4s:	push cx
	mov cx,160
	rep movsb
	pop cx
	loop sub4s

	mov cx,80
	mov si,0
sub4s1:	mov byte ptr [si],' '
	add si,2
	loop sub4s1

	pop es
	pop ds
	pop di
	pop si
	pop cx
	ret

screenend:
	nop

code	ends				;����ν���
	end start			;��������ͬʱָ��������ʼ��
