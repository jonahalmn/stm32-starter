#include <stdio.h>
#include <math.h>
#include "sys/cm4.h"
#include "sys/devices.h"
#include "sys/init.h"
#include "sys/clock.h"
#include "button.h"

void button_init()
{
	/* configure PB3-PB6, PB8 as inputs, no pull */
	GPIOB.MODER = GPIOB.MODER & ~(0xFF<<6 & 3<<16);
	GPIOB.PUPDR = GPIOB.PUPDR & ~(0xFF<<6 & 3<<16);
	/* configure PC13 as inputs, no pull */
	GPIOC.MODER = GPIOC.MODER & ~(0x3<<26);
	GPIOC.PUPDR = GPIOC.PUPDR & ~(0x3<<26);
}

void button_irq_init ()
{
	/* configure interruptions on PB8 */
	/* set PB8 as EXTI8 input */
	SYSCFG.EXTICR3 = (SYSCFG.EXTICR3 & ~(0xf<<0)) | (0x1<<0);

	/* setup interrupt for EXTI8, falling edge */
	EXTI.IMR  |= (1<<8);
	EXTI.FTSR &= ~(1<<8);
	EXTI.RTSR |= (1<<8);

	/* enable EXTI5_9 IRQ */
	NVIC.ISER[23/32] = (1<<(23%32)); 
 
	/* configure interruptions on PC13 */
	/* set PC13 as EXTI13 input */
	SYSCFG.EXTICR4 = (SYSCFG.EXTICR4 & ~(0xf<<4)) | (0x2<<4);

	/* setup interrupt for EXTI13, falling edge */
	EXTI.IMR  |= (1<<13);
	EXTI.FTSR &= ~(1<<13);
	EXTI.RTSR |= (1<<13);

	/* enable EXTI15_10 IRQ */
	NVIC.ISER[40/32] = (1<<(40%32)); 
}

uint32_t button_poll()
{
	/* check if PC13 pressed - return 1, else return 0 */
	return (~(GPIOC.IDR>>13) & 1); /* 1 if pressed */
}


