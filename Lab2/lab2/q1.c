#include "stm32f4xx.h"

int main(void)
{
	unsigned short x,y,z;
	x=0x1B;
	y=0x0B;
	RCC->AHB1ENR |=1;
	GPIOA->MODER |=0x5555;
	GPIOA->ODR=0x00;
	z=x+y;
	GPIOA->ODR=z;
	
	return 0;
}
