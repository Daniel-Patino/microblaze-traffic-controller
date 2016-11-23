/* defines */
#define TRUE 1
#define FALSE 0
#define ERRORS 1
#define NOERRORS 0
#define CONSTANT 0
#define FIRST_PRIME 2
#define SECOND_PRIME 3
#define PRIME_MAX 500


#include <stdio.h>
#include "stm32l476xx.h"
#include "lcd.h"

void delay();

int main(void){
	
	unsigned short arrayOfPrime[PRIME_MAX];
	unsigned short numberOfPrimesInArray = 1;
	unsigned short numberToCheckIfPrime = SECOND_PRIME;
	
	unsigned short boolThisNumberIsPrime = TRUE;
	unsigned short nthPrime = CONSTANT;
	unsigned short setArray = CONSTANT;
	unsigned short testForPrime = CONSTANT;
	unsigned short primeToFind = 1;
	unsigned short factor = 1;
	
	char string[6];


	arrayOfPrime[CONSTANT] = FIRST_PRIME;
	
	// Enable the clock to GPIO Ports A, B, and E	
	RCC->AHB2ENR |= RCC_AHB2ENR_GPIOAEN;
	
	// Set PA0, PA1, PA2, PA3, and PA5 as input
	GPIOA->MODER &= ~0xCFF;

	// Configure PA0, PA1, PA2, PA3, PA5 as pull-down
	GPIOA->PUPDR &= ~0xCFF;
	GPIOA->PUPDR |= 0x8AA;
	
    // Make sure to set entire array to CONSTANT, since it doesn't seem to be set that way
	for(setArray = 1; setArray <= PRIME_MAX; setArray++){
        arrayOfPrime[setArray] = CONSTANT;
	}


	// This loop determines how many prime numbers we wish to find
	while(nthPrime < PRIME_MAX){


		for(testForPrime = CONSTANT; testForPrime < numberOfPrimesInArray; testForPrime++){
			if(numberToCheckIfPrime % arrayOfPrime[testForPrime] == CONSTANT){
				boolThisNumberIsPrime = FALSE;
				break;
			}
			else{
				boolThisNumberIsPrime = TRUE;
			}
		}


		if(boolThisNumberIsPrime){
			arrayOfPrime[numberOfPrimesInArray] = numberToCheckIfPrime;
			numberOfPrimesInArray++;
			nthPrime++;
		}


		numberToCheckIfPrime = numberToCheckIfPrime + 2;
	}
	
	LCD_Initialization();
	
	while (1) {
		sprintf(string, "%i", primeToFind);
		LCD_DisplayString((uint8_t*)string);
		
		// middle button
		if((GPIOA->IDR & 0x1) != 0x00){
			sprintf(string, "%i", arrayOfPrime[primeToFind - 1]);
			LCD_DisplayString((uint8_t*)string);
			while(1);
		}
	
		// left button
		if((GPIOA->IDR & 0x2) != 0x00){
			factor /= 10;
			if (factor < 1)
				factor = 1;
			delay();
		}
		
		// right button
		if((GPIOA->IDR & 0x4) != 0x00){
			factor *= 10;
			if (factor > 100)
				factor = 100;
			delay();
		}
		
		// up button
		if((GPIOA->IDR & 0x8) != 0x00){
			LCD_Clear();
			if (primeToFind + factor <= PRIME_MAX)
				primeToFind += factor;
			delay();
		}
		
		// down button
		if((GPIOA->IDR & 0x20) != 0x00){
			LCD_Clear();
			if (primeToFind - factor >= 1)
				primeToFind -= factor;
			delay();
		}		
	}
}

void delay()
{
    int i = 0;
    while (100000 > i)
			i++;
}