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
	push si
	
s:	cmp byte ptr ds:[si],0
	je ok
	cmp byte ptr [si],61h
	jb s1
	cmp byte ptr [si],7Ah
	ja s1
	and byte ptr [si],11011111b
s1:	inc si
	loop s

ok:	pop si
	ret

codesg	ends				;����ν���
	end start
					;��������ͬʱָ��������ʼ��