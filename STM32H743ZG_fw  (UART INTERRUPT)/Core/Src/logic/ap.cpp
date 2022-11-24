/*
 * ap.cpp
 *
 *  Created on: Nov 16, 2022
 *      Author: taeka
 */


#include "ap.h"



void apInit(void){
	uartOpen(_DEF_UART1, 115200);
	uartOpen(_DEF_UART2, 115200);
}


void apMain(void){
	uint32_t pre_time;
	pre_time = HAL_GetTick();

	while(1){
		if(HAL_GetTick()-pre_time >= 500){
			pre_time = HAL_GetTick();
			uartPrintf(_DEF_UART2, "HELLO %d\r\n", millis());
		}

		if(uartAvailable(_DEF_UART2)>0){
			uint8_t rx_data;
			rx_data = uartRead(_DEF_UART2);
			uartPrintf(_DEF_UART2, "UART8 :  %c %X\r\n", rx_data, rx_data);

		}
	}
}


