.ORIG x3000
AND R1,R1,x0 ;清R1, 用来存放运行总和
AND R4,R4,x0 ;清R4, 用来作为一个计数器
ADD R4,R4,xA ; 用#10装载R4, 添加的次数
LEA R2,x0FC ; 装载数据的起始地址
LOOP LDR R3,R2,x0 ; 装载下一个数被相加
ADD R2,R2,x1 ; 递增指针
ADD R1,R1,R3 ; 添加下一个数到运行总和
ADD R4,R4,x-1 ; 递减计数器
BRP LOOP  ; 如果计数器不为零，继续做
HALT  ;停止
.END  