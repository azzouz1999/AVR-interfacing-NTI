/*
 * EXTI_program.c
 *
 * Created: 3/3/2024 1:29:51 PM
 *  Author: ali_a
 */ 

/*libraries*/
#include "STD_types.h"
#include "BIT_math.h"

/*mcal*/
#include "EXTI_interface.h"
#include "EXTI_private.h"

static void (*EXTI_pvoidfUserFunctionINT0)(void)=NULL_POINTER;
static void (*EXTI_pvoidfUserFunctionINT1)(void)=NULL_POINTER;
static void (*EXTI_pvoidfUserFunctionINT2)(void)=NULL_POINTER;
void EXTI_Enable(EXTI_source copy_enumInterruptSource, EXTI_senseControl copy_enumInterruptMode)
{

	switch(copy_enumInterruptSource)
	{
		case EXTI_INT0:
		{

			switch(copy_enumInterruptMode)
			{
				case EXTI_RISING_EDGE:
				{
					SET_BIT(MCUCR_REG,ISC00);
					SET_BIT(MCUCR_REG,ISC01);
					break;
				}
				case EXTI_FALLING_EDGE:
				{
					CLEAR_BIT(MCUCR_REG,ISC00);
					SET_BIT(MCUCR_REG,ISC01);
					break;
				}
				case EXTI_LOW_LEVEL:
				{
					CLEAR_BIT(MCUCR_REG,ISC00);
					CLEAR_BIT(MCUCR_REG,ISC01);
					break;
				}
				case EXTI_ANY_LOGICAL_CHANGE:
				{
					SET_BIT(MCUCR_REG,ISC00);
					CLEAR_BIT(MCUCR_REG,ISC01);
					break;
				}
				SET_BIT(GICR_REG,INT0);  //ENABLE EXTERNAL INTERRUPT 0

			}
		break;
		}

		case EXTI_INT1:
		{
			switch(copy_enumInterruptMode)
			{
				case EXTI_RISING_EDGE:
				{
					SET_BIT(MCUCR_REG,ISC10);
					SET_BIT(MCUCR_REG,ISC11);
					break;
				}
				case EXTI_FALLING_EDGE:
				{
					CLEAR_BIT(MCUCR_REG,ISC10);
					SET_BIT(MCUCR_REG,ISC11);
					break;
				}
				case EXTI_LOW_LEVEL:
				{
					CLEAR_BIT(MCUCR_REG,ISC10);
					CLEAR_BIT(MCUCR_REG,ISC11);
					break;
				}
				case EXTI_ANY_LOGICAL_CHANGE:
				{
					SET_BIT(MCUCR_REG,ISC10);
					CLEAR_BIT(MCUCR_REG,ISC11);
					break;
				}

			}
			SET_BIT(GICR_REG,INT1);  //ENABLE EXTERNAL INTERRUPT 1


		break;
		}

		case EXTI_INT2:
		{
				switch(copy_enumInterruptMode)
			{
				case EXTI_FALLING_EDGE:
				{
				CLEAR_BIT(MCUCSR_REG,ISC2);
				break;
				}
				case EXTI_RISING_EDGE:
				{
				SET_BIT(MCUCSR_REG,ISC2);
				break;
				}
				default: /*report an error*/break;
			}
			SET_BIT(GICR_REG,INT2);  //ENABLE EXTERNAL INTERRUPT 2
			break;
		}
		default: /*report an error*/break;

	}
}
void EXTI_Disable(EXTI_source copy_enumInterruptSource)
{
	switch(copy_enumInterruptSource)
	{
	case EXTI_INT0:
	{
		CLEAR_BIT(GICR_REG,INT0);
	
	break;
	}
	case EXTI_INT1:
	{
		CLEAR_BIT(GICR_REG,INT1);
		
		break;
	}
	case EXTI_INT2:
	{
		CLEAR_BIT(GICR_REG,INT2);
		
		break;
	}
	}
}

void EXTI_SetCallBack(void(*copy_pvoidfUserfunction)(void),EXTI_source copy_enumInterruptSource)
{
	if(copy_pvoidfUserfunction!=NULL_POINTER)
	{
		switch(copy_enumInterruptSource)
		{
		case EXTI_INT0:
			EXTI_pvoidfUserFunctionINT0=copy_pvoidfUserfunction;
			break;
		case EXTI_INT1:
			EXTI_pvoidfUserFunctionINT1=copy_pvoidfUserfunction;
			break;
		case EXTI_INT2:
			EXTI_pvoidfUserFunctionINT2=copy_pvoidfUserfunction;
			break;
		}
	}
	else
	{
		/*report an error*/
	}

}
void __vector_1(void)__attribute__((signal));
void __vector_1(void)
{
	if(EXTI_pvoidfUserFunctionINT0!=NULL_POINTER)
	{
		(*EXTI_pvoidfUserFunctionINT0)();
	}
	else
	{
		/*report an error*/
	}
}

void __vector_2(void)__attribute__((signal));
void __vector_2(void)
{
	if(EXTI_pvoidfUserFunctionINT1!=NULL_POINTER)
	{
		(*EXTI_pvoidfUserFunctionINT1)();
	}
	else
	{
		/*report an error*/
	}
}
void __vector_3(void)__attribute__((signal));
void __vector_3(void)
{
	if(EXTI_pvoidfUserFunctionINT2!=NULL_POINTER)
	{
		(*EXTI_pvoidfUserFunctionINT2)();
	}
	else
	{
		/*report an error*/
	}
}
