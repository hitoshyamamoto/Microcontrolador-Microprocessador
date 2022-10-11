		EXPORT __main
		AREA	OUR_PROG, CODE, READONLY
__main
		MOV R1, #0x30 //R1 = 30
		LDR R0, =0x00000015 //posicao da memoria R0 = 0x00000015
		STRB R1,[R0]
		
		MOV R2, #0x97 //R2 = 97
		ldr R0, =0x00000016 //posicao da memoria R0 = 0x00000016
		STRB R2, [R0]
		
HERE	B	HERE
		END