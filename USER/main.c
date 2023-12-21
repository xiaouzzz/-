/****************************************************************************

ÂóÂÖÐ¡³µÒý½Å·ÖÅä

N20µç»ú

STBY1:PB4    STBY2:PB9

STBYÒý½Å¿ÉÒÔÀí½âÎª´ËÇý¶¯Æ÷µÄ×Ü¿ª¹Ø£¬¸ßµçÆ½µÄÇé¿öÏÂÇý¶¯Æ÷²Å¿ÉÒÔÕý³£¹¤×÷£
STBYÎªµÍµçÆ½µÄÊ±ºò£¬Õû¸öÇý¶¯Æ÷Í£Ö¹¹¤×÷¡£

1:PA2,PB6      2:PA3,PB5
3:PA0,PB8      4:PA1,PB7

À¶ÑÀÄ£¿é£ºPA9,PA10


NRF24L01 
CE->PB13  CSN->PB14  IRQ->PB15  SCK->PA5  MISO->PA6  MOSI->PA7  

|-----------------|  IRQ   MISO 
|       NRF     ::|  MOSI  SCK                       
|      24L01    ::|  CSN   CE
|-----------------|  VCC   GND


³¬Éù²¨Ä£¿é

TRIG:PB10         ECHO:PB11

RGB²ÊµÆ

DI:PB0


************************************************************************************/


#include "stdio.h"
#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "control.h"


int main(void)
{	
	delay_init();	    	 //ÑÓÊ±º¯Êý³õÊ¼»¯	 
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	LED_Init(); 
	USART1_Init(9600);	 //´®¿Ú³õÊ¼»¯Îª9600
	NRF24L01_Init();
    NRF24L01_Check_detection();//NRF24L01µÈ´ýÓ¦´ð
	Motor_Init();//µç»ú³õÊ¼»¯
	Hcsr04_Init();//³¬Éù²¨³õÊ¼»¯
	Motion_State(OFF);//¹Ø±Õµç»úÇý¶¯Ê§ÄÜ
	RGB_LED_Init();//RGB²ÊµÆ³õÊ¼»¯
	delay_ms(1000);
	LED=0;
	while(1)
  {
		Control();	
	}
} 

