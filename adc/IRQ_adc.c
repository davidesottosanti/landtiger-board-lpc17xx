/*********************************************************************************************************
**--------------File Info---------------------------------------------------------------------------------
** File name:           IRQ_adc.c
** Last modified Date:  20184-12-30
** Last Version:        V1.00
** Descriptions:        functions to manage A/D interrupts
** Correlated files:    adc.h
**--------------------------------------------------------------------------------------------------------       
*********************************************************************************************************/

#include "lpc17xx.h"
#include "adc.h"
#include "../led/led.h"
#include "../timer/timer.h"

/*----------------------------------------------------------------------------
  A/D IRQ: Executed when A/D Conversion is ready (signal from ADC peripheral)
 *----------------------------------------------------------------------------*/

unsigned short AD_current;       //valore corrente
unsigned short AD_last = 0xFFF;  //valore precedente

/* k=1/f'*f/n  k=f/(f'*n) k=25MHz/(f'*45) */

//const int freqs[8]={4240,3779,3367,3175,2834,2525,2249,2120};
/* 
131Hz		k=4240 C3
147Hz		k=3779
165Hz		k=3367
175Hz		k=3175
196Hz		k=2834		
220Hz		k=2525
247Hz		k=2249
262Hz		k=2120 C4
*/

const int freqs[8]={2120,1890,1684,1592,1417,1263,1125,1062};
/*
//FREQUENZE DA METTERE NEL TIMER 0,1,2,3(da 25Mhz)
//Formula:  k=25/(f*45)  con f=frequenza della nota desiderata, 45 sono i campioni, 25 sono i Mhz del timer
262Hz	k=2120		C 4
294Hz	k=1890		D
330Hz	k=1684		E
349Hz	k=1592		F
392Hz	k=1417		G
440Hz	k=1263		A
494Hz	k=1125		B
523Hz	k=1062		C 5
*/
int val;

void ADC_IRQHandler(void) {
  	
  AD_current = ((LPC_ADC->ADGDR>>4) & 0xFFF); //legge il campione
  if(AD_current != AD_last){
		
		//LED_Off(AD_last*7/0xFFF);	  // ad_last : AD_max = x : 7 		LED_Off((AD_last*7/0xFFF));	
		//LED_On(AD_current*7/0xFFF);	// ad_current : AD_max = x : 7 		LED_On((AD_current*7/0xFFF));	
		
		//val = freqs[AD_current*7/0xFFF]; //  (AD_current*7/0xFFF)  Divide in 8 valori il fondoscala del potenziometro e 
		                                   // e prende un valore fra gli 8, corrispondente proporzionalmente ad AD_current (il campione)
		AD_last = AD_current;
  }
	
}
