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
	db 'word',0
	db 'unix',0
	db 'wind',0
	db 'good',0
data ends

codesg	segment				;��������

start:	mov ax,data
	mov ds,ax
	mov bx,0			;ds:siָ���һ��word��Ԫ

	mov cx,4
s:	mov si,bx
	call capital
	add bx,5
	loop s

	mov ax,4c00h
	int 21h				;���ù��ܵ��÷���DOS

capital:push cx
	push si

change:	mov cl,[si]
	mov ch,0
	jcxz ok
	and byte ptr [si],11011111b
	inc si
	jmp short change

ok:	pop si
	pop cx
	ret

codesg	ends				;����ν���
	end start
					;��������ͬʱָ��������ʼ��