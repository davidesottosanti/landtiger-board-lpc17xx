/*********************************************************************************************************
**--------------File Info---------------------------------------------------------------------------------
** File name:           IRQ_RIT.c
** Last modified Date:  2014-09-25
** Last Version:        V1.00
** Descriptions:        functions to manage T0 and T1 interrupts
** Correlated files:    RIT.h
**--------------------------------------------------------------------------------------------------------
*********************************************************************************************************/
#include "lpc17xx.h"
#include "RIT.h"
#include "../led/led.h"
#include "../timer/timer.h"
#include "../adc/adc.h"

/*-----------L E D ---------------------------------------------------
		x--->  7      6      5       4       3       2       1        0
		led-> LD4    LD5    LD6     LD7     LD8     LD9     LD10     LD11    
		LED_Out(0);    //SPEGNI  TUTTI I LED
		LED_Out(0xFF); //ACCENDI TUTTI I LED
-------------P U L S A N T I------------------------------------------
		KEY2  -> GPIO 2 - PIN 12				JOY SELECT->  GPIO 1 - PIN 25
		KEY1  -> GPIO 2 - PIN 11				JOY DOWN	->  GPIO 1 - PIN 26
		KEY0  -> GPIO 2 - PIN 10				JOY LEFT	->  GPIO 1 - PIN 27
																		JOY RIGHT ->  GPIO 1 - PIN 28
																		JOY UP	  ->  GPIO 1 - PIN 29
----------------------------------------------------------------------
CATTURARE VALORE DEL TIMER 0   ->   VAR=LPC_TIM0->TC;
*/
extern int count;
int down_k0=0;
int down_k1=0;
int down_k2=0;

//extern int funzioneASM (int VETT[], unsigned int dim); //funzione assembly da richiamare come una funzione C

void RIT_IRQHandler (void)
{
	static int select=0;
	
	
	
	if((LPC_GPIO1->FIOPIN & (1<<29)) == 0){//----------------------JOYSTICK UP------------------------------------
		//mettere gli IF per i flag qui dentro
	}
	
	
	if((LPC_GPIO1->FIOPIN & (1<<26)) == 0){//----------------------JOYSTICK DOWN----------------------------------
		//mettere gli IF per i flag qui dentro
	}
	
	
	if((LPC_GPIO1->FIOPIN & (1<<28)) == 0){//----------------------JOYSTICK RIGHT---------------------------------
		//mettere gli IF per i flag qui dentro
	}
	
	
	if((LPC_GPIO1->FIOPIN & (1<<27)) == 0){//----------------------JOYSTICK LEFT----------------------------------
		//mettere gli IF per i flag qui dentro
	}
	

	if((LPC_GPIO1->FIOPIN & (1<<25)) == 0){//----------------------JOYSTICK SELECT--------------------------------
		//mettere gli IF per i flag qui dentro

		select++;
		switch(select){
			case 1:
				
				break;
			default:
				break;
		}
	}else{//tasto rilasciato
			select=0;
	}
	
	
	
	
	
	
	if(down_k2!=0){//---------------------------------KEY 2--------------------------------------------
		if((LPC_GPIO2->FIOPIN & (1<<12)) == 0){
			//mettere gli IF per i flag qui dentro
			
			down_k2++;				
			switch(down_k2){
				case 2://prima pressione
										
					
					break;
				default:
					break;
			}
		}else{//rilascio tasto
			down_k2=0;
			NVIC_EnableIRQ(EINT2_IRQn);//riabilito interrupt su EINT2
			LPC_PINCON->PINSEL4    |= (1 << 24);//riabilito interrupt su EINT2
		}
	}
	
	if(down_k1!=0){//---------------------------------KEY 1--------------------------------------------
		if((LPC_GPIO2->FIOPIN & (1<<11)) == 0){
			//mettere gli IF per i flag qui dentro
			
			down_k1++;				
			switch(down_k1){
				case 2://prima pressione
										
					
					break;
				default:
					break;
			}
		}else{//rilascio tasto
			down_k1=0;
			NVIC_EnableIRQ(EINT1_IRQn);//riabilito interrupt su EINT1
			LPC_PINCON->PINSEL4    |= (1 << 22);//riabilito interrupt su EINT1
		}
	}
	
	if(down_k0!=0){//---------------------------------KEY 0--------------------------------------------
		if((LPC_GPIO2->FIOPIN & (1<<10)) == 0){
			//mettere gli IF per i flag qui dentro
			
			down_k0++;				
			switch(down_k0){
				case 2://prima pressione
										
					
					break;
				default:
					break;
			}
		}else{//rilascio tasto
			down_k0=0;
			NVIC_EnableIRQ(EINT0_IRQn);//riabilito interrupt su EINT0
			LPC_PINCON->PINSEL4    |= (1 << 20);//riabilito interrupt su EINT0
		}
	}
	
	
	
	//ADC_start_conversion();					//funzione che fa 1 campionamento del potenziometro (essendo nel rit, si campiona ogni 50ms).
																		//Quando arriva un campione, scatta l'ADC handler
	
	
	
  LPC_RIT->RICTRL |= 0x1;	/* clear interrupt flag */
}
