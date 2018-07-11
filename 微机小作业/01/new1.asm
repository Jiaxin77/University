DATA	SEGMENT
A		DW 100,30,78,99,15,-1,66,54,189,256
A_TYPE 	EQU 2
A_COUNT EQU 10
DATA 	ENDS
CODE 	SEGMENT
		ASSUME CS:CODE,DS:DATA
START:	MOV AX,DATA
		MOV DS,AX	;DS指向DATA段
					;以下将数组A从大到小排序
		MOV CX,A_COUNT-1
					;外层循环次数是数组个数减1
LOOP1:	MOV DI,CX	;保存循环次数以免被内层循环破坏
					;内层循环次数正好与外层循环次数相同，无须初始化CX
		MOV BX,0    ;内层循环的初始状态，从头开始
LOOP2:	MOV AX,A[BX]
		CMP AX,A[BX+2];同后面一个数比较
		JGE CONT1
		XCHG AX,A[BX+2];小于后面一个数则交换
		MOV A[BX],AX
CONT1:	ADD BX,A_TYPE;下一个数的下标
		LOOP LOOP2
		MOV CX,DI	;恢复外层循环次数
		LOOP LOOP1
		;
		MOV AX,4C00H
		INT 21H		;返回操作系统
CODE	ENDS
		END START
		