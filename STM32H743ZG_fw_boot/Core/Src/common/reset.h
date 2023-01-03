/*
 * reset.h
 *
 *  Created on: Dec 29, 2022
 *      Author: taeka
 */

#ifndef SRC_COMMON_RESET_H_
#define SRC_COMMON_RESET_H_


#include "hw_def.h"


#ifdef _USE_HW_RESET



bool resetInit(void);
uint32_t resetGetCount(void);

#endif

#endif /* SRC_COMMON_RESET_H_ */
