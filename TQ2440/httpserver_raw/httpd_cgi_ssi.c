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
//本程序只供学习使用，未经作者许可，不得用于其它任何用途

//ALIENTEK STM32F4&F7开发板
//http 代码	   
//正点原子@ALIENTEK
//技术论坛:www.openedv.com
//创建日期:2016/8/5
//版本：V1.0
//版权所有，盗版必究。
//Copyright(C) 广州市星翼电子科技有限公司 2009-2019
//All rights reserved									  
//*******************************************************************************
//修改信息
//无
////////////////////////////////////////////////////////////////////////////////// 	   
 

#define NUM_CONFIG_CGI_URIS	2  //CGI的URI数量
#define NUM_CONFIG_SSI_TAGS	6  //SSI的TAG数量   要改！ 

//控制LED和BEEP的CGI handler
const char* LEDS_CGI_Handler(int iIndex, int iNumParams, char *pcParam[], char *pcValue[]);
const char* BEEP_CGI_Handler(int iIndex,int iNumParams,char *pcParam[],char *pcValue[]);

int BEEP_FLAG=0;//蜂鸣器状态 0-不响 1-响 
int LED_FLAG=0;//灯状态 0-不亮 1-亮 

static const char *ppcTAGs[]=  //SSI的Tag
{
	"t", //ADC值
//	"w", //温度值
	"h", //时间
	"y", //日期
	"k",//ticks
	"c",//cpu使用率
	"o",//task count
	"task"//task信息 
};



static const tCGI ppcURLs[]= //cgi程序
{
	{"/leds.cgi",LEDS_CGI_Handler},
	{"/beep.cgi",BEEP_CGI_Handler},
};


//当web客户端请求浏览器的时候,使用此函数被CGI handler调用
static int FindCGIParameter(const char *pcToFind,char *pcParam[],int iNumParams)
{
	int iLoop;
	for(iLoop = 0;iLoop < iNumParams;iLoop ++ )
	{
		if(strcmp(pcToFind,pcParam[iLoop]) == 0)
		{
			return (iLoop); //返回iLOOP
		}
	}
	return (-1);
}
//SSIHandler用来处理task的函数 
//cpu利用率 
void Usage_Handler(char *pcInsert)
{ 
	char Digit1=0, Digit2=0, Digit3=0, Digit4=0; 
    INT8S    CPU_Usage;

    //获取usage的值
	CPU_Usage= OSCPUUsage;		

     
    Digit1= CPU_Usage;
 
        
    //准备添加到html中的数据
    *pcInsert       = (char)(Digit1+0x30);
}
//ticks_handler 
void TICK_Handler(char *pcInsert)
{ 
	char Digit1=0, Digit2=0, Digit3=0, Digit4=0; 
    INT32S ticks = 0;        

    //获取ticks的值
	ticks=OSTimeGet(); 
		
    
     
    Digit1= ticks/1000;
    Digit2= (ticks-(Digit1*1000))/100 ;
    Digit3= (ticks-((Digit1*1000)+(Digit2*100)))/10;
    Digit4= ticks -((Digit1*1000)+(Digit2*100)+ (Digit3*10));
        
    //准备添加到html中的数据
    *pcInsert       = (char)(Digit1+0x30);
    *(pcInsert + 1) = (char)(Digit2+0x30);
    *(pcInsert + 2) = (char)(Digit3+0x30);
    *(pcInsert + 3) = (char)(Digit4+0x30);
}
//任务数 
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
 //task信息 
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
		for(j=0;j<20;j++)//taskid字符串 
		{
			Digit[j+count]=taskid[j];
		 } 
		 count=count+20;
		 //task id数值 
		Digit[count]=(OSTCBTbl[i].OSTCBId)/10;
		Digit[count+1]=(char)(OSTCBTbl[i].OSTCBId-(Digit[count]*10));
		count=count+2;
		// 
		for(j=0;j<20;j++)//tasktop字符串 
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
	/*	for(j=0;j<1;j++)//top地址 
		{
			Digit[j+count]= add_char;//一位一位取
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
	
	memcpy(pcInsert, Digit,OS_N_SYS_TASKS*200);//赋值到数组 
 } 

//SSIHandler中需要用到的处理ADC的函数
void ADC_Handler(char *pcInsert)
{ 
	char Digit1=0, Digit2=0, Digit3=0, Digit4=0; 
    int ADCVal = 0;        

    //获取ADC的值
	//ADCVal = Get_Adc_Average(5,10); //获取ADC1_CH5的电压值
	ADCVal = ReadAdc(5);//Adc.c	
    //转换为电压 ADCVval * 0.8mv
   // ADCVal = (uint32_t)(ADCVal * 0.8);  
     ADCVal = (ADCVal * 0.8);  
    Digit1= ADCVal/1000;
    Digit2= (ADCVal-(Digit1*1000))/100 ;
    Digit3= (ADCVal-((Digit1*1000)+(Digit2*100)))/10;
    Digit4= ADCVal -((Digit1*1000)+(Digit2*100)+ (Digit3*10));
        
    //准备添加到html中的数据
    *pcInsert       = (char)(Digit1+0x30);
    *(pcInsert + 1) = (char)(Digit2+0x30);
    *(pcInsert + 2) = (char)(Digit3+0x30);
    *(pcInsert + 3) = (char)(Digit4+0x30);
}

/*

//SSIHandler中需要用到的处理内部温度传感器的函数
void Temperate_Handler(char *pcInsert)
{
	char Digit1=0, Digit2=0, Digit3=0, Digit4=0,Digit5=0; 
	short Temperate = 0;
		
	//获取内部温度值
	Temperate = Get_Temprate(); //获取温度值 此处扩大了100倍
	Digit1 = Temperate / 10000;
	Digit2 = (Temperate % 10000)/1000;
    Digit3 = (Temperate % 1000)/100 ;
    Digit4 = (Temperate % 100)/10;
    Digit5 = Temperate % 10;
	//添加到html中的数据
	*pcInsert 		= (char)(Digit1+0x30);
	*(pcInsert+1) = (char)(Digit2+0x30);
	*(pcInsert+2)	=	(char)(Digit3+0x30);
	*(pcInsert+3) = '.';
	*(pcInsert+4) = (char)(Digit4+0x30);
	*(pcInsert+5) = (char)(Digit5+0x30);
}
*/
//SSIHandler中需要用到的处理RTC时间的函数
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

//SSIHandler中需要用到的处理RTC日期的函数
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
//	year = 0x2000+rBCDYEAR  ;		//年
//	month = rBCDMON  ;		//月
//	date = rBCDDAY  ;		//日

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
//SSI的Handler句柄
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
static const char *ppcTAGs[]=  //SSI的Tag
{
	"t", //ADC值
//	"w", //温度值
	"h", //时间
	"y", //日期
	"k",//ticks
	"c",//cpu使用率
	"o",//task count
	"task"//task信息 
};

*/ 

//CGI LED控制句柄
const char* LEDS_CGI_Handler(int iIndex, int iNumParams, char *pcParam[], char *pcValue[])
{
	int i=0;  //注意根据自己的GET的参数的多少来选择i值范围
	iIndex = FindCGIParameter("LED1",pcParam,iNumParams);  //找到led的索引号
	//只有一个CGI句柄 iIndex=0
	if (iIndex != -1)
	{
		//LED1(1);  //关闭LED1灯
		LED_FLAG=LED_Control(0);
		for (i=0; i<iNumParams; i++) //检查CGI参数
		{
		  if (strcmp(pcParam[i] , "LED1")==0)  //检查参数"led" 属于控制LED1灯的
		  {
			if(strcmp(pcValue[i], "LED1ON") ==0)  //改变LED1状态
				//LED1(0); //打开LED1  //////////修改寄存器 
				{
					LED_FLAG=LED_Control(1);
				}
			else if(strcmp(pcValue[i],"LED1OFF") == 0)
				//LED1(1); //关闭LED1 //////////修改寄存器 
				{
					LED_FLAG=LED_Control(0); 
				}
		  }
		}
	 }
/*	if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_0)==0&&PCF8574_ReadBit(BEEP_IO)==0) 		return "/tq2440_led_on_beep_on.shtml";  	//LED1开,BEEP关
	else if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_0)==0&&PCF8574_ReadBit(BEEP_IO)==1) return "/tq2440_led_on_beep_off.shtml";	//LED1开,BEEP开
	else if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_0)==1&&PCF8574_ReadBit(BEEP_IO)==1) return "/tq2440_led_off_beep_off.shtml";	//LED1关,BEEP开
	else return "/tq2440_led_off_beep_on.shtml";   							//LED1关,BEEP关					
*/
	//if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_0)==0&&PCF8574_ReadBit(BEEP_IO)==0) 	
	if(LED_FLAG==1&&BEEP_FLAG==1)
		return "/tq2440_led_on_beep_on.shtml";  	//LED1开,BEEP开 
	//else if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_0)==0&&PCF8574_ReadBit(BEEP_IO)==1) 
	else if(LED_FLAG==1&&BEEP_FLAG==0)
		return "/tq2440_led_on_beep_off.shtml";	//LED1开,BEEP关 
	//else if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_0)==1&&PCF8574_ReadBit(BEEP_IO)==1) 
	else if(LED_FLAG==0&&BEEP_FLAG==0)
		return "/tq2440_led_off_beep_off.shtml";	//LED1关,BEEP关 
	else return "/tq2440_led_off_beep_on.shtml";   							//LED1关,BEEP关	
}

//BEEP的CGI控制句柄
const char *BEEP_CGI_Handler(int iIndex,int iNumParams,char *pcParam[],char *pcValue[])
{
	int i=0;
	iIndex = FindCGIParameter("BEEP",pcParam,iNumParams);  //找到BEEP的索引号
	if(iIndex != -1) //找到BEEP索引号
	{
       // PCF8574_WriteBit(BEEP_IO,1);//关闭
       	Buzzer_Stop() ;
       	BEEP_FLAG=0;
		for(i = 0;i < iNumParams;i++)
		{
			if(strcmp(pcParam[i],"BEEP") == 0)  //查找CGI参数
			{
				if(strcmp(pcValue[i],"BEEPON") == 0) //打开BEEP
                    //PCF8574_WriteBit(BEEP_IO,0);
                    {
                    	
                    	BEEP_FLAG=BeepControl(1);//蜂鸣器响 
						
                    
						
					} 
				else if(strcmp(pcValue[i],"BEEPOFF") == 0) //关闭BEEP
                    //PCF8574_WriteBit(BEEP_IO,1);//关闭
                    {
                    	BEEP_FLAG=BeepControl(0);
					}
			}
		}
	}
	//if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_0)==0&&PCF8574_ReadBit(BEEP_IO)==0) 	
	if(LED_FLAG==1&&BEEP_FLAG==1)
		return "/tq2440_led_on_beep_on.shtml";  	//LED1开,BEEP开 
	//else if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_0)==0&&PCF8574_ReadBit(BEEP_IO)==1) 
	else if(LED_FLAG==1&&BEEP_FLAG==0)
		return "/tq2440_led_on_beep_off.shtml";	//LED1开,BEEP关 
	//else if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_0)==1&&PCF8574_ReadBit(BEEP_IO)==1) 
	else if(LED_FLAG==0&&BEEP_FLAG==0)
		return "/tq2440_led_off_beep_off.shtml";	//LED1关,BEEP关 
	else return "/tq2440_led_off_beep_on.shtml";   							//LED1关,BEEP关	
}

//SSI句柄初始化
void httpd_ssi_init(void)
{  
	//配置SSI句柄
	http_set_ssi_handler(SSIHandler,ppcTAGs,NUM_CONFIG_SSI_TAGS);
}

//CGI句柄初始化
void httpd_cgi_init(void)
{ 
  //配置CGI句柄
  http_set_cgi_handlers(ppcURLs, NUM_CONFIG_CGI_URIS);
}



