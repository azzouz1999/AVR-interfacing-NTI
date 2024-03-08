/*
 * EXTI_interface.h
 *
 * Created: 3/3/2024 1:13:33 PM
 *  Author: ali_a
 */ 


#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

typedef enum
{
	EXTI_INT0=0,
	EXTI_INT1,   //1
	EXTI_INT2,   //2
}EXTI_source;

typedef enum
{
  EXTI_RISING_EDGE=0,
  EXTI_FALLING_EDGE,
  EXTI_LOW_LEVEL,
  EXTI_ANY_LOGICAL_CHANGE,
}EXTI_senseControl;

void EXTI_Enable(EXTI_source copy_enumInterruptSource ,  EXTI_senseControl copy_enumInterruptMode);
void EXTI_Disable(EXTI_source copy_enumInterruptSource);
void EXTI_SetCallBack(void(*copy_pvoidfUserfunction)(void),EXTI_source copy_enumInterruptSource);



#endif /* EXTI_INTERFACE_H_ */
