/*
* PWMTask.c
*
* Created: 2015-05-13 11:13:53
*  Author: Andreas Bjärntoft
*/

#include <asf.h>
#include "pwmFunctions.h"
#include "Global.h"
#include "TaskPWM.h"

int u = 0;
int y = 0;
int e_prev = 0;
int e_now = 0;
int e_diff = 0;

void task_pwm(void *p)
{
	
	
	while(1)
	{
		
		portTickType xLastWakeTime;
		const portTickType xTimeIncrement = PWM_SAMPLING_TIME;
		
		update_pwm(&pwm_h_channel_instance, H_VALUE);
		update_pwm(&pwm_d_channel_instance, D_VALUE);
		
		y = ((abs(sensor_diff_f) + abs(sensor_diff_b)) / 2);
		e_prev = e_now;
		e_now = 0 - y; // Börvärde - Ärvärde. Nollan representerar börvärdet (än så länge).
		e_diff = e_now - e_prev;
		
		
		if ((sensor_diff_f<0 && sensor_diff_b>0) || // Rotation!
		(sensor_diff_f>0 && sensor_diff_b<0) ||
		(sensor_diff_f<0 && sensor_diff_b==0) ||
		(sensor_diff_f>0 && sensor_diff_b==0) ||
		(sensor_diff_f==0 && sensor_diff_b<0) ||
		(sensor_diff_f==0 && sensor_diff_b>0))
		{
			
			u = KP_ROT * (e_now + ((TD_ROT * e_diff)/DT));
			u = abs(u);
			//u = abs( KP_ROT * (e_now + ( (1/TD_ROT) + (e_diff*DT) ) ) );
			
			if ((sensor_diff_f<0 && sensor_diff_b>0) ||
			(sensor_diff_f<0 && sensor_diff_b==0) ||
			(sensor_diff_f==0 && sensor_diff_b>0))
			{
				update_pwm(&pwm_fl_channel_instance, u); //u
				update_pwm(&pwm_br_channel_instance, u); //u
				update_pwm(&pwm_fr_channel_instance, 0);
				update_pwm(&pwm_bl_channel_instance, 0);
				//printf("Rotation FL+BR: %d \n", u);
			}
			else if ((sensor_diff_f>0 && sensor_diff_b<0) ||
			(sensor_diff_f>0 && sensor_diff_b==0) ||
			(sensor_diff_f==0 && sensor_diff_b<0))
			{
				update_pwm(&pwm_fr_channel_instance, u); //u
				update_pwm(&pwm_bl_channel_instance, u); //u
				update_pwm(&pwm_fl_channel_instance, 0);
				update_pwm(&pwm_br_channel_instance, 0);
				//printf("Rotation FR+BL: %d \n", u);
			}
		}
		
		else if ((sensor_diff_f<0 && sensor_diff_b<0) || // Translokation!
		(sensor_diff_f>0 && sensor_diff_b>0))
		{
			u = KP_TRANS * (e_now + ((TD_TRANS * e_diff)/DT));
			u = abs(u);
			
			//u = abs(KP_TRANS * (e_now + ( (1/TD_TRANS) + (e_diff*DT) ) ) );
			
			if (sensor_diff_f<0 && sensor_diff_b<0)
			{
				update_pwm(&pwm_fl_channel_instance, u); //u
				update_pwm(&pwm_bl_channel_instance, u); //u
				update_pwm(&pwm_fr_channel_instance, 0);
				update_pwm(&pwm_br_channel_instance, 0);
				//printf("Translokation FL+BL: %d \n", u);
			}
			else if (sensor_diff_f>0 && sensor_diff_b>0)
			{
				update_pwm(&pwm_fr_channel_instance, u); //u
				update_pwm(&pwm_br_channel_instance, u); //u
				update_pwm(&pwm_fl_channel_instance, 0);
				update_pwm(&pwm_bl_channel_instance, 0);
				//printf("Translokation FR+BR: %d \n", u);
			}
		}
		
		
		vTaskDelayUntil(&xLastWakeTime, xTimeIncrement);
	}
}

