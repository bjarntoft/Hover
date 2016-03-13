/*
 * AD.c
 *
 * Created: 2014-11-26 15:06:46
 *  Author: ad5754
 */ 

#include "AD.h"
#include "asf.h"

void adc_setup(void)
{
	/* Configure power management of ADC timer clock */
	pmc_enable_periph_clk(ID_ADC);
	
	adc_init(ADC, sysclk_get_main_hz(), 1000000, 8);
	adc_configure_timing(ADC, 0, ADC_SETTLING_TIME_3, 1);
	adc_set_resolution(ADC, ADC_MR_LOWRES_BITS_10);
	adc_enable_channel(ADC, ADC_CHANNEL_7);
	adc_enable_channel(ADC, ADC_CHANNEL_6);
	adc_enable_channel(ADC, ADC_CHANNEL_5);
	adc_enable_channel(ADC, ADC_CHANNEL_4);
	adc_configure_trigger(ADC, ADC_TRIG_SW, 0);
}