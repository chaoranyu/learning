;----------------------------------------------------------
;版权信息：
;作者信息：
;编制日期：
;程序功能：
;
;
;使用方法：
;
;入口信息：
;
;出口信息：
;
;版本信息：
;----------------------------------------------------------
;修改信息：（对应版本，修改日期，修改者，修改原因，修改位置）
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
	int 21h				;利用功能调用返回DOS

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

codesg	ends				;代码段结束
	end start
					;汇编结束，同时指明程序起始点