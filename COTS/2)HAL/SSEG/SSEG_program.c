/************************************/
/* Author		: Ali Azzouz		*/
/* SWC			: Seven segment		*/
/* Layer		: HAL       	    */
/* Version		: 1.0				*/
/* Date			: march 1,2024		*/
/* Last Edit	: N/A			 	*/
/************************************/

#include "STD_types.h"
#include "BIT_math.h"
#include "SSEG_interface.h"
#include "SSEG_private.h"
#include "SSEG_config.h"

#include "DIO_interface.h"

void SSEG_Init(u8 copy_u8Mode)
{
	switch (copy_u8Mode)
	{
	case SSEG_4BIT_MODE:

		/*declaring the data pins*/
		DIO_voidSetPinDirection(SSEG_4BIT_DATA_PORT, SSEG_4BIT_PIN_A, DIO_PIN_OUTPUT);
		DIO_voidSetPinDirection(SSEG_4BIT_DATA_PORT, SSEG_4BIT_PIN_B, DIO_PIN_OUTPUT);
		DIO_voidSetPinDirection(SSEG_4BIT_DATA_PORT, SSEG_4BIT_PIN_C, DIO_PIN_OUTPUT);
		DIO_voidSetPinDirection(SSEG_4BIT_DATA_PORT, SSEG_4BIT_PIN_D, DIO_PIN_OUTPUT);

		/*declaring the control pin "active low"*/
		DIO_voidSetPinDirection(SSEG_4BIT_CTRL12_PORT,SSEG_4BIT_PIN_COM1,DIO_PIN_OUTPUT);
		DIO_voidSetPinValue(SSEG_4BIT_CTRL12_PORT,SSEG_4BIT_PIN_COM1,DIO_PIN_LOW);
		break;


	case SSEG_7BIT_MODE:
		/*declaring the data pins*/
		DIO_voidSetPinDirection(SSEG_7BIT_DATA_PORT ,SSEG_7BIT_PIN_0 ,DIO_PIN_OUTPUT);
		DIO_voidSetPinDirection(SSEG_7BIT_DATA_PORT ,SSEG_7BIT_PIN_1 ,DIO_PIN_OUTPUT);
		DIO_voidSetPinDirection(SSEG_7BIT_DATA_PORT ,SSEG_7BIT_PIN_2 ,DIO_PIN_OUTPUT);
	    DIO_voidSetPinDirection(SSEG_7BIT_DATA_PORT ,SSEG_7BIT_PIN_3 ,DIO_PIN_OUTPUT);
		DIO_voidSetPinDirection(SSEG_7BIT_DATA_PORT ,SSEG_7BIT_PIN_4 ,DIO_PIN_OUTPUT);
		DIO_voidSetPinDirection(SSEG_7BIT_DATA_PORT ,SSEG_7BIT_PIN_5 ,DIO_PIN_OUTPUT);
		DIO_voidSetPinDirection(SSEG_7BIT_DATA_PORT ,SSEG_7BIT_PIN_6 ,DIO_PIN_OUTPUT);

		/*declaring the control pin "active low"*/
		DIO_voidSetPinDirection(SSEG_7BIT_CTRL_PORT,SSEG_7BIT_PIN_CTRL ,DIO_PIN_OUTPUT);
		DIO_voidSetPinValue(SSEG_7BIT_CTRL_PORT,SSEG_7BIT_PIN_CTRL,DIO_PIN_LOW);
		break;

	default: /*report an error*/ break;
	}

}

void SSEG_Display_4bitMode(u8 copy_u8Num)
{

	
	u8 local_u8counter;
	if(copy_u8Num<=10)
	{
		local_u8counter=GET_BIT(copy_u8Num,0);
		DIO_voidSetPinValue(DIO_PORTB,DIO_PIN0,local_u8counter);

		local_u8counter=GET_BIT(copy_u8Num,1);
		DIO_voidSetPinValue(DIO_PORTB,DIO_PIN1,local_u8counter);

		local_u8counter=GET_BIT(copy_u8Num,2);
		DIO_voidSetPinValue(DIO_PORTB,DIO_PIN2,local_u8counter);

		local_u8counter=GET_BIT(copy_u8Num,3);
		DIO_voidSetPinValue(DIO_PORTB,DIO_PIN4,local_u8counter);
	}
	else
	{
		/*report an error*/
	}

}

void SSEG_Display_7bitMode(u8 copy_u8Num)
 {
	 if(copy_u8Num<=10)
	{
 	u8 local_u87BitArray[10] = {0b1000000,0b1111001,0b0100100,0b0110000,0b0011001,0b0010010,0b0000010,0b1111000,0b0000000,0b0010000};

		DIO_voidSetPortValue(DIO_PORTB,~local_u87BitArray[copy_u8Num]);
	}
	else
	{
		/*report an error*/
	}
		
 }


