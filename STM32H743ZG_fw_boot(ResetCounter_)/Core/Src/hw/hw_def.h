/*
 * hw_def.h
 *
 *  Created on: Nov 16, 2022
 *      Author: taeka
 */

#ifndef SRC_COMMON_HW_DEF_H_
#define SRC_COMMON_HW_DEF_H_


#include "def.h"
#include "bsp.h"


#define _USE_HW_UART
#define 		HW_UART_MAX_CH 				3
#define _USE_HW_FLASH

#define _USE_HW_CLI
#define      HW_CLI_CMD_NAME_MAX    16
#define      HW_CLI_CMD_LIST_MAX    16
#define      HW_CLI_LINE_HIS_MAX    4
#define      HW_CLI_LINE_BUF_MAX    32

#define _USE_HW_RTC

#define _USE_HW_RESET

#endif /* SRC_COMMON_HW_DEF_H_ */
