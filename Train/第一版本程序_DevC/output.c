#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h> 
#include"Define.h"
#include"funtion.h"
#include"input.h"
#include"output.h"
#include"priority.h"
#include"traincontrol.h"
#include"varible.h"
void outputLight()//���̽���λ�ã������в��� ��ͼ�λ�����ʹ�� 
{
	
	
	if(Light1State==01)
	printf("LampA1 is on\n");
	
	if(Light1State==00)
	printf("LampA1 is off\n");
	
	if(Light2State==01)
	printf("LampA2 is on\n");
	
	if(Light2State==00)
	printf("LampA2 is off\n");
	
	if(Light3State==01)
	printf("LampA3 is on\n");
	
	if(Light3State==00)
	printf("LampA3 is off\n");
	
	if(Light4State==01)
	printf("LampA4 is on\n");
	
	if(Light4State==00)
	printf("LampA4 is off\n");
	
	if(Light5State==01)
	printf("LampB1 is on\n");
	
	if(Light5State==00)
	printf("LampB1 is off\n");
	
	if(Light6State==01)
	printf("LampB2 is on\n");
	
	if(Light6State==00)
	printf("LampB2 is off\n");
	
	if(Light7State==01)
	printf("LampC1 is on\n");
	
	if(Light7State==00)
	printf("LampC1 is off\n");
	
	if(Light8State==01)
	printf("LampC2 is on\n");
	
	if(Light8State==00)
	printf("LampC2 is off\n");
 } 


DWORD WINAPI OUTPUT(LPVOID lpParameter)//��Ļ���+�ļ�����߳� 
{
	clock_t start1, finish1;//����ʱ�� 
	FILE*f1=fopen("ģ��𳵵���ϵͳ.txt","w");
	fclose(f1);
	start1=clock();
	char tra[10]={0}; 
    char run[10]={0};
    while(1)
	{	f1=fopen("ģ��𳵵���ϵͳ.txt","a");//�ÿ���ӷ�ʽ���ļ� 
		finish1=clock();
	    count=(finish1-start1)/1000;//�����ǰʱ�� 
	   
		if(count%3==0)//ÿ3s���һ�� 
		{
		Sleep(1000); 
		printf("��ǰʱ�䣺%d\n",count);//�����ǰʱ�� 
		printf("��ǰ����Ϊ�쳵���Ȳ���\n");
		 
		fprintf(f1,"��ǰʱ�䣺%d\n",count);//���ʱ�䵽�ļ� 
		fprintf(f1,"��ǰ����Ϊ�쳵���Ȳ���\n"); 
		 
		//�����A��Ϣ 
		if(A.Circle==0)
		printf("A��˳ʱ������\n");
		fprintf(f1,"A��˳ʱ������\n");
		if(A.Circle==1)
		printf("A����ʱ������\n"); 
		fprintf(f1,"A����ʱ������\n"); 
		
		if(A.state==0&&((A.location>10)&&(A.location<16)||(A.location>18)&&(A.location<26))	)//�ж�A��״̬	   	
		{	if(A.control==1)//�ж�A��ͣ��ԭ�� 
			{	strcpy(tra,"�����û�����");
				strcpy(run,"��ͣ");	
			}
			else
			{
			strcpy(tra,"ռ�ù������");
			strcpy(run,"ͣ��");
			AStayFinish=clock();//�ж�Aͣ��ʣ��ʱ�� 
			AStay=StayTime*1000-(AStayFinish-AStayStart)+100;
			if(count<=A.startTime)
			{	printf("A���ȴ�����\n");
				fprintf(f1,"A���ȴ�����\n");
			}
			else
			{
			printf("A��ͣ��ʣ��ʱ�䣺%d����\n",AStay);
			fprintf(f1,"A��ͣ��ʣ��ʱ�䣺%d����\n",AStay);}
			}//������ļ� 
		}	   
		if(A.state==0&&((A.location<=10)||((A.location>=16)&&(A.location<=18))||(A.location>=26)))	//�ж�A��״̬   
		{	if(A.control==1)
			{	strcpy(tra,"�����û�����");
				strcpy(run,"��ͣ");	
			}
			else
			{
			strcpy(tra,"�ȴ��������");
			strcpy(run,"��ͣ");}
		}		  
		if(A.state==1&&(((A.location>10)&&(A.location<16))||((A.location>18)&&(A.location<26))))//�ж�A��״̬ 
		{
			strcpy(tra,"�������");
			strcpy(run,"����");
		}
		if(A.state==1&&(A.location<=10||(A.location>=16)&&(A.location<=18)||A.location>=26))	//�ж�A��״̬	   
		{
   			strcpy(tra,"�ǹ������");
			strcpy(run,"����");
		}
		printf("A������״̬��%s-%s\n",run,tra);//���A��״̬ 
		
		printf("A�𳵵�ǰλ�ã�%d\n",A.location);//���A��λ�� 
		fprintf(f1,"A������״̬��%s-%s\n",run,tra);//���A��״̬ 
		
		fprintf(f1,"A�𳵵�ǰλ�ã�%d\n",A.location);//���A��λ�� 

//���B����Ϣ 
	    if(B.Circle==0)
		printf("B��˳ʱ������\n");
		fprintf(f1,"B��˳ʱ������\n");
		if(B.Circle==1)
		printf("B����ʱ������\n"); 
		fprintf(f1,"B����ʱ������\n"); 
		if(B.state==0&&(B.location>5&&B.location<11))	 //�ж�B��״̬  	
		{	if(B.control==1)//�ж�B����ͣԭ�� 
			{	strcpy(tra,"�����û�����");
			  	strcpy(run,"��ͣ");
			}
			else
			{
			strcpy(tra,"ռ�ù������");
			strcpy(run,"ͣ��");
			BStayFinish=clock();//����B��ͣ��ʣ��ʱ�� 
			BStay=StayTime*1000-(BStayFinish-BStayStart)+100;
			if(count<=B.startTime)
			{	printf("B���ȴ�����\n");
				fprintf(f1,"B���ȴ�����\n");
			}
			else
			{
			printf("B��ͣ��ʣ��ʱ��:%d����\n",BStay);
			fprintf(f1,"B��ͣ��ʣ��ʱ��:%d����\n",BStay);}
			} 
		}
    		if(B.state==0&&(B.location<=5||B.location>=11))	//�ж�B��״̬	   	
		{	if(B.control==1)
			{	strcpy(tra,"�����û�����");
			  	strcpy(run,"��ͣ");
			}
			else
			{
			strcpy(tra,"�ȴ��������");
			strcpy(run,"��ͣ");} 
		}	   
    		if(B.state==1&&(B.location>5&&B.location<11))//�ж�B��״̬		   	
		{ 
			strcpy(tra,"�������");
			strcpy(run,"����");	
			
		}
			if((B.state==1)&&((B.location<=5)||(B.location>=11)))		   	
		{
			strcpy(tra,"�ǹ������");
			strcpy(run,"����");
		
		}	   	  
 
		printf("B������״̬��%s-%s\n",run,tra);
		
		printf("B�𳵵�ǰλ�ã�%d\n",B.location);
		fprintf(f1,"B������״̬��%s-%s\n",run,tra);
		
		fprintf(f1,"B�𳵵�ǰλ�ã�%d\n",B.location);
//���C����Ϣ 
		if(C.Circle==0)
		printf("C��˳ʱ������\n");
		fprintf(f1,"C��˳ʱ������\n");
		if(C.Circle==1)
		printf("C����ʱ������\n");
		fprintf(f1,"C����ʱ������\n"); 
	
	
		if(C.state==0&&(C.location>12&&C.location<20))	   	
		{	if(C.control==1)
			{strcpy(tra,"�����û�����");
			 strcpy(run,"��ͣ"); 
			}
			else
			{
			strcpy(tra,"ռ�ù������");
			strcpy(run,"ͣ��");
			CStayFinish=clock();//����C��ͣ��ʣ��ʱ�� 
			CStay=StayTime*1000-(CStayFinish-CStayStart)+100;
			if(count<=C.startTime)
			{	printf("C���ȴ�����\n");
				fprintf(f1,"C���ȴ�����\n");
			}
			else{ 
			printf("C��ͣ��ʣ��ʱ��:%d����\n",CStay);
			fprintf(f1,"C��ͣ��ʣ��ʱ��:%d����\n",CStay);}
			} 
		}
	   if(C.state==0&&(C.location<=12||C.location>=20))		   	
		{
			if(C.control==1)
			{strcpy(tra,"�����û�����");
			 strcpy(run,"��ͣ"); 
			}
			else
			{
			strcpy(tra,"�ȴ��������");
			strcpy(run,"��ͣ");}
		}	   
		if(C.state==1&&(C.location>12&&C.location<20))		   	
		{ 
			strcpy(tra,"�������");
			strcpy(run,"����");	
	
		}
		if((C.state==1)&&((C.location<=12||C.location>=20)))		   	
		{
			strcpy(tra,"�ǹ������");
			strcpy(run,"����");
	
		}	   	  
     	
		printf("C������״̬��%s-%s\n",run,tra);
		
		printf("C�𳵵�ǰλ�ã�%d\n",C.location);
		
		fprintf(f1,"C������״̬��%s-%s\n",run,tra);
		
		fprintf(f1,"C�𳵵�ǰλ�ã�%d\n",C.location);

	//������״̬	
		if((A.location>10)&&(A.location<16))
		{
		printf("AB���������A��ռ��\n");
		fprintf(f1,"AB���������A��ռ��\n");
		} 
		else if((B.location>5)&&(B.location<11))
		{
		printf("AB���������B��ռ��\n");
		fprintf(f1,"AB���������B��ռ��\n");
		}
		else
		{
		printf("AB�����������\n"); 
		fprintf(f1,"AB�����������\n"); 
		}
		if((A.location>18)&&(A.location<26))
		{
		printf("AC���������A��ռ��\n");
		fprintf(f1,"AC���������A��ռ��\n");
		}
		else if((C.location>12)&&(C.location<20))
		{
		printf("AC���������C��ռ��\n");
		fprintf(f1,"AC���������C��ռ��\n");
		}
		else
		{
		printf("AC�����������\n");
		fprintf(f1,"AC�����������\n"); 	
		}
		//outputLight();����Ҫ�������״̬�� 
			
		printf("\n");	
		fprintf(f1,"\n");	
		
	
		finish1=clock();
		count=(finish1-start1)/1000;}
	 fclose(f1);//�رղ������ļ� 
		}
		

	}






void printChange()
{	char trac[10]={0}; 
    char runc[10]={0};
   
    
    int count1;
	{	finish=clock();
	    count1=(finish-start)/1000;
	   
	
		printf("��ǰʱ�䣺%d\n",count1);
		printf("��ǰ����Ϊ�쳵���Ȳ���\n"); 
		
		
		if(A.Circle==0)
		printf("A��˳ʱ������\n");
		if(A.Circle==1)
		printf("A����ʱ������\n"); 

		if(A.state==0&&((A.location>10)&&(A.location<16)||(A.location>18)&&(A.location<26))	)	   	
		{	if(A.control==1)
			{	strcpy(trac,"�����û�����");
				strcpy(runc,"��ͣ");	
			}
			else
			{
			strcpy(trac,"ռ�ù������");
			strcpy(runc,"ͣ��");
			AStayFinish=clock();
			AStay=StayTime*1000-(AStayFinish-AStayStart);
			printf("A��ͣ��ʣ��ʱ�䣺%d����\n",AStay);}
		}	   
		if(A.state==0&&((A.location<=10)||((A.location>=16)&&(A.location<=18))||(A.location>=26)))	   
		{	if(A.control==1)
			{	strcpy(trac,"�����û�����");
				strcpy(runc,"��ͣ");	
			}
			else
			{
			strcpy(trac,"�ȴ��������");
			strcpy(runc,"��ͣ");}
		}		  
		if(A.state==1&&(((A.location>10)&&(A.location<16))||((A.location>18)&&(A.location<26))))
		{
			strcpy(trac,"�������");
			strcpy(runc,"����");
		}
		if(A.state==1&&(A.location<=10||(A.location>=16)&&(A.location<=18)||A.location>=26))		   
		{
   			strcpy(trac,"�ǹ������");
			strcpy(runc,"����");
		}
		printf("A������״̬��%s-%s\n",runc,trac);
		
		printf("A�𳵵�ǰλ�ã�%d\n",A.location);


	    if(B.Circle==0)
		printf("B��˳ʱ������\n");
		if(B.Circle==1)
		printf("B����ʱ������\n"); 

		if(B.state==0&&(B.location>5&&B.location<11))	   	
		{	if(B.control==1)
			{	strcpy(trac,"�����û�����");
			  	strcpy(runc,"��ͣ");
			}
			else
			{
			strcpy(trac,"ռ�ù������");
			strcpy(runc,"ͣ��");
			BStayFinish=clock();
			BStay=StayTime*1000-(BStayFinish-BStayStart);
			printf("B��ͣ��ʣ��ʱ��:%d����\n",BStay);}
		}
    		if(B.state==0&&(B.location<=5||B.location>=11))		   	
		{	if(B.control==1)
			{	strcpy(trac,"�����û�����");
			  	strcpy(runc,"��ͣ");
			}
			else
			{
			strcpy(trac,"�ȴ��������");
			strcpy(runc,"��ͣ");} 
		}	   
    		if(B.state==1&&(B.location>5&&B.location<11))		   	
		{ 
			strcpy(trac,"�������");
			strcpy(runc,"����");	
			
		}
			if((B.state==1)&&((B.location<=5)||(B.location>=11)))		   	
		{
			strcpy(trac,"�ǹ������");
			strcpy(runc,"����");
	
		}	   	  
 
		printf("B������״̬��%s-%s\n",runc,trac);
		
		printf("B�𳵵�ǰλ�ã�%d\n",B.location);

		if(C.Circle==0)
		printf("C��˳ʱ������\n");
		if(C.Circle==1)
		printf("C����ʱ������\n"); 
	
	
		if(C.state==0&&(C.location>12&&C.location<20))	   	
		{	if(C.control==1)
			{strcpy(trac,"�����û�����");
			 strcpy(runc,"��ͣ"); 
			}
			else
			{
			strcpy(trac,"ռ�ù������");
			strcpy(runc,"ͣ��");
			CStayFinish=clock();
			CStay=StayTime*1000-(CStayFinish-CStayStart);
			printf("C��ͣ��ʣ��ʱ��:%d����\n",CStay);}
		}
	   if(C.state==0&&(C.location<=12||C.location>=20))		   	
		{
			if(C.control==1)
			{strcpy(trac,"�����û�����");
			 strcpy(runc,"��ͣ"); 
			}
			else
			{
			strcpy(trac,"�ȴ��������");
			strcpy(runc,"��ͣ");}
		}	   
		if(C.state==1&&(C.location>12&&C.location<20))		   	
		{ 
			strcpy(trac,"�������");
			strcpy(runc,"����");	
	
		}
		if((C.state==1)&&((C.location<=12||C.location>=20)))		   	
		{
			strcpy(trac,"�ǹ������");
			strcpy(runc,"����");
	
		}	   	  
     	
		printf("C������״̬��%s-%s\n",runc,trac);
		
		printf("C�𳵵�ǰλ�ã�%d\n",C.location);

		
		if((A.location>10)&&(A.location<16))
		printf("AB���������A��ռ��\n");
		else if((B.location>5)&&(B.location<11))
		printf("AB���������B��ռ��\n");
		else
		printf("AB�����������\n"); 

		if((A.location>18)&&(A.location<26))
		printf("AC���������A��ռ��\n");
		else if((C.location>12)&&(C.location<20))
		printf("AC���������C��ռ��\n");
		else
		printf("AC�����������\n");
	
		//outputLight();�������������Ҫ��ͼ�λ������� 
			
		printf("\n");	
			
		
		}
	}















