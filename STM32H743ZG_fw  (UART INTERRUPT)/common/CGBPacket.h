/*
 * CGBPacket.h
 *
 *  Created on: Jul 20, 2021
 *      Author: taeka
 */

#ifndef COMMON_CGBPACKET_H_
#define COMMON_CGBPACKET_H_

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
//#include "huart.h"

#ifdef __cplusplus

class CLS_UART;

class CGBPacket{
public :
	uint8_t rxbuffer[64];
	uint16_t stx;
	int16_t roll;
	int16_t pitch;
	int16_t yaw;
	int16_t gx;
	int16_t gy;
	int16_t gz;
	int16_t ax;
	int16_t ay;
	int16_t az;
	uint16_t crc = 0;

	CLS_UART *uart;

};


extern "C" {
#endif
}
#ifdef __cplusplus
#endif
#endif /* COMMON_CGBPACKET_H_ */
