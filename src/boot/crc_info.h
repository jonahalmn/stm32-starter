#include<stdint.h>

typedef struct {
  uint32_t data_size;
  uint32_t data_crc;
} crc_info;

extern const crc_info flash_crc_info;
