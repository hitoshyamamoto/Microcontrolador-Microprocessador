       EXPORT __main
       AREA MY_PROG, CODE, READONLY
__main
       MOV	R1,#27
       MOV	R2,#15
       SUBS	R3, R1, R2
       MOV	R1,#20
       MOV	R2,#15
       SUBS	R3, R1, R2
       MOV	R1,#95
       MOV	R2,#95
       SUBS	R3, R1, R2
       MOV	R1,#50
       MOV	R2,#70
       SUBS	R3, R1, R2
H      B    H          ;stay here forever
       END