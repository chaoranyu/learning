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
assume cs:codesg,ds:datasg

datasg	segment				;�������ݶ�
	db 'welcome to masm!'
	db '                '
datasg	ends

codesg	segment				;��������

start:	mov ax,datasg
	mov ds,ax
	mov si,0

	mov cx,8
s:	mov ax,0[si]
	mov 16[si],ax
	add si,2
	loop s

	mov ax,4c00h
	int 21h				;���ù��ܵ��÷���DOS

codesg	ends				;����ν���
	end start
					;��������ͬʱָ��������ʼ��