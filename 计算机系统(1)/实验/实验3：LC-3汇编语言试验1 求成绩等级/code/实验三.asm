.ORIG		X3000
		AND	R0,R0,#0;
		AND	R1,R1,#0;
		AND	R2,R2,#0;
		AND	R3,R3,#0;
		AND 	R4,R4,#0;
		AND 	R5,R5,#0;
		AND 	R6,R6,#0;
		AND	R7,R7,#0;��ʼ���Ĵ���

		ADD	R5,R5,#15;
		ADD	R5,R5,#1;���ѭ��16��
		LD	R2,SCORE2;ָ���ɼ��ռ�
OUTLOOP		ADD	R6,R6,#15;�ڲ�ѭ��15��
		LD	R3,SCORE;ָ��ָ��ɼ�	
		LDR	R0,R3,#0;�����һλΪ���ֵ������R0
		NOT	R0,R0;
		ADD	R0,R0,#1;R0���ֵ����
LOOP1		ADD	R3,R3,#1;ָ��ָ����һ������	
		LDR	R1,R3,#0;R1����Ա�����
		ADD	R4,R0,R1;R1>R0����R0��Ϊ�µ����ֵR1���������
		BRp	SWAP;�����ֵ����Ϊ��ǰ��ѯ��
		ADD	R6,R6,#-1;
		BRz	GOOUT;�ڲ�ѭ����������������ѭ��
		BRnzp	LOOP1;
SWAP		AND	R0,R0,#0;
		NOT	R1,R1;
		ADD	R1,R1,#1;R1���ֵ����
		ADD	R0,R0,R1;	
		ADD	R6,R6,#-1;
		BRz	GOOUT;�ڲ�ѭ����������������ѭ��	
		BRnzp	LOOP1;
GOOUT		LD	R7,SCORE;�����ɼ��������ֵ��ȵ���������Ϊ-1��
LOOP2		LDR	R1,R7,#0;
		ADD	R1,R1,R0;
		BRz	SET;
		ADD	R7,R7,#1;
		ADD	R1,R1,#0;
		BRnp	LOOP2;
SET		LD	R1,MINUS1;ɾ����ǰ�����ֵ������Ϊ-1��
		STR	R1,R7,#0;
		NOT	R0,R0;
		ADD	R0,R0,#1;R0Ϊ��ǰ�����ֵ
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
		AND	R7,R7,#0;��ʼ���Ĵ���


	
		ADD	R1,R1,#4;����1-4���ɼ����ж��Ƿ�ΪA
		LD	R2,SCORE2;��ָ��ָ���һ���ɼ�
		ADD	R2,R2,#1;
		LD	R6,EIGHTYFIVE;R6�洢-85

LOOP		LDR	R0,R2,#0;R0�洢��ǰ��ѯ�ɼ�
		ADD	R4,R0,R6;��鵱ǰ�ɼ��Ƿ���ھ��Է���85�֣�������R5=1��С��R5=0
		BRzp	OVERABSOLUTE;
		AND	R5,R5,#0;
		BRnzp	NEXT2;
OVERABSOLUTE	AND	R5,R5,#0;
		ADD	R5,R5,#1;
NEXT2		ADD	R5,R5,#-1;R5����1���������㣬ΪA������0�����������㣬������һ�ֲ���
		BRn	NO;
YES		ADD	R7,R7,#1;R7��¼A����������һ
		ADD	R2,R2,#1;ָ��ָ����һλ�ɼ�
		ADD	R1,R1,#-1;ѭ��������һ
		BRp	LOOP;
		BRz	END1;
NO		ADD	R2,R2,#1;ָ��ָ����һλ�ɼ�
		ADD	R1,R1,#-1;ѭ��������һ
		BRp	LOOP;
		BRz	END1;
END1		STI	R7,GRADEA;��R7���ݴ���x4100



		LD	R2,SCORE2;
		ADD	R2,R2,#1;
		ADD	R2,R2,R7;��ָ��ָ���N+1���ɼ�
		NOT	R7,R7;
		ADD	R7,R7,#1;
		ADD	R7,R7,#8;
		AND	R1,R1,#0;
		ADD	R1,R1,R7;����N+1-8���ɼ����ж��Ƿ�ΪB,ѭ������8-n����R1		
		AND	R6,R6,#0;
		LD	R6,SEVENTYFIVE;R6�洢-75
		AND	R7,R7,#0;����ͳ�ƹ���

LOOP0		LDR	R0,R2,#0;R0�洢��ǰ��ѯ�ɼ�
		ADD	R4,R0,R6;��鵱ǰ�ɼ��Ƿ���ھ��Է���75�֣�������R5=1��С��R5=0
		BRzp	OVERABSOLUTE1;
		AND	R5,R5,#0;
		BRnzp	NO1;
OVERABSOLUTE1	AND	R5,R5,#0;
		ADD	R5,R5,#1;
NEXT4		ADD	R5,R5,#-1;R5����1���������㣬ΪB������0�����������㣬Ĭ��ΪC
		BRn	NO1;
YES1		ADD	R7,R7,#1;R7��¼A����������һ
		ADD	R2,R2,#1;ָ��ָ����һλ�ɼ�
		ADD	R1,R1,#-1;ѭ��������һ
		BRp	LOOP0;
		BRz	END2;
NO1		ADD	R2,R2,#1;ָ��ָ����һλ�ɼ�
		ADD	R1,R1,#-1;ѭ��������һ
		BRp	LOOP0;
		BRz	END2;
END2		STI	R7,GRADEB;��R7���ݴ���x4101
 
HALT;
SCORE		.fill	x3200;
SCORE2		.FILL	X3FFF;
GRADEA		.fill	x4100;
GRADEB		.fill	x4101;
EIGHTYFIVE	.fill	#-85;
SEVENTYFIVE	.fill	#-75;
MINUS1		.FILL	#-1;
.END;