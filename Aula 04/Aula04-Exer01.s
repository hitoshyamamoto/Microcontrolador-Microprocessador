       EXPORT __main
       AREA MY_PROG, CODE, READONLY
__main
       LDR	R1,=0x33322292
       LDR	R2,=0x55566623
	   LDR 	R3,=0x9998884B
	   MOV	R4,#0xFF
	   LDR	R5,=0xDDDEEE01
	   
	   MOV	R6,#0	;Zera o registrador que vai somar
	   MOV	R7,#0	;Zera o registrador que vai carregar o carry
	   
	   ADDS	R6,R1	;Soma o proprio R6 com R1 // R6=R6+R1 //	R6 = 0X33322292 // C=0;Z=0
	   ADC	R7,#0	;Soma o proprio R7 com 0  // R7=R7+0+carry //	C=0;Z=0
	   
	   ADDS R6,R2	;R6=R6+R2 // R6 = 0X888888B5	// C=0;Z=0
	   ADC	R7,#0	;Se houver carry, R7=R7+carry //  C=0;Z=0
	   
	   ADDS R6,R3	;R6 = 0X22211100	// C=1;Z=0
	   ADC	R7,#0	;C=1;Z=0	
	   
	   ADDS R6,R4	;R6 = 0X222111FF // C=0;Z=0
	   ADC	R7,#0	;C=0;Z=0
	   
	   ADDS R6,R5	;R6=0	// C=0;Z=0
	   ADC	R7,#0	;C=1;Z=1
	   
H      B    H          ;stay here forever
       END