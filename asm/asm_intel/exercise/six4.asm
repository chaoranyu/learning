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
sseg	segment stack			;�����ջ��
	dw 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
					;��ջ����16�֣�32�ֽڣ��ռ�
sseg	ends				;��ջ�ν���
;
dseg	segment				;�������ݶ�
	dw 0123h,0456h,0789h,0abch,0defh,0fedh,0cbah,0987h
dseg	ends
;
code	segment 'code'			;��������
	assume cs:code,ds:dseg
	assume ss:sseg
start:	mov ax,sseg			;����SS�ε�ַ
	mov ss,ax
	mov sp,20h

	mov ax,dseg			;����DS�ε�ַ
	mov ds,ax
	mov bx,0
	mov cx,8

s:	push,[bx]
	add bx,2
	loop s

	mov bx,0
	mov cx,8

s0:	pop,[bx]
	add bx,2
	loop s0
		
	mov ax,4c00h
	int 21h				;���ù��ܵ��÷���DOS
code	ends				;����ν���
	end start
					;��������ͬʱָ��������ʼ��
