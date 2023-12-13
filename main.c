
#include "config.h" 

uint8_t tx = 'a'; 
uint8_t rx; 
int check = 0; 

int main() {
	
	config(); 
	
	initDMA1Channel2(&tx, &(USART3->DR), 1); 

//	enItDma(1, 1); 
	check = 1; 
	while(1) {

	} 
	return 0; 
	
}

