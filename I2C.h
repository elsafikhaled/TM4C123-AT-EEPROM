#ifndef __I2C_H__
#define __I2C_H__
#include "data_types.h"

//! I2C Setup modes MASTER and SLAVE
//MASTER Mode.
void I2C1_Master_Init(void);
//MASTER modes TX or RX.
//TX mode.
U16_t I2C1_Master_TX(U16_t data);
//RX mode.
U16_t I2C1_Master_RX(U8_t ACK);

//TX start bit
void I2C1_StartBit(void); 

//TX stop bit
void I2C1_StopBit(void);


#endif //__I2C_H__
