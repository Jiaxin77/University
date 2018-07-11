#include "/lwip/src/include/lwip/debug.h"
#include "httpd.h"
#include "lwip/tcp.h"
#include "fs.h"
//#include "lwip_comm.h"
//#include "led.h"
//#include "pcf8574.h"
//#include "adc.h"
//#include "rtc.h"
//#include "lcd.h"
#include "webif.h"
#include "ucos_ii.h"
#include "os_cfg.h"
#include "S3C2440addr.h" 
#include "S3C2440lib.h"
#include <string.h>
#include <stdlib.h>
//////////////////////////////////////////////////////////////////////////////////	 
//new 
//������ֻ��ѧϰʹ�ã�δ��������ɣ��������������κ���;

//ALIENTEK STM32F4&F7������
//http ����	   
//����ԭ��@ALIENTEK
//������̳:www.openedv.com
//��������:2016/8/5
//�汾��V1.0
//��Ȩ���У�����ؾ���
//Copyright(C) ������������ӿƼ����޹�˾ 2009-2019
//All rights reserved									  
//*******************************************************************************
//�޸���Ϣ
//��
////////////////////////////////////////////////////////////////////////////////// 	   
 

#define NUM_CONFIG_CGI_URIS	2  //CGI��URI����
#define NUM_CONFIG_SSI_TAGS	6  //SSI��TAG����   Ҫ�ģ� 

//����LED��BEEP��CGI handler
const char* LEDS_CGI_Handler(int iIndex, int iNumParams, char *pcParam[], char *pcValue[]);
const char* BEEP_CGI_Handler(int iIndex,int iNumParams,char *pcParam[],char *pcValue[]);

int BEEP_FLAG=0;//������״̬ 0-���� 1-�� 
int LED_FLAG=0;//��״̬ 0-���� 1-�� 

static const char *ppcTAGs[]=  //SSI��Tag
{
	"t", //ADCֵ
//	"w", //�¶�ֵ
	"h", //ʱ��
	"y", //����
	"k",//ticks
	"c",//cpuʹ����
	"o",//task count
	"task"//task��Ϣ 
};



static const tCGI ppcURLs[]= //cgi����
{
	{"/leds.cgi",LEDS_CGI_Handler},
	{"/beep.cgi",BEEP_CGI_Handler},
};


//��web�ͻ��������������ʱ��,ʹ�ô˺�����CGI handler����
static int FindCGIParameter(const char *pcToFind,char *pcParam[],int iNumParams)
{
	int iLoop;
	for(iLoop = 0;iLoop < iNumParams;iLoop ++ )
	{
		if(strcmp(pcToFind,pcParam[iLoop]) == 0)
		{
			return (iLoop); //����iLOOP
		}
	}
	return (-1);
}
//SSIHandler��������task�ĺ��� 
//cpu������ 
void Usage_Handler(char *pcInsert)
{ 
	char Digit1=0, Digit2=0, Digit3=0, Digit4=0; 
    INT8S    CPU_Usage;

    //��ȡusage��ֵ
	CPU_Usage= OSCPUUsage;		

     
    Digit1= CPU_Usage;
 
        
    //׼����ӵ�html�е�����
    *pcInsert       = (char)(Digit1+0x30);
}
//ticks_handler 
void TICK_Handler(char *pcInsert)
{ 
	char Digit1=0, Digit2=0, Digit3=0, Digit4=0; 
    INT32S ticks = 0;        

    //��ȡticks��ֵ
	ticks=OSTimeGet(); 
		
    
     
    Digit1= ticks/1000;
    Digit2= (ticks-(Digit1*1000))/100 ;
    Digit3= (ticks-((Digit1*1000)+(Digit2*100)))/10;
    Digit4= ticks -((Digit1*1000)+(Digit2*100)+ (Digit3*10));
        
    //׼����ӵ�html�е�����
    *pcInsert       = (char)(Digit1+0x30);
    *(pcInsert + 1) = (char)(Digit2+0x30);
    *(pcInsert + 2) = (char)(Digit3+0x30);
    *(pcInsert + 3) = (char)(Digit4+0x30);
}
//������ 
void COUNT_Handler(char *pcInsert)
{
	char Digit1=0,Digit2=0;
	INT32S count=0;
	
	count= OS_N_SYS_TASKS;
	Digit1= count/10;
    Digit2= (count-(Digit1*10));
    
    *pcInsert       = (char)(Digit1+0x30);
    *(pcInsert + 1) = (char)(Digit2+0x30);	
	 
 } 
 //task��Ϣ 
void TASK_Handler(char *pcInsert)
{
	char Digit[OS_N_SYS_TASKS*200]={0};
	char taskid[20]="task id(prio):";
	char tasktop[20]="task top of stack:" ;
	//char addr[11]={NULL};
	OS_STK*  addr;
	int add;
	int add_int[8];

	char taskstat[20]="task stat:";
	char taskdly[20]="task delay ticks:";
	int i,j;
	INT32S count=0;
	for(i=0;i<OS_N_SYS_TASKS;i++)
	{
		for(j=0;j<9;j++)
		{
			add_int[j]=0;
		}
		for(j=0;j<20;j++)//taskid�ַ��� 
		{
			Digit[j+count]=taskid[j];
		 } 
		 count=count+20;
		 //task id��ֵ 
		Digit[count]=(OSTCBTbl[i].OSTCBId)/10;
		Digit[count+1]=(char)(OSTCBTbl[i].OSTCBId-(Digit[count]*10));
		count=count+2;
		// 
		for(j=0;j<20;j++)//tasktop�ַ��� 
		{
			Digit[j+count]=taskid[j];
		 } 
		 count=count+20;
		addr = OSTCBTbl[i].OSTCBStkBase;
		add = (int)addr;
		add_int[0]=add/10000000;
		add_int[1]=(add-(add_int[0]*10000000))/1000000;
		add_int[2]=(add-(add_int[0]*10000000+add_int[1]*1000000))/100000;
		add_int[3]=(add-(add_int[0]*10000000+add_int[1]*1000000+add_int[2]*100000))/10000;
		add_int[4]=(add-(add_int[0]*10000000+add_int[1]*1000000+add_int[2]*100000+add_int[3]*10000))/1000;
		add_int[5]=(add-(add_int[0]*10000000+add_int[1]*1000000+add_int[2]*100000+add_int[3]*10000+add_int[4]*1000))/100;
		add_int[6]=(add-(add_int[0]*10000000+add_int[1]*1000000+add_int[2]*100000+add_int[3]*10000+add_int[4]*1000+add_int[2]*100))/10;
		add_int[7]=(add-(add_int[0]*10000000+add_int[1]*1000000+add_int[2]*100000+add_int[3]*10000+add_int[4]*1000+add_int[2]*100+add_int[6]*10));
		
		for(j=0;j<8;j++)
		{
			Digit[j+count]=(char)add_int[j]; 
		}
		//add_char = (char)add;
	/*	for(j=0;j<1;j++)//top��ַ 
		{
			Digit[j+count]= add_char;//һλһλȡ
		 }
		 */
		 count=count+8;
		for(j=0;j<20;j++)//stat
		{
			Digit[j+count]=taskstat[j];
		 }
		 count=count+20;
		 //stat 
		Digit[count]= (char)OSTCBTbl[i].OSTCBStat;
		count++;
		for(j=0;j<20;j++)//stat
		{
			Digit[j+count]=taskdly[j];
		 }
		count=count+20;
		Digit[j+count]=(OSTCBTbl[i].OSTCBDly/10);
		Digit[j+count+1]=(char)(OSTCBTbl[i].OSTCBDly-(Digit[j+count]*10));	
		count=count+2;
		Digit[count]='\n'; 
		count++;
		  
	} 
	
	memcpy(pcInsert, Digit,OS_N_SYS_TASKS*200);//��ֵ������ 
 } 

//SSIHandler����Ҫ�õ��Ĵ���ADC�ĺ���
void ADC_Handler(char *pcInsert)
{ 
	char Digit1=0, Digit2=0, Digit3=0, Digit4=0; 
    int ADCVal = 0;        

    //��ȡADC��ֵ
	//ADCVal = Get_Adc_Average(5,10); //��ȡADC1_CH5�ĵ�ѹֵ
	ADCVal = ReadAdc(5);//Adc.c	
    //ת��Ϊ��ѹ ADCVval * 0.8mv
   // ADCVal = (uint32_t)(ADCVal * 0.8);  
     ADCVal = (ADCVal * 0.8);  
    Digit1= ADCVal/1000;
    Digit2= (ADCVal-(Digit1*1000))/100 ;
    Digit3= (ADCVal-((Digit1*1000)+(Digit2*100)))/10;
    Digit4= ADCVal -((Digit1*1000)+(Digit2*100)+ (Digit3*10));
        
    //׼����ӵ�html�е�����
    *pcInsert       = (char)(Digit1+0x30);
    *(pcInsert + 1) = (char)(Digit2+0x30);
    *(pcInsert + 2) = (char)(Digit3+0x30);
    *(pcInsert + 3) = (char)(Digit4+0x30);
}

/*

//SSIHandler����Ҫ�õ��Ĵ����ڲ��¶ȴ������ĺ���
void Temperate_Handler(char *pcInsert)
{
	char Digit1=0, Digit2=0, Digit3=0, Digit4=0,Digit5=0; 
	short Temperate = 0;
		
	//��ȡ�ڲ��¶�ֵ
	Temperate = Get_Temprate(); //��ȡ�¶�ֵ �˴�������100��
	Digit1 = Temperate / 10000;
	Digit2 = (Temperate % 10000)/1000;
    Digit3 = (Temperate % 1000)/100 ;
    Digit4 = (Temperate % 100)/10;
    Digit5 = Temperate % 10;
	//��ӵ�html�е�����
	*pcInsert 		= (char)(Digit1+0x30);
	*(pcInsert+1) = (char)(Digit2+0x30);
	*(pcInsert+2)	=	(char)(Digit3+0x30);
	*(pcInsert+3) = '.';
	*(pcInsert+4) = (char)(Digit4+0x30);
	*(pcInsert+5) = (char)(Digit5+0x30);
}
*/
//SSIHandler����Ҫ�õ��Ĵ���RTCʱ��ĺ���
void RTCTime_Handler(char *pcInsert)
{
    RTC_TimeTypeDef RTC_TimeStruct;
	int hour,minute,sec;
	
   // HAL_RTC_GetTime(&RTC_Handler,&RTC_TimeStruct,RTC_FORMAT_BIN);
   	RTC_TimeStruct=RTC_GetDate();
    hour=RTC_TimeStruct.hour;
    minute=RTC_TimeStruct.minute;
    sec=RTC_TimeStruct.second;
    
    
    
   

	
	*pcInsert = 		(char)((hour/10) + 0x30);
	*(pcInsert+1) = (char)((hour%10) + 0x30);
	*(pcInsert+2) = ':';
	*(pcInsert+3) = (char)((minute/10) + 0x30);
	*(pcInsert+4) = (char)((minute%10) + 0x30);
	*(pcInsert+5) = ':';
	*(pcInsert+6) = (char)((sec/10) + 0x30);
	*(pcInsert+7) = (char)((sec%10) + 0x30);
}

//SSIHandler����Ҫ�õ��Ĵ���RTC���ڵĺ���
void RTCdate_Handler(char *pcInsert)
{
	int year;
	int  month,date; 
    RTC_TimeTypeDef RTC_DateStruct;
    
  //  HAL_RTC_GetDate(&RTC_Handler,&RTC_DateStruct,RTC_FORMAT_BIN);
/*    year=RTC_DateStruct.Year;
    month=RTC_DateStruct.Month;
    date=RTC_DateStruct.Date;
    week=RTC_DateStruct.WeekDay;
*/
//	year = 0x2000+rBCDYEAR  ;		//��
//	month = rBCDMON  ;		//��
//	date = rBCDDAY  ;		//��

	RTC_DateStruct=	RTC_GetDate();
	year=RTC_DateStruct.year;
    month=RTC_DateStruct.month;
    date=RTC_DateStruct.day;
  //  week=RTC_DateStruct.WeekDay;
	*pcInsert = '2';
	*(pcInsert+1) = '0';
	*(pcInsert+2) = (char)((year/10) + 0x30);
	*(pcInsert+3) = (char)((year%10) + 0x30);
	*(pcInsert+4) = '-';
	*(pcInsert+5) = (char)((month/10) + 0x30);
	*(pcInsert+6) = (char)((month%10) + 0x30);
	*(pcInsert+7) = '-';
	*(pcInsert+8) = (char)((date/10) + 0x30);
	*(pcInsert+9) = (char)((date%10) + 0x30);
/*	*(pcInsert+10) = ' ';
	*(pcInsert+11) = 'w';
	*(pcInsert+12) = 'e';
	*(pcInsert+13) = 'e';
	*(pcInsert+14) = 'k';
	*(pcInsert+15) = ':';
*/
//	*(pcInsert+16) = (char)(week + 0x30);
	
}
//SSI��Handler���
static u16_t SSIHandler(int iIndex,char *pcInsert,int iInsertLen)
{
	switch(iIndex)
	{/* 
		case 0: 
				ADC_Handler(pcInsert);
				break;
		case 1:
				Temperate_Handler(pcInsert);
				break;
		case 2:
				RTCTime_Handler(pcInsert);
				break;
		case 3:
				RTCdate_Handler(pcInsert);
				break;
	*/
		case 0: 
				ADC_Handler(pcInsert);
				break;
		case 1:
			 	RTCTime_Handler(pcInsert);
				break;
		case 2:
				RTCdate_Handler(pcInsert);
				break;
		case 3:
				TICK_Handler(pcInsert);
				break;
		case 4:
				Usage_Handler(pcInsert);
				break;
		case 5:
				COUNT_Handler(pcInsert);
				break;
		case 6:
				TASK_Handler(pcInsert);
				break;
	}
	return strlen(pcInsert);
}

/*
static const char *ppcTAGs[]=  //SSI��Tag
{
	"t", //ADCֵ
//	"w", //�¶�ֵ
	"h", //ʱ��
	"y", //����
	"k",//ticks
	"c",//cpuʹ����
	"o",//task count
	"task"//task��Ϣ 
};

*/ 

//CGI LED���ƾ��
const char* LEDS_CGI_Handler(int iIndex, int iNumParams, char *pcParam[], char *pcValue[])
{
	int i=0;  //ע������Լ���GET�Ĳ����Ķ�����ѡ��iֵ��Χ
	iIndex = FindCGIParameter("LED1",pcParam,iNumParams);  //�ҵ�led��������
	//ֻ��һ��CGI��� iIndex=0
	if (iIndex != -1)
	{
		//LED1(1);  //�ر�LED1��
		LED_FLAG=LED_Control(0);
		for (i=0; i<iNumParams; i++) //���CGI����
		{
		  if (strcmp(pcParam[i] , "LED1")==0)  //������"led" ���ڿ���LED1�Ƶ�
		  {
			if(strcmp(pcValue[i], "LED1ON") ==0)  //�ı�LED1״̬
				//LED1(0); //��LED1  //////////�޸ļĴ��� 
				{
					LED_FLAG=LED_Control(1);
				}
			else if(strcmp(pcValue[i],"LED1OFF") == 0)
				//LED1(1); //�ر�LED1 //////////�޸ļĴ��� 
				{
					LED_FLAG=LED_Control(0); 
				}
		  }
		}
	 }
/*	if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_0)==0&&PCF8574_ReadBit(BEEP_IO)==0) 		return "/tq2440_led_on_beep_on.shtml";  	//LED1��,BEEP��
	else if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_0)==0&&PCF8574_ReadBit(BEEP_IO)==1) return "/tq2440_led_on_beep_off.shtml";	//LED1��,BEEP��
	else if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_0)==1&&PCF8574_ReadBit(BEEP_IO)==1) return "/tq2440_led_off_beep_off.shtml";	//LED1��,BEEP��
	else return "/tq2440_led_off_beep_on.shtml";   							//LED1��,BEEP��					
*/
	//if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_0)==0&&PCF8574_ReadBit(BEEP_IO)==0) 	
	if(LED_FLAG==1&&BEEP_FLAG==1)
		return "/tq2440_led_on_beep_on.shtml";  	//LED1��,BEEP�� 
	//else if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_0)==0&&PCF8574_ReadBit(BEEP_IO)==1) 
	else if(LED_FLAG==1&&BEEP_FLAG==0)
		return "/tq2440_led_on_beep_off.shtml";	//LED1��,BEEP�� 
	//else if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_0)==1&&PCF8574_ReadBit(BEEP_IO)==1) 
	else if(LED_FLAG==0&&BEEP_FLAG==0)
		return "/tq2440_led_off_beep_off.shtml";	//LED1��,BEEP�� 
	else return "/tq2440_led_off_beep_on.shtml";   							//LED1��,BEEP��	
}

//BEEP��CGI���ƾ��
const char *BEEP_CGI_Handler(int iIndex,int iNumParams,char *pcParam[],char *pcValue[])
{
	int i=0;
	iIndex = FindCGIParameter("BEEP",pcParam,iNumParams);  //�ҵ�BEEP��������
	if(iIndex != -1) //�ҵ�BEEP������
	{
       // PCF8574_WriteBit(BEEP_IO,1);//�ر�
       	Buzzer_Stop() ;
       	BEEP_FLAG=0;
		for(i = 0;i < iNumParams;i++)
		{
			if(strcmp(pcParam[i],"BEEP") == 0)  //����CGI����
			{
				if(strcmp(pcValue[i],"BEEPON") == 0) //��BEEP
                    //PCF8574_WriteBit(BEEP_IO,0);
                    {
                    	
                    	BEEP_FLAG=BeepControl(1);//�������� 
						
                    
						
					} 
				else if(strcmp(pcValue[i],"BEEPOFF") == 0) //�ر�BEEP
                    //PCF8574_WriteBit(BEEP_IO,1);//�ر�
                    {
                    	BEEP_FLAG=BeepControl(0);
					}
			}
		}
	}
	//if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_0)==0&&PCF8574_ReadBit(BEEP_IO)==0) 	
	if(LED_FLAG==1&&BEEP_FLAG==1)
		return "/tq2440_led_on_beep_on.shtml";  	//LED1��,BEEP�� 
	//else if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_0)==0&&PCF8574_ReadBit(BEEP_IO)==1) 
	else if(LED_FLAG==1&&BEEP_FLAG==0)
		return "/tq2440_led_on_beep_off.shtml";	//LED1��,BEEP�� 
	//else if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_0)==1&&PCF8574_ReadBit(BEEP_IO)==1) 
	else if(LED_FLAG==0&&BEEP_FLAG==0)
		return "/tq2440_led_off_beep_off.shtml";	//LED1��,BEEP�� 
	else return "/tq2440_led_off_beep_on.shtml";   							//LED1��,BEEP��	
}

//SSI�����ʼ��
void httpd_ssi_init(void)
{  
	//����SSI���
	http_set_ssi_handler(SSIHandler,ppcTAGs,NUM_CONFIG_SSI_TAGS);
}

//CGI�����ʼ��
void httpd_cgi_init(void)
{ 
  //����CGI���
  http_set_cgi_handlers(ppcURLs, NUM_CONFIG_CGI_URIS);
}



