		EXPORT __main
		AREA	OUR_PROG, CODE, READONLY
__main
		MOV R1, #0x12
		MOV R2, #0x25
		ADD R3, R2, R1
HERE	B	HERE
		END