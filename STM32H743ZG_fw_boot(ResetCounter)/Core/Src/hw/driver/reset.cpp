/*
 * reset.cpp
 *
 *  Created on: Dec 29, 2022
 *      Author: taeka
 */



#include "reset.h"
#include "rtc.h"
#include "uart.h"


uint32_t reset_count = 0;

bool resetInit(void)
{
	bool ret = true;
//	HAL_PWR_EnableBkUpAccess();
	__HAL_RCC_RTC_ENABLE();


//reset pin check...i don't know why it is not working..
///it is not working...
	if(RCC->CSR & (1<<26))
	{
		rtcBackupRegWrite(0, rtcBackupRegRead(0) + 1);
		delay(500);
		reset_count = rtcBackupRegRead(0);
	}


////////////////////////////////////////////////


	rtcBackupRegWrite(0, rtcBackupRegRead(0)+1);


//	//임시방편
	//(rtcBackupRegRead(0) == 1 -> firmware // (rtcBackupRegRead(0) == 0 -> bootloader
	if(rtcBackupRegRead(0) > 1 || rtcBackupRegRead(0) < 0)
	{
		rtcBackupRegWrite(0, 0);
	}

	reset_count = rtcBackupRegRead(0);



//	HAL_PWR_DisableBkUpAccess();
	return ret;
}

uint32_t resetGetCount(void)
{

	return reset_count;
}


