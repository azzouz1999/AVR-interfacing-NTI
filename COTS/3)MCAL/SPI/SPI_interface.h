/*
 * SPI_interface.h
 *
 *  Created on: Mar 5, 2024
 *      Author: ali_a
 */

#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_

void SPI_voidInitMaster(void);
void SPI_voidInitSlave(void);
void SPI_u8Transieve(u8 copy_u8TxData,u8*  copy_u8RxData);

void SPI_voidEnableInterrupt(void);
void SPI_voidDisableInterrupt(void);

void SPI_voidSetCallBack(void(*copy_pvoidfUserFunction)(void));

#endif /* SPI_INTERFACE_H_ */
