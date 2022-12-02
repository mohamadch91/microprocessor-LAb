		AREA MY_DATA,DATA
PIO_PER equ  0x400E0E00	
PIO_SODR equ 0x400E0E30
PIO_CODR equ 0x400E0E34
PIO_OER equ  0x400E0E10 
PIO_PDSR equ 0x400E0E3C
PIO_ISR equ  0x400E0E4C
		area mycode, code, readonly
		export __main
		entry
__main
	mov r12,#1 ;counter for clock
	LDR R4, =2_1111100000000000
	LDR R5,=PIO_PER ;enable pio
	STR R4, [R5]
	LDR R5,=PIO_OER ;here enable out put register
	STR R4, [R5]

loop
	; select slaves
	LDR R5, =PIO_ISR ;interupt service routin selector
	LDR R2, [R5]
	LDR R3, =2_11100000000 ; and with this to see which logix gate is on 
	AND R2, R2, R3 ; mask to get wanted bits
	LSL R2, R2, #5
	LDR R5, =PIO_SODR
	STR R2, [R5]
	MVN R2, R2 ; not
	LDR R3, =2_1110000000000000
	AND R2, R2, R3 ; again masking
	LDR R5, =PIO_CODR ; enable and clear registers
	STR R2, [R5]

; setting numbers ti R1 register

segmenton
	
	; sending message
	CMP R9, #0
	BEQ clock ; no message
	CMP R9, #6
	BNE six ; these 4 lines only for when counter is 6
	LDR R2, =2_1000000000000
	LDR R5, =PIO_SODR
	STR R2, [R5]
	SUB R9, R9, #1
	B clock
six
	CMP R9, #1
	BNE one ; these 4 lines only for when counter is 1
	LDR R2, =2_1000000000000
	LDR R5, =PIO_CODR
	STR R2, [R5]
	SUB R9, R9, #1
	B clock
one
	ASR R1, R1, #1
	BCS high
	LDR R2, =2_1000000000000
	LDR R5, =PIO_CODR
	STR R2, [R5]
	SUB R9, R9, #1
	B clock
high
	LDR R2, =2_1000000000000
	LDR R5, =PIO_SODR
	STR R2, [R5]
	SUB R9, R9, #1
	
clock ;clock implementation
	CMP R12, #1
	BNE low
	LDR R2, =2_100000000000
	LDR R5, =PIO_SODR
	STR R2, [R5]
	MOV R12, #0
	B delay
low
	LDR R2, =2_100000000000
	LDR R5, =PIO_CODR
	STR R2, [R5]
	MOV R12, #1

delay
	MOV r4, #0
	LDR r5, =0x0000C00

loop_delay
	ADD r4,r4,#1
	
	CMP r4,r5
	BNE loop_delay
	B loop


here B here
	END