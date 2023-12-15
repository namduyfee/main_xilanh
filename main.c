
#include "config.h" 
#include "stdio.h"
#include "function.h"
uint8_t tay_ps; 
int tam = 0; 
// 0 : gap 1 : tha 
uint8_t trang_thai = 0; 

// 10000 11

//uint8_t dc_keo[3] = {0x83, 7 , 0xFF}; 

dc canh_tay = {0x01, 1, 0xFF, 0x82, 1, 0xFF, 0x03, 40 , 0xFF}; 

int t = 0;

int check = 0; 

int main() {
	
	config(); 
//	 
//	initDMA1Channel7(dc_keo, &(USART2->DR), 3);
//	check = 10; 

	initDMA1Channel7(&(canh_tay.diachi_trai), &(USART2->DR), 9); 
	tam = 1; 
//	enItDma(1, 1); 

	while(1) {

	} 
	return 0; 
	
}

