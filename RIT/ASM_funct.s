;VARIABILI ALIAS FISSE IN ALTO A SINISTRA
;base0 RN 0      ;chiamo R0 con "base"
;base1 RN 1      ;chiamo R1 con "offset"

;currval RN 4	
;offset RN 5
;indirizzo RN 6
;indice RN 7
;xxx RN 8

;N EQU 4 ;definizione di costante
			AREA asm_functions, CODE, READONLY
			EXPORT funzioneASM
funzioneASM	
			;ARGOMENTI PASSATI DA C ad ASM:        r0, r1, r2, r3
			;ARGOMENTI DI RITORNO CHE MANDO AL C:  r0, r1
			MOV r12, sp		;salva lo stack pointer per poter accedere al suo contenuto velocemente
			;push9			;---STACK----
			;push8			;|r4 |+28        |push1| SP   |push1|+4   |push1|+8   |push1|+16   
			;push7			;|r5 |+24                     |push2|SP   |push2|+4   |push2|+8   
			;push6			;|r6 |+20                                 |push3|SP   |push3|+4   
			;push5			;|r7 |+16                                             |push4|SP   
			;push4	+44		;|r8 |+12
			;push3	+40		;|r10|+8
			;push2	+36		;|r11|+4
			;push1	+32		;|lr |SP
			;---------------------------------------------------------------------------------------
			;ldr r1,[sp,#4] 				;carica in r1 l'SP+4
			;ldr indirizzo, =datablock  	;carica l'indirizzo di datablock dentro indirizzo (r6), creando un literal pool
			;ldr currval,[indirizzo,offset] ;scorro i valori del literal pool
			;---------------------------------------------------------------------------------------
			STMFD sp!,{r4-r8,r10-r11,lr}	;salva i registri che posso usare come variabili per questo programma ASM
			
			;mov indice,#0					;resetta le variabili che uso per il ciclo
			;mov offset,#0					;resetta le variabili che uso per il ciclo
;loop										;CICLO
			
			
			
			;add indice,#1					;da 0 a N-1 CICLA
			;cmp indice,N
			;bne loop
			
			
			
			LDMFD sp!,{r4-r8,r10-r11,pc}	;ripristina i registri volatile
;DICHIARAZIONE DI DATABLOCK GIA' ALLINEATO
;			align 4			
;datablock  DCD 0x11,0x22,0x33			
			END
