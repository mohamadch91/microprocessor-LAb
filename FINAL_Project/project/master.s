		AREA MY_DATA,DATA
PIO_PER equ  0x400E0E00	
PIO_SODR equ 0x400E0E30
PIO_CODR equ 0x400E0E34
PIO_OER equ  0x400E0E10 
PIO_PDSR equ 0x400E0E3C
PIO_ISR equ  0x400E0E4C
		area master, code, readonly
		export __main
		entry
__main
	mov R12,#1 ;counter for clock
	LDR R4, =2_1111100000000000
	LDR R5,=PIO_PER ;enable pio
	STR R4, [R5]
	LDR R5,=PIO_OER ;here enable out put register
	STR R4, [R5]

loop
	; select slaves
	LDR R5, =PIO_ISR ;interupt service routin selector
	LDR R2, [R5]
	LDR R3, =2_111000 ; and with this to see which logix gate is on 
	AND R2, R2, R3 ;check digits with and
	LSL R2, R2, #22
	LDR R5, =PIO_SODR
	STR R2, [R5]
	MVN R2, R2 ; not register 2
	LDR R3, =2_1110000000000000000000000
	AND R2, R2, R3 ; check digits again for new values
	LDR R5, =PIO_CODR ; enable and clear register
	STR R2, [R5]
	; check which key pad num is pushed
	LDR R5, =PIO_ISR
	LDR R2, [R5]
	LDR R3, =2_111111111111
	AND R2, R2, R3 ; check which key pad data is on
	CMP R2, #2_010000001000
	BEQ num0
	CMP R2, #2_100000000100
	BEQ num1
	CMP R2, #2_010000000100
	BEQ num2
	CMP R2, #2_001000000100
	BEQ num3
	CMP R2, #2_100000000010
	BEQ num4
	CMP R2, #2_010000000010
	BEQ num5
	CMP R2, #2_001000000010
	BEQ num6
	CMP R2, #2_100000000001
	BEQ num7
	CMP R2, #2_010000000001
	BEQ num8
	CMP R2, #2_001000000001
	BEQ num9

num0
	LDR R1, =0 ;valuue of key pad register
	MOV R9, #6 
	B segmenton
num1
	LDR R1, =1
	MOV R9, #6
	B segmenton
num2
	LDR R1, =2
	MOV R9, #6 
	B segmenton
num3
	LDR R1, =3
	MOV R9, #6 
	B segmenton
num4
	LDR R1, =4
	MOV R9, #6 
	B segmenton
num5
	LDR R1, =5
	MOV R9, #6 
	B segmenton
num6
	LDR R1, =6
	MOV R9, #6 
	B segmenton
num7
	LDR R1, =7
	MOV R9, #6 
	B segmenton
num8
	LDR R1, =8
	MOV R9, #6 
	B segmenton
num9
	LDR R1, =9
	MOV R9, #6 
		
segmenton
	; sending message
	SUBS R11,R9,#0
	BEQ clock ; no message
	SUBS R11,R9,#6
	BNE six 
	LDR R2, =2_1000000000000000
	LDR R5, =PIO_SODR
	STR R2, [R5]
	SUB R9, R9, #1
	B clock
six ;SENDING LAST BIT OF DATA
	SUBS R11, R9, #1
	BNE one 
	LDR R2, =2_1000000000000
	LDR R5, =PIO_CODR
	STR R2, [R5]
	SUB R9, R9, #1
	B clock
one ;SENDING FIRST BIT OF DATA 
	ASR R1, R1, #1
	BCS high
	LDR R2, =2_2_1000000000000
	LDR R5, =PIO_CODR
	STR R2, [R5]
	SUB R9, R9, #1
	B clock
high ;SET HIGH BIT READY FOR DATA TRANSPORT
	LDR R2, =2_100000000000000
	LDR R5, =PIO_SODR
	STR R2, [R5]
	SUB R9, R9, #1
	
clock ;clock implementation
	CMP R12, #0
	BEQ low
	LDR R2, =2_100000000000
	LDR R5, =PIO_SODR
	STR R2, [R5]
	MOV R12, #1
	B delay
low; SENDING LOW MEANS ITS ENDING OF DARA
	LDR R2, =2_100000000000
	LDR R5, =PIO_CODR
	STR R2, [R5]
	MOV R12, #0

delay
	MOV r4, #0
	LDR r5, =100

delayLOOP
	ADD r4,r4,#1
	SUSB R11,R4,R5
	BNE delayLOOP
	B loop


here B here
	END