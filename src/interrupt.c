
#include "interrupt.h"

// cb chu U 1 : PB5
// cb chu U 2 : 

void EXTI3_IRQHandler (void) {
	
	if(EXTI->PR & 1<<3) {
			 
		EXTI->PR |= 1<<3;
	}
	
}


void EXTI4_IRQHandler (void) {
	// A8, A11, A12, B8
	
	if(EXTI->PR & 1<<4) {
		delayUs(50000); 
		dc_trai[1] = 0;  
		if( t == 0) 
			GPIOA->ODR |= 1<<8;  
		if(t == 1) 
			GPIOA->ODR |= 1<<11; 
		if(t == 2) 
			GPIOA->ODR |= 1<<12; 
		if(t == 3) 
			GPIOB->ODR |= 1<<8;
		t++; 
		t = t % 4;
		delayUs(1000000);
		EXTI->PR |= 1<<4;
		dc_trai[1] = 30;
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

