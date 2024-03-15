#include "button.h"
#include "lpc17xx.h"

extern int down_k1;
extern int down_k2;
extern int down_k0; 

void EINT0_IRQHandler (void){//INT0
	NVIC_DisableIRQ(EINT0_IRQn);		          // disabilito gli interrupt al tasto			 
	LPC_PINCON->PINSEL4    &= ~(1 << 20);     // seleziono modalità GPIO al posto di EINT0
	down_k0=1;
	LPC_SC->EXTINT &= (1 << 0);               // clear pending interrupt         

}
void EINT1_IRQHandler (void){//KEY1
	NVIC_DisableIRQ(EINT1_IRQn);		          // disabilito gli interrupt al tasto
	LPC_PINCON->PINSEL4    &= ~(1 << 22);     // seleziono modalità GPIO al posto di EINT1
	down_k1=1;
	LPC_SC->EXTINT &= (1 << 1);               // clear pending interrupt         

}
void EINT2_IRQHandler (void){ //KEY2
	NVIC_DisableIRQ(EINT2_IRQn);		          // disabilito gli interrupt al tasto			 
	LPC_PINCON->PINSEL4    &= ~(1 << 24);     // seleziono modalità GPIO al posto di EINT2
	down_k2=1;
  LPC_SC->EXTINT &= (1 << 2);               // clear pending interrupt             

}
