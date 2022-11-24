/*
 * Buffer.cpp
 *
 *  Created on: Jul 20, 2021
 *      Author: taeka
 */

#include <Buffer.h>

Buffer::Buffer(){
	_head = _tail = 0;
	_count = 0;
	_size = 0;
}

void Buffer::clear(){
	while(_head != _tail) pop();
}
