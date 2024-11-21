/*
 * std_macros.h
 *
 * Created: 10/19/2023 12:49:25 PM
 *  Author: Ghada_Moemn
 */ 


#ifndef STD_MACROS_H_
#define STD_MACROS_H_

#define REGISTER_SIZE 8

#define SET_BIT(number, bit)number|=(1<<bit)
#define CLR_BIT(number, bit)number&=(~(1<<bit))
#define TOG_BIT(number, bit)number^=(1<<bit)
#define Read_BIT(number, bit)((number&(1<<bit))>>bit)


#endif /* STD_MACROS_H_ */