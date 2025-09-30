#include <stdint.h>
#include "stm32f446xx.h"

int main(void)
{
	RCC->APBENR1 |= RCC_APBENR1_GPIOAEN;				// Enable Clock GPIOA 
	GPIOA->MODER  |= 1 << GPIO_MODER_MODE5_Pos;		// PA5 output mode

	while(1){
		for(uint32_t i = 0 ; i<100000; i++);
			GPIOA->ODR^= 1<<5				// Toggle PA5	
	}
}