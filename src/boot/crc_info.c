#include "crc_info.h"

#ifndef FLASH_SIZE
#define FLASH_SIZE 0x00000000
#endif

#ifndef FLASH_CRC
#define FLASH_CRC  0xffffffff
#endif

const __attribute__(( section("crc_info") )) 
crc_info flash_crc_info = { FLASH_SIZE, FLASH_CRC };
