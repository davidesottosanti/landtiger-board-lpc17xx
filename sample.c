/*----------------------------------------------------------------------------
 * Name:    sample.c
 * Purpose: to control led through EINT and joystick buttons
 * Note(s):
 *----------------------------------------------------------------------------
 *
 * This software is supplied "AS IS" without warranties of any kind.
 *
 * Copyright (c) 2017 Politecnico di Torino. All rights reserved.
 *----------------------------------------------------------------------------*/    
#include <stdio.h>
#include "LPC17xx.H"                    /* LPC17xx definitions                */
#include "led/led.h"
#include "button_EXINT/button.h"
#include "timer/timer.h"
#include "RIT/RIT.h"
#include "joystick/joystick.h"
#include "adc/adc.h"
#include "dac/dac.h"

/*----------------------------------------------------------------------------
  Main Program
 *----------------------------------------------------------------------------*/
//extern int funzioneASM (void); //funzione assembly da richiamare come una funzione C

int main (void) {
  	
	SystemInit();  												/* System Initialization (i.e., PLL)  */
  LED_init();                           
  BUTTON_init();												
	joystick_init();											
	
	ADC_init();														/* ADC Initialization	(POTENZIOMETRO) */
	DAC_init();														/* DAC Initialization	  (SPEAKER) 		*/
	
	
	init_RIT(0x004C4B40);									//RIT inizializzato a 50 msec (0,050 * 100 000 000 = 5 000 000 = 4C4B40)
	enable_RIT();													//il RIT va a 100Mhz
	
	
																				//timer blinking ( 2hz -> 1/(2*2) * 25 000 000 = 6 250 000)
	//I timer vanno a 25Mhz								//timer da 60sec ( 60s ->     60  * 25 000 000 = 1 500 000 000)
	//init_timer(0,6250000);              //(X hz -> 1/X * 25 000 000 = ..hex or dec..)
	//init_timer(1,6250000);              //(X hz -> 1/X * 25 000 000 = ..hex or dec..)
	//init_timer(2,6250000);              //(X hz -> 1/X * 25 000 000 = ..hex or dec..)
	//init_timer(3,6250000);              //(X hz -> 1/X * 25 000 000 = ..hex or dec..)
	//enable_timer(0);
	//enable_timer(1);
	//enable_timer(2);
	//enable_timer(3);
	
	
	LPC_SC->PCON |= 0x1;									/* power-down	mode										*/
	LPC_SC->PCON &= ~(0x2);						
		
  while (1) {                           /* Loop forever                       */	
		__ASM("wfi");
  }

}
