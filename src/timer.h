#pragma once
#include <stdio.h>
#include <math.h>
#include "sys/cm4.h"
#include "sys/devices.h"
#include "sys/init.h"
#include "sys/clock.h"

#define TIM_Base 100000

void setup_timer(struct TIMx_registers *TIMER, uint32_t channel, uint32_t frequency, double duty_cycle);
void set_timer(struct TIMx_registers *TIMER, uint32_t frequency, double duty_cycle);
void toggle_timer(struct TIMx_registers *TIMER);
