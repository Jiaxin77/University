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
#include"egg.h"
#include<string.h>
/*���������+�ļ�������߳�*/ 
DWORD WINAPI OUTPUT(LPVOID lpParameter)
{
	FILE*f1=fopen("ģ��𳵵���ϵͳ.txt","w");
	clock_t start1, finish1;//����ʱ�� 
	fclose(f1);
	start1=clock();
	char tra[10]={0}; 
    char run[10]={0};
    while(1)
	{
		f1=fopen("ģ��𳵵���ϵͳ.txt","a");//�ÿ���ӷ�ʽ���ļ� 
		
		
		finish1=clock();
	    count=(finish1-start1)/1000;//���㵱ǰʱ�� 
		if(count%1==0)//ÿ1s���һ�� 
		{
		    Sleep(1000); 
		    printf("��ǰʱ�䣺%d\n",count);//�����ǰʱ�� 
		    /*�����ǰ���Ʋ���*/ 
		    if(priority_control==0)
		    {
		        printf("��ǰ����Ϊ�쳵���Ȳ���\n");			
		    }
            else
            {
        	    printf("��ǰ����Ϊ�˹����Ʋ���\n");
		    }
				
		    /*�����ǰʱ��Ϳ��Ʋ��Ե��ļ�*/ 
   		    fprintf(f1,"��ǰʱ�䣺%d\n",count);
		    if(priority_control==0) 
		    {
			    fprintf(f1,"��ǰ����Ϊ�쳵���Ȳ���\n"); 
		    }		
            else
            {
        	    fprintf(f1,"��ǰ����Ϊ�˹����Ʋ���\n"); 
		    }
		    
		    
            /*���A�𳵵���Ϣ�������к��ļ�*/
            /*���A�𳵵�˳��ʱ����Ϣ�������к��ļ�*/
		    if(A.Circle==0)
		    { 
		        printf("A��˳ʱ������\n");
		        fprintf(f1,"A��˳ʱ������\n");
		    } 
		    if(A.Circle==1)
		    { 
		        printf("A����ʱ������\n"); 
		        fprintf(f1,"A����ʱ������\n"); 
		    }
		    
		    /*���A�𳵵�״̬��Ϣ�������к��ļ�*/
		    if(A.state==0&&((A.location>50)&&(A.location<75)||(A.location>90)&&(A.location<125)))//A�ڹ����������״̬Ϊ��ֹ	   	
		    {	
			    if(A.control==1)//�ж�A��ͣ��ԭ�� 
			    {
				    strcpy(tra,"�����û�����");
				    strcpy(run,"��ͣ");	
			    }
			    else
			    {
			        strcpy(tra,"ռ�ù������");
			        strcpy(run,"ͣ��");
			        AStayFinish=clock();
			        AStay=StayTime*1000-(AStayFinish-AStayStart)+100;//����Aͣ��ʣ��ʱ�� 
			        if(count<=A.startTime)
			        {	
				        printf("A���ȴ�����\n");
				        fprintf(f1,"A���ȴ�����\n");
			        }
			        else
			        {
			            printf("A��ͣ��ʣ��ʱ�䣺%d����\n",AStay);
			            fprintf(f1,"A��ͣ��ʣ��ʱ�䣺%d����\n",AStay);
			        }
			    }
		    }
				   
		    if(A.state==0&&((A.location<=50)||((A.location>=75)&&(A.location<=90))||(A.location>=125)))//A���ڹ����������״̬Ϊ��ֹ
		    {	
			    if(A.control==1)
			    {	
				    strcpy(tra,"�����û�����");
				    strcpy(run,"��ͣ");	
			    }
			    else
			    {
			        strcpy(tra,"�ȴ��������");
			        strcpy(run,"��ͣ");
				}
		    }		
			  
		    if(A.state==1&&(((A.location>50)&&(A.location<75))||((A.location>90)&&(A.location<125))))//A�ڹ����������״̬Ϊ�˶� 
		    {
			    strcpy(tra,"�������");
			    strcpy(run,"����");
		    }
		    
		    if(A.state==1&&(A.location<=50||(A.location>=75)&&(A.location<=90)||A.location>=125))//A�ڹ����������״̬Ϊ�˶�		   
		    {
   			    strcpy(tra,"�ǹ������");
		 	    strcpy(run,"����");
		    }
		    printf("A������״̬��%s-%s\n",run,tra);//���A��״̬ 
		    printf("A�𳵵�ǰλ�ã�%f\n",A.location);//���A��λ�� 
		    fprintf(f1,"A������״̬��%s-%s\n",run,tra);//���A��״̬ 
		    fprintf(f1,"A�𳵵�ǰλ�ã�%f\n",A.location);//���A��λ�� 




            /*���B�𳵵���Ϣ�������к��ļ�*/ 
            /*���B�𳵵�˳��ʱ����Ϣ�������к��ļ�*/
	        if(B.Circle==0)
	        { 
		        printf("B��˳ʱ������\n");
		        fprintf(f1,"B��˳ʱ������\n");
		    } 
		    if(B.Circle==1)
		    {
			   printf("B����ʱ������\n"); 
		       fprintf(f1,"B����ʱ������\n"); 
		    } 
		    
		    /*���B�𳵵�״̬��Ϣ�������к��ļ�*/
		    if(B.state==0&&(B.location>25&&B.location<50))//B�����������״̬Ϊ��ֹ
	     	{	
			    if(B.control==1)//�ж�B����ͣԭ�� 
			    {	
				    strcpy(tra,"�����û�����");
			  	    strcpy(run,"��ͣ");
			    }
			    else
			    {
			        strcpy(tra,"ռ�ù������");
			        strcpy(run,"ͣ��");
			        BStayFinish=clock();//����B��ͣ��ʣ��ʱ�� 
			        BStay=StayTime*1000-(BStayFinish-BStayStart)+100;
			        if(count<=B.startTime)
			        {	
					    printf("B���ȴ�����\n");
				        fprintf(f1,"B���ȴ�����\n");
			        }
			        else
			        {
			            printf("B��ͣ��ʣ��ʱ��:%d����\n",BStay);
			            fprintf(f1,"B��ͣ��ʣ��ʱ��:%d����\n",BStay);
                    }
			    } 
		    }
    		if(B.state==0&&(B.location<=25||B.location>=50))//B�ڹ����������״̬Ϊ��ֹ
		    {	
			    if(B.control==1)
			    {	
				    strcpy(tra,"�����û�����");
			  	    strcpy(run,"��ͣ");
			    }
			    else
			    {
			        strcpy(tra,"�ȴ��������");
			        strcpy(run,"��ͣ");
				} 
		    }	   
    		if(B.state==1&&(B.location>25&&B.location<505))//B�ڹ����������״̬Ϊ�˶�	   	
		    { 
			    strcpy(tra,"�������");
			    strcpy(run,"����");	
			}
			if((B.state==1)&&((B.location<=25)||(B.location>=50)))//B�ڹ����������״̬Ϊ��ֹ	   	
		    {
			    strcpy(tra,"�ǹ������");
			    strcpy(run,"����");
		    }	   	  
            printf("B������״̬��%s-%s\n",run,tra);//���B��״̬
		    printf("B�𳵵�ǰλ�ã�%f\n",B.location);//���B��λ�� 
		    fprintf(f1,"B������״̬��%s-%s\n",run,tra);//���B��״̬
		    fprintf(f1,"B�𳵵�ǰλ�ã�%f\n",B.location);//���B��λ�� 



            /*���C�𳵵���Ϣ�������к��ļ�*/  
            /*���C�𳵵�˳��ʱ����Ϣ�������к��ļ�*/
		    if(C.Circle==0)
		    {
			    printf("C��˳ʱ������\n");
		        fprintf(f1,"C��˳ʱ������\n");
		    } 
		    if(C.Circle==1)
		    {
			    printf("C����ʱ������\n");
		        fprintf(f1,"C����ʱ������\n");
			} 
	
	        /*���C�𳵵�״̬��Ϣ�������к��ļ�*/
		    if(C.state==0&&(C.location>60&&C.location<95))//C�ڹ����������״̬Ϊ��ֹ	   	
		    {	
			    if(C.control==1)
			    {
				    strcpy(tra,"�����û�����");
			        strcpy(run,"��ͣ"); 
			    }
			    else
			    {
			        strcpy(tra,"ռ�ù������");
			        strcpy(run,"ͣ��");
			        CStayFinish=clock();//����C��ͣ��ʣ��ʱ�� 
		         	CStay=StayTime*1000-(CStayFinish-CStayStart)+100;
			        if(count<=C.startTime)
			        {	
				        printf("C���ȴ�����\n");
				        fprintf(f1,"C���ȴ�����\n");
			        }
			        else
					{ 
			            printf("C��ͣ��ʣ��ʱ��:%d����\n",CStay);
			            fprintf(f1,"C��ͣ��ʣ��ʱ��:%d����\n",CStay);
	                }
			   } 
		    }
	        if(C.state==0&&(C.location<=60||C.location>=95))//C�ڹ����������״̬Ϊ��ֹ		   	
		    {
			    if(C.control==1)
			    {
				    strcpy(tra,"�����û�����");
			        strcpy(run,"��ͣ"); 
			    }
			    else
			    {
			        strcpy(tra,"�ȴ��������");
			        strcpy(run,"��ͣ");
				}
		    }	   
		    if(C.state==1&&(C.location>60&&C.location<95))	//C�ڹ����������״̬Ϊ�˶�	   	
		    { 
			    strcpy(tra,"�������");
			    strcpy(run,"����");	
	        }
		    if((C.state==1)&&((C.location<=60||C.location>=95)))//C�ڹ����������״̬Ϊ��ֹ		   	
		    {
			    strcpy(tra,"�ǹ������");
			    strcpy(run,"����");
	        }	   	  
     	    printf("C������״̬��%s-%s\n",run,tra);
		    printf("C�𳵵�ǰλ�ã�%f\n",C.location);
		    fprintf(f1,"C������״̬��%s-%s\n",run,tra);
		    fprintf(f1,"C�𳵵�ǰλ�ã�%f\n",C.location);
		    


		    /*���AB�������״̬*/
		    if((A.location>50)&&(A.location<75))
		    {
		        printf("AB���������A��ռ��\n");
		        fprintf(f1,"AB���������A��ռ��\n");
	      	} 
		    else if((B.location>25)&&(B.location<50))
		    {
		        printf("AB���������B��ռ��\n");
		        fprintf(f1,"AB���������B��ռ��\n");
		    }
		    else
		    {
		        printf("AB�����������\n"); 
		        fprintf(f1,"AB�����������\n"); 
		    }
		    /*���AC�������״̬*/
		    if((A.location>90)&&(A.location<125))
		    {
		        printf("AC���������A��ռ��\n");
		        fprintf(f1,"AC���������A��ռ��\n");
		    }
		    else if((C.location>60)&&(C.location<95))
		    {
		        printf("AC���������C��ռ��\n");
		        fprintf(f1,"AC���������C��ռ��\n");
		    }
		    else
		    {
		        printf("AC�����������\n");
		        fprintf(f1,"AC�����������\n"); 	
	     	}

					
		    printf("\n");	
		    fprintf(f1,"\n");	
		
	
		    finish1=clock();
		    count=(finish1-start1)/1000;
		}
	        fclose(f1);//�رղ������ļ� 
	}
}

/*ͼ�λ��������*/
void Output_picture()
{
	    char time[10]={0};
	    
	    
	    /*���ƻ𳵵Ļ����ĸ���*/
		TrainAmove();
        TrainBmove();
        TrainCmove();


         /*���ư�ť�Ļ����ĸ���*/
		if(FlagFast==1)//���¿쳵���� 
		{	
		    fast();
		}
		if(FlagFast==0)//�����˹����� 
		{	
		    facility();
		}
		
		
         /*������ʱ��Ļ����ĸ���*/		
		int m;
		if(count>0)
		{
			m=count-1;
		}
		else
		{
			m=0;
		}
		sprintf(time,   "%d ",   m); //������ת��Ϊ�ַ�����
	   	SetActiveEgg(Time);
	   	MovePen(650.9,396.2);
	   	DrawString(time);	
	   	
	   	
	   	/*����Aͣ��ʱ��Ļ����ĸ���*/
	   	if(A.state==0&&((A.location>50)&&(A.location<75)||(A.location>90)&&(A.location<125)))	   	
		{	
		    if(A.control==1) 
			{	
			}
			else
			{
			    if(count<=A.startTime)
			    {	
			    }
			    else//����ΪA��ʾʾͣ��ʱ������� 
			    {
			        memset(Astay,'\0',sizeof(Astay));
			        sprintf(Astay,   "%d ",   AStay);
			        SetActiveEgg(ASstay);
		           	ShowEgg(1);
	   		        MovePen(396.2,424.5);
	   		        DrawString(Astay);
	  	 	        strcpy(Astay,"0000"); 

			    }
			}
		}
		else
		{	
		    SetActiveEgg(ASstay);
			ShowEgg(0);
		}
		
		/*����Bͣ��ʱ��Ļ����ĸ���*/
		if(B.state==0&&(B.location>25&&B.location<50))	   	
		{	if(B.control==1)
			{	
			}
			else
			{
			    if(count<=B.startTime)
			    {
			    }
			    else//����ΪB��ʾʾͣ��ʱ������� 
			    {
			        sprintf(Bstay,   "%d ",   BStay);			    	
			        SetActiveEgg(BSstay);
			        ShowEgg(1);
	   		        MovePen(452.8,424.5);
	   		        DrawString(Bstay);
	  	 	        strcpy(Bstay,"0"); 
			    }
			} 
		}
		else
		{	
		    SetActiveEgg(BSstay);
			ShowEgg(0);
		}
		
		/*����Cͣ��ʱ��Ļ����ĸ���*/
		if(C.state==0&&(C.location>60&&C.location<95))	   	
		{	
		    if(C.control==1)
			{
			}
			else
			{

			    if(count<=C.startTime)
			    {	
			    }
			    else
				{ 
			        sprintf(Cstay,   "%d ",   CStay);
			        SetActiveEgg(CSstay);
			        ShowEgg(1);
	   		        MovePen(537.7,424.5);
	   		        DrawString(Cstay);
	  	 	        strcpy(Cstay,"0000"); 
			   }
			} 
		}
		else
		{
			SetActiveEgg(CSstay);
			ShowEgg(0);
		}
		

	    /*����̽��ƵĻ����ĸ���*/
		if(Light_control_AB==1)
		{
		    SetActiveEgg(LightA7);
		    ShowEgg(0);
		    SetActiveEgg(LightA8);
		    ShowEgg(1);
		}
		else if(Light_control_AB==2)
		{
		    SetActiveEgg(LightA5);
		    ShowEgg(0);
		    SetActiveEgg(LightA6);
		    ShowEgg(1);
		}
		if(A.location>=75||A.location<=50)
		{
			Light_control_AB=0;
			SetActiveEgg(LightA8);
			ShowEgg(0);
			SetActiveEgg(LightA7);
			ShowEgg(1);
			SetActiveEgg(LightA6);
			ShowEgg(0);
			SetActiveEgg(LightA5);
			ShowEgg(1);
		}				
		
				
		if(Light_control_AC==1)
		{
		    SetActiveEgg(LightA3);
		    ShowEgg(0);
		    SetActiveEgg(LightA4);
		    ShowEgg(1);			
		}
		else if(Light_control_AC==2)
		{
		    SetActiveEgg(LightA1);
		    ShowEgg(0);
		    SetActiveEgg(LightA2);
		    ShowEgg(1); 
		}
		if(A.location>=125||A.location<=90)
		{
			Light_control_AC=0;
			SetActiveEgg(LightA2);
			ShowEgg(0);
			SetActiveEgg(LightA1);
			ShowEgg(1);
			SetActiveEgg(LightA4);
			ShowEgg(0);
			SetActiveEgg(LightA3);
			ShowEgg(1);
		}
		
		if(Light_control_BA==1)
		{
		    SetActiveEgg(LightB3);
		    ShowEgg(0);
		    SetActiveEgg(LightB4);
		    ShowEgg(1);
		}
		else if(Light_control_BA==2)
		{
		    SetActiveEgg(LightB1);
		    ShowEgg(0);
		    SetActiveEgg(LightB2);
		    ShowEgg(1);
		}
		if(B.location>=50||B.location<=25)
		{
			Light_control_BA=0;
		    SetActiveEgg(LightB4);
		    ShowEgg(0);
		    SetActiveEgg(LightB3);
		    ShowEgg(1);	
			SetActiveEgg(LightB2);
		    ShowEgg(0);
		    SetActiveEgg(LightB1);
		    ShowEgg(1);		
		}
		
		
		if(Light_control_CA==1)
		{
		    SetActiveEgg(LightC1);
		    ShowEgg(0);
		    SetActiveEgg(LightC2);
		    ShowEgg(1);
		}
		else if(Light_control_CA==2)
		{
		    SetActiveEgg(LightC3);
		    ShowEgg(0);
		    SetActiveEgg(LightC4);
		    ShowEgg(1); 			
		}
		if(C.location>=95||C.location<=60)
		{
			Light_control_CA=0;
			SetActiveEgg(LightC4);
		    ShowEgg(0);
		    SetActiveEgg(LightC3);
		    ShowEgg(1);
		    SetActiveEgg(LightC2);
		    ShowEgg(0);
		    SetActiveEgg(LightC1);
		    ShowEgg(1);		    
		}	
}



/*��Ҫ��ʱ���ʱ���õĺ���*/
void printChange()
{
	FILE*f1=fopen("ģ��𳵵���ϵͳ.txt","a");
    //f1=fopen("ģ��𳵵���ϵͳ1.txt","a");
	char trac[10]={0}; 
    char runc[10]={0};
   
    
    int count1;
	{	finish=clock();
	    count1=(finish-start)/1000;
	   
	
		printf("��ǰʱ�䣺%d\n",count1);
		if(priority_control==0)
		{
		    printf("��ǰ����Ϊ�쳵���Ȳ���\n");			
		}
        else
        {
        	printf("��ǰ����Ϊ�˹����Ʋ���\n");
		}
   		    fprintf(f1,"��ǰʱ�䣺%d\n",count);
		    if(priority_control==0) 
		    {
			    fprintf(f1,"��ǰ����Ϊ�쳵���Ȳ���\n"); 
		    }		
            else
            {
        	    fprintf(f1,"��ǰ����Ϊ�˹����Ʋ���\n"); 
		    }		
		
		
		
		    if(A.Circle==0)
		    { 
		        printf("A��˳ʱ������\n");
		        fprintf(f1,"A��˳ʱ������\n");
		    } 
		    if(A.Circle==1)
		    { 
		        printf("A����ʱ������\n"); 
		        fprintf(f1,"A����ʱ������\n"); 
		    }

		    if(A.state==0&&((A.location>50)&&(A.location<75)||(A.location>90)&&(A.location<125)))//A�ڹ����������״̬Ϊ��ֹ	   	
		    {	
			    if(A.control==1)//�ж�A��ͣ��ԭ�� 
			    {
				    strcpy(trac,"�����û�����");
				    strcpy(runc,"��ͣ");	
			    }
			    else
			    {
			        strcpy(trac,"ռ�ù������");
			        strcpy(runc,"ͣ��");
			        AStayFinish=clock();
			        AStay=StayTime*1000-(AStayFinish-AStayStart)+100;//����Aͣ��ʣ��ʱ�� 
			        if(count<=A.startTime)
			        {	
				        printf("A���ȴ�����\n");
				        fprintf(f1,"A���ȴ�����\n");
			        }
			        else
			        {
			            printf("A��ͣ��ʣ��ʱ�䣺%d����\n",AStay);
			            fprintf(f1,"A��ͣ��ʣ��ʱ�䣺%d����\n",AStay);
			        }
			    }
		    }	   
		    if(A.state==0&&((A.location<=50)||((A.location>=75)&&(A.location<=90))||(A.location>=125)))//A���ڹ����������״̬Ϊ��ֹ
		    {	
			    if(A.control==1)
			    {	
				    strcpy(trac,"�����û�����");
				    strcpy(runc,"��ͣ");	
			    }
			    else
			    {
			        strcpy(trac,"�ȴ��������");
			        strcpy(runc,"��ͣ");
				}
		    }		
			  
		    if(A.state==1&&(((A.location>50)&&(A.location<75))||((A.location>90)&&(A.location<125))))//A�ڹ����������״̬Ϊ�˶� 
		    {
			    strcpy(trac,"�������");
			    strcpy(runc,"����");
		    }
		    
		    if(A.state==1&&(A.location<=50||(A.location>=75)&&(A.location<=90)||A.location>=125))//A�ڹ����������״̬Ϊ�˶�		   
		    {
   			    strcpy(trac,"�ǹ������");
		 	    strcpy(runc,"����");
		    }
		    printf("A������״̬��%s-%s\n",runc,trac);//���A��״̬ 
		    printf("A�𳵵�ǰλ�ã�%f\n",A.location);//���A��λ�� 
		    fprintf(f1,"A������״̬��%s-%s\n",runc,trac);//���A��״̬ 
		    fprintf(f1,"A�𳵵�ǰλ�ã�%f\n",A.location);//���A��λ�� 
		    

	        if(B.Circle==0)
	        { 
		        printf("B��˳ʱ������\n");
		        fprintf(f1,"B��˳ʱ������\n");
		    } 
		    if(B.Circle==1)
		    {
			   printf("B����ʱ������\n"); 
		       fprintf(f1,"B����ʱ������\n"); 
		    } 
		    
		    
		    if(B.state==0&&(B.location>25&&B.location<50))//B�����������״̬Ϊ��ֹ
	     	{	
			    if(B.control==1)//�ж�B����ͣԭ�� 
			    {	
				    strcpy(trac,"�����û�����");
			  	    strcpy(runc,"��ͣ");
			    }
			    else
			    {
			        strcpy(trac,"ռ�ù������");
			        strcpy(runc,"ͣ��");
			        BStayFinish=clock();//����B��ͣ��ʣ��ʱ�� 
			        BStay=StayTime*1000-(BStayFinish-BStayStart)+100;
			        if(count<=B.startTime)
			        {	
					    printf("B���ȴ�����\n");
				        fprintf(f1,"B���ȴ�����\n");
			        }
			        else
			        {
			            printf("B��ͣ��ʣ��ʱ��:%d����\n",BStay);
			            fprintf(f1,"B��ͣ��ʣ��ʱ��:%d����\n",BStay);
                    }
			    } 
		    }
    		if(B.state==0&&(B.location<=25||B.location>=50))//B�ڹ����������״̬Ϊ��ֹ
		    {	
			    if(B.control==1)
			    {	
				    strcpy(trac,"�����û�����");
			  	    strcpy(runc,"��ͣ");
			    }
			    else
			    {
			        strcpy(trac,"�ȴ��������");
			        strcpy(runc,"��ͣ");
				} 
		    }	   
    		if(B.state==1&&(B.location>25&&B.location<505))//B�ڹ����������״̬Ϊ�˶�	   	
		    { 
			    strcpy(trac,"�������");
			    strcpy(runc,"����");	
			}
			if((B.state==1)&&((B.location<=25)||(B.location>=50)))//B�ڹ����������״̬Ϊ��ֹ	   	
		    {
			    strcpy(trac,"�ǹ������");
			    strcpy(runc,"����");
		    }	   	  
            printf("B������״̬��%s-%s\n",runc,trac);//���B��״̬
		    printf("B�𳵵�ǰλ�ã�%f\n",B.location);//���B��λ�� 
		    fprintf(f1,"B������״̬��%s-%s\n",runc,trac);//���B��״̬
		    fprintf(f1,"B�𳵵�ǰλ�ã�%f\n",B.location);//���B��λ�� 
		
		    if(C.Circle==0)
		    {
			    printf("C��˳ʱ������\n");
		        fprintf(f1,"C��˳ʱ������\n");
		    } 
		    if(C.Circle==1)
		    {
			    printf("C����ʱ������\n");
		        fprintf(f1,"C����ʱ������\n");
			}
	
	
		    if(C.state==0&&(C.location>60&&C.location<95))//C�ڹ����������״̬Ϊ��ֹ	   	
		    {	
			    if(C.control==1)
			    {
				    strcpy(trac,"�����û�����");
			        strcpy(runc,"��ͣ"); 
			    }
			    else
			    {
			        strcpy(trac,"ռ�ù������");
			        strcpy(runc,"ͣ��");
			        CStayFinish=clock();//����C��ͣ��ʣ��ʱ�� 
		         	CStay=StayTime*1000-(CStayFinish-CStayStart)+100;
			        if(count<=C.startTime)
			        {	
				        printf("C���ȴ�����\n");
				        fprintf(f1,"C���ȴ�����\n");
			        }
			        else
					{ 
			            printf("C��ͣ��ʣ��ʱ��:%d����\n",CStay);
			            fprintf(f1,"C��ͣ��ʣ��ʱ��:%d����\n",CStay);
	                }
			   } 
		    }
	        if(C.state==0&&(C.location<=60||C.location>=95))//C�ڹ����������״̬Ϊ��ֹ		   	
		    {
			    if(C.control==1)
			    {
				    strcpy(trac,"�����û�����");
			        strcpy(runc,"��ͣ"); 
			    }
			    else
			    {
			        strcpy(trac,"�ȴ��������");
			        strcpy(runc,"��ͣ");
				}
		    }	   
		    if(C.state==1&&(C.location>60&&C.location<95))	//C�ڹ����������״̬Ϊ�˶�	   	
		    { 
			    strcpy(trac,"�������");
			    strcpy(runc,"����");	
	        }
		    if((C.state==1)&&((C.location<=60||C.location>=95)))//C�ڹ����������״̬Ϊ��ֹ		   	
		    {
			    strcpy(trac,"�ǹ������");
			    strcpy(runc,"����");
	        }	   	  
     	    printf("C������״̬��%s-%s\n",runc,trac);
		    printf("C�𳵵�ǰλ�ã�%f\n",C.location);
		    fprintf(f1,"C������״̬��%s-%s\n",runc,trac);
		    fprintf(f1,"C�𳵵�ǰλ�ã�%f\n",C.location);

		
		    if((A.location>50)&&(A.location<75))
		    {
		        printf("AB���������A��ռ��\n");
		        fprintf(f1,"AB���������A��ռ��\n");
	      	} 
		    else if((B.location>25)&&(B.location<50))
		    {
		        printf("AB���������B��ռ��\n");
		        fprintf(f1,"AB���������B��ռ��\n");
		    }
		    else
		    {
		        printf("AB�����������\n"); 
		        fprintf(f1,"AB�����������\n"); 
		    }
		    /*���AC�������״̬*/
		    if((A.location>90)&&(A.location<125))
		    {
		        printf("AC���������A��ռ��\n");
		        fprintf(f1,"AC���������A��ռ��\n");
		    }
		    else if((C.location>60)&&(C.location<95))
		    {
		        printf("AC���������C��ռ��\n");
		        fprintf(f1,"AC���������C��ռ��\n");
		    }
		    else
		    {
		        printf("AC�����������\n");
		        fprintf(f1,"AC�����������\n"); 	
	     	}
	
			
		printf("\n");	
			
		fclose(f1);
		}
	}




/*���ƿ쳵���Ȱ�ť�Ķ���*/
void fast()
{		SetActiveEgg(Facility);
	   	ShowEgg(0);
    	SetActiveEgg(Fast);
    //	MoveEgg(635,334);
	   	ShowEgg(1);
}
/*�����˹����ư�ť�Ķ���*/
void facility()
{	SetActiveEgg(Fast);
	ShowEgg(0);
	SetActiveEgg(Facility);
//	MoveEgg(635,285);
	ShowEgg(1);
}
