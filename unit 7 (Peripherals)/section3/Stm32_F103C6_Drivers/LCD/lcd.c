/*
 * lcd.c
 *
 * Created: 10/29/2022 12:21:18 PM
 *  Author: Ayman
 */

#include "lcd.h"
//extern delay_ms () ;
void delay_ms(uint32_t time )
{
	volatile uint32_t i ,j ;
	for(i=0 ; i< time ; i++)
		for(j=0 ;j<255 ;j++)
			;
}

void LCD_kick()
{
//	LCD_CONTROL &=~(1<<ENABLE_SWITCH);
	MCAL_GPIO_WritePin(LCD_CONTROL ,ENABLE_SWITCH ,GPIO_PIN_SET) ;

	delay_ms(50);
//	LCD_CONTROL |=(1<<ENABLE_SWITCH);
	MCAL_GPIO_WritePin(LCD_CONTROL ,ENABLE_SWITCH ,GPIO_PIN_RESET) ;

}

void LCD_gotoxy(unsigned char line ,unsigned char position)
{
	if (line ==2)
	{
		if( position < 16 && position >= 0 )
		{
			LCD_WRITE_COMMAND(LCD_BEGIN_AT_SECOND_ROW + position);
		}

	}
	else if (line ==1)
	{
		if( position < 16 && position >= 0 )
		{
			LCD_WRITE_COMMAND(LCD_BEGIN_AT_FIRST_ROW + position);
		}


	}
}



void LCD_init(void)
{
	delay_ms(20);
	//DATADIR_LCD_CONTROL |=((1<<RS_SWITCH)|(1<<ENABLE_SWITCH)|(1<<RW_SWITCH));                     //set out control PINS AS output
	//LCD_CONTROL &=~((1<<RS_SWITCH)|(1<<ENABLE_SWITCH)|(1<<RW_SWITCH));                           // out zero


	pinconfig.GPIO_PIN_Numbers = RS_SWITCH        ;
	pinconfig.GPIO_PIN_MODE    = PIN_MODE_OUT_PP  ;
	pinconfig.GPIO_OUTPIN_Speed    = PIN_OUT_SPEED_10 ;
	MCAL_GPIO_INIT(LCD_CONTROL , &pinconfig );

	pinconfig.GPIO_PIN_Numbers = RW_SWITCH        ;
	pinconfig.GPIO_PIN_MODE    = PIN_MODE_OUT_PP  ;
	pinconfig.GPIO_OUTPIN_Speed    = PIN_OUT_SPEED_10 ;	MCAL_GPIO_INIT(LCD_CONTROL , &pinconfig );
	MCAL_GPIO_INIT(LCD_CONTROL , &pinconfig );

	pinconfig.GPIO_PIN_Numbers = ENABLE_SWITCH        ;
	pinconfig.GPIO_PIN_MODE    = PIN_MODE_OUT_PP  ;
	pinconfig.GPIO_OUTPIN_Speed    = PIN_OUT_SPEED_10 ;
	MCAL_GPIO_INIT(LCD_CONTROL , &pinconfig );






	//DATADIR_LCD_PORT=0xff ;
    //out data port as output

	pinconfig.GPIO_PIN_Numbers = GPIO_PIN_7        ;
	pinconfig.GPIO_PIN_MODE    = PIN_MODE_OUT_PP  ;
	pinconfig.GPIO_OUTPIN_Speed    = PIN_OUT_SPEED_10 ;
	MCAL_GPIO_INIT(LCD_PORT , &pinconfig );

	pinconfig.GPIO_PIN_Numbers = GPIO_PIN_6        ;
	pinconfig.GPIO_PIN_MODE    = PIN_MODE_OUT_PP  ;
	pinconfig.GPIO_OUTPIN_Speed    = PIN_OUT_SPEED_10 ;
	MCAL_GPIO_INIT(LCD_PORT , &pinconfig );

	pinconfig.GPIO_PIN_Numbers = GPIO_PIN_5        ;
	pinconfig.GPIO_PIN_MODE    = PIN_MODE_OUT_PP  ;
	pinconfig.GPIO_OUTPIN_Speed    = PIN_OUT_SPEED_10 ;
	MCAL_GPIO_INIT(LCD_PORT , &pinconfig );

	pinconfig.GPIO_PIN_Numbers = GPIO_PIN_4        ;
	pinconfig.GPIO_PIN_MODE    = PIN_MODE_OUT_PP  ;
	pinconfig.GPIO_OUTPIN_Speed    = PIN_OUT_SPEED_10 ;
	MCAL_GPIO_INIT(LCD_PORT , &pinconfig );
#ifdef EIGHT_BIT_MODE

	pinconfig.GPIO_PIN_Numbers = GPIO_PIN_3        ;
	pinconfig.GPIO_PIN_MODE    = PIN_MODE_OUT_PP  ;
	pinconfig.GPIO_OUTPIN_Speed    = PIN_OUT_SPEED_10 ;
	MCAL_GPIO_INIT(LCD_PORT , &pinconfig );

	pinconfig.GPIO_PIN_Numbers = GPIO_PIN_2        ;
	pinconfig.GPIO_PIN_MODE    = PIN_MODE_OUT_PP  ;
	pinconfig.GPIO_OUTPIN_Speed    = PIN_OUT_SPEED_10 ;
	MCAL_GPIO_INIT(LCD_PORT , &pinconfig );

	pinconfig.GPIO_PIN_Numbers = GPIO_PIN_1        ;
	pinconfig.GPIO_PIN_MODE    = PIN_MODE_OUT_PP  ;
	pinconfig.GPIO_OUTPIN_Speed    = PIN_OUT_SPEED_10 ;
	MCAL_GPIO_INIT(LCD_PORT , &pinconfig );


	pinconfig.GPIO_PIN_Numbers = GPIO_PIN_0        ;
	pinconfig.GPIO_PIN_MODE    = PIN_MODE_OUT_PP  ;
	pinconfig.GPIO_OUTPIN_Speed    = PIN_OUT_SPEED_10 ;
	MCAL_GPIO_INIT(LCD_PORT , &pinconfig );
#endif

	MCAL_GPIO_WritePin(LCD_CONTROL ,RS_SWITCH ,GPIO_PIN_RESET) ;
	MCAL_GPIO_WritePin(LCD_CONTROL ,RW_SWITCH ,GPIO_PIN_RESET) ;
	MCAL_GPIO_WritePin(LCD_CONTROL ,ENABLE_SWITCH ,GPIO_PIN_RESET) ;


	delay_ms(15);
	LCD_clear_screen();

#ifdef EIGHT_BIT_MODE

	LCD_WRITE_COMMAND(LCD_FUNCTION_8BIT_2LINES);
#endif

#ifdef FOUR_BIT_MODE
	LCD_WRITE_COMMAND(0x02);
	LCD_WRITE_COMMAND(LCD_FUNCTION_4BIT_2LINES);

#endif
	LCD_WRITE_COMMAND(LCD_ENTRY_MODE);
	LCD_WRITE_COMMAND(LCD_BEGIN_AT_FIRST_ROW);
	LCD_WRITE_COMMAND(LCD_DISP_ON_CURSOR_BLINK);
}








void LCD_CHECK_ISBUSY(void)
{
	//four bit mode
	//DATADIR_LCD_PORT &=~(0xff <<DATA_SHIFT) ;
	///eight bit mode
	//DATADIR_LCD_PORT =0x00 ;                                      // input mode in arm set them as input floating
	//port data all is input  highz floating input
	pinconfig.GPIO_PIN_Numbers = GPIO_PIN_0        ;
	pinconfig.GPIO_PIN_MODE  = PIN_MODE_IN_FI ;
	MCAL_GPIO_INIT(LCD_PORT, &pinconfig) ;

	pinconfig.GPIO_PIN_Numbers = GPIO_PIN_1        ;
	pinconfig.GPIO_PIN_MODE  = PIN_MODE_IN_FI ;
	MCAL_GPIO_INIT(LCD_PORT, &pinconfig) ;

	pinconfig.GPIO_PIN_Numbers = GPIO_PIN_2        ;
	pinconfig.GPIO_PIN_MODE  = PIN_MODE_IN_FI ;
	MCAL_GPIO_INIT(LCD_PORT, &pinconfig) ;

	pinconfig.GPIO_PIN_Numbers = GPIO_PIN_3        ;
	pinconfig.GPIO_PIN_MODE  = PIN_MODE_IN_FI ;
	MCAL_GPIO_INIT(LCD_PORT, &pinconfig) ;

	pinconfig.GPIO_PIN_Numbers = GPIO_PIN_4        ;
	pinconfig.GPIO_PIN_MODE  = PIN_MODE_IN_FI ;
	MCAL_GPIO_INIT(LCD_PORT, &pinconfig) ;

	pinconfig.GPIO_PIN_Numbers = GPIO_PIN_5        ;
	pinconfig.GPIO_PIN_MODE  = PIN_MODE_IN_FI ;
	MCAL_GPIO_INIT(LCD_PORT, &pinconfig) ;

	pinconfig.GPIO_PIN_Numbers = GPIO_PIN_6        ;
	pinconfig.GPIO_PIN_MODE  = PIN_MODE_IN_FI ;
	MCAL_GPIO_INIT(LCD_PORT, &pinconfig) ;

	pinconfig.GPIO_PIN_Numbers = GPIO_PIN_7        ;
	pinconfig.GPIO_PIN_MODE  = PIN_MODE_IN_FI ;
	MCAL_GPIO_INIT(LCD_PORT, &pinconfig) ;


	//config pin as read mode
//	LCD_CONTROL |=(1<<RW_SWITCH);                                   // read
	MCAL_GPIO_WritePin(LCD_CONTROL, RW_SWITCH, GPIO_PIN_SET);
//	LCD_CONTROL &=~(1<<RS_SWITCH);
	MCAL_GPIO_WritePin(LCD_CONTROL, RS_SWITCH, GPIO_PIN_RESET);

	//delay_ms(10);
	LCD_kick();
//	DATADIR_LCD_PORT=0xff ;
	pinconfig.GPIO_PIN_Numbers = GPIO_PIN_0        ;
	pinconfig.GPIO_PIN_MODE    = PIN_MODE_OUT_PP  ;
	pinconfig.GPIO_OUTPIN_Speed    = PIN_OUT_SPEED_10 ;
	MCAL_GPIO_INIT(LCD_PORT , &pinconfig );

	pinconfig.GPIO_PIN_Numbers = GPIO_PIN_1        ;
	pinconfig.GPIO_PIN_MODE    = PIN_MODE_OUT_PP  ;
	pinconfig.GPIO_OUTPIN_Speed    = PIN_OUT_SPEED_10 ;
	MCAL_GPIO_INIT(LCD_PORT , &pinconfig );

	pinconfig.GPIO_PIN_Numbers = GPIO_PIN_2        ;
	pinconfig.GPIO_PIN_MODE    = PIN_MODE_OUT_PP  ;
	pinconfig.GPIO_OUTPIN_Speed    = PIN_OUT_SPEED_10 ;
	MCAL_GPIO_INIT(LCD_PORT , &pinconfig );

	pinconfig.GPIO_PIN_Numbers = GPIO_PIN_3        ;
	pinconfig.GPIO_PIN_MODE    = PIN_MODE_OUT_PP  ;
	pinconfig.GPIO_OUTPIN_Speed    = PIN_OUT_SPEED_10 ;
	MCAL_GPIO_INIT(LCD_PORT , &pinconfig );

	pinconfig.GPIO_PIN_Numbers = GPIO_PIN_4        ;
	pinconfig.GPIO_PIN_MODE    = PIN_MODE_OUT_PP  ;
	pinconfig.GPIO_OUTPIN_Speed    = PIN_OUT_SPEED_10 ;
	MCAL_GPIO_INIT(LCD_PORT , &pinconfig );

	pinconfig.GPIO_PIN_Numbers = GPIO_PIN_5        ;
	pinconfig.GPIO_PIN_MODE    = PIN_MODE_OUT_PP  ;
	pinconfig.GPIO_OUTPIN_Speed    = PIN_OUT_SPEED_10 ;
	MCAL_GPIO_INIT(LCD_PORT , &pinconfig );

	pinconfig.GPIO_PIN_Numbers = GPIO_PIN_6        ;
	pinconfig.GPIO_PIN_MODE    = PIN_MODE_OUT_PP  ;
	pinconfig.GPIO_OUTPIN_Speed    = PIN_OUT_SPEED_10 ;
	MCAL_GPIO_INIT(LCD_PORT , &pinconfig );


	pinconfig.GPIO_PIN_Numbers = GPIO_PIN_7        ;
	pinconfig.GPIO_PIN_MODE    = PIN_MODE_OUT_PP  ;
	pinconfig.GPIO_OUTPIN_Speed    = PIN_OUT_SPEED_10 ;
	MCAL_GPIO_INIT(LCD_PORT , &pinconfig );




	//output mode for data port
	//LCD_CONTROL &=~(1<<RW_SWITCH);                                     //write

	MCAL_GPIO_WritePin(LCD_CONTROL, RW_SWITCH, GPIO_PIN_RESET);
}
void LCD_WRITE_COMMAND (unsigned char command)
{

	MCAL_GPIO_WritePin(LCD_CONTROL, RW_SWITCH, GPIO_PIN_RESET);
	MCAL_GPIO_WritePin(LCD_CONTROL, RS_SWITCH, GPIO_PIN_RESET);
#ifdef EIGHT_BIT_MODE
	MCAL_GPIO_WritePort(LCD_PORT , command);



	delay_ms(1);
	LCD_kick();
#endif
#ifdef FOUR_BIT_MODE
	MCAL_GPIO_Write_Nibble(LCD_CONTROL, LCD_NIBBLE, (command &0xF0)>>4);//Send first nibble of command

	LCD_kick();//Set and Reset E bin
	delay_ms(1);

	MCAL_GPIO_Write_Nibble(LCD_CONTROL, LCD_NIBBLE, (command &0x0F));//Send Second Nibble command
	LCD_kick();//Set and Reset E bin
	delay_ms(1);
#endif
}
void LCD_WRITE_CHAR (unsigned char data)
{
	//LCD_CONTROL &=~(1<<RW_SWITCH);
	MCAL_GPIO_WritePin(LCD_CONTROL, RW_SWITCH, GPIO_PIN_RESET);

	//LCD_CONTROL |= (1<<RS_SWITCH);
	MCAL_GPIO_WritePin(LCD_CONTROL, RS_SWITCH, GPIO_PIN_SET);
#ifdef EIGHT_BIT_MODE
	//LCD_CHECK_ISBUSY();

	//LCD_PORT=data ;
	MCAL_GPIO_WritePort(LCD_PORT , data);



	delay_ms(1);

	LCD_kick();
#endif
#ifdef FOUR_BIT_MODE

	MCAL_GPIO_Write_Nibble(LCD_CONTROL, LCD_NIBBLE, ((data &0xF0)>>4));

	LCD_kick();//Set and Reset E bin
	delay_ms(1);

	MCAL_GPIO_Write_Nibble(LCD_CONTROL, LCD_NIBBLE,(data & 0x0F));
	
	LCD_kick();//Set and Reset E bin
	delay_ms(1);
#endif

}
void LCD_WRITE_STRING (char* data)
{
	int count = 0 ;
	while (*data > 0)
	{
		count++ ;
		LCD_WRITE_CHAR(*data++) ;
		if (count ==16)
		{
			LCD_gotoxy(2,0) ;

		}
		else if (count==32)
		{

			LCD_clear_screen();
			LCD_gotoxy(1,0);
			count=0 ;
		}
	}
}

void LCD_clear_screen(){
	LCD_WRITE_COMMAND(LCD_CLEAR_SCREEN);
}
