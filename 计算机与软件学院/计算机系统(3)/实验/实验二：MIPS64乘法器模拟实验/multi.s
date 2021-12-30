.data
CONTROL:    .word 0x10000
DATA:       .word 0x10008
NUM1:       .word 0
NUM2:       .word 0
STACKBOTTOM:   .space 20
STACKTOP:       .word 0
OFSTR:      .asciiz "warning: result overflow\n"
STR:        .asciiz "please enter two numbers:\n"
RES:        .asciiz "result:\n"

.text
main:
    daddi $sp, $zero, STACKTOP  # 创建栈
 
    daddi $a0, $zero, STR       # 打印输入提示
    jal printStr

    daddi $a0, $zero, NUM1      # 读入num1
    jal readInt

    daddi $a0, $zero, NUM2      # 读入num2
    jal readInt

    daddi $a0, $zero, RES       # 打印结果提示
    jal printStr

    daddi $s0, $zero, 32    # s0 = i
    lw $s1, NUM1($zero)     # s1 = num1
    lw $s2, NUM2($zero)     # s2 = num2

loop:
    beq $s0, $zero, end
    daddi $s0, $s0, -1

    andi $s3, $s1, 1        # s3 = 被乘数的最后一位
    beq $s3, $zero, notadd  # 最后一位 = 0 --> not add

    dadd $s4, $s4, $s2      # ans += s2
notadd:
    dsll $s2, $s2, 1        # s3<<1
    dsrl $s1, $s1, 1        # s1>>1
    
    j loop
end:
    daddi $a0, $s4, 0       # 输出s4
    jal printInt

    # 溢出检测
    dsrl $s4, $s4, 8        # 高32位
    dsrl $s4, $s4, 8        
    dsrl $s4, $s4, 8        
    dsrl $s4, $s4, 8        
    beq $s4, $zero, halt    # 高32位 = 0 --> halt
    daddi $a0, $zero, OFSTR # 输出溢出警告
    jal printStr
halt:
    halt 

#   @function readInt   : 读入一个int
#   @param arg0         : int的地址
#   @return             : ----
readInt:
    daddi $sp, $sp, -4  # 创建栈
    sw $ra, ($sp)       # 保存返回地址

    daddi $t0, $zero, 8     # t0 = 8
    lw $t1, DATA($zero)     # t1 = 0x10008
    lw $t2, CONTROL($zero)  # t2 = 0x10000
    sw $t0, ($t2)           # CONTROL = 8
    lw $t1, ($t1)           # t1 = DATA
    sw $t1, ($a0)           # M[arg0] = DATA

    lw $ra, ($sp)       # 恢复返回地址
    daddi $sp, $sp, 4   # 退栈
    jr $ra

#   @function printInt  :
#   @param arg0         : 打印的int的地址
#   @return             : ----
printInt:
    daddi $sp, $sp, -4  # sp -= 4
    sw $ra, ($sp)       # 保存返回地址

    daddi $t0, $zero, 2     # t0 = 2
    lw $t1, DATA($zero)     # t1 = 0x10008
    lw $t2, CONTROL($zero)  # t2 = 0x10000
    sw $a0, ($t1)           # DATA = arg0
    sw $t0, ($t2)           # CONTROL = 2

    lw $ra, ($sp)       # 恢复返回地址
    daddi $sp, $sp, 4   # sp += 4
    jr $ra              # return

#   @function printStr  :
#   @param a0           : 字符串地址
#   @return             : ----
printStr:
    daddi $sp, $sp, -4      # sp -= 4
    sw $ra, ($sp)           # 保存返回地址
    daddi $t0, $zero, 4     # t0 = 4
    dadd $t1, $zero, $a0    # t1 = arg0
    lw $t2, DATA($zero)     # t2 = M[DATA] = 0x10008
    lw $t3, CONTROL($zero)  # t3 = M[CONTROL] = 0x10000
    sw $t1, ($t2)           # M[0x10008] = t1 = arg0
    sw $t0, ($t3)           # M[0x10000] = t0 = 4
    lw $ra, ($sp)           # 恢复返回地址
    daddi $sp, $sp, 4       # sp += 4
    jr $ra                  # return

