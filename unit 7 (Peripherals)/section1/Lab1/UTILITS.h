/*
 * UTILITS.h
 *
 * Created: 10/24/2022 11:19:10 PM
 *  Author: Ayman_Gamal 
 */ 


#ifndef UTILITS_H_
#define UTILITS_H_

#define Setbit(reg,bit)    (reg |= (1<<bit))
#define Clearbit(reg,bit)    (reg &= ~(1<<bit))
#define Readbit(reg,bit)    ((reg & (1<<bit))>>bit)



#endif /* UTILITS_H_ */