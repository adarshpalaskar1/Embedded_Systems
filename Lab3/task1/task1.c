#include "stm32f429xx.h"

void delay(int dd);

int main()
{
	RCC->AHB1ENR |=(1<<6); // Enables Clock
	GPIOA->MODER |=0x14000000; // Mode Register
	GPIOA->ODR=0x6000; // Output Data Register
	
	while(1)
	{
		GPIOA->ODR=0x00;
		delay(120);
		GPIOA->ODR=0x6000;
		delay(120);
	}
  //return 1;
}

void delay (int dd) //Delay function definition
{
	int i;
	for (;dd>0;dd--)
	{
		for(i=0;i<30000;i++);
	}
}
