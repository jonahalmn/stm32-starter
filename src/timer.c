#include "timer.h"

volatile uint32_t current_freq;

void setup_timer(struct TIMx_registers *TIMER, uint32_t channel, uint32_t frequency, double duty_cycle) {
 /* configure TIM2_CH2 as PWM output */
  TIMER->CR1   = 0x0080;	/* Buffered preload up-counting mode */
  TIMER->CR2   = 0x0000;
  TIMER->SMCR  = 0x0000;
  TIMER->DIER  = 0x0000;
  TIMER->CCMR1 = 0x6800;	/* Pwm Mode */
  TIMER->CCMR2 = 0x0000;
  TIMER->CCER  = (0x1 << ((channel-1) * 4));
  //TIMER->CCER  = 0x0010; /* Channel 2 output to pin PB9 */
  TIMER->CNT   = 0x0000;
  TIMER->PSC   = get_APB1TIMCLK() / TIM_Base;
  TIMER->ARR   = TIM_Base/frequency;
  TIMER->CCR2  = (TIM_Base/frequency) * duty_cycle; /* rapport cyclique 50% */
  TIMER->EGR  |= 0x0001;	/* update event */
}

void setup_timer_DMA(struct TIMx_registers *TIMER, uint32_t channel, uint32_t frequency, double duty_cycle, uint32_t addr) {

  /* configure TIM2_CH2 as PWM output */
  TIMER->CR1   = 0x0080;	/* Buffered preload up-counting mode */
  TIMER->CR2   = 0x2 << 4 | 0x0 << 3 | 0x1 << 7;
  TIMER->SMCR  = 0x0000;
  TIMER->DIER  = 0x0000;
  TIMER->CCMR1 = 0x6800;	/* Pwm Mode */
 // TIMER->CCMR1 = 0x0000;	/* Pwm Mode */
  TIMER->CCMR2 = 0x0000;
  TIMER->CCER  = (0x1 << ((channel-1) * 4));
  //TIMER->CCER  = 0x0010; /* Channel 2 output to pin PB9 */
  TIMER->CNT   = 0x0000;
  TIMER->PSC   = 0;
  TIMER->ARR   = 0xfff;
  //TIMER->CCR2  = (frequency*100000) * duty_cycle; /* rapport cyclique 50% */
   //TIMER->PSC   = get_APB1TIMCLK() / TIM_Base;
 // TIMER->ARR   = TIM_Base/frequency;
  TIMER->CCR2  = 00; 
  TIMER->DCR = 0x0001;
  TIMER->EGR  |= 0x0001;	/* update event */
//  TIMER->EGR  |= 1 << 6;	/* update event */
  TIMER->DIER |= 1 << 8 | 1 << 14 | 1 << 10;
}

void set_timer(struct TIMx_registers *TIMER, uint32_t frequency, double duty_cycle) {
  TIMER->ARR   = TIM_Base/frequency;
  TIMER->CCR2  = (TIM_Base/frequency) * duty_cycle; /* rapport cyclique 50% */
}

void toggle_timer(struct TIMx_registers *TIMER)
{
  TIMER->CR1 ^= 0x1; /* counter on/off */
  TIMER->EGR |= 0x1;
}
