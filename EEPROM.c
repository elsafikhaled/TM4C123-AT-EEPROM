#include "EEPROM.h"
#include "I2C.h"


void EEPROM_init(void){//Start setup function.
//I2C protocol setup function to control EEPROM.	
//MASTER Mode 400KHZ speed of bus sys.clock=16MHZ.
  I2C1_Master_Init();
		
}//! End of setup function.


//Writing data to EEPROM addresses. 
void EEPROM_Write(U8_t data,U8_t address){//start of writing function.
U8_t error=0;	
//I2C timing protocol frame of data on Bus.
 //send start bit (low bit) to win bus control.
   	I2C1_StartBit();
 //send Adresse of EEPROM ID:(0XA0|0x00)->0 as A0,A1,A2 connected to GND and 0x00 Write bit.
    error=I2C1_Master_TX(EEPROM_ID|WRITE);
	  while(error==1){
		     error=I2C1_Master_TX(EEPROM_ID|WRITE);
	  }	
 //send Adresse which i will write to it.
	  error=I2C1_Master_TX(address);
	  while(error==1){
		     error=I2C1_Master_TX(address);
	  }			
 //send data to the demanded addresse.
    error=I2C1_Master_TX(data);
	  while(error==1){
		     error=I2C1_Master_TX(data);
	  }			
 //send stop bit to finish TX data.
    I2C1_StopBit();
 //END of frame.
	
}//! End of Write function.


void EEPROM_Read(U8_t *data,U8_t ACK,U8_t address){//! start Reading function.
	U8_t error=0;
//I2C timing protocol frame of data on Bus.
 //send start bit (low bit) to win bus control.
    I2C1_StartBit();	
 //send Adresse of EEPROM ID:(0XA0|0x00)->0 as A0,A1,A2 connected to GND and 0x00 Write bit.
    error=I2C1_Master_TX(EEPROM_ID|WRITE);
	  while(error==1){
		     error=I2C1_Master_TX(EEPROM_ID|WRITE);
	  }
 //send Adresse which i will write to it.
	  error=I2C1_Master_TX(address);
	  while(error==1){
		     error=I2C1_Master_TX(address);
	  }		
 //Repeat start to change mode from write to Read.
	  I2C1_StartBit();
 //send Adresse of EEPROM ID:(0XA0|0x01)->0 as A0,A1,A2 connected to GND and 0x01 Read bit.
    error=I2C1_Master_TX(EEPROM_ID|READ);
	  while(error==1){
		     error=I2C1_Master_TX(EEPROM_ID|READ);
	  }	  		
 //Read data from EEPROM
   *data=I2C1_Master_RX(ACK);	
	  while(*data==1){
         *data=I2C1_Master_RX(ACK);
  	     }
 //Stop bit TX to finish reading.
	 I2C1_StopBit();
 //END 
				 
}//! End of Reading function.


