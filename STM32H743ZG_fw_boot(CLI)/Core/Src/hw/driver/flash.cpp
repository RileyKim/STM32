/*
 * flash.cpp
 *
 *  Created on: Nov 25, 2022
 *      Author: taeka
 */


#include "flash.h"
#include "string.h"

#define FLASH_MAX_SECTOR		8
#define constrain(amt,low,high) ((amt)<(low)?(low):((amt)>(high)?(high):(amt)))

typedef struct
{

	uint16_t index;
	uint32_t bank;

	uint32_t addr;
	uint32_t length;


}flash_tbl_t;


const flash_tbl_t flash_tbl_bank1[FLASH_MAX_SECTOR] =
	{
        {0, FLASH_BANK_1, 0x08000000, 128*1024},
        {1, FLASH_BANK_1, 0x08020000, 128*1024},
        {2, FLASH_BANK_1, 0x08040000, 128*1024},
        {3, FLASH_BANK_1, 0x08060000, 128*1024},
        {4, FLASH_BANK_1, 0x08080000, 128*1024},
        {5, FLASH_BANK_1, 0x080A0000, 128*1024},
        {6, FLASH_BANK_1, 0x080C0000, 128*1024},
        {7, FLASH_BANK_1, 0x080E0000, 128*1024},

	};

const flash_tbl_t flash_tbl_bank2[FLASH_MAX_SECTOR] =
    {
        {0, FLASH_BANK_2, 0x08100000, 128*1024},
        {1, FLASH_BANK_2, 0x08120000, 128*1024},
        {2, FLASH_BANK_2, 0x08140000, 128*1024},
        {3, FLASH_BANK_2, 0x08160000, 128*1024},
        {4, FLASH_BANK_2, 0x08180000, 128*1024},
        {5, FLASH_BANK_2, 0x081A0000, 128*1024},
        {6, FLASH_BANK_2, 0x081C0000, 128*1024},
        {7, FLASH_BANK_2, 0x081E0000, 128*1024},
    };



static flash_tbl_t flash_tbl[FLASH_MAX_SECTOR];

static bool flashInSector(uint16_t sector_num, uint32_t addr, uint32_t length);

bool flashInit(void)
{
	return true;
}

bool flashErase(uint32_t addr, uint32_t length)
{

	bool ret = false;

	int16_t start_sector = -1;
	int16_t end_sector = -1;
	uint32_t banks;

	const flash_tbl_t *flash_tbl;

	HAL_FLASH_Unlock();

	for (banks = 0; banks < 2; banks++)
	{
		if (banks == 0)
		{
		  flash_tbl = flash_tbl_bank1;
		}
		else
		{
		  flash_tbl = flash_tbl_bank2;
		}

		for(int i = 0; i<FLASH_MAX_SECTOR; i++){

			bool update = false;
			uint32_t start_addr;
			uint32_t end_addr;

			start_addr = flash_tbl[i].addr;
			end_addr = flash_tbl[i].addr + flash_tbl[i].length -1;


			if(start_addr >= addr && start_addr < (addr+length))
			{
				update = true;
			}
			if(end_addr >= addr && end_addr <(addr+length))
			{
				update = true;

			}
			if(addr >= start_addr && addr <= end_addr)
			{
				update = true;
			}
			if((addr+length-1) >= start_addr && (addr+length-1) <=end_addr)
			{
				update = true;
			}

			if(update == true){
				if(start_sector < 0)
				{
					start_sector = i;
				}
				end_sector = i;
			}
		}

		if(start_sector >= 0)
		{
			HAL_StatusTypeDef status;
			FLASH_EraseInitTypeDef EraseInit;
			uint32_t SectorError;

			EraseInit.Sector = start_sector;
			EraseInit.NbSectors = (end_sector - start_sector)+1;
			EraseInit.TypeErase = FLASH_TYPEERASE_SECTORS;
			EraseInit.VoltageRange = FLASH_VOLTAGE_RANGE_3;
			EraseInit.Banks = flash_tbl[start_sector].bank;


			status = HAL_FLASHEx_Erase(&EraseInit, &SectorError);

			if(status == HAL_OK){
				ret = true;
			}
		}
	}
	HAL_FLASH_Lock();

	return ret;
}

bool flashWrite(uint32_t addr, uint8_t *p_data, uint32_t length)
{
	bool ret = true;
	uint32_t index;
	uint32_t write_length;
	uint32_t write_addr;
	uint8_t buf[32];
	uint32_t offset;
	HAL_StatusTypeDef status;




	HAL_FLASH_Unlock();

	index = 0;
	offset = addr%32;

	if(offset != 0 || length <32)
	{
		write_addr = addr - offset;
		memcpy(&buf[0], (void *)write_addr, 32);
		memcpy(&buf[offset], &p_data[0], constrain(32-offset, 0, length));
		status = HAL_FLASH_Program(FLASH_TYPEPROGRAM_FLASHWORD, write_addr, (uint32_t)buf);


		if(status != HAL_OK)
		{
			return false;
		}

		if(offset == 0 && length <32)
		{
			index += length;
		}
		else
		{
			index += (32-offset);
		}
	}

	while(index < length)
	{
		write_length = constrain(length - index, 0, 32);

		if(write_length == 32){
			status = HAL_FLASH_Program(FLASH_TYPEPROGRAM_FLASHWORD, addr + index, (uint32_t)&p_data[index]);
			if(status != HAL_OK)
			{
				ret = false;
				break;
			}
			index += write_length;
		}

		if((length - index) > 0 && (length - index) < 32)
		{
			offset = length - index;
			write_addr = addr + index;
			memcpy(&buf[0], (void *)write_addr, 32);
			memcpy(&buf[0], &p_data[index], offset);

			status = HAL_FLASH_Program(FLASH_TYPEPROGRAM_FLASHWORD,write_addr, (uint32_t)buf);

			if(status != HAL_OK)
			{
				return false;
			}
			break;
		}
	}

	HAL_FLASH_Lock();
	return ret;
}

bool flashRead(uint32_t addr, uint8_t *p_data, uint32_t length)
{
	bool ret = true;

	uint8_t *p_byte = (uint8_t*)addr;

	for(int i = 0; i<(int)length; i++)
	{
		p_data[i] = p_byte[i];
	}

	return ret;
}

static bool flashInSector(uint16_t sector_num, uint32_t addr, uint32_t length)
{
	bool ret = false;

	uint32_t sector_start;
	uint32_t sector_end;
	uint32_t flash_start;
	uint32_t flash_end;

	sector_start 	= flash_tbl[sector_num].addr;
	sector_end 		= flash_tbl[sector_num].addr + flash_tbl[sector_num].length -1;
	flash_start 	= addr;
	flash_end		= addr + length -1;

	if(sector_start >= flash_start && sector_start <= flash_end)
	{
		ret = true;
	}

	if(sector_end >= flash_start && sector_end <= flash_end)
	{
		ret = true;
	}

	if(flash_start >= sector_start && flash_start <= sector_end)
	{
		ret = true;
	}

	if(flash_end >= sector_start && flash_end <= sector_end)
	{
		ret = true;
	}
	return ret;
}

