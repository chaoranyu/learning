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
	db 'welcome to masm!'
data ends

codesg	segment				;��������

start:	mov ax,data
	mov ds,ax
	mov bx,0

	mov ax,0b800h
	mov es,ax
	mov bp,0

	mov cx,16
s:	mov al,[bx]
	mov es:[bp].64,al
	mov es:[bp].224,al
	mov es:[bp].384,al
	inc bx
	add bp,2
	loop s

	mov bp,0
	mov cx,16
s0:	mov al,2h
	mov es:[bp].65,al
	mov al,24h
	mov es:[bp].225,al
	mov al,71h
	mov es:[bp].385,al
	add bp,2
	loop s0

	mov ax,4c00h
	int 21h				;���ù��ܵ��÷���DOS

codesg	ends				;����ν���
	end start
					;��������ͬʱָ��������ʼ��