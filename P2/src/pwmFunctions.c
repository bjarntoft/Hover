/*
 *  pwmFunctions.c
 *  Collects all functions related to PWM.
 *
 *  Created: 2015-04-27 11:20:09
 *  Author: Andreas Bjärntoft
 */ 

#include <asf.h>
#include "pwmFunctions.h"


/* 
 *  Function makes general setup for all PWM fans.
 */
void pwm_setup(pwm_channel_t *pwm_h_chan, pwm_channel_t *pwm_d_chan, pwm_channel_t *pwm_fl_chan, pwm_channel_t *pwm_fr_chan, pwm_channel_t *pwm_bl_chan, pwm_channel_t *pwm_br_chan)
{
	// Enables specified peripheral clock.
	pmc_enable_periph_clk(ID_PWM);
	
	// Setup for individual PWM fans.
	pwm_h_setup(pwm_h_chan);		// Height fan.
	pwm_d_setup(pwm_d_chan);		// Drive fan.
	pwm_fl_setup(pwm_fl_chan);		// Front-left fan.
	pwm_fr_setup(pwm_fr_chan);		// Front-right fan.
	pwm_bl_setup(pwm_bl_chan);		// Back-left fan.
	pwm_br_setup(pwm_br_chan);		// Back-right fan.
}


/* 
 *  Function makes setup for height PWM fan and it's output.
 */
void pwm_h_setup(pwm_channel_t *pwm_chan)
{	
	// PWM channel needs to be disabled before it can be re-initialized.
	pwm_channel_disable(PWM, PWM_H_CHANNEL);
	
	// Parameters for PWM related clock.
	pwm_clock_t clock_setting = {
		.ul_clka = PWM_FREQUENCY * PWM_PERIOD,		// Frequency (Hz) for clock A.
		.ul_clkb = 0,								// Frequency (Hz) for clock B (0 = turned off).
		.ul_mck = SYS_CLOCK							// Frequency (Hz) for master clock (48000000).
	};
	
	// Re-initializing of PWM related clock.
	pwm_init(PWM, &clock_setting);
	
	// Parameters for PWM channel.
	pwm_chan->alignment = PWM_ALIGN_LEFT;
	pwm_chan->polarity = PWM_LOW;
	pwm_chan->ul_prescaler = PWM_CMR_CPRE_CLKA;
	pwm_chan->ul_period = PWM_PERIOD;
	pwm_chan->ul_duty = PWM_INIT_DUTY_CYCLE;
	pwm_chan->channel = PWM_H_CHANNEL;
	
	// Re-initializing of PWM channel.
	pwm_channel_init(PWM, pwm_chan);

	// Connects PWM to an output-pin.
	pio_set_peripheral(PWM_H_PIO, PWM_H_PERIPHERAL, PWM_H_PIN);
	
	// Enables PWM channel.
	pwm_channel_enable(PWM, PWM_H_CHANNEL);
}


/* 
 *  Function makes setup for drive PWM fan and it's output.
 */
void pwm_d_setup(pwm_channel_t *pwm_chan)
{	
	// PWM channel needs to be disabled before it can be re-initialized.
	pwm_channel_disable(PWM, PWM_D_CHANNEL);
	
	// Parameters for PWM related clock.
	pwm_clock_t clock_setting = {
		.ul_clka = PWM_FREQUENCY * PWM_PERIOD,		// Frequency (Hz) for clock A.
		.ul_clkb = 0,								// Frequency (Hz) for clock B (0 = turned off).
		.ul_mck = SYS_CLOCK							// Frequency (Hz) for master clock (48000000).
	};
	
	// Re-initializing of PWM related clock.
	pwm_init(PWM, &clock_setting);
	
	// Parameters for PWM channel.
	pwm_chan->alignment = PWM_ALIGN_LEFT;
	pwm_chan->polarity = PWM_LOW;
	pwm_chan->ul_prescaler = PWM_CMR_CPRE_CLKA;
	pwm_chan->ul_period = PWM_PERIOD;
	pwm_chan->ul_duty = PWM_INIT_DUTY_CYCLE;
	pwm_chan->channel = PWM_D_CHANNEL;
	
	// Re-initializing of PWM channel.
	pwm_channel_init(PWM, pwm_chan);

	// Connects PWM to an output-pin.
	pio_set_peripheral(PWM_D_PIO, PWM_D_PERIPHERAL, PWM_D_PIN);
	
	// Enables PWM channel.
	pwm_channel_enable(PWM, PWM_D_CHANNEL);
}


/* 
 *  Function makes setup for front-left PWM fan and it's output.
 */
void pwm_fl_setup(pwm_channel_t *pwm_chan)
{	
	// PWM channel needs to be disabled before it can be re-initialized.
	pwm_channel_disable(PWM, PWM_FL_CHANNEL);
	
	// Parameters for PWM related clock.
	pwm_clock_t clock_setting = {
		.ul_clka = PWM_FREQUENCY * PWM_PERIOD,		// Frequency (Hz) for clock A.
		.ul_clkb = 0,								// Frequency (Hz) for clock B (0 = turned off).
		.ul_mck = SYS_CLOCK							// Frequency (Hz) for master clock (48000000).
	};
	
	// Re-initializing of PWM related clock.
	pwm_init(PWM, &clock_setting);
	
	// Parameters for PWM channel.
	pwm_chan->alignment = PWM_ALIGN_LEFT;
	pwm_chan->polarity = PWM_LOW;
	pwm_chan->ul_prescaler = PWM_CMR_CPRE_CLKA;
	pwm_chan->ul_period = PWM_PERIOD;
	pwm_chan->ul_duty = PWM_INIT_DUTY_CYCLE;
	pwm_chan->channel = PWM_FL_CHANNEL;
	
	// Re-initializing of PWM channel.
	pwm_channel_init(PWM, pwm_chan);

	// Connects PWM to an output-pin.
	pio_set_peripheral(PWM_FL_PIO, PWM_FL_PERIPHERAL, PWM_FL_PIN);
	
	// Enables PWM channel.
	pwm_channel_enable(PWM, PWM_FL_CHANNEL);
}


/* 
 *  Function makes setup for front-right PWM fan and it's output.
 */
void pwm_fr_setup(pwm_channel_t *pwm_chan)
{
	// PWM channel needs to be disabled before it can be re-initialized.
	pwm_channel_disable(PWM, PWM_FR_CHANNEL);
	
	// Parameters for PWM related clock.
	pwm_clock_t clock_setting = {
		.ul_clka = PWM_FREQUENCY * PWM_PERIOD,		// Frequency (Hz) for clock A.
		.ul_clkb = 0,								// Frequency (Hz) for clock B (0 = turned off).
		.ul_mck = SYS_CLOCK							// Frequency (Hz) for master clock (48000000).
	};
	
	// Re-initializing of PWM related clock.
	pwm_init(PWM, &clock_setting);
	
	// Parameters for PWM channel.
	pwm_chan->alignment = PWM_ALIGN_LEFT;
	pwm_chan->polarity = PWM_LOW;
	pwm_chan->ul_prescaler = PWM_CMR_CPRE_CLKA;
	pwm_chan->ul_period = PWM_PERIOD;
	pwm_chan->ul_duty = PWM_INIT_DUTY_CYCLE;
	pwm_chan->channel = PWM_FR_CHANNEL;
	
	// Re-initializing of PWM channel.
	pwm_channel_init(PWM, pwm_chan);

	// Connects PWM to an output-pin.
	pio_set_peripheral(PWM_FR_PIO, PWM_FR_PERIPHERAL, PWM_FR_PIN);
	
	// Enables PWM channel.
	pwm_channel_enable(PWM, PWM_FR_CHANNEL);
}


/* 
 *  Function makes setup for back-left PWM fan and it's output.
 */
void pwm_bl_setup(pwm_channel_t *pwm_chan)
{
	// PWM channel needs to be disabled before it can be re-initialized.
	pwm_channel_disable(PWM, PWM_BL_CHANNEL);
	
	// Parameters for PWM related clock.
	pwm_clock_t clock_setting = {
		.ul_clka = PWM_FREQUENCY * PWM_PERIOD,		// Frequency (Hz) for clock A.
		.ul_clkb = 0,								// Frequency (Hz) for clock B (0 = turned off).
		.ul_mck = SYS_CLOCK							// Frequency (Hz) for master clock (48000000).
	};
	
	// Re-initializing of PWM related clock.
	pwm_init(PWM, &clock_setting);
	
	// Parameters for PWM channel.
	pwm_chan->alignment = PWM_ALIGN_LEFT;
	pwm_chan->polarity = PWM_LOW;
	pwm_chan->ul_prescaler = PWM_CMR_CPRE_CLKA;
	pwm_chan->ul_period = PWM_PERIOD;
	pwm_chan->ul_duty = PWM_INIT_DUTY_CYCLE;
	pwm_chan->channel = PWM_BL_CHANNEL;
	
	// Re-initializing of PWM channel.
	pwm_channel_init(PWM, pwm_chan);

	// Connects PWM to an output-pin.
	pio_set_peripheral(PWM_BL_PIO, PWM_BL_PERIPHERAL, PWM_BL_PIN);
	
	// Enables PWM channel.
	pwm_channel_enable(PWM, PWM_BL_CHANNEL);
}


/* 
 *  Function makes setup for back-right PWM fan and it's output.
 */
void pwm_br_setup(pwm_channel_t *pwm_chan)
{
	// PWM channel needs to be disabled before it can be re-initialized.
	pwm_channel_disable(PWM, PWM_BR_CHANNEL);
	
	// Parameters for PWM related clock.
	pwm_clock_t clock_setting = {
		.ul_clka = PWM_FREQUENCY * PWM_PERIOD,		// Frequency (Hz) for clock A.
		.ul_clkb = 0,								// Frequency (Hz) for clock B (0 = turned off).
		.ul_mck = SYS_CLOCK							// Frequency (Hz) for master clock (48000000).
	};
	
	// Re-initializing of PWM related clock.
	pwm_init(PWM, &clock_setting);
	
	// Parameters for PWM channel.
	pwm_chan->alignment = PWM_ALIGN_LEFT;
	pwm_chan->polarity = PWM_LOW;
	pwm_chan->ul_prescaler = PWM_CMR_CPRE_CLKA;
	pwm_chan->ul_period = PWM_PERIOD;
	pwm_chan->ul_duty = PWM_INIT_DUTY_CYCLE;
	pwm_chan->channel = PWM_BR_CHANNEL;
	
	// Re-initializing of PWM channel.
	pwm_channel_init(PWM, pwm_chan);

	// Connects PWM to an output-pin.
	pio_set_peripheral(PWM_BR_PIO, PWM_BR_PERIPHERAL, PWM_BR_PIN);
	
	// Enables PWM channel.
	pwm_channel_enable(PWM, PWM_BR_CHANNEL);
}


/* 
 *  Function makes an update of the PWM duty-cycle after ensuring that the duty-cycle
 *  doesn't falls below zero or outrun it's maximum (PWM_PERIOD).
 */
void update_pwm(pwm_channel_t *chan, int ul_duty)
{
	//int duty_cycle = 0;
	
	// Control for duty-cycle out of range.
	if(ul_duty < 0)
	{
		//duty_cycle = 0;
		pwm_channel_update_duty(PWM, chan, 0);
	}
	else if(ul_duty > 1000)
	{
		// duty_cycle = PWM_PERIOD;
		pwm_channel_update_duty(PWM, chan, 1000);
	}
	else
	{
		//duty_cycle = ul_duty;
		pwm_channel_update_duty(PWM, chan, ul_duty);
	}
	
	
	//pwm_channel_update_duty(PWM, chan, duty_cycle);
}