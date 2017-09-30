#include "HW_gpio.h"
#include "GPIO_I2C.h"
#include "SysCtrl.h"

void GPIO_I2C1(void){
//test mode
    //Clock enable portA.
	clock_Enable_PORT(Clock_PortA);
	//Open lock
	GPIO_PORTA_lock=0x4c4f434b;
	GPIO_PORTA_CR|=0x000000C0;
	
	//OPen drain for data pin SDATA.
	GPIO_PORTA_OPDR|=(1<<7);
	//Select alternating Function for PORTA pins as I2C
	GPIO_PORTA_AFSEL|=0xc0;
	// Access port functions from control table
	GPIO_PORTA_PCTRL|=0x33000000;
	//Enable digital function for PORTA pins
	GPIO_PORTA_DEN|=(1<<PA6)|(1<<PA7);
	//Turn off Analog function
	GPIO_PORTA_AMSEL=0x00;
	
}//!End of GPIO SPI Function.