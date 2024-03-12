/*
 * SPI_program.c
 *
 *  Created on: Mar 5, 2024
 *      Author: ali_a
 */
#include "STD_types.h"
#include "BIT_math.h"

#include"SPI_interface.h"
#include"SPI_private.h"
#include"SPI_register.h"

static void (*SPI_pvoidfUserFunction)(void)=NULL_POINTER;

void SPI_voidInit(u8 ARG_u8Mode, u8 ARG_u8ClockPolPha, u8 ARG_u8DataOrder,u8 ARG_u8Prescaler)
{
	if((ARG_u8Mode<=1)&&(ARG_u8ClockPolPha<=3)&&(ARG_u8DataOrder<=1)&&(ARG_u8Prescaler<=6))
	{
		SPI->SPCR=(SPI->SPCR&0xC0)|((ARG_u8Mode<<MSTR)|(ARG_u8ClockPolPha<<CPHA)|(ARG_u8DataOrder<<DORD)|(ARG_u8Prescaler&0b11));
		/*Mask the 3rd bit so i take first 2 bits in pre-scaler and put them in SPR1 and SPR2*/
		SPI->SPSR=(SPI->SPSR&0xFE)|(ARG_u8Prescaler>>2);
		/*shift the first 2 bits so that i take the third bit from prescaler and put it in SPSR*/
	}
	else
	{
		/*report an error*/
	}
}

void SPI_voidEnable(void)
{
	SET_BIT(SPI->SPCR,SPE);
}

void SPI_voidDisable(void)
{
	CLEAR_BIT(SPI->SPCR,SPE);
}

void SPI_voidEnableInterrupt(void)
{
	SET_BIT(SPI->SPCR,SPIE);
}

void SPI_voidDisableInterrupt(void)
{
	CLEAR_BIT(SPI->SPCR,SPIE);
}

void SPI_voidSetCallback(void(*ARG_pvoidfUserFunction)(void))
{
	if(ARG_pvoidfUserFunction!=NULL_POINTER)
	{
	SPI_pvoidfUserFunction=ARG_pvoidfUserFunction;
	}
	else
	{
		/* report an error*/
	}

}

void SPI_voidFlagPolling(void)
{
	while(!GET_BIT(SPI->SPSR,SPIF));
}

char SPI_charTranceive(char ARG_charData)
{
	SPI->SPDR=ARG_charData;

	SPI_voidFlagPolling();
	/*flag polling reads the SPSR while SPIF is set*/
	return SPI->SPDR;
	/*return SPDR accesses the SPDR register SPIF is cleared*/

}

void __vector_12(void) __attribute__((signal)); /*TIMER0 OUTPUT COMPARE MATCH*/
void __vector_12(void)
{
	if(SPI_pvoidfUserFunction!=NULL_POINTER)
	{
	(*SPI_pvoidfUserFunction)();

	}
	else
	{
		/*report an error*/
	}
}
