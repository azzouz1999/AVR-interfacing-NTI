/************************************/
/* Author		: Ali Azzouz		*/
/* SWC			: Seven segment		*/
/* Layer		: HAL       	    */
/* Version		: 1.0				*/
/* Date			: march 1,2024	*/
/* Last Edit	: N/A			 	*/
/************************************/
#ifndef SSEG_INTERFACE_H_
#define SSEG_INTERFACE_H_

#define SSEG_4BIT_MODE	1
#define SSEG_7BIT_MODE	2


void SSEG_Init(u8 copy_u8Mode);
void SSEG_Display_4bitMode(u8 copy_u8Num);
void SSEG_Display_7bitMode(u8 copy_u8Num);

#endif  /*SSEG_INTERFACE_H_*/
