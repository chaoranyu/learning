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
	mov si,offset lp
	mov ax,0
	mov es,ax
	mov di,200h
	mov cx,offset lpend - offset lp
	cld
	rep movsb
	
	mov ax,0
	mov es,ax
	mov word ptr es:[7ch*4],200h
	mov word ptr es:[7ch*4+2],0

	mov ax,4c00h
	int 21h				;���ù��ܵ��÷���DOS

lp:	push bp
	mov bp,sp
	dec cx
	jcxz lpret
	add [bp+2],bx
lpret:	pop bp
	iret
	mov ax,4c00h
	int 21h

lpend:	nop

codesg	ends				;����ν���
	end start
					;��������ͬʱָ��������ʼ��