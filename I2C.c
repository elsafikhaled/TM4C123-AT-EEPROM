#include "I2C.h"
#include "HW_I2C.h"
#include "GPIO_I2C.h"
#include "SysCtrl.h"

//! I2C Setup modes MASTER and SLAVE
//MASTER Mode.
void I2C1_Master_Init(void){
//Enable clock for I2C1.
Clock_Enable_I2C(I2C1);
//GPIO setup.
GPIO_I2C1();
//MASTER mode select.
I2CMCR|=0x00000010;
//calculate the SCL period at a speed of 400kbps at 16 MHZ.
/***************SCL period calculation.*****************
TPR = (System Clock/(2*(SCL_LP + SCL_HP)*SCL_CLK))-1;  *
TPR = (16MHz/(2*(6+4)*400000))-1;                      *
TPR = 1                                                *
*******************************************************/	
I2CMTPR|=0x01;
//write slave addresse 7bit and R/W bit.
I2CMSA=0x3B;
//Set RUN bit to make MASTER TX and RX.
I2CMCS|=(1<<0);
//Data Acknowledge Enable
I2CMCS|=(1<<3);
	
}//! End of MASTER Function.


//TX start bit
void I2C1_StartBit(void){
	I2CMCS|=(1<<1);
}//! End of TX start bit

//TX stop bit
void I2C1_StopBit(void){
	I2CMCS|=(1<<2);
}//! End of TX stop bit


//MASTER modes TX or RX.
//TX mode.
U16_t I2C1_Master_TX(U16_t data){
	I2CMDR=data;
	//ckeck that data sent well by polling busy bit.
	while(I2CMCS&(1<<0));
	//check that slave sent ACK  by polling ERROR bit..
	if(I2CMCS&(1<<1)){
	 	return 1;//error
	}
	return 0;//well
}//! End of TX mode.


U16_t I2C1_Master_RX(U8_t ACK){
	U16_t data=0;
	//ckeck that data get well by polling busy bit.
	while(I2CMCS&(1<<0));
	//check that no operation error  by polling ERROR bit..
	if(I2CMCS&(1<<1)){
	 	return 1;//error
	}
	data=I2CMDR;
	//Data Acknowledge Enable
     I2CMCS|=(0x8&(ACK<<3));
	return data ;//well
	
}//! End of RX mode.



