#include "gpio.h"

void setup_gpio_mode(struct GPIO_registers *GPIOx, uint32_t id, uint32_t mode) {
  GPIOx->MODER = (GPIOx->MODER & ~(3<<id*2)) | ((mode & 0x3)<<id*2);
}


void setup_gpio_otyper(struct GPIO_registers *GPIOx, uint32_t id, uint32_t typer) {
  GPIOx->OTYPER = (GPIOx->OTYPER & ~(1<<id)) | ((typer & 0x1)<<id);
}

void setup_gpio_ospeedr(struct GPIO_registers *GPIOx, uint32_t id, uint32_t speed) {
  GPIOx->OSPEEDR = (GPIOx->OSPEEDR & ~(3<<id*2)) | ((speed & 0x3)<<id*2);
}

void setup_gpio_pupdr(struct GPIO_registers *GPIOx, uint32_t id, uint32_t pupdr) {
  GPIOx->PUPDR = (GPIOx->PUPDR & ~(3<<id*2)) | ((pupdr & 0x3)<<id*2);
}

void setup_gpio_afr(struct GPIO_registers *GPIOx, uint32_t id, uint32_t afr) {
  if(id <= 7) {
    GPIOx->AFRL = (GPIOx->AFRL & ~(0xf<<id*4)) | (afr<<id*4);
  } else {
    GPIOx->AFRH = (GPIOx->AFRH & ~(0xf<<((id-8)*4))) | (afr<<((id-8)*4));
  }
}


uint8_t read_gpio(struct GPIO_registers *GPIOx, uint32_t id) {
  return (GPIOx->IDR >> id) & 0x1;
}

uint8_t read_gpio_output(struct GPIO_registers *GPIOx, uint32_t id) {
  return (GPIOx->ODR >> id) & 0x1;
}

void write_gpio(struct GPIO_registers *GPIOx, uint32_t id, uint8_t value) {
  GPIOx->ODR = (GPIOx->ODR & ~(1<<id)) | ((value & 0x1)<<id);
}
