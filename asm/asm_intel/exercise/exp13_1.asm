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
assume cs:codesg

codesg segment
start:	mov ax,cs
	mov ds,ax
	mov si,offset do0
	mov ax,0
	mov es,ax
	mov di,200h
	mov cx,offset do0end - offset do0
	cld
	rep movsb
	
	mov ax,0
	mov es,ax
	mov word ptr es:[7ch*4],200h
	mov word ptr es:[7ch*4+2],0

	mov ax,4c00h
	int 21h				;���ù��ܵ��÷���DOS

do0:	push ax
	push si
	push di

	mov ax,0b800h
	mov es,ax
	mov al,160
	mul dh
	mov di,ax
	mov al,2
	mul dl
	add di,ax

	mov ax,0
	mov ah,cl
s:	mov al,[si]
	cmp al,0
	je ok
;	jcxz ok
	mov es:[di],ax
	inc si
	add di,2
	jmp short s

ok:	pop di
	pop si
	pop ax
	iret
	mov ax,4c00h
	int 21h

do0end:	nop

codesg	ends				;����ν���
	end start
					;��������ͬʱָ��������ʼ��