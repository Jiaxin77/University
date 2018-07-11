#include<stdio.h>
#include<stdlib.h>

#include "webif.h"


#include "Option.h"
#include "S3C2440addr.h"
#include "S3C2440lib.h"
#include "S3C2440slib.h" 


#define REQCNT 100 
#define ADC_FREQ 2500000
#define LOOP 10000

//#define    LED3_ON()    (rGPBDAT &= ~(0x1))   //��LED3����ʱ�򣬰�GPBDAT�����һλ��0 ��GPB0�����һλ����
//#define    LED3_OFF()   (rGPBDAT |= (0x1)) //��LED3 ���ʱ�򣬰�GPBDAT�����һλ��1 ��GPB0�����һλ����


volatile U32 preScaler;


void Led_Display(int data)
{
	rGPBDAT = (rGPBDAT & ~(0xf<<5)) | ((~data&0xf)<<5);
	Delay(1000);
}

void Led_off()
{
	rGPBDAT=rGPBDAT&0x20;
	 
}


int BeepControl(int control)
{
	if(control==1)//��������
		{
			while(1)
			{
			
				Beep(3000,60); 
				Beep(3000,60); 
				Beep(3000,60); 
				Beep(3000,60); 
				Beep(3000,60); 
			}
			return 1;//�������� 
		}
	else if(control==0)//�ط����� 
	{
		Buzzer_Stop();
		return 0;
	}
 } 
 
 int LED_Control(int control)
 {
 	if(control==1)//����
	 {
	 	Led_Display(1);
	 	return 1;
	  } 
    else if(control==0)
    {
    	Led_off();
    	return 0;
	} 
  } 
  
  
RTC_TimeTypeDef RTC_GetDate(void)
{
	RTC_TimeTypeDef time;
	rRTCCON = 1 ;	
	time.year=0x2000+rBCDYEAR ;
	time.month = rBCDMON  ;	
	time.day = rBCDDAY  ;
	time.hour = rBCDHOUR  ;		//Сʱ
	time.minute = rBCDMIN  ;		//��
	time.second = rBCDSEC  ;		//��
	rRTCCON &= ~1 ;	
	return time;
}


int ReadAdc(int ch)
{
	int i;
	static int prevCh=-1;

	rADCCON = (1<<14)|(preScaler<<6)|(ch<<3);		//setup channel

	if(prevCh!=ch)
	{
		rADCCON = (1<<14)|(preScaler<<6)|(ch<<3);	//setup channel
		for(i=0;i<LOOP;i++);							//delay to set up the next channel
		prevCh=ch;
	}
	rADCCON|=0x1;									//start ADC

	while(rADCCON & 0x1);							//check if Enable_start is low
	while(!(rADCCON & 0x8000));						//check if EC(End of Conversion) flag is high

	return ( (int)rADCDAT0 & 0x3ff );
}
