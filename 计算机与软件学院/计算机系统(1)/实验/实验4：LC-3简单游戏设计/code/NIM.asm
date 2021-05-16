		.ORIG X3000;
		AND	R1,R1,#0;
		ADD	R1,R1,#3;
		AND	R2,R2,#0;
		ADD	R2,R2,#5;
		AND	R3,R3,#0;
		ADD	R3,R3,#8;初始化石子数目，r1存A,r2存B，r3存C
CONTINUE	JSR	PRINT;打印棋盘
		JSR	AINPUTDATA;玩家一输入数据
		LD	R4,WINNERID;
		ADD	R4,R4,#-2;
		BRZ	WINNERISB;检查胜者是否是选手二
		LD	R0,NEWLINE;
		OUT;			换行
		JSR	PRINT;打印棋盘
		JSR	BINPUTDATA;玩家一输入数据
		LD	R4,WINNERID;
		ADD	R4,R4,#-1;
		BRZ	WINNERISA;检查胜者是否是选手二
		LD	R0,NEWLINE;
		OUT;			换行
		BRNZP	CONTINUE;
WINNERISA	LD	R0,NEWLINE;
		OUT;
		LEA	R0,AWIN;
		PUTS;
		BRNZP	over;输出玩家A获胜信息
WINNERISB	LD	R0,NEWLINE;
		OUT;
		LEA	R0,BWIN;
		PUTS;
		BRNZP	over;输出玩家B获胜信息
over		HALT;
;以上是主程序部分





;子程序1 输出棋盘 参数r1r2r3
PRINT	ST	R4,SAVER4;
	ST	R0,SAVER0;
	ST	R7,SAVER7;
	LEA	R4,ROWA;
	ADD	R0,R4,#0;
	PUTS;			输出"ROWA:"		
	LD	R0,ASCofO;	准备输出o
	ADD	R4,R1,#0;	R4计数器，记录A石子数量
	BRNZ	NEXT1;
OUTA	OUT;
	ADD	R4,R4,#-1;
	BRP	OUTA;
NEXT1	LD	R0,NEWLINE;
	OUT;			换行

	LEA	R4,ROWB;
	ADD	R0,R4,#0;
	PUTS;			输出"ROWB:"		
	LD	R0,ASCofO;	准备输出o
	ADD	R4,R2,#0;	R4计数器，记录B石子数量
	BRNZ	NEXT2;
OUTB	OUT;
	ADD	R4,R4,#-1;
	BRP	OUTB;
NEXT2	LD	R0,NEWLINE;
	OUT;			换行

LEA	R4,ROWC;
	ADD	R0,R4,#0;
	PUTS;			输出"ROWC:"		
	LD	R0,ASCofO;	准备输出o
	ADD	R4,R3,#0;	R4计数器，记录C石子数量
	BRNZ	NEXT3
OUTC	OUT;
	ADD	R4,R4,#-1;
	BRP	OUTC;
NEXT3	LD	R0,NEWLINE;
	OUT;			换行
	
	LD	R4,SAVER4;
	LD	R0,SAVER0;
	LD	R7,SAVER7;
	RET;


;子程序2 作用是玩家一输入操作数，完成石子搬移，参数r1r2r3
AINPUTDATA	ST	R0,SAVER0;	
		ST	R7,SAVER7;
		ST	R5,SAVER5;
		ST	R6,SAVER6;
AGAIN1		LEA	R0,PLAYER1;
		PUTS;
		GETC;接受字母指令
		OUT;
		AND	R5,R5,#0;
		ADD	R5,R0,#0;将字母ASCII码复制到R5
		GETC;
		OUT;接受数字指令
		AND	R6,R6,#0;
		LD	R6,NUMASC;
		ADD	R6,R0,R6;将数字复制到R5
		LD	R0,NEWLINE;
		OUT;换行
		ADD	R6,R6,#0;
		BRNZ	ERROR1;数字小于0，输入错误
		LD	R4,MINUSA;
		ADD	R4,R5,R4;字母ABC对应0，1，2
		BRN	ERROR1;
		ADD	R4,R4,#-2;字母ABC对应-2，-1，0
		BRP	ERROR1;字母输入错误
		BRNZP	RIGHT1;满足两项，输入正确
		ERROR1	LEA	R0,TRYAGAIN;
		PUTS;输出错误信息，重新输入
		LD	R0,NEWLINE;
		OUT;换行
		BRNZP	AGAIN1;返回重新输入
RIGHT1		ADD	R4,R6,#0;
		NOT	R4,R4;
		ADD	R4,R4,#1;R4数字取相反数
		LD	R0,MINUSB;
		ADD	R0,R5,R0;R0存字母，ABC对应-1，0，1
		BRZP	A1;如果是A继续，否则跳过
		ADD	R7,R4,R1;
		BRN	ERROR1;判断数字是否大于剩余石头数量
		ADD	R1,R7,#0;更新A石堆数量
		BRZ	WIN111;若更新后A石堆数量为0，检查游戏是否结束
		BRNZP	JUMP1;
WIN111		AND	R7,R7,#0;
		ADD	R7,R7,R1;
		ADD	R7,R7,R2;
		ADD	R7,R7,R3;
		BRNP	JUMP1;
		AND	R4,R4,#0;
		ADD	R4,R4,#2;若剩余石头数量为0，则玩家二胜利
		ST	R4,WINNERID;
		BRNZP	JUMP1;
A1		ADD	R0,R0,#0;
		BRP	A2;如果是B继续，否则跳过
		ADD	R7,R4,R2;
		BRN	ERROR1;判断数字是否大于剩余石头数量
		ADD	R2,R7,#0;更新B石堆数量
		BRZ	WIN111;若更新后B石堆数量为0，检查游戏是否结束
		BRNZP	JUMP1;
A2		ADD	R7,R4,R3;
		BRN	ERROR1;判断数字是否大于剩余石头数量
		ADD	R3,R7,#0;更新C石堆数量
		BRZ	WIN111;若更新后C石堆数量为0，检查游戏是否结束
		BRNZP	JUMP1;
JUMP1		LD	R0,SAVER0;
		LD	R5,SAVER5;
		LD	R6,SAVER6;
		LD	R7,SAVER7;
		RET;

;子程序3 作用是玩家二输入操作数，完成石子搬移，参数r1r2r3
BINPUTDATA	ST	R0,SAVER0;	
		ST	R7,SAVER7;
		ST	R5,SAVER5;
		ST	R6,SAVER6;
AGAIN2		LEA	R0,PLAYER2;
		PUTS;
		GETC;接受字母指令
		OUT;
		AND	R5,R5,#0;
		ADD	R5,R0,#0;将字母ASCII码复制到R5
		GETC;
		OUT;接受数字指令
		AND	R6,R6,#0;
		LD	R6,NUMASC;
		ADD	R6,R0,R6;将数字复制到R5
		LD	R0,NEWLINE;
		OUT;换行
		ADD	R6,R6,#0;
		BRNZ	ERROR2;数字小于0，输入错误
		LD	R4,MINUSA;
		ADD	R4,R5,R4;字母ABC对应0，1，2
		BRN	ERROR2;
		ADD	R4,R4,#-2;字母ABC对应-2，-1，0
		BRP	ERROR2;字母输入错误
		BRNZP	RIGHT2;满足两项，输入正确
ERROR2		LEA	R0,TRYAGAIN;
		PUTS;输出错误信息，重新输入
		LD	R0,NEWLINE;
		OUT;换行
		BRNZP	AGAIN2;返回重新输入
RIGHT2		ADD	R4,R6,#0;
		NOT	R4,R4;
		ADD	R4,R4,#1;R4数字取相反数
		LD	R0,MINUSB;
		ADD	R0,R5,R0;R0存字母，ABC对应-1，0，1
		BRZP	B;如果是A继续，否则跳过
		ADD	R7,R4,R1;
		BRN	ERROR2;判断数字是否大于剩余石头数量
		ADD	R1,R7,#0;更新A石堆数量
		BRZ	WIN112;若更新后A石堆数量为0，检查游戏是否结束
		BRNZP	JUMP2;
WIN112		AND	R7,R7,#0;
		ADD	R7,R7,R1;
		ADD	R7,R7,R2;
		ADD	R7,R7,R3;
		BRNP	JUMP2;
		AND	R4,R4,#0;
		ADD	R4,R4,#1;若剩余石头数量为0，则玩家一胜利
		ST	R4,WINNERID;
		BRNZP	JUMP2;
B		ADD	R0,R0,#0;
		BRP	B2;如果是B继续，否则跳过
		ADD	R7,R4,R2;
		BRN	ERROR2;判断数字是否大于剩余石头数量
		ADD	R2,R7,#0;更新B石堆数量
		BRZ	WIN111;若更新后B石堆数量为0，检查游戏是否结束
		BRNZP	JUMP2;
B2		ADD	R7,R4,R3;
		BRN	ERROR2;判断数字是否大于剩余石头数量
		ADD	R3,R7,#0;更新C石堆数量
		BRZ	WIN112;若更新后C石堆数量为0，检查游戏是否结束
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