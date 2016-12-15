;
;P312 17.4      课程设计2 精简版        程序大小：212H-15H=1FDH(509.B)
;               全部使用已学指令        BY cutebe @ asmedu.net
;
;            不足：只完成了基本功能，小了没办法（有些确实占空间）
;               1、时间设置没有判断是否合法
;               2、时间设置时光标不跟随，也是为了省空间=_||
;               3、没有清屏程序
;               4、选中菜单没有高亮
;               5、没有判断代码长度，毕竟为了小于512嘛
;
ASSUME CS:CODE

CODE SEGMENT

ENTRY:
INSTALL:PUSH    CS              ;安装引导
        POP     ES
        MOV     BX,OFFSET BOOTMGR
        MOV     CX,0001H        ;磁道扇区（第1扇区）
        MOV     DX,0000H        ;碰头驱动
        MOV     AX,0301H        ;写入数量（共1个扇区）
        INT     13H

        MOV     AX,4C00H
        INT     21H             ;结束安装***


BOOTMGR:                        ;程序开始>>>
SHOWMENU:                       ;显示菜单项
        JMP     SHORT SHOWM
        MENU1   DB '1) reset pc',0              ;清单文字
        MENU2   DB '2) start system',0
        MENU3   DB '3) clock',0
        MENU4   DB '4) set clock',0
        ;TABLE  DW MENU1,MENU2,MENU3,MENU4      ;实际使用MENU1，这里精简

SHOWM:  PUSH    CS              ;原来想用INT 21H的9号功能，因为代码更少
        POP     DS              ;但不能显示，原来是DOS的中断，启动时只能用BIOS中断
        MOV     BX,OFFSET MENU1
        SUB     BX,OFFSET BOOTMGR-7C00H         ;安装时一定要变化的地方
        MOV     CX,0B800H
        MOV     ES,CX
        MOV     DH,11           ;头一个清单项位于第11行
        MOV     CX,4            ;清单数
MLIS:   MOV     AL,160
        MUL     DH
        ADD     AX,64           ;清单显示从列32开始
        MOV     DI,AX

SMS:    MOV     AL,[BX]
        INC     BX
        CMP     AL,0            ;一条清单结束标识
        JE      ENDSM
        MOV     ES:[DI],AX      ;逐个显示清单字符，颜色使用前面传下来的，未特别设置
        INC     DI
        INC     DI
        JMP     SHORT SMS
ENDSM:  ADD     DH,2            ;清单间相隔两行
        LOOP    MLIS            ;循环，下一清单


MENUCHOICE:                     ;清单选择
;        JMP     SHORT INPUTM    ;原用于清单选择高亮显示，精简
;        CHOOSE  DW RESET,HDDC,CLOCK,SETCLOCK
INPUTM: SUB     AH,AH
        INT     16H

NUM:    SUB     AH,AH
        CMP     AL,'1'          ;选1时跳到重启
        JE      RESET
        CMP     AL,'2'          ;选2时跳到原系统启动
        JE      HDDC

        CMP     AL,'3'          ;选3时调用时间显示
        JNE     INPUTCN
        CALL    CLOCK
        JMP     SHORT INPUTM
INPUTCN:CMP     AL,'4'          ;选4时调用时间设置
        JNE     INPUTM
        CALL    SETCLOCK
        ;CMP    AL,13           ;回车退出，实际程序要注释掉
        ;JE     CEND
        JMP     SHORT INPUTM
CEND:   ;NOP                    ;能省一个是一个


RESET:  DB      0EAH,0,0,0FFH,0FFH      ;精简方式5B，对应DEBUG中JMP FFFF:0000
        ;MOV    BP,SP                   ;重启 方法1
        ;MOV    WORD PTR [BP-2],0FFFFH
        ;MOV    WORD PTR [BP-4],0
        ;JMP    DWORD PTR [BP-4]

        ;MOV    AX,0FFFFH               ;重启 方法2
        ;MOV    DS,AX
        ;MOV    BX,1
        ;JMP    DWORD PTR [BX]
        ;RET


HDDC:   ;PUSH   CS              ;复制“读取程序”到 0000:0200 处，防止被覆盖
        ;POP    DS              ;精简方式中，检查后发现DS固定为0，可省
        MOV     SI,OFFSET READSEC
        SUB     SI,OFFSET BOOTMGR-7C00H
        ;SUB    AX,AX
        ;MOV    ES,AX           ;改用栈，省2字节（如下）
        PUSH    CS
        POP     ES
        MOV     DI,200H
        MOV     CX,OFFSET FINREAD-OFFSET READSEC
        CLD
        REP     MOVSB

        MOV     BX,200H
        JMP     BX              ;跳到读取磁盘处


READSEC:SUB     AX,AX           ;读取 C: 盘逻辑 0 扇区内容到 0000:7C00 处
        MOV     ES,AX
        MOV     BX,7C00H
        MOV     CX,0001H        ;磁道起始
        MOV     DX,0080H        ;磁头驱动
        MOV     AX,0201H        ;读取数量
        INT     13H
        MOV     BX,7C00H
        JMP     BX              ;跳到 0000:7C00 处执行，C: 盘引导
FINREAD:


INT9:   PUSH    AX              ;新INT9中断例程
        PUSH    BX
        PUSH    CX
        PUSH    ES
        PUSH    DI

        MOV     BX,0B800H
        MOV     ES,BX
        MOV     DI,6*160+(80-19)/2*2

        IN      AL,60H          ;键盘操作变颜色与返回，ESC 1，F1 3BH

        PUSHF
        CALL    DWORD PTR CS:[200H]

        CMP     AL,1            ;ESC，退出
        JE      ENDCF1
        CMP     AL,3BH          ;F1，改变显示时间的颜色
        JNE     ENDCF0
        MOV     CX,19
SDTC:   ADD     BYTE PTR ES:1[DI],1     ;颜色加1
        INC     DI
        INC     DI
        LOOP    SDTC
        JMP     SHORT ENDINT9

ENDCF1: MOV     BYTE PTR CS:[204H],1    ;结束时钟显示标识FLAG
        ;JMP    SHORT ENDINT9   ;直接到了，不用跳了^_^
ENDCF0:
ENDINT9:POP     DI
        POP     ES
        POP     CX
        POP     BX
        POP     AX
        IRET                    ;结束例程
FINT9:


CLOCK:  JMP     SHORT PREC              ;显示时间
        SIGN    DB '-','-',' ',':',':'  ;日期时间显示时的间隔符，放前面还省一字节呢^_^
        DTIME   DB 9,8,7,4,2,0
PREC:   PUSH    AX
        PUSH    BX
        PUSH    CX
        PUSH    DX
        PUSH    ES
        PUSH    DI

        ;PUSH   CS              ;安装INT9中断例程，实际中是改变一下中断向量
        ;POP    DS              ;向量可保存在程序开头，为了省点就辛苦一下200H吧
        MOV     CX,DS:[9*4+2]
        MOV     BX,DS:[9*4]
        MOV     DS:[202H],CX
        MOV     DS:[200H],BX
        ;PUSH   CS:[9*4+2]      ;CS换DS后与MOV机器码长度相同，任选一
        ;POP    CS:[202H]
        ;PUSH   CS:[9*4]
        ;POP    CS:[200H]

        MOV     BYTE PTR DS:[204H],0    ;初始化结束标识

        MOV     BX,OFFSET INT9
        SUB     BX,OFFSET BOOTMGR-7C00H
        CLI
        MOV     DS:[9*4+2],CS           ;更改向量指向新INT9
        MOV     DS:[9*4],BX
        STI

        MOV     AX,0B800H
        MOV     ES,AX
SHOWC:  MOV     DI,6*160+(80-19)/2*2

        CMP     BYTE PTR DS:[204H],1    ;检查结束标识
        JE      ENDT                    ;若有结束标识，表明按了ESC键，则退出时间显示程

序

        MOV     BYTE PTR ES:[DI],'2'    ;2
        MOV     BYTE PTR ES:2[DI],'0'   ;0

        SUB     BX,BX
        SUB     BX,OFFSET BOOTMGR-7C00H
        ADD     DI,4
DTNEXT: MOV     AL,DTIME[BX]
        OUT     70H,AL
        IN      AL,71H          ;读取端口

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
        CMP     CL,9            ;下个是9时循环
        JE      SHOWC
        MOV     ES:4[DI],CL
        ADD     DI,6
        INC     BX
        JMP     SHORT DTNEXT

ENDT:   ;PUSH   CS              ;卸载新INT9
        ;POP    DS
        MOV     CX,DS:[202H]
        MOV     BX,DS:[200H]
        CLI
        MOV     DS:[9*4+2],CX   ;还原向量
        MOV     DS:[9*4],BX
        ;STI                    ;省一个是一个

        POP     DI
        POP     ES
        POP     DX
        POP     CX
        POP     BX
        POP     AX
        RET


SETCLOCK:                       ;设置时间
        PUSH    AX
        PUSH    BX
        PUSH    CX
        PUSH    DX
        PUSH    ES
        PUSH    DI

        MOV     AX,0B800H
        MOV     ES,AX
        MOV     DI,8*160+32*2   ;8行32列
INPUTK: ;MOV    AX,DI
        ;MOV    DL,160
        ;DIV    DL
        ;MOV    DH,AL
        ;SHR    AH,1
        ;MOV    DL,AH           ;算出用于光标的行列

        ;MOV    AH,2            ;置光标，不得已而精简
        ;SUB    BH,BH           ;对于输入时不知道输到哪了，可以退格删除几个字符，就能看出来了。
        ;INT    10H

        SUB     AH,AH           ;接受输入
        INT     16H

        CMP     AL,13           ;ENTER
        JE      SETCK
        CMP     AL,8            ;BACKSPACE
        JE      BACKSPACEK
        CMP     AL,32           ;32-126为字符
        JB      INPUTK
        MOV     ES:[DI],AL      ;显示字符
        INC     DI
        INC     DI
        JMP     SHORT INPUTK
BACKSPACEK:
        CMP     DI,8*160+32*2   ;是否在开始输入位置
        JE      INPUTK
        DEC     DI
        DEC     DI
        MOV     BYTE PTR ES:[DI],' '    ;删除字符
        JMP     SHORT INPUTK
SETCK:  MOV     DI,8*160+32*2
        SUB     BX,BX
        SUB     BX,OFFSET BOOTMGR-7C00H
        MOV     CX,6
SETCKN: PUSH    CX              ;计数保存
        MOV     AH,ES:[DI]
        MOV     AL,ES:2[DI]
        SUB     AX,3030H
        MOV     CL,4
        SHL     AH,CL
        AND     AL,00001111B
        OR      AH,AL           ;AH暂存

        MOV     AL,DTIME[BX]    ;取得地址
        OUT     70H,AL
        MOV     AL,AH           ;修改时间
        OUT     71H,AL
        INC     BX
        ADD     DI,6
        POP     CX
        LOOP    SETCKN

        ;MOV    AH,2            ;置光标回原点
        ;SUB    BH,BH           ;置光标的都省了，就是不大好看了
        ;SUB    DX,DX
        ;INT    10H

        POP     DI
        POP     ES
        POP     DX
        POP     CX
        POP     BX
        POP     AX
        RET
FINBOOT:                ;完全结束标签，未用到。<<<程序结束

CODE ENDS

END ENTRY