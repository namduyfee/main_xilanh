
#include "interrupt.h"

// cb chu U 1 : PB5
// cb chu U 2 : 

void EXTI3_IRQHandler (void) {
	
	if(EXTI->PR & 1<<3) {
		delayUs(50000); 
		canh_tay.tocdo_keo = 1; 
		
		canh_tay.tocdo_trai = 40; 
		canh_tay.diachi_phai = 40; 
		EXTI->PR |= 1<<3;
	}
	
}

void EXTI4_IRQHandler (void) {
	// A8, A11, A12, B8
	// 1 : A12 -- 2 : A11 -- 3 : A8 -- 4 : B8 
	
	if(EXTI->PR & 1<<4) {

		int tem = 0; 
		if(check == 0&& tem == 0) {
			canh_tay.tocdo_trai = 1;
			
			while((EXTI->PR & 1<<5)== 0);
			canh_tay.tocdo_phai = 1;
			
			if( t == 0) { 
				control_xilanh(1, 1); 
				control_xilanh(5, 1); 
			}
			if(t == 1)  {
				control_xilanh(2, 1); 
				control_xilanh(6, 1);
			}
			if(t == 2) {
				control_xilanh(3, 1); 
				control_xilanh(7, 1);
			}
			if(t == 3) {
				control_xilanh(4, 1); 
				control_xilanh(8, 1);
			}
			t++; 
		delayUs(1500000);
		
		if(t <= 3)  { 
			canh_tay.tocdo_trai = 40;
			canh_tay.tocdo_phai = 40;
		}
		check = 1;
		tem = 1; 
	}
	if(check == 1 && tem == 0) {
		delayUs(20000);
		check = 0; 
	}
	EXTI->PR |= 1<<4;

}
	
}

void EXTI9_5_IRQHandler (void) {
	
	if(EXTI->PR & 1<<5) {
		int tem = 0; 
		if(check == 0 && tem == 0) {
			canh_tay.tocdo_phai = 1; 
			
//			canh_tay.diachi_trai = 0x01; 
//			canh_tay.end_trai = 0xFF;
			
			while((EXTI->PR & 1<<4)== 0);
			
			canh_tay.tocdo_trai = 1;
			if( t == 0) { 
				control_xilanh(1, 1); 
				control_xilanh(5, 1); 
			}
			if(t == 1)  {
				control_xilanh(2, 1); 
				control_xilanh(6, 1);
			}
			if(t == 2) {
				control_xilanh(3, 1); 
				control_xilanh(7, 1);
			}
			if(t == 3) {
				control_xilanh(4, 1); 
				control_xilanh(8, 1);
			}
			t++; 
		delayUs(1500000);
		
		if(t <= 3)  { 
			canh_tay.tocdo_trai = 40;
			canh_tay.tocdo_phai = 40;
		}
//		delayUs(20000);
		check = 1;
		tem = 1; 
	}
	if(check == 1 && tem == 0) {
		delayUs(20000);
		check = 0; 
	}
	EXTI->PR |= 1<<5;

}
}


void EXTI15_10_IRQHandler (void) {
	
	if(EXTI->PR & 1<<15) {
		
		
		EXTI->PR |= 1<<15;
	}
	
}

