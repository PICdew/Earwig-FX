/*
 * File:        sram.h
 * Author:      Sam Faull
 * Description: 
 */

#ifndef SRAM_H
#define	SRAM_H

#include <xc.h> // include processor files - each processor file is guarded.  
#include "system.h"

// pin declarations
#define SRAM0_SS LATAbits.LATA8 //SS SPI slave select for 1st SRAM
#define SRAM1_SS LATAbits.LATA9 //SS SPI slave select for 2nd SRAM

// SRAM chip commands
#define READ  0x03  // Read data from memory array beginning at selected address
#define WRITE 0x02  // Write data to memory array beginning at selected address
#define RDMR  0x05  // Read mode register
#define WRMR  0x01  // Wrrite mode register

// SRAM Modes of operation
#define byte 0
#define seq  64
#define page 128

#define SRAM_SIZE (128L * 1024L)  // 128kb
#define AVAILABLE_MEMORY (SRAM_SIZE * 2)    // we have two SRAM chips available

void sram_init(unsigned char sram_mode);
void sram_fill(unsigned char sramdata);
void sram_write(unsigned long sramaddress, unsigned int sramdata);
unsigned int sram_read(unsigned long sramaddress);

#endif	/* SRAM_H */

