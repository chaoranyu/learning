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

stack segment
	db 128 dup (0)
stack ends

data segment
	dw 0,0
data ends

code	segment				;��������
start:	mov ax,stack
	mov ss,ax
	mov sp,128

	mov ax,data
	mov ds,ax

	mov ax,0
	mov es,ax

	;��ԭ����int 9�ն����̵���ڵ�ַ������ds:0��ds:2��Ԫ��
	push es:[9*4]
	pop ds:[0]
	push es:[9*4+2]
	pop ds:[2]

	;���ж��������������µ�int 9�ն����̵���ڵ�ַ
	cli
	mov word ptr es:[9*4],offset int9
	mov es:[9*4+2],cs
	sti

	mov ax,0b800h
	mov es,ax
	mov ah,'a'
s:	mov es:[160*12+40*2],ah
	call delay
	inc ah
	cmp ah,'z'
	jna s

	mov ax,0
	mov es,ax

	push ds:[0]
	pop es:[9*4]
	push ds:[2]
	pop es:[9*4+2]

	mov ax,4c00h
	int 21h

delay:	push ax
	push dx
	mov ax,0
	mov dx,4000h
s1:	sub ax,1
	sbb dx,0
	cmp ax,0
	jne s1
	cmp dx,0
	jne s1
	pop dx
	pop ax
	ret

	;����Ϊ�µ�int9�ж�����------
int9:	push ax
	push bx
	push es

	in al,60h

	;��intָ�����ģ��
	pushf
;	pushf
;	pop bx
;	and bh,11111100b
;	push bx
;	popf
	call dword ptr ds:[0]		;����ԭ����int 9�ж�����

	cmp al,1
	jne int9ret

	mov ax,0b800h
	mov es,ax
	inc byte ptr es:[160*12+40*2+1]	;������ֵ��1���ı���ɫ
int9ret:
	pop es
	pop bx
	pop ax
	iret
code	ends				;����ν���
	end start
					;��������ͬʱָ��������ʼ��
