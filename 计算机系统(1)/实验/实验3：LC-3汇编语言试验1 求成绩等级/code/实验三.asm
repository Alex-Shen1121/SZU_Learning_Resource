.ORIG		X3000
		AND	R0,R0,#0;
		AND	R1,R1,#0;
		AND	R2,R2,#0;
		AND	R3,R3,#0;
		AND 	R4,R4,#0;
		AND 	R5,R5,#0;
		AND 	R6,R6,#0;
		AND	R7,R7,#0;初始化寄存器

		ADD	R5,R5,#15;
		ADD	R5,R5,#1;外层循环16次
		LD	R2,SCORE2;指向存成绩空间
OUTLOOP		ADD	R6,R6,#15;内层循环15次
		LD	R3,SCORE;指针指向成绩	
		LDR	R0,R3,#0;假设第一位为最大值，存入R0
		NOT	R0,R0;
		ADD	R0,R0,#1;R0最大值求补数
LOOP1		ADD	R3,R3,#1;指针指向下一个数字	
		LDR	R1,R3,#0;R1存入对比数字
		ADD	R4,R0,R1;R1>R0，将R0设为新的最大值R1，否则继续
		BRp	SWAP;将最大值设置为当前查询数
		ADD	R6,R6,#-1;
		BRz	GOOUT;内层循环结束，跳出二层循环
		BRnzp	LOOP1;
SWAP		AND	R0,R0,#0;
		NOT	R1,R1;
		ADD	R1,R1,#1;R1最大值求补数
		ADD	R0,R0,R1;	
		ADD	R6,R6,#-1;
		BRz	GOOUT;内层循环结束，跳出二层循环	
		BRnzp	LOOP1;
GOOUT		LD	R7,SCORE;遍历成绩表，与最大值相等的数据设置为-1。
LOOP2		LDR	R1,R7,#0;
		ADD	R1,R1,R0;
		BRz	SET;
		ADD	R7,R7,#1;
		ADD	R1,R1,#0;
		BRnp	LOOP2;
SET		LD	R1,MINUS1;删除当前轮最大值（设置为-1）
		STR	R1,R7,#0;
		NOT	R0,R0;
		ADD	R0,R0,#1;R0为当前轮最大值
		ADD	R2,R2,#1;
		STR	R0,R2,#0;
		ADD	R7,R7,#1;
		ADD	R5,R5,#-1;
		BRp	OUTLOOP;	
		BRZ	END;


END		AND	R0,R0,#0;
		AND	R1,R1,#0;
		AND	R2,R2,#0;
		AND	R3,R3,#0;
		AND 	R4,R4,#0;
		AND 	R5,R5,#0;
		AND 	R6,R6,#0;
		AND	R7,R7,#0;初始化寄存器


	
		ADD	R1,R1,#4;遍历1-4名成绩，判断是否为A
		LD	R2,SCORE2;将指针指向第一名成绩
		ADD	R2,R2,#1;
		LD	R6,EIGHTYFIVE;R6存储-85

LOOP		LDR	R0,R2,#0;R0存储当前查询成绩
		ADD	R4,R0,R6;检查当前成绩是否大于绝对分数85分，若大于R5=1，小于R5=0
		BRzp	OVERABSOLUTE;
		AND	R5,R5,#0;
		BRnzp	NEXT2;
OVERABSOLUTE	AND	R5,R5,#0;
		ADD	R5,R5,#1;
NEXT2		ADD	R5,R5,#-1;R5等于1，条件满足，为A，等于0，条件不满足，进行下一轮测试
		BRn	NO;
YES		ADD	R7,R7,#1;R7记录A等人数，加一
		ADD	R2,R2,#1;指针指向下一位成绩
		ADD	R1,R1,#-1;循环次数减一
		BRp	LOOP;
		BRz	END1;
NO		ADD	R2,R2,#1;指针指向下一位成绩
		ADD	R1,R1,#-1;循环次数减一
		BRp	LOOP;
		BRz	END1;
END1		STI	R7,GRADEA;将R7数据存入x4100



		LD	R2,SCORE2;
		ADD	R2,R2,#1;
		ADD	R2,R2,R7;将指针指向第N+1名成绩
		NOT	R7,R7;
		ADD	R7,R7,#1;
		ADD	R7,R7,#8;
		AND	R1,R1,#0;
		ADD	R1,R1,R7;遍历N+1-8名成绩，判断是否为B,循环次数8-n存入R1		
		AND	R6,R6,#0;
		LD	R6,SEVENTYFIVE;R6存储-75
		AND	R7,R7,#0;人数统计归零

LOOP0		LDR	R0,R2,#0;R0存储当前查询成绩
		ADD	R4,R0,R6;检查当前成绩是否大于绝对分数75分，若大于R5=1，小于R5=0
		BRzp	OVERABSOLUTE1;
		AND	R5,R5,#0;
		BRnzp	NO1;
OVERABSOLUTE1	AND	R5,R5,#0;
		ADD	R5,R5,#1;
NEXT4		ADD	R5,R5,#-1;R5等于1，条件满足，为B，等于0，条件不满足，默认为C
		BRn	NO1;
YES1		ADD	R7,R7,#1;R7记录A等人数，加一
		ADD	R2,R2,#1;指针指向下一位成绩
		ADD	R1,R1,#-1;循环次数减一
		BRp	LOOP0;
		BRz	END2;
NO1		ADD	R2,R2,#1;指针指向下一位成绩
		ADD	R1,R1,#-1;循环次数减一
		BRp	LOOP0;
		BRz	END2;
END2		STI	R7,GRADEB;将R7数据存入x4101
 
HALT;
SCORE		.fill	x3200;
SCORE2		.FILL	X3FFF;
GRADEA		.fill	x4100;
GRADEB		.fill	x4101;
EIGHTYFIVE	.fill	#-85;
SEVENTYFIVE	.fill	#-75;
MINUS1		.FILL	#-1;
.END;