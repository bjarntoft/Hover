/*
 * Global.h
 *
 * Created: 2015-05-14 11:27:43
 *  Author: ad5754
 */ 


#ifndef GLOBAL_H_
#define GLOBAL_H_

extern int sensor_diff_f;
extern int sensor_diff_b;
extern int u;

// PWM-instances for fan-control.
extern pwm_channel_t pwm_h_channel_instance;		// Height fan.
extern pwm_channel_t pwm_d_channel_instance;		// Drive fan.
extern pwm_channel_t pwm_fl_channel_instance;		// Front-left fan.
extern pwm_channel_t pwm_fr_channel_instance;		// Front-right fan.
extern pwm_channel_t pwm_bl_channel_instance;		// Back-left fan.
extern pwm_channel_t pwm_br_channel_instance;		// Back-right fan.

#endif /* GLOBAL_H_ */