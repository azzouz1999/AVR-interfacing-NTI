/*
 * SPI_interface.h
 *
 *  Created on: Mar 5, 2024
 *      Author: ali_a
 */

#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_

#define SPI_MODE_MASTER   1
#define SPI_MODE_SLAVE   0

#define SPI_CLOCK_POLPHA_NONINVERTING_LEADING    0
#define SPI_CLOCK_POLPHA_NONINVERTING_TRAILING   1
#define SPI_CLOCK_POLPHA_INVERTING_LEADING       2
#define SPI_CLOCK_POLPHA_INVERTING_TRAILING      3

#define SPI_DATAORDER_MSB  0
#define SPI_DATAORDER_LSB  1

#define SPI_PRESCALER_4       0
#define SPI_PRESCALER_16      1
#define SPI_PRESCALER_64      2
#define SPI_PRESCALER_128     3
#define SPI_PRESCALER_2       4
#define SPI_PRESCALER_8       5
#define SPI_PRESCALER_32      6



void SPI_voidInit(u8 ARG_u8Mode, u8 ARG_u8ClockPolPha, u8 ARG_u8DataOrder,u8 ARG_u8Prescaler);
void SPI_voidEnable(void);
void SPI_voidDisable(void);
void SPI_voidEnableInterrupt(void);
void SPI_voidDisableInterrupt(void);
void SPI_voidSetCallback(void(*ARG_pvoidfUserFunction)(void));
void SPI_voidFlagPolling(void);
char SPI_charTranceive(char ARG_charData);


#endif /* SPI_INTERFACE_H_ */
