


#ifndef		__INTERRUPT__

#define	__INTERRUPT__

#include <stm32f10x.h> 

#include "timer.h" 
#include "servo.h"

extern int t; 
extern uint8_t dc_trai[3]; 
extern uint8_t dc_phai[3]; 

 void EXTI3_IRQHandler (void); 
 
 void EXTI4_IRQHandler (void); 
 
 void EXTI9_5_IRQHandler (void); 
	
	void EXTI15_10_IRQHandler (void); 

#endif
