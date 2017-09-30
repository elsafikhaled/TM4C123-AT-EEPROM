#ifndef __EEPROM_H__
#define __EEPROM_H__
#include "I2C.h"

//! EEPROM ID enum.
enum EEPROM{
	EEPROM_ID=0XA0,
	WRITE=0X00,
	READ=0X01,
};//!End of ID enum.


//!calculate the SCL period at a speed of 400kbps at 16 MHZ.

/********      SCL period EEPROM      ******************
TPR = (System Clock/(2*(SCL_LP + SCL_HP)*SCL_CLK))-1;  *
TPR = (16MHz/(2*(6+4)*400000))-1;                      *
TPR = 1                                                *
*******************************************************/	


//Setup function for ATMEL EEPROM*32KBYTE based on I2C protocol.
void EEPROM_init(void);

//Writing data to EEPROM addresses. 
void EEPROM_Write(U8_t data,U8_t address);

/** Reading from EEPROM addresses when reading:
     - one  byte  make ACK=0
	   - Many bytes make ACK=1
**/
void EEPROM_Read(U8_t *data,U8_t ACK,U8_t address);


#endif //__EEPROM_H__

