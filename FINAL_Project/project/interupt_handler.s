PER EQU 0x400E0E00
SODR EQU 0x400E0E30
CODR EQU 0x400E0E34
OER EQU 0x400E0E10
PDSR EQU 0x400E0E3C
ISR EQU 0x400E0E4C
IER EQU 0x400E0460
	
	AREA mycode, CODE, READONLY
	IMPORT __main
	EXPORT interupt_handler
	ENTRY
	
interupt_handler
	
	; check slave select
	LDR R2, [R5]
	LDR R3, =2_100000000000000000000
	AND R2, R2, R3
	CMP R2, R3
	BNE eend
	
	; check MOSI
	LDR R2, [R5]
	AND R2, R2, #2_10
	CMP R8, #0
	BNE get_data ; have data
	CMP R2, #2_10 ; dont have data so checks for data transfer start
	BNE eend ; dont have data
	MOV R8, #4 ; have data and make counter 4
	B eend
	
get_data
	CMP R2, #2_10
	BEQ high
	LSL R7, #1 ;data register
	SUB R8, R8, #1
	B check
high
	LSL R7, #1
	ADD R7, R7, #1
	SUB R8, R8, #1
	B check
	
check
	CMP R8, #0 ; check if getting data is finished
	BNE eend
	AND R7, R7, #2_1111 ; mask to get only the lower 4 bits
	CMP R7, #0
	BEQ zero
	CMP R7, #1
	BEQ one
	CMP R7, #2
	BEQ two
	CMP R7, #3
	BEQ three
	CMP R7, #4
	BEQ four
	CMP R7, #5
	BEQ five
	CMP R7, #6
	BEQ six
	CMP R7, #7
	BEQ seven
	CMP R7, #8
	BEQ eight
	CMP R7, #9
	BEQ nine
	
zero
	LDR R5, =CODR
	LDR R4, =2_111111100
	STR R4, [R5]
	LDR R5, =SODR
	LDR R4, =2_100000000
	STR R4, [R5]
	B eend
one
	LDR R5, =CODR
	LDR R4, =2_111111100
	STR R4, [R5]
	LDR R5, =SODR
	LDR R4, =2_100000000
	STR R4, [R5]
	B eend
two	LDR R5, =CODR
	LDR R4, =2_111111100
	STR R4, [R5]
	LDR R5, =SODR
	LDR R4, =2_100000000
	STR R4, [R5]
	B eend
three
	LDR R5, =CODR
	LDR R4, =2_111111100
	STR R4, [R5]
	LDR R5, =SODR
	LDR R4, =2_100000000
	STR R4, [R5]
	B eend
four
	LDR R5, =CODR
	LDR R4, =2_111111100
	STR R4, [R5]
	LDR R5, =SODR
	LDR R4, =2_100000000
	STR R4, [R5]
	B eend
five
	LDR R5, =CODR
	LDR R4, =2_111111100
	STR R4, [R5]
	LDR R5, =SODR
	LDR R4, =2_100000000
	STR R4, [R5]
	B eend
six
	LDR R5, =CODR
	LDR R4, =2_111111100
	STR R4, [R5]
	LDR R5, =SODR
	LDR R4, =2_100000000
	STR R4, [R5]
	B eend
seven
	LDR R5, =CODR
	LDR R4, =2_111111100
	STR R4, [R5]
	LDR R5, =SODR
	LDR R4, =2_100000000
	STR R4, [R5]
	B eend
eight
	LDR R5, =CODR
	LDR R4, =2_111111100
	STR R4, [R5]
	LDR R5, =SODR
	LDR R4, =2_100000000
	STR R4, [R5]
	B eend
nine
	LDR R5, =CODR
	LDR R4, =2_111111100
	STR R4, [R5]
	LDR R5, =SODR
	LDR R4, =2_100000000
	STR R4, [R5]
	B eend

eend
	BX lr
	END
	