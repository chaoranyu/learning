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
code	segment 'code'			;��������
boot:	jmp read
;===================================
;ֱ�Ӷ�ַ��
;===================================
m0	db 'cs=7c00',0
m1	db 'ip>7c00',0
m2	db 'cs!=7c00',0

;=========== read ==================
read:	push cs
	pop ds
	mov ax,ds

	call screen
	cmp ax,7c0h
	je showcs
	mov dh,1
	mov dl,0
	mov cl,2
	mov si,m2-boot
	call showstr
	jmp readend

showcs:	mov si,m0-boot
	mov dh,0
	mov dl,0
	mov cl,2
	call showstr

readend:
	jmp read
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

code	ends				;����ν���
	end start
					;��������ͬʱָ��������ʼ��
