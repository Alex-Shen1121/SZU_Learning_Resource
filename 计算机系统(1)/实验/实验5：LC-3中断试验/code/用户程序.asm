	.ORIG	x3000
	LD	R6,STACK		; initialize the stack pointer
	LD	R1,ENTRY1		; set up the keyboard interrupt vector table entry
	LD	R2,STARTS;
	STR	R2,R1,#0;
	LD	R3,IE			; enable keyboard interrupts
	STI	R3,KBSR; 
					;start of actual user program to print ICS checkerboard
AGAIN	LEA	R0,STR1;
	PUTS;
	JSR	DELAY;
	LEA	R0,STR2;
	PUTS;
	JSR	DELAY;
	BR	AGAIN;
	HALT;

ENTRY1	.FILL	X0180
STARTS	.FILL	X2000
STACK	.FILL	X3000
IE	.FILL	X4000
KBSR	.FILL	XFE00
STR1	.STRINGZ	"ICS ICS ICS ICS ICS ICS \n"
STR2	.STRINGZ	"  ICS ICS ICS ICS ICS ICS \n"

DELAY   ST  R1, SaveR1
        LD  R1, COUNT
REP     ADD R1,R1,#-1
        BRp REP
        LD  R1, SaveR1
        RET
COUNT   .FILL #2500
SaveR1  .BLKW 1

.END
