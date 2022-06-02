#include "dac.h"

void setup_dac(uint32_t channel) {
    DAC.CR = (DAC.CR & ~(0x1 << 2)) | ((0x1) << 2);
    DAC.CR = (DAC.CR & ~(0x7 << 3)) | ((channel & 0x7) << 3);
    DAC.CR = (DAC.CR & ~(0x1 << 12)) | ((0x1) << 12);
}

void start_dac() {
    DAC.CR |= 0x1;
}