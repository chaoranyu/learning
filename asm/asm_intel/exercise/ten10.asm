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

data segment
	dw 1,2,3,4,5,6,7,8
	dd 0,0,0,0,0,0,0,0
data ends

codesg	segment				;��������

start:	mov ax,data
	mov ds,ax
	mov si,0			;ds:siָ���һ��word��Ԫ
	mov di,16			;ds:diָ��ڶ���dword��Ԫ

	mov cx,8
s:	mov bx,[si]
	call cube
	mov [di],ax
	mov [di].2,dx
	add si,2
	add di,4
	loop s

	mov ax,4c00h
	int 21h				;���ù��ܵ��÷���DOS

cube:	mov ax,bx
	mul bx
	mul bx
	ret

codesg	ends				;����ν���
	end start
					;��������ͬʱָ��������ʼ��