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

code	segment				;��������
time db "yy/mm/dd hh:mm:ss",'$'
cmos db 9,8,7,4,2,0
start:	mov ax,cs
	mov ds,ax
	mov si,0
	mov bx,0
	mov cx,6
 
a:	push cx
	mov al,cmos[bx]
	out 70h,al
	in al,71h

	mov ah,al
	mov cl,4
	shr al,cl		;be careful of low byte and high byte
	and ah,0fh
	add ax,3030h
	mov [si],ax

	add si,3
	inc bx
	pop cx
	loop a

;���ƣ�BIOS�ж�(int 10h)
;���ܣ�(ah)=2�ù�굽��Ļָ��λ�á�(ah)=9�ڹ��λ����ʾ�ַ�
;������(al)=�ַ���(bh)=ҳ����(dh)=�кš�(dl)=�к�
;      (bl)=��ɫ���ԡ�(cx)=�ַ��ظ�����
	mov ah,2
	mov bh,0
	mov dh,12
	mov dl,31
	int 10h

;���ƣ�DOS�ж�(int 21h)
;���ܣ�(ah)=9��ʾ��'$'�������ַ�����(ah)=4ch���򷵻�
;������ds:dxָ���ַ�����(al)=����ֵ
	mov dx,0
	mov ah,9
	int 21h
;����
	mov ax,4c00h
	int 21h				;���ù��ܵ��÷���DOS
code	ends				;����ν���
	end start
					;��������ͬʱָ��������ʼ��
