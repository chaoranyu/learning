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
start:	mov ax,cs
	mov ds,ax
	mov si,offset s
	mov ax,0
	mov es,ax
	mov di,200h
	mov cx,offset send - offset s
	cld
	rep movsb

	cli
	mov word ptr es:[7ch*4],200h
	mov word ptr es:[7ch*4+2],0
	sti

	mov ax,4c00h
	int 21h

s:	push ax
	push cx
	push dx
	
	cmp ah,0
	je read
	cmp ah,1
	je write
	ja sret
	cmp dx,2879
	ja sret

common:	push ax
	mov ax,dx
	mov dx,0
	mov cx,1440
	div cx
	push ax		;save��ͷ�ţ��棩
	mov ax,dx
	mov dl,18
	div dl
	mov ch,al	;�ŵ���
	inc ah
	mov cl,ah	;������
	pop ax
	mov dh,al	;��ͷ�ţ��棩

	pop ax
	mov al,1	;����д1������
	mov dl,0	;��������
	int 13h

sret:	pop dx
	pop cx
	pop ax
	iret

read:	mov ah,2
	jmp short common

write:	mov ah,3
	jmp short common
	
send:	nop

code	ends				;����ν���
	end start
					;��������ͬʱָ��������ʼ��
