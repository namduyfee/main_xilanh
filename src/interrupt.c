
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
	// 3 : A11, 1 : A12 ; 2 : A11 ; 4 : B8 
	
	if(EXTI->PR & 1<<4) {
		delayUs(50000); 
		dc_trai[0] = 0x01; 
		dc_trai[1] = 0;
		dc_trai[2] = 0xFF;   
		if( t == 0) 
			GPIOA->ODR |= 1<<11;  
		if(t == 1) 
			GPIOA->ODR |= 1<<12; 
		if(t == 2) 
			GPIOA->ODR |= 1<<8; 
		if(t == 3) 
			GPIOB->ODR |= 1<<8;
		t++; 

		delayUs(1000000);
		EXTI->PR |= 1<<4;
		if(t <= 3)  {
			dc_trai[0] = 0x01; 
			dc_trai[1] = 6;
			dc_trai[2] = 0xFF; 
		}
		delayUs(50000);
		
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

