/************************************/
/* Author		: Ali Azzouz		*/
/* SWC			: Seven segment		*/
/* Layer		: HAL       	    */
/* Version		: 1.0				*/
/* Date			: march 1,2024	*/
/* Last Edit	: N/A			 	*/
/************************************/
#ifndef SSEG_CONFIG_H_
#define SSEG_CONFIG_H_


/****************** 4BIT MODE ******************/
	
/*****************control port******************/
	
	#define SSEG_4BIT_CTRL12_PORT   DIO_PORTA
	#define SSEG_4BIT_CTRL34_PORT   DIO_PORTB

/*********************** data port ***********************/

	#define SSEG_4BIT_DATA_PORT   DIO_PORTB
	
/***********************   data pins  ***********************/

	#define SSEG_4BIT_PIN_A       0
	#define SSEG_4BIT_PIN_B       1
	#define SSEG_4BIT_PIN_C       2
	#define SSEG_4BIT_PIN_D       4

/***********************  control pins  ***********************/

	#define SSEG_4BIT_PIN_COM1 		  3
	#define SSEG_4BIT_PIN_COM2 		  2
	#define SSEG_4BIT_PIN_COM3 		  5
	#define SSEG_4BIT_PIN_COM4 		  6
	
	
	
	
/******************************* 7BIT MODE *******************************/

/*********************** control port ***********************/

    #define SSEG_7BIT_CTRL_PORT   DIO_PORTA

/*********************** data port ***********************/
	
	#define SSEG_7BIT_DATA_PORT   DIO_PORTB

/***********************   data pins  ***********************/

	#define SSEG_7BIT_PIN_0       0
	#define SSEG_7BIT_PIN_1       1
	#define SSEG_7BIT_PIN_2       2
	#define SSEG_7BIT_PIN_3       3
	#define SSEG_7BIT_PIN_4       4
	#define SSEG_7BIT_PIN_5       5
	#define SSEG_7BIT_PIN_6       6

/***********************  control pins  ***********************/

	#define SSEG_7BIT_PIN_CTRL 		  0
	
#endif  /*SSEG_CONFIG_H_*/
