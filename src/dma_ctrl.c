#include "dma_ctrl.h"

void setup_dma(
    struct DMA_registers *DMAx,
    uint16_t stream,
    uint16_t channel,
    uint16_t direction,
    uint8_t priority,
    uint8_t pctrl,
    uint8_t circ,
    uint8_t data_w,
    uint8_t incrmem,
    uint8_t incrper
) {
    DMAx->S[stream].CR &= 0x0;
    DMAx->S[stream].CR = (DMAx->S[stream].CR & ~(0x7 << 25)) | ((channel & 0x7) << 25);
    DMAx->S[stream].CR = (DMAx->S[stream].CR & ~(0x3 << 16)) | ((priority & 0x3) << 16);
    DMAx->S[stream].CR = (DMAx->S[stream].CR & ~(0x3 << 11)) | ((data_w & 0x3) << 11);
    DMAx->S[stream].CR = (DMAx->S[stream].CR & ~(0x3 << 13)) | ((data_w & 0x3) << 13);
    DMAx->S[stream].CR = (DMAx->S[stream].CR & ~(0x1 << 10)) | ((incrmem & 0x1) << 10);
    DMAx->S[stream].CR = (DMAx->S[stream].CR & ~(0x1 << 9)) | ((incrper & 0x1) << 9);
    DMAx->S[stream].CR = (DMAx->S[stream].CR & ~(0x1 << 8)) | ((circ & 0x1) << 8);
    DMAx->S[stream].CR = (DMAx->S[stream].CR & ~(0x3 << 6)) | ((direction & 0x3) << 6);
    DMAx->S[stream].CR = (DMAx->S[stream].CR & ~(0x1 << 5)) | ((pctrl & 0x1) << 5);
}

void setup_dma_data(
    struct DMA_registers *DMAx,
    uint16_t stream,
    uint32_t base_addr,
    uint16_t size,
    uint32_t peripheral_addr
) {
    DMAx->S[stream].NDTR = size;
    DMAx->S[stream].PAR = peripheral_addr;
    DMAx->S[stream].M0AR = base_addr;
    DMAx->S[stream].M1AR = base_addr;
}

void toggle_dma(
    struct DMA_registers *DMAx,
    uint16_t stream
) {
    DMAx->S[stream].CR ^= 0x1;
}

void enable_dma(
    struct DMA_registers *DMAx,
    uint16_t stream
) {
    DMAx->S[stream].CR |= 0x1;
}


void print_dma() {
    printf("lisr: %d\r", DMA1.LISR);
    printf("hisr: %d\r", DMA1.HISR);
    printf("DMA CR %d", DMA1.S[6].CR);
}