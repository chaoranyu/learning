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
	dw 8 dup (0)
data ends

codesg	segment				;��������

start:	mov ax,data
	mov ss,ax
	mov sp,16
	mov word ptr ss:[0],offset s
	mov ss:[2],cs
	call dword ptr ss:[0]
	nop
s:	mov ax,offset s
	sub ax,ss:[0ch]
	mov bx,cs
	sub bx,ss:[0eh]

	mov ax,4c00h
	int 21h				;���ù��ܵ��÷���DOS

codesg	ends				;����ν���
	end start
					;��������ͬʱָ��������ʼ��