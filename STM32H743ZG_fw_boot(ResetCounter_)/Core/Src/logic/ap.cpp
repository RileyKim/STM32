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

	cliOpen(_DEF_UART1, 115200);
	cliOpenLog(_DEF_UART2, 115200);
}


void apMain(void){
	uint32_t pre_time;
	pre_time = HAL_GetTick();

	while(1){
//		if(uartAvailable(_DEF_UART1)>0)
//		{
//			uint8_t rx_data;
//			rx_data = uartRead(_DEF_UART1);
//			if(rx_data == 'q')
//			{
//				resetInit();
//			}
//		}

		if(HAL_GetTick()-pre_time >= 500){

//			resetInit();
			pre_time = HAL_GetTick();
//			logPrintf("print test %d \r\n", millis());

//			resetInit();
			uartPrintf(_DEF_UART1, " resetCount : %d 	Time :  %d \r\n",resetGetCount(), pre_time);
		}



#if 0 //UART

		if(uartAvailable(_DEF_UART1)>0){
			uint8_t rx_data;
			rx_data = uartRead(_DEF_UART1);
			uartPrintf(_DEF_UART1, "UART5 :  %c %X\r\n", rx_data, rx_data);

		}

		if(uartAvailable(_DEF_UART2)>0){
			uint8_t rx_data;
			rx_data = uartRead(_DEF_UART2);
			uartPrintf(_DEF_UART2, "UART1 :  %c %X\r\n", rx_data, rx_data);

		}
#endif //UART
		cliMain();
	}
}


