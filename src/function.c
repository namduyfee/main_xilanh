
#include "function.h"

 


void control_xilanh(uint8_t xilanh_number, uint8_t trang_thai) {
	
	// kep vao
	if(trang_thai == 1) {
		
		if(xilanh_number == 1) 
			GPIOA->ODR |= 1<<11; 
		if(xilanh_number == 2)  
			GPIOA->ODR |= 1<<12; 
		if(xilanh_number == 3) 
			GPIOA->ODR |= 1<<8;
		if(xilanh_number == 4) 
			 GPIOB->ODR |= 1<<8;
		
		// tay 2 
		
		if(xilanh_number == 5) 
				GPIOB->ODR |= 1<<12; 
		if(xilanh_number == 6) 
			GPIOB->ODR |= 1<<13; 
		if(xilanh_number == 7) 
			GPIOB->ODR |= 1<<14; 
		if(xilanh_number == 8) 
			GPIOB->ODR |= 1<<15; 
		
	}
	//mo ra  
	if(trang_thai == 0) {
		
		if(xilanh_number == 1) 
			GPIOA->ODR &= (~(1<<11)); 
		if(xilanh_number == 2)  
			GPIOA->ODR &= (~(1<<12)); 
		if(xilanh_number == 3) 
			GPIOA->ODR &= (~(1<<8)); 
		if(xilanh_number == 4) 
			 GPIOB->ODR &= (~(1<<8)); 
		
		// tay 2 
		
		if(xilanh_number == 5) 
				GPIOB->ODR &= (~(1<<12)); 
		if(xilanh_number == 6) 
			GPIOB->ODR &= (~(1<<13)); 
		if(xilanh_number == 7) 
			GPIOB->ODR &= (~(1<<14)); 
		if(xilanh_number == 8) 
			GPIOB->ODR &= (~(1<<15));  		
		
	}
	
}

//void khoi_dong_mem (uint8_t dc1, uint8_t dc2, uint8_t toc_do) {
//	
//	uint8_t i; 
//	for(i = 0; i < toc_do; i++) {
//		if(dc1 == 1 || dc2 == 1)  
//			canh_tay.tocdo_trai = i; 
//		if(dc1 == 2 || dc2 == 2) 
//			canh_tay.tocdo_phai = i;
//		if(dc1 == 3 || dc2 == 3) 
//			canh_tay.tocdo_keo = i;
//		delayUs(60000); 
//	}

//}

