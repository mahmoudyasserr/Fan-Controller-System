 /******************************************************************************
 *
 * Module: ADC
 *
 * File Name: adc.c
 *
 * Description: Source file for the ATmega16 ADC driver
 *
 * Author: Mahmoud Yasser
 *
 *******************************************************************************/

#include "avr/io.h" /* To use the ADC Registers */
#include <avr/interrupt.h> /* For ADC ISR */
#include "adc.h"
#include "common_macros.h" /* To use the macros like SET_BIT */




/*******************************************************************************
 *                          Functions Definitions                              *
 *******************************************************************************/

void ADC_init(const ADC_ConfigType * Config_Ptr)
{
	/*Setting the reference voltage in the ADMUX register in bits REFS1 & REFS0 */
	ADMUX = ((ADMUX &0x3F)|(Config_Ptr->ref_volt)<<6);

	/*Enabling the ADC & Setting the preScaller value in the ADCSRA register in bits ADPS2:0 */
	ADCSRA = (1<<ADEN)|((ADCSRA&0xF8)|(Config_Ptr->prescaler));
}

uint16 ADC_readChannel(uint8 channel)
{
	channel &= 0x07; /*The channel must be a number between 0 and 7 */

	/* Determine the ADC Channel to read in the register ADMUX */
	ADMUX = ((ADMUX &0xE0)|(ADC_CHANNEL_ID));
	/* Start the conversion */
	ADCSRA |= (1<<ADSC);

	/* Waiting until the conversion is finished */
	while(bit_is_clear(ADCSRA,ADIF));

	/*Clearing the flag */
	SET_BIT(ADCSRA,ADIF);
	return ADC;
}
