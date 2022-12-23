/*
 * WDT.c
 * 
 * Created: 11/30/2022 8:08:48 PM
 * Author : Ayman_Gamal 
 */ 

#define  F_CPU    8000000UL
#include <avr/io.h>
#include <util/delay.h>


#define LED_DDR                       DDRA
#define LED_PROT                      PORTA
#define LED_PIN                          1
#define SET_PIN(PORT,PIN)       (PORT |=1<<PIN)    
#define CLEAR_PIN(PORT,PIN)     (PORT &=~(1<<PIN))
#define TOGGLE_PIN(PORT,PIN)    (PORT ^=1<<PIN)

void WDT_OFF()
{
	WDTCR = (1<<WDE)|(1<<WDTOE) ;
	WDTCR = 0 ;
}
#define WDT_16ms        0
#define WDT_32ms        1
#define WDT_65ms        2
#define WDT_130ms       3
#define WDT_260ms       4
#define WDT_520ms       5
#define WDT_1s          6
#define WDT_2s          7


void WDT_ON(uint8_t time)
{
	switch (time)
	{
		case 0:
		WDTCR &=~(7<<0);
		break;
		case 1:
		WDTCR |=(1<<0);
		break;
		case 2:
		WDTCR |=(2<<0);
		break;
		case 3:
		WDTCR |=(3<<0);
		break;
		case 4:
		WDTCR |=(4<<0);
		break;
		case 5:
		WDTCR |=(5<<0);
		break;
		case 6:
		WDTCR |=(6<<0);
		break;
		case 7:
		WDTCR |=(7<<0);
		break;
		default :
		break ;
	}
	WDTCR |= 1<<WDE ; 
}

int main(void)
{
  
  SET_PIN(LED_DDR,LED_PIN);
  CLEAR_PIN(LED_PROT,LED_PIN);
  
  _delay_ms(2000);
    while (1) 
    {
		 WDT_ON(WDT_1s);
		 SET_PIN(LED_PROT,LED_PIN) ;
			WDT_OFF();
    }

}

