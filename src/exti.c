


#include "exti.h"


void configEXTI(void) {
	
	EXTI->IMR &= 0; 
	EXTI->FTSR &= 0; 
	
	EXTI->IMR |= 1<<3; 
	EXTI->FTSR |= 1<<3; 
	
	
	EXTI->IMR |= 1<<4; 
	EXTI->FTSR |= 1<<4;
	
	EXTI->IMR |= 1<<5; 
	EXTI->FTSR |= 1<<5;
	
	EXTI->IMR |= 1<<15; 
	EXTI->FTSR |= 1<<15;
	
	\
}


