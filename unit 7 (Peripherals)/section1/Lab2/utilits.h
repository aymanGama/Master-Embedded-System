/*
 * utilits.h
 *
 * Created: 10/24/2022 2:17:35 AM
 *  Author: DR-Mosaad
 */ 


#ifndef UTILITS_H_
#define UTILITS_H_

#define Setbit(reg,bit)    (reg |= (1<<bit))
#define Clearbit(reg,bit)    (reg &= ~(1<<bit))
#define Readbit(reg,bit)    ((reg & (1<<bit))>>bit)


#endif /* UTILITS_H_ */