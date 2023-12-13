
#include "config.h" 

uint8_t tx = 'b'; 
uint8_t rx; 
int check = 0; 
int main() {
	
	config(); 
	
	initDMA1Channel4(&tx, &(USART1->DR), 1); 
//	initDMA1Channel4(&(USART1->DR), &tx, 1);
//	enItDma(1, 1); 
	check = 1; 
	while(1) {

	} 
	return 0; 
	
}

