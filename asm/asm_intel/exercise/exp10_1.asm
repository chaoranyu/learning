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
	db 'welcome to masm!',0
data ends

codesg	segment				;��������

start:	mov dh,8			;�к�(ȡֵ��Χ0~24)
	mov dl,3			;�к�(ȡֵ��Χ0~79)
	mov cl,2			;��ɫ
	mov ax,data
	mov ds,ax
	mov si,0			;ds:siָ���ַ����׵�ַ
	call show_str

	mov ax,4c00h
	int 21h				;���ù��ܵ��÷���DOS

show_str:push ax
	push bx
	push cx
	push si

	mov ax,0b800h
	mov es,ax
	mov al,160
	mul dh
	mov bx,ax
	mov al,2
	mul dl
	add bx,ax
	mov ah,cl
	mov ch,0

set:	mov cl,[si]
	jcxz ok
	mov es:[bx],cl
	mov es:[bx].1,ah

	inc si
	add bx,2
	jmp short set

ok:	pop si
	pop cx
	pop bx
	pop ax
	ret

codesg	ends				;����ν���
	end start
					;��������ͬʱָ��������ʼ��