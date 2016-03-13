/*
 * TaskAD.h
 *
 * Created: 2015-05-13 10:49:06
 *  Author: ad5754
 */ 

#ifndef TASKAD_H_
#define TASKAD_H_

#define TASK_AD_STACK_SIZE (2048/sizeof(portSTACK_TYPE))
#define AD_SAMPLING_TIME	10
#define avg_sensor_read		15 //25 //40
//#define TASK_AD_STACK_PRIORITY (tskIDLE_PRIORITY)

void task_ad(void *p);
void GetSensorValue(void);

#endif /* TASKAD_H_ */