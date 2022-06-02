#include "sys/devices.h"

#define MODER_INPUT 0
#define MODER_GPO 1
#define MODER_AF 2
#define MODER_ANALOG 3

#define OTYPER_PUSHPULL 0
#define OTYPER_OPENDRAIN 1

#define OSPEEDR_LOW 0
#define OSPEEDR_MEDIUM 1
#define OSPEEDR_FAST 2
#define OSPEEDR_HIGH 3

#define PUPDR_NONE 0
#define PUPDR_UP 1
#define PUPDR_DOWN 2


void setup_gpio_mode(struct GPIO_registers *GPIOx, uint32_t id, uint32_t mode);
void setup_gpio_otyper(struct GPIO_registers *GPIOx, uint32_t id, uint32_t typer);
void setup_gpio_ospeedr(struct GPIO_registers *GPIOx, uint32_t id, uint32_t speed);
void setup_gpio_pupdr(struct GPIO_registers *GPIOx, uint32_t id, uint32_t pupdr);
void setup_gpio_afr(struct GPIO_registers *GPIOx, uint32_t id, uint32_t afr);

uint8_t read_gpio(struct GPIO_registers *GPIOx, uint32_t id);
uint8_t read_gpio_output(struct GPIO_registers *GPIOx, uint32_t id);

void write_gpio(struct GPIO_registers *GPIOx, uint32_t id, uint8_t value);

