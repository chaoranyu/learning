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

datasg segment
	db "Beginner's All-purpose Symbolic Instruction Code.",0
datasg ends

codesg segment
start:	mov ax,datasg
	mov ds,ax
	mov si,0
	call letterc
	
	mov ax,4c00h
	int 21h				;���ù��ܵ��÷���DOS

letterc:
	push ax
	push cx
	push si
	mov cx,0

s:	mov cl,[si]
	jcxz ok
	cmp cx,61h
	jb s1
	cmp cx,7Ah
	ja s1
	sub cl,20h
	mov [si],cl
s1:	inc si
	loop s

ok:	pop si
	pop cx
	pop ax
	ret

codesg	ends				;����ν���
	end start
					;��������ͬʱָ��������ʼ��