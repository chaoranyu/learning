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
start:	mov bx,0b800h
	mov es,bx
	mov bx,160*12+31*2
	mov di,0
	mov dx,9
 
date:	mov al,dl
	out 70h,al
	in al,71h

	mov ah,al
	mov cl,4
	shr ah,cl
	and al,00001111b

	add ah,30h
	add al,30h

	mov es:[bx+di],ah
	mov es:[bx+di].2,al

	dec dl
	add di,6
	cmp di,18
	je hour
	jmp short date

hour:	mov dx,4
 
s1:	mov al,dl
	out 70h,al
	in al,71h

	mov ah,al
	mov cl,4
	shr ah,cl
	and al,00001111b

	add ah,30h
	add al,30h

	mov es:[bx+di],ah
	mov es:[bx+di].2,al

	sub dl,2
	add di,6
	cmp di,36
	je spec
	jmp short s1

spec:	mov al,'/'
	mov es:[bx].4,al
	mov es:[bx].10,al
	mov al,':'
;	mov es:[bx].16,al
	mov es:[bx].22,al
	mov es:[bx].28,al

	mov ax,4c00h
	int 21h				;���ù��ܵ��÷���DOS
code	ends				;����ν���
	end start
					;��������ͬʱָ��������ʼ��
