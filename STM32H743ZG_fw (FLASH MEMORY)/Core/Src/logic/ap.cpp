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
//			logPrintf("print test %d \r\n", millis());
		}

		if(uartAvailable(_DEF_UART1) > 0)
		{
			uint8_t rx_data;

			rx_data = uartRead(_DEF_UART1);

			if(rx_data == '1')
			{
				uint8_t buf[32];
				logPrintf("Read...\r\n");
				flashRead(0x08104000 + (70*1024), buf, 32);

				for(int i = 0; i<32; i++)
				{
					logPrintf("0x%X : 0x%X\r\n",0x08100000 + (70*1024) + i, buf[i] );
				}
			}


			//why don't erase address in bank1....? address in bank2 can be erased.
			if(rx_data == '2')
			{
				logPrintf("Erase....\r\n");
				if(flashErase(0x08104000 + (70*1024), 32) == true){
					logPrintf("Erase OK \r\n");
				}
				else
				{
					logPrintf("Erase Fail..\r\n");
				}
			}

			if(rx_data == '3')
			{
				uint8_t buf[32];
				logPrintf("Write...\r\n");
				for(int i = 0; i<32; i++)
				{
					buf[i]=i;
				}
				if(flashWrite(0x08104000 + (70*1024), buf, 32) == true)
				{
					logPrintf("Write OK \r\n");
				}
				else
				{
					logPrintf("Write Fail..\r\n");
				}
			}

		}
#if 0

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
#endif


	}
}


