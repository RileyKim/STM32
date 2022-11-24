/*
 * huart.h
 *
 *  Created on: Jul 20, 2021
 *      Author: taeka
 */

#ifndef COMMON_HUART_H_
#define COMMON_HUART_H_


#include "CGBPacket.h"
#include "Buffer.h"
#include <string>
#include <stdlib.h>
#include "cmsis_os.h"
#include "stm32h7xx_hal.h"

//#define DATA_QUEUE Buffer

//typedef class Buffer DATA_QUEUE;

#define DATA_QUEUE Buffer




#define TX_BUSY  1
#define TX_READY 0
#define RX_BUSY  2
#define UART_BUFFER_SIZE 	1024



#define DATA_GET(x,y,z)		osMessageQueueGet(x, (void *)&y, NULL, z)
#define DATA_PUT(x,y,z)		osMessageQueuePut(x, (void *)&y, 0, z)
#define GetTickCount()	osKernelGetTickCount()

#ifdef __cplusplus
class CLS_UART{
public :
	UART_HandleTypeDef *uart;
	DATA_QUEUE *m_sndq;
#ifdef USE_UART_IT
	osMessageQueueId_t m_rcvq;
#else
	DATA_QUEUE *m_rcvq;
#endif
	uint8_t				status;
	uint8_t 		_use_dma;
	uint8_t			_use_collision_avoid;
	uint32_t		_rxtick;
	uint32_t		_reinttick=0;
	uint8_t			_rxbuffer[UART_BUFFER_SIZE];
	uint16_t        _rcvqSize;
	uint32_t			_txtick;
	uint8_t 			wc = 0;
#ifdef USE_UART_IT
	CLS_UART(UART_HandleTypeDef* ahuart, DATA_QUEUE *sndq, uint8_t use_ca=0, uint8_t use_dma = 1, uint16_t rcvqSize=1024);
#else
	CLS_UART(UART_HandleTypeDef* ahuart, DATA_QUEUE *sndq, DATA_QUEUE *rcvq, uint8_t use_ca=0, uint8_t use_dma = 0);
#endif

	virtual int8_t readByte(uint8_t &c, uint32_t timeout=0);
	uint8_t write(uint8_t* buff, uint16_t size);
//	virtual uint8_t write(CGBPacket* pkt);
	void PutFormat(const char *fmt, ...);
	CLS_UART & operator<<(const char* string);
	CLS_UART & operator<<(const char c);
	CLS_UART & operator<<(const uint8_t c);
	CLS_UART & operator<<(const uint32_t l);
	CLS_UART & operator<<(const uint16_t w);
	CLS_UART & operator<<(const std::string & s);
};

extern "C"{
#endif

void Init_UART_IT();


#ifdef __cplusplus
};
#endif
#endif /* COMMON_HUART_H_ */
