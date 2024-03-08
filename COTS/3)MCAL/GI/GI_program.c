/*
 * GI_program.c
 *
 *  Created on: Mar 7, 2024
 *      Author: ali_a
 */
#include "STD_types.h"
#include "BIT_math.h"

#include "GI_private.h"
#include "GI_interface.h"

void MGIE_voidEnableGI(void)
{
	SET_BIT(SREG,I_BIT);
}
void MGIE_voidDisnableGI(void)
{
	CLEAR_BIT(SREG,I_BIT);
}


