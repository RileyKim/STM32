/*
 * Buffer.h
 *
 *  Created on: Jul 20, 2021
 *      Author: taeka
 */

#ifndef COMMON_BUFFER_H_
#define COMMON_BUFFER_H_


#include "stdint.h"
#include "stdlib.h"

class Buffer{
public:
	Buffer();
	void clear();
	uint8_t _buff[2048];
private:
	uint16_t _head;
	uint16_t _tail;
	uint16_t _count;
	uint16_t _size;

};


#endif /* COMMON_BUFFER_H_ */
