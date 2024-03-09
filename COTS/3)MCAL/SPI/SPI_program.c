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

void SPI_voidInitMaster(void)
{
	/*Disable interrupt DO NOT need now*/
	CLEAR_BIT(SPI->SPCR,SPIE);

	/*Data order: MSB*/
	SET_BIT(SPI->SPCR,DORD);

	/*slave*/
	SET_BIT(SPI->SPCR,MSTR);

	SET_BIT(SPI->SPCR,CPOL);//POLARITY
	SET_BIT(SPI->SPCR,CPHA);//PHASE
	/*clock*/

	CLEAR_BIT(SPI->SPCR,SPR0);
	SET_BIT(SPI->SPCR,SPR1);
	CLEAR_BIT(SPI->SPSR,SPI2X);

	/*enable SPI*/
	SET_BIT(SPI->SPCR,SPE);

}
void SPI_voidInitSlave(void)
{
	/*Disable interrupt DO NOT need now*/
	CLEAR_BIT(SPI->SPCR,SPIE);

	//Data order: MSB
	SET_BIT(SPI->SPCR,DORD);

	 /*slave*/
	CLEAR_BIT(SPI->SPCR,MSTR);

	SET_BIT(SPI->SPCR,CPOL);/*POLARITY*/
	SET_BIT(SPI->SPCR,CPHA);/*PHASE*/
	/*enable SPI*/
	SET_BIT(SPI->SPCR,SPE);
}
void SPI_u8Transieve(u8 copy_u8TxData,u8*  copy_u8RxData)
{
	/*if the received data is not empty*/
	if(copy_u8RxData!=NULL_POINTER)
	{
		/*put transfered data in SPDR register to be sent*/
		SPI->SPDR = copy_u8TxData;

		/*POLLING*/
		while(0==GET_BIT(SPI->SPSR,SPIF));
		/*take received data*/
		*  copy_u8RxData = SPI->SPDR;
	}
	else
	{

	}
}
void SPI_voidEnableInterrupt(void)
{
	SET_BIT(SPI->SPCR,SPIE);

}
void SPI_voidDisableInterrupt(void)
{
	CLEAR_BIT(SPI->SPCR,SPIE);
}
void SPI_voidSetCallBack(void(*copy_pvoidfUserFunction)(void))
{
	if(copy_pvoidfUserFunction!=NULL_POINTER)
	{
		SPI_pvoidfUserFunction=copy_pvoidfUserFunction;
	}
	else
	{
		/*error*/
	}
}

void __vector_12(void) __attribute__((signal));
void __vector_12(void)
{
	if(SPI_pvoidfUserFunction!=NULL_POINTER)
	{
		(*SPI_pvoidfUserFunction)();
	}
	else
	{
		/*error*/
	}
}




