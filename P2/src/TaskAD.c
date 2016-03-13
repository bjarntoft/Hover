/*
* TaskAD.c
*
* Created: 2015-05-13 10:48:41
*  Author: ad5754
*/

#include <asf.h>
#include "TaskAD.h"
#include "Global.h"

uint32_t count = 0;
uint32_t totalFR = 0;
uint32_t totalFL = 0;
uint32_t totalBR = 0;
uint32_t totalBL = 0;

void task_ad(void *p)
{
	while(1)
	{
		portTickType xLastWakeTime;
		const portTickType xTimeIncrement = AD_SAMPLING_TIME;
		adc_start(ADC);
		//while((adc_get_status(ADC) & 0x1<<24)==0); //Wait until DRDY get high
		GetSensorValue();
		vTaskDelayUntil(&xLastWakeTime, xTimeIncrement);
	}
}

void GetSensorValue(void)
{
	totalFR = totalFR + adc_get_channel_value(ADC,ADC_CHANNEL_7) * (3.3/2.55);
	totalFL = totalFL + adc_get_channel_value(ADC,ADC_CHANNEL_6) * (3.3/2.55);
	totalBR = totalBR + adc_get_channel_value(ADC,ADC_CHANNEL_5) * (3.3/2.55);
	totalBL = totalBL + adc_get_channel_value(ADC,ADC_CHANNEL_4) * (3.3/2.55);
	
	count++;

	if(count==avg_sensor_read)
	{
		uint32_t sensorValueFR = totalFR/avg_sensor_read;
		uint32_t sensorValueFL = totalFL/avg_sensor_read;
		uint32_t sensorValueBR = totalBR/avg_sensor_read;
		uint32_t sensorValueBL = totalBL/avg_sensor_read;
		totalFR = 0;
		totalFL = 0;
		totalBR = 0;
		totalBL = 0;
		count = 0;
		
		sensor_diff_f = sensorValueFL-sensorValueFR;
		sensor_diff_b = sensorValueBL-sensorValueBR;
		
		//printf("högerfram: %d \n", sensorValuefr);
		//printf("vänsterfram: %d \n", sensorvaluefl);
		//printf("högerbak: %d \n", sensorvaluebr);
		//printf("vänsterbak: %d \n", sensorvaluebl);
		//printf("Differens fram: %d \n", sensor_diff_f);
		//printf("Differens bak: %d \n", sensor_diff_b);
	}
}