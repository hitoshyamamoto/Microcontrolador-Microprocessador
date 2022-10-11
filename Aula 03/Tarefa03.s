		EXPORT __main
		AREA	OUR_PROG, CODE, READONLY
__main		
		LDR R2, =0x129F		
		LDR R1, =0x20001450
		STR R2,[R1]	//R1 recebe o valor vindo da posicao da
					//memoria 0x129F, sendo o valor eh 0x9F.
		
HERE	B	HERE
		END