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
	
;	mov ax,0
;	mov es,ax
	mov word ptr es:[0*4],200h
	mov word ptr es:[0*4+2],0

	mov ax,4c00h
	int 21h				;���ù��ܵ��÷���DOS

do0:	jmp short do0start
	db "divide error!"
	
do0start:
	mov ax,cs
	mov ds,ax
	mov si,202h

	mov ax,0b800h
	mov es,ax
	mov di,12*160+34*2

	mov cx,13
s:	mov al,[si]
	mov es:[di],al
	;mov es:[di],byte ptr 3		;test
	inc si
	add di,2
	loop s

	mov ax,4c00h
	int 21h

do0end:	nop

codesg	ends				;����ν���
	end start
					;��������ͬʱָ��������ʼ��