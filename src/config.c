
#include "config.h"


void config(void) {
	
	configGPIOA(); 
	configGPIOB(); 
	configGPIOC(); 
	configAFIO();
	tam = 1; 
	configEXTI(); 
	tam = 2; 
	configNVIC(); 
	tam = 3; 
	configTIM4();
	
	configDMA1(); 
	
	configUART1(); 
	configUART2(); 
	configUART3(); 
	
//	configI2c(); 
	
	
//	configTIM3();
//	configTIM1(); 
	
	 
	
	
}