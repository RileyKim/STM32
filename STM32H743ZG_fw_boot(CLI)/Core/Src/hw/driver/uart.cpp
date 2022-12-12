/*
 * uart.cpp
 *
 *  Created on: Nov 16, 2022
 *      Author: taeka
 */


#include "def.h"
#include "uart.h"
#include "qbuffer.h"


#define UART5_IT


//UART_HandleTypeDef huart8;
//UART_HandleTypeDef huart1;


static bool is_open[UART_MAX_CH];
static qbuffer_t qbuffer[UART_MAX_CH];

static uint8_t rx_buf[256];
static uint8_t rx_data[UART_MAX_CH];


uint32_t uartPrintf(uint8_t ch, char *fmt, ...);


bool uartInit(void){
	for(int i =0; i<UART_MAX_CH; i++){
		is_open[i] = false;
	}
	return 0;
}
bool uartOpen(uint8_t ch, uint32_t baud){
	bool ret = false;


	switch(ch)
	{
		case _DEF_UART1:

			qbufferCreate(&qbuffer[_DEF_UART1], &rx_buf[0], 256);

			if(HAL_UART_Init(&huart5) != HAL_OK){
				ret = false;
			}
			else
			{
				ret = true;
				is_open[ch] = true;
#ifdef UART5_DMA
				if(HAL_UART_Receive_DMA(&huart5, &rx_buf[0], 256)!=HAL_OK)
#endif

#ifdef UART5_IT
				if(HAL_UART_Receive_IT(&huart5, (uint8_t *)&rx_data[_DEF_UART1], 1) != HAL_OK)
#endif
				{
					ret = false;
				}
#ifdef UART5_DMA
				qbuffer[ch].in = qbuffer[ch].len - DMA2_Stream2->NDTR;
				qbuffer[ch].out = qbuffer[ch].in;
#endif
			}
			break;

		case _DEF_UART2:

			qbufferCreate(&qbuffer[_DEF_UART2], &rx_buf[0], 256);

			if(HAL_UART_Init(&huart1) != HAL_OK){
				ret = false;
			}
			else
			{
				ret = true;
				is_open[ch] = true;
				if(HAL_UART_Receive_DMA(&huart1, &rx_buf[0], 256)!=HAL_OK)


#ifdef UART1_IT
				if(HAL_UART_Receive_IT(&huart1, (uint8_t *)&rx_data[_DEF_UART2], 1) != HAL_OK)
#endif
				{
					ret = false;
				}
				qbuffer[ch].in = qbuffer[ch].len - DMA1_Stream0->NDTR;
				qbuffer[ch].out = qbuffer[ch].in;
			}
			break;
	}

	return ret;
}
uint32_t uartAvailable(uint8_t ch){
	uint32_t ret = 0;

	switch(ch){

	case _DEF_UART1:
#ifdef UART5_DMA
		qbuffer[ch].in = qbuffer[ch].len - DMA2_Stream2->NDTR;
#endif
		ret = qbufferAvailable(&qbuffer[ch]);
		break;


	case _DEF_UART2:
		qbuffer[ch].in = qbuffer[ch].len - DMA1_Stream0->NDTR;
		ret = qbufferAvailable(&qbuffer[ch]);
		break;
	}
	return ret;
}
uint8_t uartRead(uint8_t ch){
	uint8_t ret = 0;

	switch(ch){

		case _DEF_UART1:
			qbufferRead(&qbuffer[_DEF_UART1], &ret, 1);
			return ret;
			break;


		case _DEF_UART2:
			qbufferRead(&qbuffer[_DEF_UART2], &ret, 1);
			return ret;
			break;
	}
	return ret;
}


void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
#ifdef UART5_IT
	if(huart->Instance == UART5){
		qbufferWrite(&qbuffer[_DEF_UART1], &rx_data[_DEF_UART1], 1);
		HAL_UART_Receive_IT(&huart5, (uint8_t *)&rx_data[_DEF_UART1], 1);
	}
#endif
}


uint32_t uartWrite(uint8_t ch, uint8_t *p_data, uint32_t length){
	uint32_t ret = 0;
	HAL_StatusTypeDef status;
	switch(ch){

		case _DEF_UART1:
			status = HAL_UART_Transmit(&huart5, p_data, length, 100);
			if(status == HAL_OK){
				ret = length;
			}
			break;

		case _DEF_UART2:
			status = HAL_UART_Transmit(&huart1, p_data, length, 100);
			if(status == HAL_OK){
				ret = length;
			}
			break;
	}
	return ret;
}


uint32_t uartPrintf(uint8_t ch, char *fmt, ...){
	char buf[256];
	va_list args;
	int len;

	va_start(args, fmt);
	len = vsnprintf(buf , 256, fmt, args);

	uartWrite(ch, (uint8_t *)buf, len);

	va_end(args);

	return 0;
}
