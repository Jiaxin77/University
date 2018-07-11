#ifndef _WEBIF_H
#define _WEBIF_H



typedef struct RTCTime{
	int year;
	int month;
	int day;
	int hour;
	int minute;
	int second;
	
} RTC_TimeTypeDef; 


extern int BeepControl(int control);
extern int LED_Contorl(int control);
extern RTC_TimeTypeDef RTC_GetDate(void);
extern int ReadAdc(int ch);
extern void Led_Display(int data);
extern void Led_off();


#endif
