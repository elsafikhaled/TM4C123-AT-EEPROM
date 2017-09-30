#ifndef __HW_I2C_H__
#define __HW_I2C_H__

//! I2C base register.
#define I2C0_BASE    0x40020000
#define I2C1_BASE    0x40021000
#define I2C2_BASE    0x40022000
#define I2C3_BASE    0x40023000

//! MASTER 
#define     I2CMSA      (*((volatile U32_t*)0x40021000 )) 
#define     I2CMCS      (*((volatile U32_t*)0x40021004 )) 
#define     I2CMDR      (*((volatile U32_t*)0x40021008 )) 
#define     I2CMTPR     (*((volatile U32_t*)0x4002100C )) 
#define     I2CMIMR     (*((volatile U32_t*)0x40021010 )) 
#define     I2CMRIS     (*((volatile U32_t*)0x40021014 )) 
#define     I2CMMIS     (*((volatile U32_t*)0x40021018 )) 
#define     I2CMICR     (*((volatile U32_t*)0x4002101C )) 
#define     I2CMCR      (*((volatile U32_t*)0x40021020 )) 
#define     I2CMCLKOCNT (*((volatile U32_t*)0x40021024 )) 
#define     I2CMBMON    (*((volatile U32_t*)0x4002102C )) 
#define     I2CMCR2     (*((volatile U32_t*)0x40021038 )) 

//! SLAVE
#define     I2CSOAR     (*((volatile U32_t*)0x40021800 )) 
#define     I2CSCSR     (*((volatile U32_t*)0x40021804 )) 
#define     I2CSDR      (*((volatile U32_t*)0x40021808 )) 
#define     I2CSIMR     (*((volatile U32_t*)0x4002180C )) 
#define     I2CSRIS     (*((volatile U32_t*)0x40021810 )) 
#define     I2CSMIS     (*((volatile U32_t*)0x40021814 )) 
#define     I2CSICR     (*((volatile U32_t*)0x40021818 )) 
#define     I2CSOAR2    (*((volatile U32_t*)0x4002181C )) 
#define     I2CSACKCTL  (*((volatile U32_t*)0x40021820 )) 

//! STATUS 
#define     I2CPP       (*((volatile U32_t*)0x40021FC0 )) 
#define     I2CPC       (*((volatile U32_t*)0x40021FC4 )) 







#endif //__HW_I2C_H__
