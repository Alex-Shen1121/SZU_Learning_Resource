	.ORIG	x2000
	ADD	R6,R6,#-1		;������ѹ��ջ��
	STR	R0,R6,#0
	ADD	R6,R6,#-1
	STR	R1,R6,#0
	ADD	R6,R6,#-1
	STR	R2,R6,#0
	ADD	R6,R6,#-1
	STR	R3,R6,#0
	ADD	R6,R6,#-1
	STR	R4,R6,#0

	LD	R4,STRING		;IE:�ַ����׵�ַ
LOOP1	LDI	R1,KBSR			;������״̬
	BRZP	LOOP1
	LDI	R0,KBDR
	LD	R2,BREAK		;�ж��Ƿ�Ϊ�س�
	ADD	R2,R2,R0
	BRZ	LOOP			;�����������
	STR	R0,R4,#0		;����������ַ���
	ADD	R4,R4,#1
	BRNZP	LOOP1
LOOP	AND	R0,R0,#0		;���ַ���������س���Ϊ������ʶ
	ADD	R0,R0,#10
	STR	R0,R4,#0
NEXT1	AND	R3,R3,#0
	ADD	R3,R3,#10		;R3:������,ѭ��ʮ��
LOOP3	LD	R4,STRING
LOOP5	LDR	R0,R4,#0		;��ȡ�ַ���
	ADD	R4,R4,#1
LOOP4	LDI	R1,DSR			;�����ʾ��״̬
	BRZP	LOOP4
	LD	R2,BREAK		;�ж��Ƿ�Ϊ�س�
	ADD	R2,R2,R0
	BRZ	NEXT3			;���������һ��ѭ��
	STI	R0,DDR			;����������ַ�
	BRNZP	LOOP5
NEXT3	ADD	R3,R3,#-1
	BRP	LOOP3
NEXT2	LDR	R4,R6,#0		;��ջ��ȡ������

	ADD	R6,R6,#1
	LDR	R3,R6,#0
	ADD	R6,R6,#1
	LDR	R2,R6,#0
	ADD	R6,R6,#1
	LDR	R1,R6,#0
	ADD	R6,R6,#1
	LDR	R0,R6,#0
	ADD	R6,R6,#1
	RTI				;�ص��û�����

KBSR	.FILL	xFE00
KBDR	.FILL	xFE02
DSR	.FILL	xFE04
DDR	.FILL	xFE06
BREAK	.FILL	xFFF6			;-x000A
STRING	.FILL	x4000			;�ַ����׵�ַ
.END