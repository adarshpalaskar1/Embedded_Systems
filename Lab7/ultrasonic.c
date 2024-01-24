#include "stm32f429xx.h"
#include "uart.h"
#include "RccConfig.h"

#define ARM_MATH_CM4

void GPIO_Init(void);
void TIM2_us_Delay(uint32_t delay); 																							


uint32_t static data;    //  vriable declaration etc.
double static time,dist;   //variable for collecting the distance, time etc.

void GPIO_Init () {									//Configuring PE4 for generating pulse sent to trig pin
	
	RCC->AHB1ENR = (1<<2) + (1<<4); 				//Enable GPIOC/E clock
	GPIOE->MODER = 0x100;			//Set the PE4 pin to output mode

	//Configuring output from echo pin to be sent to the board (PC6 pin)
	GPIOC->MODER = 0x00;				//Set PC6 to input mode
}


void TIM2_us_Delay(uint32_t delay){
	RCC->APB1ENR |= 1; 								//Start the clock for the timer peripheral
	uint32_t val;
	val = delay*16 - 1;
	TIM2->ARR = val; 									// Total period of the timer
	TIM2->CNT = 0;
	TIM2->CR1 |= 1;										//Start the Timer
	while(!(TIM2->SR & TIM_SR_UIF)){} //Polling the update interrupt flag
	TIM2->SR &= ~0x0001; 							//Reset the update interrupt flag
}

int main(){
	char buffer[30] ={0};       // initializing a buffer string that will be utilized for sending to UART for display
		
	SysClockConfig();
	UART1Config();
	RCC->CFGR |= 0<<10; 							// set APB1 = 16 MHz
	GPIO_Init();
		
	UART1_SendString("Ultrasonic");		// Setting trig pin to low to initialize the module

	while(1){
		//1. Sending 10us pulse to  PE4
		GPIOE->BSRR = 0x0;			//PE4 is low
		TIM2_us_Delay(2);   //waiting just for 2 us
		GPIOE->BSRR = 0x010;		//PE4 set to High
		TIM2_us_Delay(10);		 // wait for 10us
		GPIOE->BSRR = 0x0;		// Make PE4 low again
		TIM2_us_Delay(4);
		
		//2. Measure the pulse width of the pulse sent from the echo pin by polling IDR for port C
		//??????? ???? write your logic ????????
		data = 0;
		while(GPIOC->IDR & 64){
			data += 1;
		}
			

		//3.Converting the gathered data into distance in cm and send to UART
		
                  //??????? ???? write your logic ????????
		if(data != 0){
			time = data*(0.0625*0.000001);
			dist = ((time*340)/2)*100;
			sprintf(buffer, "Distance : %f\r\n",dist);
			UART1_SendString(buffer);
		}
		TIM2_us_Delay(4);
		data = 0;
		
	}  //  end of while()

}  //  end of main()