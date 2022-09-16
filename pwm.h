 /******************************************************************************
 *
 * Module: PWM
 *
 * File Name: pwm.h
 *
 * Description: header file for the PWM driver
 *
 * Author: Mahmoud Yasser
 *
 *******************************************************************************/


#ifndef PWM_H_
#define PWM_H_

/*******************************************************************************
 *                                   Includes                                  *
 *******************************************************************************/

#include "std_types.h"


/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define PWM_TOP_VALUE  0xFF


/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/


/*
 ****************************** 1.Timer0 PWM Function *******************************
 Function Description: This function is used to generate the PMW Signal from the pin PB3
 Function Inputs: uint8 duty_cycle [Duty Cycle from 0 to 100 ]
  */
void PWM_Timer0_Start(uint8 duty_cycle);

#endif /* PWM_H_ */
