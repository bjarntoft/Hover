/*
 *  pwmFunctions.h
 *
 *  Created: 2015-04-27 11:20:30
 *  Author: Andreas Bjärntoft
 */ 


#ifndef PWMFUNCTIONS_H_
#define PWMFUNCTIONS_H_


// General PWM-definitions.
#define SYS_CLOCK			sysclk_get_cpu_hz()	// System clock (Hz).
#define PWM_FREQUENCY		1000				// PWM frequency (Hz).
#define PWM_PERIOD			1000				// PWM period ("bits").
#define PWM_INIT_DUTY_CYCLE	0					// 

// PIO and PWM for height fan (pin 40 on Arduino Due).
#define PWM_H_PIO			PIOC				// Pin base address.
#define PWM_H_PERIPHERAL	PIO_PERIPH_B		// Pin peripheral.
#define PWM_H_PIN			PIO_PC8B_PWML3		// Pin port.
#define PWM_H_CHANNEL		PWM_CHANNEL_3		// PWM-channel.

// PIO and PWM for drive fan (pin 34 on Arduino Due).
#define PWM_D_PIO			PIOC				// Pin base address.
#define PWM_D_PERIPHERAL	PIO_PERIPH_B		// Pin peripheral.
#define PWM_D_PIN			PIO_PC2B_PWML0		// Pin port.
#define PWM_D_CHANNEL		PWM_CHANNEL_0		// PWM-channel.

// PIO and PWM for front-left steering fan (pin 9 on Arduino Due).
#define PWM_FL_PIO			PIOC				// Pin base address.
#define PWM_FL_PERIPHERAL	PIO_PERIPH_B		// Pin peripheral.
#define PWM_FL_PIN			PIO_PC21B_PWML4		// Pin port.
#define PWM_FL_CHANNEL		PWM_CHANNEL_4		// PWM-channel.

// PIO and PWM for front-right steering fan (pin 8 on Arduino Due).
#define PWM_FR_PIO			PIOC				// Pin base address.
#define PWM_FR_PERIPHERAL	PIO_PERIPH_B		// Pin peripheral.
#define PWM_FR_PIN			PIO_PC22B_PWML5		// Pin port.
#define PWM_FR_CHANNEL		PWM_CHANNEL_5		// PWM-channel.

// PIO and PWM for back-left steering fan (pin 7 on Arduino Due).
#define PWM_BL_PIO			PIOC				// Pin base address.
#define PWM_BL_PERIPHERAL	PIO_PERIPH_B		// Pin peripheral.
#define PWM_BL_PIN			PIO_PC23B_PWML6		// Pin port.
#define PWM_BL_CHANNEL		PWM_CHANNEL_6		// PWM-channel.

// PIO and PWM for back-right steering fan (pin 6 on Arduino Due).
#define PWM_BR_PIO			PIOC				// Pin base address.
#define PWM_BR_PERIPHERAL	PIO_PERIPH_B		// Pin peripheral.
#define PWM_BR_PIN			PIO_PC24B_PWML7		// Pin port.
#define PWM_BR_CHANNEL		PWM_CHANNEL_7		// PWM-channel.


// General setup for all the fans.
void pwm_setup(pwm_channel_t*, pwm_channel_t*, pwm_channel_t*, pwm_channel_t*, pwm_channel_t*, pwm_channel_t*);

// PIO and PWM setup functions.
void pwm_h_setup(pwm_channel_t *);				// Height fan.
void pwm_d_setup(pwm_channel_t *);				// Drive fan.
void pwm_fl_setup(pwm_channel_t *);				// Front-left steering fan.
void pwm_fr_setup(pwm_channel_t *);				// Front-right steering fan.
void pwm_bl_setup(pwm_channel_t *);				// Back-left steering fan.
void pwm_br_setup(pwm_channel_t *);				// Back-right steering fan.

// Other functions.
void update_pwm(pwm_channel_t *, int);			// Update PWM duty-cycle.


#endif /* PWMFUNCTIONS_H_ */