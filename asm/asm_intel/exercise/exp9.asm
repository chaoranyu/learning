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
	mov si,0

	mov cx,16
s:	mov ax,[bx]
	mov ah,2h
	mov es:[si].720h,ax

	mov ah,24h
	mov es:[si].7c0h,ax

	mov ah,71h
	mov es:[si].860h,ax

	inc bx
	add si,2
	loop s

	mov ax,4c00h
	int 21h				;���ù��ܵ��÷���DOS

codesg	ends				;����ν���
	end start
					;��������ͬʱָ��������ʼ��