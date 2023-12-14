


#ifndef		__INTERRUPT__

#define	__INTERRUPT__

#include <stm32f10x.h> 

#include "timer.h" 
#include "servo.h"
#include "function.h" 


typedef struct {
	uint8_t diachi_trai; 
	uint8_t tocdo_trai; 
	uint8_t end_trai; 
	uint8_t diachi_phai; 
	uint8_t tocdo_phai; 
	uint8_t end_phai;
	
} dc; 

extern int t; 
extern int check; 
extern dc canh_tay; 

 void EXTI3_IRQHandler (void); 
 
 void EXTI4_IRQHandler (void); 
 
 void EXTI9_5_IRQHandler (void); 
	
	void EXTI15_10_IRQHandler (void); 

#endif
