/*
 * rtc.h
 *
 *  Created on: Dec 29, 2022
 *      Author: taeka
 */

#ifndef SRC_COMMON_RTC_H_
#define SRC_COMMON_RTC_H_

#include "hw_def.h"


#ifdef _USE_HW_RTC


bool rtcInit(void);
void rtcBackupRegWrite(uint32_t index, uint32_t data);
uint32_t rtcBackupRegRead(uint32_t index);

#endif



#endif /* SRC_COMMON_RTC_H_ */
