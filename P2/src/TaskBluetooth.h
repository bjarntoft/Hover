/*
 * TaskBluetooth.h
 *
 * Created: 2015-05-05 16:57:46
 *  Author: Viktor
 */ 

#ifndef TASKBLUETOOTH_H_
#define TASKBLUETOOTH_H_

#define TASK_BLUETOOTH_STACK_SIZE (2048/sizeof(portSTACK_TYPE))
//#define TASK_BLUETOOTH_STACK_PRIORITY (tskIDLE_PRIORITY)

void task_bluetooth(void *p);
//double readASCII(void);
//void sendASCII(double result);

#endif /* TASKBLUETOOTH_H_ */