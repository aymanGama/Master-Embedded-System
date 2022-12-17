/*
 * KAYBAD.c
 *
 * Created: 11/6/2022 5:13:58 AM
 *  Author: Ayman 
 */ 
#include "KEYPAD.h"

char KEKEYBAD_R[] = {R0 , R1 , R2 , R3};
char KEKEYBAD_C[] = {C0 , C1 , C2 , C3};
void KEYBAD_INIT()
{
	DATADIR_KEYPAD &= ~((1<<R0) |(1<<R1) | (1<<R2) | (1<<R3));
	DATADIR_KEYPAD |= ((1<<C0) |(1<<C1) | (1<<C2) | (1<<C3));
	KEYPAD_PORT =0xff ;
	
}
char KEYPAD_GET_CHAR()
{
	int i ,j ;
	for (i = 0 ; i < 4 ; i++)
	{
		KEYPAD_PORT |= ((1<<C0) |(1<<C1) | (1<<C2) | (1<<C3));
		KEYPAD_PORT &=~(1<<KEKEYBAD_C[i]);
		for ( j =0 ; j < 4 ; j++)
		{
			if (!(KEYPAD_PIN &(1<<KEKEYBAD_R[j])))
			{
				while (!(KEYPAD_PIN &(1<<KEKEYBAD_R[j])));
				switch (i)
				{
					case 0:
					{
						
						if (j==0) return ('7');
						if (j==1) return ('4');
						if (j==2) return ('1');
						if (j==3) return ('?');
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
