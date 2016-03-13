/*
* TaskOne.c
*
* Created: 2015-04-10 13:11:05
*  Author: Viktor
*/

#include <asf.h>
#include "TaskBluetooth.h"
#include "Global.h"

void task_bluetooth(void *p)
{
	while (1)
	{
		////int ran = rand() % 100;
		//int ran = 88;
		//printf("%d",ran);
		//printf("\n");
		//vTaskDelay(500);
		
		printf("%d \n", u);
		
		
	}
}

//double readASCII(void)
//{
//char str[10]={0};
//scanf("%s",str);
//double result = atof(str);
//return result;
//}

//void sendASCII(double doubleValue)
//{
//char str[10] = {0};
//sprintf(str,"%0.4f", doubleValue);
//printf("%s\n",str);
//}