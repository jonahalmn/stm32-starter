#include <stdio.h>
#include <math.h>
#include "sys/cm4.h"
#include "sys/devices.h"
#include "sys/init.h"
#include "sys/clock.h"
#include "buzzer.h"

void buzzer_pwm_init (uint32_t TIM2_freq)
{
	/* buzzer is on TIM2_CH2 */
	/* configure PB9 as alternate function TIM2 */
	GPIOB.MODER = (GPIOB.MODER & ~(3<<18)) | (1<<19);

	/* setup TIM2_CH2 as alternate function */
	GPIOB.AFRH = (GPIOB.AFRH & ~(0xf<<4)) | (1<<4);  

	/* configure TIM2_CH2 as PWM output */
	TIM2.CR1   = 0x0080;	/* buffered preload up-counting mode */
	TIM2.CR2   = 0x0000;
	TIM2.SMCR  = 0x0000;
	TIM2.DIER  = 0x0000;
	TIM2.CCMR1 = 0x6800;	/* PWM mode */
	TIM2.CCMR2 = 0x0000;
	TIM2.CCER  = 0x0010;	/* channel 2 output to pin PB9 */
	TIM2.CNT   = 0x0000;
	TIM2.PSC   = get_APB1TIMCLK()/TIM2_Base;
	TIM2.ARR   = TIM2_Base/TIM2_freq;
	TIM2.CCR2  = (TIM2_Base/TIM2_freq) * 0.9;
	TIM2.EGR  |=  0x1; /* update event */
}

void toggle_buzzer()
{
	TIM2.CR1 ^= 0x1; /* counter on/off */
}
