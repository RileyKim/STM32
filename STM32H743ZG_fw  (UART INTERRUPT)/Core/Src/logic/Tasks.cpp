/*
 * Tasks.cpp
 *
 *  Created on: Nov 16, 2022
 *      Author: taeka
 */

#include "def.h"
#include "ap.h"
#include "hw.h"
#include "hw_def.h"
#include "def.h"
#include "stm32h743xx.h"
#include "stm32h7xx_hal.h"
#include "main.h"


extern UART_HandleTypeDef huart8;


extern "C" void DebugTask(void){
	hwInit();
	apInit();
	apMain();

}


extern "C" void MainTask(void){

}

extern "C" void SensingTask(void){

}


