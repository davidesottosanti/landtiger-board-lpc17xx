/*********************************************************************************************************
**--------------File Info---------------------------------------------------------------------------------
** File name:           IRQ_timer.c
** Last modified Date:  2014-09-25
** Last Version:        V1.00
** Descriptions:        functions to manage T0 and T1 interrupts
** Correlated files:    timer.h
**--------------------------------------------------------------------------------------------------------
*********************************************************************************************************/
#include "lpc17xx.h"
#include "timer.h"
#include "../dac/dac.h"
#include "../led/led.h"
/*
uint16_t SinTable[45]=
{	410,467,523,576,627,673,714,749,778,
	799,813,819,817,807,789,764,732,694,
	650,602,550,495,438,381,324,270,217,
	169,125, 87, 55, 30, 12,  2,  0,  6,
	 20, 41, 70,105,146,193,243,297,353
};

ABBASSO DEL 60% L'ONDA SOPRA (volume 30%)
uint16_t SinTable[45]=
{ 246,280,313,345,376,404,428,449,467,
  479,488,491,490,484,473,458,439,416,
  390,361,330,297,262,228,194,162,130,
  101, 75, 52, 33, 18, 7,  1,  0,  3,
  12, 24, 42, 63, 88,116,146,178,212
};


//da mettere nell'handler di un timer, in modo da mandare 1 campione di onda ogni scattare del timer
//il timer va poi inizializzato con una frequenza opportuna a seconda della nota che si vuole far sentire (vedi tabella delle frequenze in ADC)
static int ticks=0;
DAC_convert(SinTable[ticks]<<6); //selezioni il valore di sintable con ticks, e lo shifti di 6 per poi mandarlo allo speaker. Ogni scattare del timer mandi 1 valore
ticks++;
if(ticks==45) ticks=0;

*/

void TIMER0_IRQHandler (void){
	
	
  LPC_TIM0->IR = 1;			/* clear interrupt flag */
  return;
}
void TIMER1_IRQHandler (void)
{
  LPC_TIM1->IR = 1;			/* clear interrupt flag */
  return;
}
void TIMER2_IRQHandler (void)
{
  LPC_TIM2->IR = 1;			/* clear interrupt flag */
  return;
}
void TIMER3_IRQHandler (void)
{
  LPC_TIM3->IR = 1;			/* clear interrupt flag */
  return;
}
