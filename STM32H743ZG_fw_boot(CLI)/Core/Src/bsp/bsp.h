/*
 * bsp.h
 *
 *  Created on: Nov 16, 2022
 *      Author: taeka
 */

#ifndef SRC_BSP_BSP_H_
#define SRC_BSP_BSP_H_



#include "def.h"
#include "stm32h743xx.h"
#include "stm32h7xx_hal.h"

#define _USE_LOG_PRINT		1

#if _USE_LOG_PRINT
#define logPrintf(fmt, ...)			printf(fmt, ##__VA_ARGS__)
#else
#define logPrintf(fmt, ...)
#endif
void bspInit(void);

void delay(uint32_t ms);
uint32_t millis(void);




#endif /* SRC_BSP_BSP_H_ */
