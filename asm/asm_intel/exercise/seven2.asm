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
assume cs:codesg,ds:dseg

dseg	segment				;�������ݶ�
	db 'BaSiC'
	db 'iNfOrMaTiOn'
dseg	ends

codesg	segment				;��������

start:	mov ax,dseg
	mov ds,ax

	mov bx,0
	mov cx,5
s:	mov al,[bx]
	and al,0dfh
	mov [bx],al
	inc bx
	loop s

	mov bx,5
	mov cx,11
s0:	mov al,[bx]
	or al,020h
	mov [bx],al
	inc bx
	loop s0
	
	mov ax,4c00h
	int 21h				;���ù��ܵ��÷���DOS
codesg	ends				;����ν���
	end start
					;��������ͬʱָ��������ʼ��