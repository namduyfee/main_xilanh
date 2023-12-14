
#include "config.h" 
#include "stdio.h"
uint8_t tay_ps; 



dc canh_tay = {0x01, 7, 0xFF, 0x02, 10, 0xFF}; 



int t = 0;


int check = 0; 

int main() {
	
	config(); 
	 
	
	initDMA1Channel7(&(canh_tay.diachi_trai), &(USART2->DR), 6);
//	enItDma(1, 1); 

	while(1) {

	} 
	return 0; 
	
}

