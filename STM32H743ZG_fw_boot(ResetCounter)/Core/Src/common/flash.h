/*
 * flash.h
 *
 *  Created on: Nov 25, 2022
 *      Author: taeka
 */



#include "hw_def.h"



#ifdef _USE_HW_FLASH



bool flashInit(void);
bool flashErase(uint32_t addr, uint32_t length);
bool flashWrite(uint32_t addr, uint8_t *p_data, uint32_t length);
bool flashRead(uint32_t addr, uint8_t *p_data, uint32_t length);










#endif
