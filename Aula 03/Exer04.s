		EXPORT __main
		AREA	OUR_PROG, CODE, READONLY
__main
		MOV R1, #0x02
		MOV R2, #0x00
		ADD R2, R2, R1
		
		MOV R1, #0x00
		ADD R2, R2, R1
		
		MOV R1, #0x01
		ADD R2, R2, R1
		
		MOV R1, #0x08
		ADD R2, R2, R1
		
		MOV R1, #0x00
		ADD R2, R2, R1

		MOV R1, #0x01
		ADD R2, R2, R1
		
		MOV R1, #0x08
		ADD R2, R2, R1
		
		MOV R1, #0x07
		ADD R2, R2, R1
		
		MOV R1, #0x00
		ADD R2, R2, R1
		
		MOV R1, #0x06
		ADD R2, R2, R1
		
HERE	B	HERE
		END