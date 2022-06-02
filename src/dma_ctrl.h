#include "sys/devices.h"

#define DMA_P2M 0
#define DMA_M2P 1
#define DMA_M2M 2

#define DMA_PRIO_LOW 0
#define DMA_PRIO_MED 1
#define DMA_PRIO_HI 2
#define DMA_PRIO_VHI 3

#define DMA_SIZE_BYTE 0
#define DMA_SIZE_HALF 1
#define DMA_SIZE_WORD 2

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
);

void toggle_dma(
    struct DMA_registers *DMAx,
    uint16_t stream
);

void setup_dma_data(
    struct DMA_registers *DMAx,
    uint16_t stream,
    uint32_t base_addr,
    uint16_t size,
    uint32_t peripheral_addr
);