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

//#define    LED3_ON()    (rGPBDAT &= ~(0x1))   //当LED3亮的时候，把GPBDAT的最后一位置0 （GPB0是最后一位撒）
//#define    LED3_OFF()   (rGPBDAT |= (0x1)) //当LED3 灭的时候，把GPBDAT的最后一位置1 （GPB0是最后一位撒）


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
	if(control==1)//开蜂鸣器
		{
			while(1)
			{
			
				Beep(3000,60); 
				Beep(3000,60); 
				Beep(3000,60); 
				Beep(3000,60); 
				Beep(3000,60); 
			}
			return 1;//蜂鸣器开 
		}
	else if(control==0)//关蜂鸣器 
	{
		Buzzer_Stop();
		return 0;
	}
 } 
 
 int LED_Control(int control)
 {
 	if(control==1)//开灯
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
	time.hour = rBCDHOUR  ;		//小时
	time.minute = rBCDMIN  ;		//分
	time.second = rBCDSEC  ;		//秒
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
