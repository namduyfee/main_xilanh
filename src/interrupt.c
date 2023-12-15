
#include "interrupt.h"

// cb chu U 1 : PB5
// cb chu U 2 : 

void EXTI3_IRQHandler (void) {
	
	if(EXTI->PR & 1<<3) {
		delayUs(50000); 
		
		khoa_dc_tay(3); 
		xoay_trai(1, 40); 
		xoay_trai(2, 60);
		
		EXTI->PR |= 1<<3;
	}
	
}

void EXTI4_IRQHandler (void) {
	// A8, A11, A12, B8
	// 1 : A12 -- 2 : A11 -- 3 : A8 -- 4 : B8 
	
	if(EXTI->PR & 1<<4) {

		int tem = 0; 
		if(check == 0&& tem == 0) {
			
			khoa_dc_tay(1); 
			while((EXTI->PR & 1<<5)== 0);
			khoa_dc_tay(2); 
			
			if( t == 0) { 
				if(trang_thai == 0) {
					control_xilanh(1, 1); 
					control_xilanh(5, 1); 
				}
				else {
					control_xilanh(4, 0); 
					control_xilanh(8, 0);
				}
			}
			if(t == 1)  {
				if(trang_thai == 0	) {
					control_xilanh(2, 1); 
					control_xilanh(6, 1);
				}
				else {
					control_xilanh(3, 0); 
					control_xilanh(7, 0);
				}
			}
			if(t == 2) {
				if(trang_thai == 0) {
					control_xilanh(3, 1); 
					control_xilanh(7, 1);
				}
				else {
					control_xilanh(2, 0); 
					control_xilanh(6, 0);
				}
			}
			if(t == 3) {
				if(trang_thai == 0) {
					control_xilanh(4, 1); 
					control_xilanh(8, 1);
				}
				else {
					control_xilanh(1, 0); 
					control_xilanh(5, 0);
				}
				
			}
			t++; 
		delayUs(1000000);
		
		if(t != 4) {
			if(trang_thai == 0)  { 
		
				xoay_trai(1, 40); 
				xoay_trai(2, 60);
			}
			else {
				xoay_phai(1, 40); 
				xoay_phai(2, 60);
			}
		}
		else {
			if(trang_thai == 0) {
				nang_canh_tay(40); 
				trang_thai = 1;
			}
			else {
				trang_thai = 0; 
				ha_canh_tay(40); 
			}
		}
		t = t %  4;
		
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
			 
			khoa_dc_tay(2); 
//			canh_tay.diachi_trai = 0x01; 
//			canh_tay.end_trai = 0xFF;
			
			while((EXTI->PR & 1<<4)== 0);
			khoa_dc_tay(1);
			
			if( t == 0) { 
				if(trang_thai == 0) {
					control_xilanh(1, 1); 
					control_xilanh(5, 1); 
				}
				else {
					control_xilanh(4, 0); 
					control_xilanh(8, 0);
				}
			}
			if(t == 1)  {
				if(trang_thai == 0	) {
					control_xilanh(2, 1); 
					control_xilanh(6, 1);
				}
				else {
					control_xilanh(3, 0); 
					control_xilanh(7, 0);
				}
			}
			if(t == 2) {
				if(trang_thai == 0) {
					control_xilanh(3, 1); 
					control_xilanh(7, 1);
				}
				else {
					control_xilanh(2, 0); 
					control_xilanh(6, 0);
				}
			}
			if(t == 3) {
				if(trang_thai == 0) {
					control_xilanh(4, 1); 
					control_xilanh(8, 1);
				}
				else {
					control_xilanh(1, 0); 
					control_xilanh(5, 0);
				}
				
			}
			t++; 
		delayUs(1000000);
		if(t != 4) {
			if(trang_thai == 0)  { 
		
				xoay_trai(1, 40); 
				xoay_trai(2, 60);
			}
			else {
				xoay_phai(1, 40); 
				xoay_phai(2, 60);
			}
		}
		else {
			if(trang_thai == 0)
				nang_canh_tay(40); 
			if(trang_thai == 0)
				trang_thai = 1; 
			else 
				trang_thai = 0; 
			
		}
		t = t %  4; 
	
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
		
		delayUs(50000); 
		if(trang_thai == 1) {
			khoa_dc_tay(3);
		
			xoay_phai(1, 40); 
			xoay_phai(2, 60);
		}
		EXTI->PR |= 1<<15;
	}
	
}

