/**
* \file
*
* \brief Empty user application template
*
*/

#include <asf.h>
#include "AD.h"
#include "TaskBluetooth.h"
#include "TaskAD.h"
#include "TaskPWM.h"
#include "Global.h"
#include "pwmFunctions.h"

int sensor_diff_f;
int sensor_diff_b;

int u;

pwm_channel_t pwm_h_channel_instance;		// Height fan.
pwm_channel_t pwm_d_channel_instance;		// Drive fan.
pwm_channel_t pwm_fl_channel_instance;		// Front-left fan.
pwm_channel_t pwm_fr_channel_instance;		// Front-right fan.
pwm_channel_t pwm_bl_channel_instance;		// Back-left fan.
pwm_channel_t pwm_br_channel_instance;		// Back-right fan.

static void configure_console(void)
{
	const usart_serial_options_t uart_serial_options = { .baudrate =CONF_UART_BAUDRATE, .paritytype = CONF_UART_PARITY };
	/* Konfigurera konsol UART. */
	sysclk_enable_peripheral_clock(CONSOLE_UART_ID);
	stdio_serial_init(CONF_UART, &uart_serial_options);
	/* Specifiera att stdout inte ska buffras */
	#if defined(__GNUC__)
	setbuf(stdout, NULL);
	#endif
}

int main (void)
{
	sysclk_init();
	board_init();
	adc_setup();
	configure_console();
	
	// Setup for all PWM fans.
	pwm_setup(&pwm_h_channel_instance, &pwm_d_channel_instance, &pwm_fl_channel_instance, &pwm_fr_channel_instance, &pwm_bl_channel_instance, &pwm_br_channel_instance);

	
	///* first task*/
	if (xTaskCreate(task_bluetooth, (const signed char * const) "bluetooth", TASK_BLUETOOTH_STACK_SIZE, NULL, 1, NULL) != pdPASS)
	{
	printf("failed to create bluetooth-task\r\n");
	}
	
	/* Second task*/
	if (xTaskCreate(task_ad, (const signed char * const) "AD", TASK_AD_STACK_SIZE, NULL, 1, NULL) != pdPASS)
	{
		printf("Failed to create sensorad-task\r\n");
	}
	
	/* Third task*/
	if (xTaskCreate(task_pwm, (const signed char * const) "PWM", TASK_PWM_STACK_SIZE, NULL, 1, NULL) != pdPASS)
	{
		printf("Failed to create PWM-task\r\n");
	}
	
	/* Start the FreeRTOS scheduler running all tasks indefinitely*/
	vTaskStartScheduler();
	/* The program should only end up here if there isn’t enough memory to
	create the idle task */
}
