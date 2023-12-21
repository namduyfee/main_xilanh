
#include "interrupt.h"

#define tha_lua 10
#define gap_lua_len 3
#define di_tha_lua 2

void EXTI15_10_IRQHandler (void) {
	
	if(EXTI->PR & 1<<15) {
		
		khoa_dc_tay(3); 
		
		if(start == 0) { 
			start = 1; 
			USART1->CR1 |= 1<<5;
		}
		
		if(tem == 2) {
			kep(2); 
			start = 1; 
			tem = 3; 
			delayUs(1000000); 
			nang_canh_tay(50); 
			stop_nang_ha = tha_lua; 
			trang_thai = 1; 
		}
		if(tem == 4) {
			control_xilanh(3, 1); 
			control_xilanh(5, 1);
			delayUs(500000); 
			start = 1; 
			stop_nang_ha = gap_lua_len; 
			nang_canh_tay(60);
			delayUs(500000); 
			xoay_trai(1, 50); 
			xoay_phai(2, 50); 
			 
		}
		if(tem == 5) {
			control_xilanh(2, 1); 
			control_xilanh(6, 1);
			delayUs(500000);
			start = 1; 
			stop_nang_ha = di_tha_lua; 
			nang_canh_tay(40); 
			delayUs(500000); 
			USART1->DR = 'd'; 
		}
		vi_tri_nang_ha = 0; 
		EXTI->PR = 1<<15;
	}
	
}


void EXTI4_IRQHandler (void) {

	if(EXTI->PR & 1<<4) {
	
		if(check == 0) {
			khoa_dc_tay(2); 
			while((EXTI->PR & 1<<5) == 0);
			khoa_dc_tay(1); 
			check = 1; 
			delayUs(50000);

			EXTI->PR = 1<<4;
			return; 
		}
		
		if(check == 1) {
			delayUs(50000);
			check = 0; 
			EXTI->PR = 1<<4;
		}
		
	}
}

void EXTI9_5_IRQHandler (void) {
		
	if(EXTI->PR & 1<<5) {
			
			if(check == 0) {

				khoa_dc_tay(1); 
				while((EXTI->PR & 1<<4) == 0);
				khoa_dc_tay(2);
				check = 1;
				delayUs(50000); 
		
				EXTI->PR = 1<<5;
				return; 
		}
			
			if(check == 1) { 
			delayUs(50000);
			check = 0; 
			EXTI->PR = 1<<5;
			}
		}
}


void EXTI3_IRQHandler (void) {
	if(EXTI->PR & 1<<3) {
		if(start) {
			if(trang_thai == 0) 
				vi_tri_nang_ha--; 
			else 
				vi_tri_nang_ha++; 
		
			if(stop_nang_ha == vi_tri_nang_ha) {
				khoa_dc_tay(3);
				if(tem == 1) { 
					USART1->DR = 'a';
				}
				if(tem == 3) {
					control_xilanh(2, 0); 
					control_xilanh(3, 0);
					control_xilanh(5, 0); 
					control_xilanh(6, 0);
					delayUs(1000000); 
					xoay_trai(1, 60); 
					xoay_phai(2, 60); 
					USART1->DR = 'b'; 
				}
				if(tem == 4) 
					USART1->DR = 'c'; 
				
			}
 
			delayUs(50000); 
		}
		EXTI->PR = 1<<3;
	
	}
	
}


void USART1_IRQHandler (void) {
	
	if(USART1->SR & (1<<5)) {
		tay_ps = USART1->DR; 
		if(tay_ps == 'a') {
			kep(1); 
			delayUs(1000000);
			trang_thai = 1; 
			stop_nang_ha = gap_lua_len;
			nang_canh_tay(60);
			delayUs(500000);
			xoay_trai(1, 60); 
			xoay_phai(2, 60);
			tem = 1; 
		}
		if(tay_ps == 'b') {
			ha_canh_tay(60);
			trang_thai = 0; 
			tem = 2; 
			start = 0; 
		}
		
		if(tay_ps == 'c') {
			start = 0; 
			ha_canh_tay(60); 
			tem = 4; 
		}
		if(tay_ps == 'd') {
			ha_canh_tay(60); 
			start = 0; 
			tem = 5; 
		}
		USART1->CR1 |= 1<<7; 
	}
	if(USART1->SR & (1<<7)) {
		
		USART1->CR1 &= (~(1<<7));
	}
	
}

