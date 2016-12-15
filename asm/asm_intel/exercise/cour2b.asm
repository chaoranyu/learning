;
;P312 17.4      �γ����2 �����        �����С��212H-15H=1FDH(509.B)
;               ȫ��ʹ����ѧָ��        BY cutebe @ asmedu.net
;
;            ���㣺ֻ����˻������ܣ�С��û�취����Щȷʵռ�ռ䣩
;               1��ʱ������û���ж��Ƿ�Ϸ�
;               2��ʱ������ʱ��겻���棬Ҳ��Ϊ��ʡ�ռ�=_||
;               3��û����������
;               4��ѡ�в˵�û�и���
;               5��û���жϴ��볤�ȣ��Ͼ�Ϊ��С��512��
;
ASSUME CS:CODE

CODE SEGMENT

ENTRY:
INSTALL:PUSH    CS              ;��װ����
        POP     ES
        MOV     BX,OFFSET BOOTMGR
        MOV     CX,0001H        ;�ŵ���������1������
        MOV     DX,0000H        ;��ͷ����
        MOV     AX,0301H        ;д����������1��������
        INT     13H

        MOV     AX,4C00H
        INT     21H             ;������װ***


BOOTMGR:                        ;����ʼ>>>
SHOWMENU:                       ;��ʾ�˵���
        JMP     SHORT SHOWM
        MENU1   DB '1) reset pc',0              ;�嵥����
        MENU2   DB '2) start system',0
        MENU3   DB '3) clock',0
        MENU4   DB '4) set clock',0
        ;TABLE  DW MENU1,MENU2,MENU3,MENU4      ;ʵ��ʹ��MENU1�����ﾫ��

SHOWM:  PUSH    CS              ;ԭ������INT 21H��9�Ź��ܣ���Ϊ�������
        POP     DS              ;��������ʾ��ԭ����DOS���жϣ�����ʱֻ����BIOS�ж�
        MOV     BX,OFFSET MENU1
        SUB     BX,OFFSET BOOTMGR-7C00H         ;��װʱһ��Ҫ�仯�ĵط�
        MOV     CX,0B800H
        MOV     ES,CX
        MOV     DH,11           ;ͷһ���嵥��λ�ڵ�11��
        MOV     CX,4            ;�嵥��
MLIS:   MOV     AL,160
        MUL     DH
        ADD     AX,64           ;�嵥��ʾ����32��ʼ
        MOV     DI,AX

SMS:    MOV     AL,[BX]
        INC     BX
        CMP     AL,0            ;һ���嵥������ʶ
        JE      ENDSM
        MOV     ES:[DI],AX      ;�����ʾ�嵥�ַ�����ɫʹ��ǰ�洫�����ģ�δ�ر�����
        INC     DI
        INC     DI
        JMP     SHORT SMS
ENDSM:  ADD     DH,2            ;�嵥���������
        LOOP    MLIS            ;ѭ������һ�嵥


MENUCHOICE:                     ;�嵥ѡ��
;        JMP     SHORT INPUTM    ;ԭ�����嵥ѡ�������ʾ������
;        CHOOSE  DW RESET,HDDC,CLOCK,SETCLOCK
INPUTM: SUB     AH,AH
        INT     16H

NUM:    SUB     AH,AH
        CMP     AL,'1'          ;ѡ1ʱ��������
        JE      RESET
        CMP     AL,'2'          ;ѡ2ʱ����ԭϵͳ����
        JE      HDDC

        CMP     AL,'3'          ;ѡ3ʱ����ʱ����ʾ
        JNE     INPUTCN
        CALL    CLOCK
        JMP     SHORT INPUTM
INPUTCN:CMP     AL,'4'          ;ѡ4ʱ����ʱ������
        JNE     INPUTM
        CALL    SETCLOCK
        ;CMP    AL,13           ;�س��˳���ʵ�ʳ���Ҫע�͵�
        ;JE     CEND
        JMP     SHORT INPUTM
CEND:   ;NOP                    ;��ʡһ����һ��


RESET:  DB      0EAH,0,0,0FFH,0FFH      ;����ʽ5B����ӦDEBUG��JMP FFFF:0000
        ;MOV    BP,SP                   ;���� ����1
        ;MOV    WORD PTR [BP-2],0FFFFH
        ;MOV    WORD PTR [BP-4],0
        ;JMP    DWORD PTR [BP-4]

        ;MOV    AX,0FFFFH               ;���� ����2
        ;MOV    DS,AX
        ;MOV    BX,1
        ;JMP    DWORD PTR [BX]
        ;RET


HDDC:   ;PUSH   CS              ;���ơ���ȡ���򡱵� 0000:0200 ������ֹ������
        ;POP    DS              ;����ʽ�У�������DS�̶�Ϊ0����ʡ
        MOV     SI,OFFSET READSEC
        SUB     SI,OFFSET BOOTMGR-7C00H
        ;SUB    AX,AX
        ;MOV    ES,AX           ;����ջ��ʡ2�ֽڣ����£�
        PUSH    CS
        POP     ES
        MOV     DI,200H
        MOV     CX,OFFSET FINREAD-OFFSET READSEC
        CLD
        REP     MOVSB

        MOV     BX,200H
        JMP     BX              ;������ȡ���̴�


READSEC:SUB     AX,AX           ;��ȡ C: ���߼� 0 �������ݵ� 0000:7C00 ��
        MOV     ES,AX
        MOV     BX,7C00H
        MOV     CX,0001H        ;�ŵ���ʼ
        MOV     DX,0080H        ;��ͷ����
        MOV     AX,0201H        ;��ȡ����
        INT     13H
        MOV     BX,7C00H
        JMP     BX              ;���� 0000:7C00 ��ִ�У�C: ������
FINREAD:


INT9:   PUSH    AX              ;��INT9�ж�����
        PUSH    BX
        PUSH    CX
        PUSH    ES
        PUSH    DI

        MOV     BX,0B800H
        MOV     ES,BX
        MOV     DI,6*160+(80-19)/2*2

        IN      AL,60H          ;���̲�������ɫ�뷵�أ�ESC 1��F1 3BH

        PUSHF
        CALL    DWORD PTR CS:[200H]

        CMP     AL,1            ;ESC���˳�
        JE      ENDCF1
        CMP     AL,3BH          ;F1���ı���ʾʱ�����ɫ
        JNE     ENDCF0
        MOV     CX,19
SDTC:   ADD     BYTE PTR ES:1[DI],1     ;��ɫ��1
        INC     DI
        INC     DI
        LOOP    SDTC
        JMP     SHORT ENDINT9

ENDCF1: MOV     BYTE PTR CS:[204H],1    ;����ʱ����ʾ��ʶFLAG
        ;JMP    SHORT ENDINT9   ;ֱ�ӵ��ˣ���������^_^
ENDCF0:
ENDINT9:POP     DI
        POP     ES
        POP     CX
        POP     BX
        POP     AX
        IRET                    ;��������
FINT9:


CLOCK:  JMP     SHORT PREC              ;��ʾʱ��
        SIGN    DB '-','-',' ',':',':'  ;����ʱ����ʾʱ�ļ��������ǰ�滹ʡһ�ֽ���^_^
        DTIME   DB 9,8,7,4,2,0
PREC:   PUSH    AX
        PUSH    BX
        PUSH    CX
        PUSH    DX
        PUSH    ES
        PUSH    DI

        ;PUSH   CS              ;��װINT9�ж����̣�ʵ�����Ǹı�һ���ж�����
        ;POP    DS              ;�����ɱ����ڳ���ͷ��Ϊ��ʡ�������һ��200H��
        MOV     CX,DS:[9*4+2]
        MOV     BX,DS:[9*4]
        MOV     DS:[202H],CX
        MOV     DS:[200H],BX
        ;PUSH   CS:[9*4+2]      ;CS��DS����MOV�����볤����ͬ����ѡһ
        ;POP    CS:[202H]
        ;PUSH   CS:[9*4]
        ;POP    CS:[200H]

        MOV     BYTE PTR DS:[204H],0    ;��ʼ��������ʶ

        MOV     BX,OFFSET INT9
        SUB     BX,OFFSET BOOTMGR-7C00H
        CLI
        MOV     DS:[9*4+2],CS           ;��������ָ����INT9
        MOV     DS:[9*4],BX
        STI

        MOV     AX,0B800H
        MOV     ES,AX
SHOWC:  MOV     DI,6*160+(80-19)/2*2

        CMP     BYTE PTR DS:[204H],1    ;��������ʶ
        JE      ENDT                    ;���н�����ʶ����������ESC�������˳�ʱ����ʾ��

��

        MOV     BYTE PTR ES:[DI],'2'    ;2
        MOV     BYTE PTR ES:2[DI],'0'   ;0

        SUB     BX,BX
        SUB     BX,OFFSET BOOTMGR-7C00H
        ADD     DI,4
DTNEXT: MOV     AL,DTIME[BX]
        OUT     70H,AL
        IN      AL,71H          ;��ȡ�˿�

        MOV     AH,2
        MOV     DL,AL
        MOV     CL,4
        SHR     DL,CL
        ADD     DL,30H
        AND     AL,00001111B
        ADD     AL,30H
        MOV     ES:[DI],DL
        MOV     ES:2[DI],AL
        MOV     CL,SIGN[BX]
        CMP     CL,9            ;�¸���9ʱѭ��
        JE      SHOWC
        MOV     ES:4[DI],CL
        ADD     DI,6
        INC     BX
        JMP     SHORT DTNEXT

ENDT:   ;PUSH   CS              ;ж����INT9
        ;POP    DS
        MOV     CX,DS:[202H]
        MOV     BX,DS:[200H]
        CLI
        MOV     DS:[9*4+2],CX   ;��ԭ����
        MOV     DS:[9*4],BX
        ;STI                    ;ʡһ����һ��

        POP     DI
        POP     ES
        POP     DX
        POP     CX
        POP     BX
        POP     AX
        RET


SETCLOCK:                       ;����ʱ��
        PUSH    AX
        PUSH    BX
        PUSH    CX
        PUSH    DX
        PUSH    ES
        PUSH    DI

        MOV     AX,0B800H
        MOV     ES,AX
        MOV     DI,8*160+32*2   ;8��32��
INPUTK: ;MOV    AX,DI
        ;MOV    DL,160
        ;DIV    DL
        ;MOV    DH,AL
        ;SHR    AH,1
        ;MOV    DL,AH           ;������ڹ�������

        ;MOV    AH,2            ;�ù�꣬�����Ѷ�����
        ;SUB    BH,BH           ;��������ʱ��֪���䵽���ˣ������˸�ɾ�������ַ������ܿ������ˡ�
        ;INT    10H

        SUB     AH,AH           ;��������
        INT     16H

        CMP     AL,13           ;ENTER
        JE      SETCK
        CMP     AL,8            ;BACKSPACE
        JE      BACKSPACEK
        CMP     AL,32           ;32-126Ϊ�ַ�
        JB      INPUTK
        MOV     ES:[DI],AL      ;��ʾ�ַ�
        INC     DI
        INC     DI
        JMP     SHORT INPUTK
BACKSPACEK:
        CMP     DI,8*160+32*2   ;�Ƿ��ڿ�ʼ����λ��
        JE      INPUTK
        DEC     DI
        DEC     DI
        MOV     BYTE PTR ES:[DI],' '    ;ɾ���ַ�
        JMP     SHORT INPUTK
SETCK:  MOV     DI,8*160+32*2
        SUB     BX,BX
        SUB     BX,OFFSET BOOTMGR-7C00H
        MOV     CX,6
SETCKN: PUSH    CX              ;��������
        MOV     AH,ES:[DI]
        MOV     AL,ES:2[DI]
        SUB     AX,3030H
        MOV     CL,4
        SHL     AH,CL
        AND     AL,00001111B
        OR      AH,AL           ;AH�ݴ�

        MOV     AL,DTIME[BX]    ;ȡ�õ�ַ
        OUT     70H,AL
        MOV     AL,AH           ;�޸�ʱ��
        OUT     71H,AL
        INC     BX
        ADD     DI,6
        POP     CX
        LOOP    SETCKN

        ;MOV    AH,2            ;�ù���ԭ��
        ;SUB    BH,BH           ;�ù��Ķ�ʡ�ˣ����ǲ���ÿ���
        ;SUB    DX,DX
        ;INT    10H

        POP     DI
        POP     ES
        POP     DX
        POP     CX
        POP     BX
        POP     AX
        RET
FINBOOT:                ;��ȫ������ǩ��δ�õ���<<<�������

CODE ENDS

END ENTRY