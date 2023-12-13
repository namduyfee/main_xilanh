
#include "config.h"


void config(void) {
	
	configGPIOA(); 
	configGPIOB(); 
	configGPIOC(); 
//	configAFIO();
//	configNVIC(); 
//	configEXTI(); 
	
	
	configTIM4();
	
	configDMA1(); 
	
	configUART1(); 
	configUART2(); 
	configUART3(); 
	
	configI2c(); 
	
	
//	configTIM3();
//	configTIM1(); 
	
	 
	
	
}