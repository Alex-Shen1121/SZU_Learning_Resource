      .data
mes:  .asciiz "after sorting\n"
array: .word  73
       .word 27
       .word  55
       .word  25
       .word  89
       .word  36
       .word  63
       .word  99
       .word  78
       .word  16
len:  .word 10

DATA:    .word32 0x10008
CONTROL: .word32 0x10000


        .text
        daddi $t0,$zero,0
        ld r16,array($t0)
        daddi r17,$zero,2
        lwu $t3,DATA(r0)
        lwu $t4,CONTROL(r0) ; and control registers
        sd r16,0($t3)           ; write address of message to DATA register
        sd r17,0($t4)           ; make it happen
        ld $t1,len($zero)  # $t1 = len
        dsll $t1,$t1,3     # $t1 = len*8
        daddi $t0,$t0,8
loop1:  slt $t2,$t0,$t1    # i < len?
        beqz $t2,paixu       # yes - exit
        ld r16,array($t0)
        sd r16,0($t3)
        daddi $t0,$t0,8
        sd r17,0($t4)           ; make it happen
        j loop1

paixu:        
        daddi r16,r0,4       ; set for ascii output
        daddi r17,r0,mes
        sd r17,0($t3)           ; write address of message to DATA register
        sd r16,0($t4)           ; make it happen
        daddi $t0,$zero,8  # $t0 = i = 8

        
for:    slt $t2,$t0,$t1    # i < len?
        beqz $t2,out       # yes - exit
        dadd $t3,$zero,$t0 # $t3=j=i
        ld $t4,array($t0)  # $t4=B=a[i]
loop:   slt $t2,$zero,$t3  # j>0 ?
        beqz $t2,over      # no -exit
        daddi $t5,$t3,-8   # $t5=j-1
        ld $t6,array($t5)  # get $t6=a[j-1]
        slt $t2,$t6,$t4    # >B ?
        beqz $t2,over	 
        sd $t6,array($t3)  # a[j]=a[j-1]
        dadd $t3,$zero,$t5 # j--
        j loop

over:   sd $t4,array($t3)  # a[j] = B
        daddi $t0,$t0,8    # i++
        j for

out:        daddi $t0,$zero,0
        ld r16,array($t0)
        daddi r17,$zero,2
        lwu $t3,DATA(r0)
        lwu $t4,CONTROL(r0) ; and control registers
        sd r16,0($t3)           ; write address of message to DATA register
        sd r17,0($t4)           ; make it happen
        ld $t1,len($zero)  # $t1 = len
        dsll $t1,$t1,3     # $t1 = len*8
        daddi $t0,$t0,8
loop2:  slt $t2,$t0,$t1    # i < len?
        beqz $t2,out1       # yes - exit
        ld r16,array($t0)
        sd r16,0($t3)
        daddi $t0,$t0,8
        sd r17,0($t4)           ; make it happen
        j loop2
out1:    halt