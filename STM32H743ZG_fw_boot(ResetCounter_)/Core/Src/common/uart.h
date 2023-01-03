/*
 * uart.h
 *
 *  Created on: Nov 16, 2022
 *      Author: taeka
 */

#ifndef SRC_COMMON_UART_H_
#define SRC_COMMON_UART_H_


#include "hw_def.h"

extern UART_HandleTypeDef huart8;
extern UART_HandleTypeDef huart5;
extern UART_HandleTypeDef huart1;
extern DMA_HandleTypeDef hdma_usart1_rx;
extern DMA_HandleTypeDef hdma_uart5_rx;


#ifdef __cplusplus
extern "C" {
#endif

#ifdef _USE_HW_UART
#define UART_MAX_CH					HW_UART_MAX_CH

bool     uartInit(void);
bool     uartOpen(uint8_t ch, uint32_t baud);
uint32_t uartAvailable(uint8_t ch);
uint8_t uartRead(uint8_t ch);
uint32_t uartWrite(uint8_t ch, uint8_t *p_data, uint32_t length);
uint32_t uartPrintf(uint8_t ch, char *fmt, ...);

#endif


#ifdef __cplusplus
};
#endif

#endif /* SRC_COMMON_UART_H_ */
