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
assume cs:code,ds:data

data segment
	a db 1,2,3,4,5,6,7,8
	b dw 0
	c dw a,b
data ends

code	segment 'code'			;��������
start:	nop
screen:	jmp short set
	table dw sub1,sub2
;	table dw sub1-offset screen,sub2-offset screen
;	table dw sub1-screen,sub2-screen

set:	mov ax,1
sub1:	mov ax,2
sub2:	mov ax,3

	mov ax,4c00h
	int 21h				;���ù��ܵ��÷���DOS

s:	nop
s1:	mov dx,10h
	dw 234h
	ret

code	ends				;����ν���
	end start
					;��������ͬʱָ��������ʼ��
