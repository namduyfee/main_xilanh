
#include "config.h" 

uint8_t tay_ps; 

uint8_t dc_trai[3] = {0x01, 50, 0xFF};  

uint8_t dc_phai[3] = {0x01, 50, 0xFF}; 

int t = 0; 

int check = 0; 

int main() {
	
	config(); 
	check = 1; 
	
//	initDMA1Channel2(dc_phai, &(USART3->DR), 1); 
	initDMA1Channel7(dc_trai, &(USART2->DR), 1); 

//	enItDma(1, 1); 

	while(1) {

	} 
	return 0; 
	
}

