/*
 * TaskPWM.h
 *
 * Created: 2015-05-13 11:18:57
 *  Author: ad5754
 */ 

#ifndef TASKPWM_H_
#define TASKPWM_H_

#define TASK_PWM_STACK_SIZE (2048/sizeof(portSTACK_TYPE))
#define PWM_SAMPLING_TIME 250 //250 //500
//#define TASK_PWM_STACK_PRIORITY (tskIDLE_PRIORITY)

#define KP_ROT		12 //
#define TD_ROT		3 
#define KP_TRANS	10 // 7
#define TD_TRANS	3 
#define DT			0.25 //0.5

#define H_VALUE		750
#define D_VALUE		0

void task_pwm(void *p);

#endif /* TASKPWM_H_ */