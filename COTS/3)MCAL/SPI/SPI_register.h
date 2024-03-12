/*
 * SPI_register.h
 *
 *  Created on: Mar 5, 2024
 *      Author: ali_a
 */

#ifndef SPI_REGISTER_H_
#define SPI_REGISTER_H_

typedef struct
{
	u8 SPCR;
	u8 SPSR;
	u8 SPDR;
}SPI_regs;

#define SPI ((volatile SPI_regs*)0x2D)

#define SPIE	7
#define SPE		6
#define DORD	5
#define MSTR	4
#define CPOL	3
#define CPHA	2
#define SPR1	1
#define SPR0	0

#define SPIF	7
#define WCOL	6
#define SPI2X	0
#endif /* SPI_REGISTER_H_ */
