
#include "interrupt.h"

// cb chu U 1 : PB5
// cb chu U 2 : 

void EXTI3_IRQHandler (void) {
	
	if(EXTI->PR & 1<<3) {
			 
		EXTI->PR |= 1<<3;
	}
	
}


void EXTI4_IRQHandler (void) {
	
	if(EXTI->PR & 1<<4) {
		delayUs(20000); 
		dc_trai[1] = 0; 
		EXTI->PR |= 1<<4;
		
	}
	
}

void EXTI9_5_IRQHandler (void) {
	
	if(EXTI->PR & 1<<5) {
		
		EXTI->PR |= 1<<5;
	}
}


void EXTI15_10_IRQHandler (void) {
	
	if(EXTI->PR & 1<<15) {

		EXTI->PR |= 1<<15;
	}
	
}

