 /******************************************************************************
 *
 * Module: ADC
 *
 * File Name: adc.h
 *
 * Description: header file for the ATmega16 ADC driver
 *
 * Author: Mahmoud Yasser
 *
 *******************************************************************************/

#ifndef ADC_H_
#define ADC_H_

#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define ADC_MAXIMUM_VALUE    1023
#define ADC_REF_VOLT_VALUE   2.56

/*
 ************************************* Static Configurations **********************************************
 */
#define ADC_CHANNEL_ID 		2  /*ADC Channel connected to analog device*/


/*enum to determine the prescaler */

typedef enum
{
	ADC_PRE_0,ADC_PRE_2,ADC_PRE_4,ADC_PRE_8,ADC_PRE_16,ADC_PRE_32,ADC_PRE_64,ADC_PRE_128
}ADC_Prescaler;

typedef enum
{
	AREF,AVCC,RESERVED,INTERNAL_VREF
}ADC_ReferenceVolatge;


/*Structure to receive the ADC Configurations */

typedef struct
{
	ADC_ReferenceVolatge ref_volt;
	ADC_Prescaler prescaler;

}ADC_ConfigType;




/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Function responsible for initialize the ADC driver.
 */
void ADC_init(const ADC_ConfigType * Config_Ptr);

/*
 * Description :
 * Function responsible for read analog data from a certain ADC channel
 * and convert it to digital using the ADC driver.
 */
uint16 ADC_readChannel(uint8 channel_num);

#endif /* ADC_H_ */
