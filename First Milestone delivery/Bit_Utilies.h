#ifndef BIT_H
#define BIT_H

#define GET_BIT(reg1,bit)   ((reg1>>bit)&1)
#define GET_REG(reg)        (reg&0xff)

#define SET(reg,val)        reg |= val
#define SET_BIT(reg,val)    reg |= (1<<val)

#define CLR(reg,val)        reg &=~val
#define CLR_BIT(reg,val)    reg &=~(1<<val)

#define CHECK_REG(reg1,reg2) ((reg1&reg2))

#endif
