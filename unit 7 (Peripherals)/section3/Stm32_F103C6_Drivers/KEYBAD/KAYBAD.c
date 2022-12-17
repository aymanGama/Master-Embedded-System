/*
 * KAYBAD.c
 *
 * Created: 11/6/2022 5:13:58 AM
 *  Author: Ayman 
 */ 
#include "KEYPAD.h"

char KEKEYBAD_R[] = {R0 , R1 , R2 , R3};
uint16_t KEKEYBAD_C[] = {C0 , C1 , C2 , C3}; //because C3 = 0x0100
void KEYBAD_INIT()
{
	GPIO_PIN_config_t pinconfig ;
	//	DATADIR_KEYPAD &= ~((1<<R0) |(1<<R1) | (1<<R2) | (1<<R3));
	//	DATADIR_KEYPAD |= ((1<<C0) |(1<<C1) | (1<<C2) | (1<<C3));
	// CONFIG ALL PIN AS OUTPUT
	pinconfig.GPIO_PIN_Numbers = R0        ;
	pinconfig.GPIO_PIN_MODE    = PIN_MODE_OUT_PP  ;
	pinconfig.GPIO_OUTPIN_Speed    = PIN_OUT_SPEED_10 ;
	MCAL_GPIO_INIT(KEYPAD_PORT , &pinconfig );

	pinconfig.GPIO_PIN_Numbers = R1        ;
	pinconfig.GPIO_PIN_MODE    = PIN_MODE_OUT_PP  ;
	pinconfig.GPIO_OUTPIN_Speed    = PIN_OUT_SPEED_10 ;
	MCAL_GPIO_INIT(KEYPAD_PORT , &pinconfig );

	pinconfig.GPIO_PIN_Numbers = R2        ;
	pinconfig.GPIO_PIN_MODE    = PIN_MODE_OUT_PP  ;
	pinconfig.GPIO_OUTPIN_Speed    = PIN_OUT_SPEED_10 ;
	MCAL_GPIO_INIT(KEYPAD_PORT , &pinconfig );

	pinconfig.GPIO_PIN_Numbers = R3        ;
	pinconfig.GPIO_PIN_MODE    = PIN_MODE_OUT_PP  ;
	pinconfig.GPIO_OUTPIN_Speed    = PIN_OUT_SPEED_10 ;
	MCAL_GPIO_INIT(KEYPAD_PORT , &pinconfig );

	pinconfig.GPIO_PIN_Numbers = C0        ;
	pinconfig.GPIO_PIN_MODE    = PIN_MODE_OUT_PP  ;
	pinconfig.GPIO_OUTPIN_Speed    = PIN_OUT_SPEED_10 ;
	MCAL_GPIO_INIT(KEYPAD_PORT , &pinconfig );

	pinconfig.GPIO_PIN_Numbers = C1        ;
	pinconfig.GPIO_PIN_MODE    = PIN_MODE_OUT_PP  ;
	pinconfig.GPIO_OUTPIN_Speed    = PIN_OUT_SPEED_10 ;
	MCAL_GPIO_INIT(KEYPAD_PORT , &pinconfig );

	pinconfig.GPIO_PIN_Numbers = C2        ;
	pinconfig.GPIO_PIN_MODE    = PIN_MODE_OUT_PP  ;
	pinconfig.GPIO_OUTPIN_Speed    = PIN_OUT_SPEED_10 ;
	MCAL_GPIO_INIT(KEYPAD_PORT , &pinconfig );

	pinconfig.GPIO_PIN_Numbers = C3       ;
	pinconfig.GPIO_PIN_MODE    = PIN_MODE_OUT_PP  ;
	pinconfig.GPIO_OUTPIN_Speed    = PIN_OUT_SPEED_10 ;
	MCAL_GPIO_INIT(KEYPAD_PORT , &pinconfig );


	//KEYPAD_PORT =0xff ;
	MCAL_GPIO_WritePort( KEYPAD_PORT, 	0xff);

}
char KEYPAD_GET_CHAR()
{
	volatile int i  ,j ;
	for (i = 0 ; i < 4 ; i++)
	{
		//	KEYPAD_PORT |= ((1<<C0) |(1<<C1) | (1<<C2) | (1<<C3));
		//	KEYPAD_PORT &=~(1<<KEKEYBAD_C[i]);



		MCAL_GPIO_WritePin(KEYPAD_PORT , KEKEYBAD_C[0],GPIO_PIN_SET );
		MCAL_GPIO_WritePin(KEYPAD_PORT , KEKEYBAD_C[1],GPIO_PIN_SET );
		MCAL_GPIO_WritePin(KEYPAD_PORT , KEKEYBAD_C[2],GPIO_PIN_SET );
		MCAL_GPIO_WritePin(KEYPAD_PORT , KEKEYBAD_C[3],GPIO_PIN_SET );
		MCAL_GPIO_WritePin(KEYPAD_PORT , KEKEYBAD_C[i],GPIO_PIN_RESET);


		for ( j =0 ; j < 4 ; j++)
		{
			//(MCAL_GPIO_ReadPin(KEYPAD_PORT, KEKEYBAD_R[J]) ==0)
			if ((MCAL_GPIO_ReadPin(KEYPAD_PORT, KEKEYBAD_R[j]) == 0))
			{
				while ((MCAL_GPIO_ReadPin(KEYPAD_PORT, KEKEYBAD_R[j]) == 0));
				switch (i)
				{
				case 0:
				{

					if (j==0) return ('7');
					if (j==1) return ('4');
					if (j==2) return ('1');
					if (j==3) return ('!');
					break;
				}
				case 1:
				{
					if (j==0) return ('8');
					if (j==1) return ('5');
					if (j==2) return ('2');
					if (j==3) return ('0');
					break;
				}
				case 2:
				{
					if (j==0) return ('9');
					if (j==1) return ('6');
					if (j==2) return ('3');
					if (j==3) return ('=');
					break;
				}
				case 3:
				{
					if (j==0) return ('/');
					if (j==1) return ('*');
					if (j==2) return ('-');
					if (j==3) return ('+');
					break;
				}
				
				}
			}
		}
	}
	return ('N');
}
