		.ORIG X3000;
		AND	R1,R1,#0;
		ADD	R1,R1,#3;
		AND	R2,R2,#0;
		ADD	R2,R2,#5;
		AND	R3,R3,#0;
		ADD	R3,R3,#8;��ʼ��ʯ����Ŀ��r1��A,r2��B��r3��C
CONTINUE	JSR	PRINT;��ӡ����
		JSR	AINPUTDATA;���һ��������
		LD	R4,WINNERID;
		ADD	R4,R4,#-2;
		BRZ	WINNERISB;���ʤ���Ƿ���ѡ�ֶ�
		LD	R0,NEWLINE;
		OUT;			����
		JSR	PRINT;��ӡ����
		JSR	BINPUTDATA;���һ��������
		LD	R4,WINNERID;
		ADD	R4,R4,#-1;
		BRZ	WINNERISA;���ʤ���Ƿ���ѡ�ֶ�
		LD	R0,NEWLINE;
		OUT;			����
		BRNZP	CONTINUE;
WINNERISA	LD	R0,NEWLINE;
		OUT;
		LEA	R0,AWIN;
		PUTS;
		BRNZP	over;������A��ʤ��Ϣ
WINNERISB	LD	R0,NEWLINE;
		OUT;
		LEA	R0,BWIN;
		PUTS;
		BRNZP	over;������B��ʤ��Ϣ
over		HALT;
;�����������򲿷�





;�ӳ���1 ������� ����r1r2r3
PRINT	ST	R4,SAVER4;
	ST	R0,SAVER0;
	ST	R7,SAVER7;
	LEA	R4,ROWA;
	ADD	R0,R4,#0;
	PUTS;			���"ROWA:"		
	LD	R0,ASCofO;	׼�����o
	ADD	R4,R1,#0;	R4����������¼Aʯ������
	BRNZ	NEXT1;
OUTA	OUT;
	ADD	R4,R4,#-1;
	BRP	OUTA;
NEXT1	LD	R0,NEWLINE;
	OUT;			����

	LEA	R4,ROWB;
	ADD	R0,R4,#0;
	PUTS;			���"ROWB:"		
	LD	R0,ASCofO;	׼�����o
	ADD	R4,R2,#0;	R4����������¼Bʯ������
	BRNZ	NEXT2;
OUTB	OUT;
	ADD	R4,R4,#-1;
	BRP	OUTB;
NEXT2	LD	R0,NEWLINE;
	OUT;			����

LEA	R4,ROWC;
	ADD	R0,R4,#0;
	PUTS;			���"ROWC:"		
	LD	R0,ASCofO;	׼�����o
	ADD	R4,R3,#0;	R4����������¼Cʯ������
	BRNZ	NEXT3
OUTC	OUT;
	ADD	R4,R4,#-1;
	BRP	OUTC;
NEXT3	LD	R0,NEWLINE;
	OUT;			����
	
	LD	R4,SAVER4;
	LD	R0,SAVER0;
	LD	R7,SAVER7;
	RET;


;�ӳ���2 ���������һ��������������ʯ�Ӱ��ƣ�����r1r2r3
AINPUTDATA	ST	R0,SAVER0;	
		ST	R7,SAVER7;
		ST	R5,SAVER5;
		ST	R6,SAVER6;
AGAIN1		LEA	R0,PLAYER1;
		PUTS;
		GETC;������ĸָ��
		OUT;
		AND	R5,R5,#0;
		ADD	R5,R0,#0;����ĸASCII�븴�Ƶ�R5
		GETC;
		OUT;��������ָ��
		AND	R6,R6,#0;
		LD	R6,NUMASC;
		ADD	R6,R0,R6;�����ָ��Ƶ�R5
		LD	R0,NEWLINE;
		OUT;����
		ADD	R6,R6,#0;
		BRNZ	ERROR1;����С��0���������
		LD	R4,MINUSA;
		ADD	R4,R5,R4;��ĸABC��Ӧ0��1��2
		BRN	ERROR1;
		ADD	R4,R4,#-2;��ĸABC��Ӧ-2��-1��0
		BRP	ERROR1;��ĸ�������
		BRNZP	RIGHT1;�������������ȷ
		ERROR1	LEA	R0,TRYAGAIN;
		PUTS;���������Ϣ����������
		LD	R0,NEWLINE;
		OUT;����
		BRNZP	AGAIN1;������������
RIGHT1		ADD	R4,R6,#0;
		NOT	R4,R4;
		ADD	R4,R4,#1;R4����ȡ�෴��
		LD	R0,MINUSB;
		ADD	R0,R5,R0;R0����ĸ��ABC��Ӧ-1��0��1
		BRZP	A1;�����A��������������
		ADD	R7,R4,R1;
		BRN	ERROR1;�ж������Ƿ����ʣ��ʯͷ����
		ADD	R1,R7,#0;����Aʯ������
		BRZ	WIN111;�����º�Aʯ������Ϊ0�������Ϸ�Ƿ����
		BRNZP	JUMP1;
WIN111		AND	R7,R7,#0;
		ADD	R7,R7,R1;
		ADD	R7,R7,R2;
		ADD	R7,R7,R3;
		BRNP	JUMP1;
		AND	R4,R4,#0;
		ADD	R4,R4,#2;��ʣ��ʯͷ����Ϊ0������Ҷ�ʤ��
		ST	R4,WINNERID;
		BRNZP	JUMP1;
A1		ADD	R0,R0,#0;
		BRP	A2;�����B��������������
		ADD	R7,R4,R2;
		BRN	ERROR1;�ж������Ƿ����ʣ��ʯͷ����
		ADD	R2,R7,#0;����Bʯ������
		BRZ	WIN111;�����º�Bʯ������Ϊ0�������Ϸ�Ƿ����
		BRNZP	JUMP1;
A2		ADD	R7,R4,R3;
		BRN	ERROR1;�ж������Ƿ����ʣ��ʯͷ����
		ADD	R3,R7,#0;����Cʯ������
		BRZ	WIN111;�����º�Cʯ������Ϊ0�������Ϸ�Ƿ����
		BRNZP	JUMP1;
JUMP1		LD	R0,SAVER0;
		LD	R5,SAVER5;
		LD	R6,SAVER6;
		LD	R7,SAVER7;
		RET;

;�ӳ���3 ��������Ҷ���������������ʯ�Ӱ��ƣ�����r1r2r3
BINPUTDATA	ST	R0,SAVER0;	
		ST	R7,SAVER7;
		ST	R5,SAVER5;
		ST	R6,SAVER6;
AGAIN2		LEA	R0,PLAYER2;
		PUTS;
		GETC;������ĸָ��
		OUT;
		AND	R5,R5,#0;
		ADD	R5,R0,#0;����ĸASCII�븴�Ƶ�R5
		GETC;
		OUT;��������ָ��
		AND	R6,R6,#0;
		LD	R6,NUMASC;
		ADD	R6,R0,R6;�����ָ��Ƶ�R5
		LD	R0,NEWLINE;
		OUT;����
		ADD	R6,R6,#0;
		BRNZ	ERROR2;����С��0���������
		LD	R4,MINUSA;
		ADD	R4,R5,R4;��ĸABC��Ӧ0��1��2
		BRN	ERROR2;
		ADD	R4,R4,#-2;��ĸABC��Ӧ-2��-1��0
		BRP	ERROR2;��ĸ�������
		BRNZP	RIGHT2;�������������ȷ
ERROR2		LEA	R0,TRYAGAIN;
		PUTS;���������Ϣ����������
		LD	R0,NEWLINE;
		OUT;����
		BRNZP	AGAIN2;������������
RIGHT2		ADD	R4,R6,#0;
		NOT	R4,R4;
		ADD	R4,R4,#1;R4����ȡ�෴��
		LD	R0,MINUSB;
		ADD	R0,R5,R0;R0����ĸ��ABC��Ӧ-1��0��1
		BRZP	B;�����A��������������
		ADD	R7,R4,R1;
		BRN	ERROR2;�ж������Ƿ����ʣ��ʯͷ����
		ADD	R1,R7,#0;����Aʯ������
		BRZ	WIN112;�����º�Aʯ������Ϊ0�������Ϸ�Ƿ����
		BRNZP	JUMP2;
WIN112		AND	R7,R7,#0;
		ADD	R7,R7,R1;
		ADD	R7,R7,R2;
		ADD	R7,R7,R3;
		BRNP	JUMP2;
		AND	R4,R4,#0;
		ADD	R4,R4,#1;��ʣ��ʯͷ����Ϊ0�������һʤ��
		ST	R4,WINNERID;
		BRNZP	JUMP2;
B		ADD	R0,R0,#0;
		BRP	B2;�����B��������������
		ADD	R7,R4,R2;
		BRN	ERROR2;�ж������Ƿ����ʣ��ʯͷ����
		ADD	R2,R7,#0;����Bʯ������
		BRZ	WIN111;�����º�Bʯ������Ϊ0�������Ϸ�Ƿ����
		BRNZP	JUMP2;
B2		ADD	R7,R4,R3;
		BRN	ERROR2;�ж������Ƿ����ʣ��ʯͷ����
		ADD	R3,R7,#0;����Cʯ������
		BRZ	WIN112;�����º�Cʯ������Ϊ0�������Ϸ�Ƿ����
		BRNZP	JUMP2;
JUMP2		LD	R0,SAVER0;
		LD	R5,SAVER5;
		LD	R6,SAVER6;
		LD	R7,SAVER7;
		RET;


WINNERID	.BLKW		1;
MINUSA		.FILL		XFFBF;
MINUSB		.FILL		XFFBE
NEWLINE		.FILL		X000A;
ASCofO		.FILL		X006F;
SAVER0		.FILL		X0;
SAVER4		.FILL		X0;
SAVER5		.FILL		X0;
SAVER6		.FILL		X0;
SAVER7		.FILL		X0;
NUMASC		.FILL		XFFD0;
AWIN		.STRINGZ	"PLAYER 1 Wins.";
BWIN		.STRINGZ	"Player 2 Wins.";
ROWA		.STRINGZ	"ROW A:";
ROWB		.STRINGZ	"ROW B:";
ROWC		.STRINGZ	"ROW C:";
TRYAGAIN	.STRINGZ	"Invalid move. Try again.";
PLAYER1		.STRINGZ	"Player 1, choose a row and number of rocks:";
PLAYER2		.STRINGZ	"Player 2, choose a row and number of rocks:";
.END;