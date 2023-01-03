/*
 * rtc.cpp
 *
 *  Created on: Dec 29, 2022
 *      Author: taeka
 */



#include "rtc.h"



//extern RTC_HandleTypeDef hrtc;
extern RTC_HandleTypeDef hrtc; // static으로 잡으니 전원 on/off시 쓰레기값 들어감..

bool rtcInit(void)
{
	bool ret = true;


	return ret;
}

void rtcBackupRegWrite(uint32_t index, uint32_t data)
{
	HAL_RTCEx_BKUPWrite(&hrtc, index, data);

}


uint32_t rtcBackupRegRead(uint32_t index)
{
	return HAL_RTCEx_BKUPRead(&hrtc, index);
}
