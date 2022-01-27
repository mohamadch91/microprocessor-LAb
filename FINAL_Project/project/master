PER EQU 0x400E0E00
SODR EQU 0x400E0E30
CODR EQU 0x400E0E34
OER EQU 0x400E0E10
PDSR EQU 0x400E0E3C
ISR EQU 0x400E0E4C
	
	AREA mycode, CODE, READONLY
	EXPORT __main
	ENTRY

__main
	LDR R4, =2_1111100000000000
	
	LDR R5,=PER
	STR R4, [R5]
	
	LDR R5,=OER
	STR R4, [R5]
	MOV R10, #1
	
loop
	; select slaves
	LDR R5, =ISR
	LDR R2, [R5]
	LDR R3, =2_11100000000
	AND R2, R2, R3 ; mask to get wanted bits
	LSL R2, R2, #5
	LDR R5, =SODR
	STR R2, [R5]
	MVN R2, R2 ; not
	LDR R3, =2_1110000000000000
	AND R2, R2, R3 ; again masking
	LDR R5, =CODR
	STR R2, [R5]
	
	; get keypad
	LDR R5, =ISR
	LDR R2, [R5]
	LDR R3, =2_11111111
	AND R2, R2, R3 ; mask to get keypad bits
	CMP R2, #2_01001000
	BEQ zero
	CMP R2, #2_10000100
	BEQ one
	CMP R2, #2_01000100
	BEQ two
	CMP R2, #2_00100100
	BEQ three
	CMP R2, #2_10000010
	BEQ four
	CMP R2, #2_01000010
	BEQ five
	CMP R2, #2_00100010
	BEQ six
	CMP R2, #2_10000001
	BEQ seven
	CMP R2, #2_01000001
	BEQ eight
	CMP R2, #2_00100001
	BEQ nine
settled
	
	; sending message
	CMP R9, #0
	BEQ clock ; no message
	CMP R9, #6
	BNE not_six ; these 4 lines only for when counter is 6
	LDR R2, =2_1000000000000
	LDR R5, =SODR
	STR R2, [R5]
	SUB R9, R9, #1
	B clock
not_six
	CMP R9, #1
	BNE not_six ; these 4 lines only for when counter is 1
	LDR R2, =2_1000000000000
	LDR R5, =CODR
	STR R2, [R5]
	SUB R9, R9, #1
	B clock
not_one
	ASR R1, R1, #1
	BCS send_high
	LDR R2, =2_1000000000000
	LDR R5, =CODR
	STR R2, [R5]
	SUB R9, R9, #1
	B clock
send_high
	LDR R2, =2_1000000000000
	LDR R5, =SODR
	STR R2, [R5]
	SUB R9, R9, #1
	
clock ;clock implementation
	CMP R10, #1
	BNE low
	LDR R2, =2_100000000000
	LDR R5, =SODR
	STR R2, [R5]
	MOV R10, #0
	B delay
low
	LDR R2, =2_100000000000
	LDR R5, =CODR
	STR R2, [R5]
	MOV R10, #1

delay
	MOV r4, #0
	LDR r5, =0x0000C00

loop_delay
	ADD r4,r4,#1
	
	CMP r4,r5
	BNE loop_delay
	
	B loop

; setting numbers ti R1 register
zero
	LDR R1, =0
	MOV R9, #6 ; counter
	B settled
one
	LDR R1, =1
	MOV R9, #6 ; counter
	B settled
two
	LDR R1, =2
	MOV R9, #6 ; counter
	B settled
three
	LDR R1, =3
	MOV R9, #6 ; counter
	B settled
four
	LDR R1, =4
	MOV R9, #6 ; counter
	B settled
five
	LDR R1, =5
	MOV R9, #6 ; counter
	B settled
six
	LDR R1, =6
	MOV R9, #6 ; counter
	B settled
seven
	LDR R1, =7
	MOV R9, #6 ; counter
	B settled
eight
	LDR R1, =8
	MOV R9, #6 ; counter
	B settled
nine
	LDR R1, =9
	MOV R9, #6 ; counter
	B settled
	
here B here
	END