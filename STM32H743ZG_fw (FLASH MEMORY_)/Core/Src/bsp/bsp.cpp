/*
 * bsp.cpp
 *
 *  Created on: Nov 16, 2022
 *      Author: taeka
 */


#include "bsp.h"
#include "uart.h"






void bspInit(void){

}

void delay(uint32_t ms){
	HAL_Delay(ms);
}

uint32_t millis(void){

	return HAL_GetTick();
}

extern "C" int __io_putchar(int ch){
	uartWrite(_DEF_UART1, (uint8_t *)&ch, 1);

	return 0;
}


