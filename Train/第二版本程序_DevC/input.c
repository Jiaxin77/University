#include<stdio.h>
#include"varible.h"
int shuzizhuanhua(int m);
int durushuzi();
int shuzidaozhi(int m);
void Clear_number(int m); 
/*���������뺯�� */
int getTrain()
{   
    int n;//Ϊ���û���������������ı��� 
	int m;//�����ж��û��Ƿ��������� 

    /*����ͣ��ʱ�� */
	printf("[StayTime]��>=0��������:");
	fflush(stdin);//��ջ��� 
    m=scanf("%d",&StayTime);
    while(StayTime<0||m==0)
    {	printf("ʱ�ⲻ�ܵ���,ʱ�䲻��Ϊ���ޣ�\n");
		printf("[StayTime]��>=0��������:");
		fflush(stdin);
    	m=scanf("%d",&StayTime);
	} 
    printf("\n");
    
    /*����A���ٶ� */
    printf("[A Speed](1-25֮������):");
    fflush(stdin);//��ջ��� 
	m=scanf("%d",&n);
	while((n>25)||(n<1)||m==0)
	{
			printf("��ע���ٶȷ�Χ�ޣ�\n");			
			printf("[A Speed](1-25֮������):");
			fflush(stdin);
			m=scanf("%d",&n);	
	}
	A.speed=n;	
	printf("\n");
	
   /*����B���ٶ� */	
	printf("[B Speed](1-25֮������):");
	fflush(stdin);//��ջ��� 
	m=scanf("%d",&n);
	while((n>25)||(n<1)||m==0)
	{		printf("��ע���ٶȷ�Χ�ޣ�\n");
			printf("[B Speed](1-25֮������):");
			fflush(stdin);
			m=scanf("%d",&n);
	}
	B.speed=n;
	printf("\n");
	
	/*����C���ٶ� */
	printf("[C Speed](1-35֮������):");
	fflush(stdin);//��ջ��� 
	m=scanf("%d",&n);
	while((n>35)||(n<1)||m==0)
	{		printf("��ע���ٶȷ�Χ�ޣ�\n");
			printf("[C Speed](1-35����):");
			fflush(stdin);
			m=scanf("%d",&n);
	}
    C.speed=n;
    printf("\n");
    
    /*����A����ʼ�˶�ʱ�� */
	printf("[A StartTime] (>=0������):");
	fflush(stdin);//��ջ��� 
	m=scanf("%d",&A.startTime);
	while(A.startTime<0||m==0)
	{	printf("ʱ�ⲻ�ܵ���,ʱ�䲻��Ϊ���ޣ�\n");
		printf("[A StartTime] (>=0������):");
		fflush(stdin);
		m=scanf("%d",&A.startTime); 
	}
    printf("\n");
    
     /*����B����ʼ�˶�ʱ�� */
	printf("[B StartTime](>=0������) :");
	fflush(stdin);//��ջ��� 
	m=scanf("%d",&B.startTime);
	while(B.startTime<0||m==0)
	{	printf("ʱ�ⲻ�ܵ���,ʱ�䲻��Ϊ���ޣ�\n");
		printf("[B StartTime] (>=0������):");
		fflush(stdin);
		m=scanf("%d",&B.startTime); 
	}
	printf("\n");
	
	/*����C����ʼ�˶�ʱ��*/
	printf("[C StartTime](>=0������):");
	fflush(stdin);//��ջ��� 
	m=scanf("%d",&C.startTime);
	while(C.startTime<0||m==0)
	{	printf("ʱ�ⲻ�ܵ���,ʱ�䲻��Ϊ���ޣ�\n");
		printf("[C StartTime] (>=0������):");
		fflush(stdin);
		m=scanf("%d",&C.startTime); 
	}
	printf("\n");
	
	/*����A��λ�� */
	printf("[A StartPoint](0-149������) :");
	fflush(stdin);//��ջ��� 
	m=scanf("%d",&n);
	while(n>149||n<0||m==0)
	{	printf("��ע����ʼ�㷶Χ��~\n");
		printf("[A StartPoint](0-149������) :");
		fflush(stdin);
		m=scanf("%d",&n);
	}
	A.startLoc=n;
	printf("\n");
	
	/*����B��λ�� */
	if((A.startLoc>50)&&(A.startLoc<75))
		printf("B��ʼ�㲻����25-50,�������������ޣ�\n"); 
	printf("[B StartPoint](0-149������) :");
	fflush(stdin);//��ջ��� 
	m=scanf("%d",&n);	
	while(n>149||n<0||m==0)
	{	printf("��ע����ʼ�㷶Χ��~\n");
		printf("[B StartPoint](0-149������) :");
		fflush(stdin);
		m=scanf("%d",&n);
	    if((A.startLoc>50)&&(A.startLoc<75))
	    {	
	        while((n>25&&n<50)||m==0)
		   {	printf("����Ҫ����ˣ���Գ���Ա�Ѻã�΢Ц��\n");
			    printf("[B StartPoint](0-149������) :");
			    fflush(stdin);
			    m=scanf("%d",&n);		
	    	}
	    }		
	}	
	B.startLoc=n;
	printf("\n");
	
	/*����C��λ�� */
	if((A.startLoc>90)&&(A.startLoc<125))
		printf("C��ʼ�㲻����60-95,�������������ޣ�\n");
	printf("[C StartPoint](0-119������) :");
	fflush(stdin);//��ջ��� 
	m=scanf("%d",&n); 
	while(n>119||n<0||m==0)
	{	printf("��ע����ʼ�㷶Χ��~\n");
		printf("[C StartPoint](0-119������) :");
		fflush(stdin);
		m=scanf("%d",&n);
	    if((n>90)&&(n<125))
	    {	while((n>60&&n<95)||m==0)
			{	printf("����Ҫ����ˣ���Գ���Ա�Ѻã�΢Ц��\n");
				printf("[C StartPoint](0-119������) :");
				fflush(stdin);
				m=scanf("%d",&n);
				
			}
	    }		
	}
	
	C.startLoc=n;
	printf("\n");
	
	/*����A���˶����� */
	printf("[A Direction](˳ʱ��Ϊ0����ʱ��Ϊ1) :");
	fflush(stdin);//��ջ��� 
	m=scanf("%d",&A.Circle);
	while((A.Circle!=1&&A.Circle!=0)||m==0)
	{	printf("ֻ����1��0��ʾ�ޣ�\n");
		printf("[A Direction](˳ʱ��Ϊ0����ʱ��Ϊ1) :");
		fflush(stdin);
		m=scanf("%d",&A.Circle);
	}
	printf("\n");
	
	/*����B���˶����� */
	printf("[B Direction](˳ʱ��Ϊ0����ʱ��Ϊ1) :");
	fflush(stdin);//��ջ��� 
	m=scanf("%d",&B.Circle);
	while((B.Circle!=1&&B.Circle!=0)||m==0)
	{	printf("ֻ����1��0��ʾ�ޣ�\n");
		printf("[B Direction](˳ʱ��Ϊ0����ʱ��Ϊ1) :");
		fflush(stdin);
		m=scanf("%d",&B.Circle);
	}
	printf("\n");
	
	/*����C���˶����� */
	printf("[C Direction](˳ʱ��Ϊ0����ʱ��Ϊ1) :");
	fflush(stdin);//��ջ��� 
	m=scanf("%d",&C.Circle);
	while((C.Circle!=1&&C.Circle!=0)||m==0)
	{	printf("ֻ����1��0��ʾ�ޣ�\n");
		printf("[C Direction](˳ʱ��Ϊ0����ʱ��Ϊ1) :");
		fflush(stdin);
		m=scanf("%d",&C.Circle);
	}
	printf("\n");
	printf("������ϣ������ĵȴ�3s!\n"); 
	return 1;
}



/*ͼ�λ����뺯�� */
int Inputpicture()
{

	int input_record=0;//��¼��������ĸ��� 
	int control_staytime=0,control_A_speed=0,control_B_speed=0,control_C_speed=0,control_A_ST=0,control_B_ST=0,control_C_ST=0;
	int control_A_SL=0,control_B_SL=0,control_C_SL=0,control_A_C=0,control_B_C=0,control_C_C=0;//�ֱ�����������Ҫ����ı����Ѿ����� 
	InputPicture=LayEgg();
	DrawBitmap("�����.bmp");
	while(1)
	{
		if (WaitForEvent() == KEYDOWN)
        {
    	    if(GetStruckKey() == VK_LBUTTON) //������������
            {
                double  X = GetMouseX();
                double  Y = GetMouseY();
                /*����ͣ��ʱ�� */
                if( (X >= 289 && X <= 362.7) && (Y >= 368.3 && Y <= 385.3)&&control_staytime==0 )
                {
                	
 	                MovePen(295.85,380.3);
	                StayTime=durushuzi();//�������� 
	                while(control_staytime==0)
	                {
	                	if(StayTime<0) //���벻��ȷ 
	                	{
	                		MovePen(295.85,380.3);
                            Clear_number(StayTime); //������� 
                            MovePen(295.85,380.3);
	                        StayTime=durushuzi(); //�ٴ�����                       
                        }
                        else//������ȷ 
                        {
                            input_record++;
							control_staytime=1;//�������� 
						}

					}					              	
				}
				/*����A���ٶ� */
				if( (X >= 226.6 && X <= 306) && (Y >= 294.6 && Y <= 317.3)&& control_A_speed==0)
				{
	                MovePen(236.3,312.3);
	                A.speed=durushuzi();	                
	                while(control_A_speed==0)
	                {
	                	if(A.speed<=0||A.speed>25)
	                	{
	                		MovePen(236.3,312.3);
	                		Clear_number(A.speed);
	                        MovePen(236.3,312.3);
	                        A.speed=durushuzi();	                		
						}
						else
						{
							input_record++;
							control_A_speed=1;
						}
					}
	                
				}
				/*����B���ٶ� */
                if( (X >= 226.6 && X <= 306) && (Y >= 255 && Y <= 277.7)&& control_B_speed==0 )
				{
	                MovePen(236.3,274.7);
	                B.speed=durushuzi();
	                while(control_B_speed==0)
	                {
	                	if(B.speed<=0||B.speed>25)
	                	{
	                		MovePen(236.36,274.7);
	                		Clear_number(B.speed);
	                        MovePen(236.3,274.7);
	                        B.speed=durushuzi();	                		
						}
						else
						{
							input_record++;
							control_B_speed=1;
						}
					}
				}
				/*����C���ٶ� */
                if( (X >= 226.6 && X <= 306) && (Y >= 226.6 && Y <= 243.7) &&control_C_speed==0)
				{
	                MovePen(236.3,240.7);
	                C.speed=durushuzi();
	                while(control_C_speed==0)
	                {
	                	if(C.speed<=0||C.speed>35)
	                	{
	                		MovePen(236.3,240.7);
	                		Clear_number(C.speed);
	                        MovePen(236.3,240.7);
	                        C.speed=durushuzi();               		
						}
						else
						{
							input_record++;
							control_C_speed=1;
						}
					}	                
				}
				/*����A������ʱ�� */
                if( (X >= 283 && X <= 368.3) && (Y >= 164.3 && Y <= 187)&&control_A_ST==0 )
				{
	                MovePen(295.65,184);
	                A.startTime=durushuzi();
	                while(control_A_ST==0)
	                {
	                	if(A.startTime<0)
	                	{
	                		MovePen(295.65,184);
	                		Clear_number(A.startTime);
	                        MovePen(295.65,1842);
	                        A.startTime=durushuzi();	                		
						}
						else
						{
							input_record++;
							control_A_ST=1;
						}
					}	                
	                
				}
				/*����B������ʱ�� */								
                if( (X >= 283 && X <= 368.3) && (Y >= 136 && Y <= 158.7)&&control_B_ST==0 )
				{
	                MovePen(295.65,153.7);
	                B.startTime=durushuzi();
	                while(control_B_ST==0)
	                {
	                	if(B.startTime<0)
	                	{
	                		MovePen(295.65,153.7);
	                		Clear_number(B.startTime);
	                        MovePen(295.65,153.7);
	                        B.startTime=durushuzi();	                		
						}
						else
						{
							input_record++;
							control_B_ST=1;
						}
					}	                
				}
				/*����C������ʱ�� */
                if( (X >= 283 && X <= 368.3) && (Y >= 102 && Y <= 119)&&control_C_ST==0 )
				{
	                MovePen(295.65,116);
	                C.startTime=durushuzi();
	                while(control_C_ST==0)
	                {
	                	if(C.startTime<0)
	                	{
	                		MovePen(295.65,116);
	                		Clear_number(C.startTime);
	                        MovePen(295.65,116);
	                        C.startTime=durushuzi();	                		
						}
						else
						{
							input_record++;
							control_C_ST=1;
						}
					}	                
				}
				/*����A����ʼλ�� */
                if( (X >= 623 && X <= 702.7) && (Y >= 294.6 && Y <= 317.3)&&control_A_SL==0 )
				{
	                MovePen(632.85,312.3);
	                A.startLoc=durushuzi();	//�������� 
	                while(control_A_SL==0)
	                {
	                	if(A.startLoc<0||A.startLoc>149)//������A�ķ�Χ�� 
	                	{
	                		MovePen(632.85,312.3);
	                		Clear_number(A.startLoc);
	                        MovePen(632.85,312.3);
	                        A.startLoc=durushuzi();//��������                		
						}
						else if(control_B_SL==1&&(A.startLoc>50&&A.startLoc<75)&&(B.startLoc>25&&B.startLoc<50))//��B�Ѿ�������ռ��AB�������������£��������AҲ�ڹ������ 
						{
	                		MovePen(632.85,312.3);
	                		Clear_number(A.startLoc);
	                        MovePen(632.85,312.3);
	                        A.startLoc=durushuzi();//�������� 						
						}
						else if(control_C_SL==1&&(A.startLoc>90&&A.startLoc<125)&&(C.startLoc>60&&C.startLoc<95))//��C�Ѿ�������ռ��AC�������������£��������AҲ�ڹ������ 
						{
	                		MovePen(632.85,312.3);
	                		Clear_number(A.startLoc);
	                        MovePen(632.85,312.3);
	                        A.startLoc=durushuzi();						
						}
						else
						{
							input_record++;
							control_A_SL=1;//������� 
						}
					}	                
				}
				/*����B����ʼλ�� */
                if( (X >= 623 && X <= 702.7) && (Y >= 255 && Y <= 277.7)&&control_B_SL==0)
				{
	                MovePen(632.85,274.7);
	                B.startLoc=durushuzi();
	                while(control_B_SL==0)
	                {
	                	if(B.startLoc<0||B.startLoc>149)   
	                	{
	                		MovePen(632.85,274.7);
	                		Clear_number(B.startLoc);
	                        MovePen(632.85,274.7);
	                        B.startLoc=durushuzi();                		
						}
						else if (control_A_SL==1&&(A.startLoc>50&&A.startLoc<75)&&(B.startLoc>25&&B.startLoc<50))
						{
	                		MovePen(632.85,274.7);
	                		Clear_number(B.startLoc);
	                        MovePen(632.85,274.7);
	                        B.startLoc=durushuzi();						
						}
						else
						{
							input_record++;
							control_B_SL=1;
						}
					}						
				}
				/*����C����ʼλ�� */
                if( (X >= 623 && X <= 702.7) && (Y >= 226.6 && Y <= 243.7)&& control_C_SL==0)
				{
	                MovePen(632.85,240.7);
	                C.startLoc=durushuzi();
	                while(control_C_SL==0)
	                {
	                	if(C.startLoc<0||C.startLoc>119)
	                	{
	                		MovePen(632.85,240.7);
	                		Clear_number(C.startLoc);
	                        MovePen(632.85,240.7);   
							C.startLoc=durushuzi();  		
						}
						else if(control_A_SL==1&&(A.startLoc>90&&A.startLoc<125)&&(C.startLoc>=60&&C.startLoc<=95))
						{
	                		MovePen(632.85,240.7);
	                		Clear_number(C.startLoc);
	                        MovePen(632.85,240.7);
	                        C.startLoc=durushuzi();												
						}
						else
						{
							input_record++;
							control_C_SL=1;
						}
					}	                
				}	
				/*����A���˶����� */																																
                if( (X >= 566.6 && X <= 651.7) && (Y >= 164.3 && Y <= 187)&&control_A_C==0 )
				{
	                MovePen(579.15,184);
	                A.Circle=durushuzi();
	                while(control_A_C==0)
	                {
	                	if(A.Circle<0||A.Circle>1)
	                	{
	                		MovePen(579.15,184);
	                		Clear_number(A.Circle);
	                        MovePen(579.15,184);
	                        A.Circle=durushuzi();                		
						}
						else
						{
							input_record++;
							control_A_C=1;
						}
					}	                
				}
				/*����B���˶����� */
                if( (X >= 566.6 && X <= 651.7) && (Y >= 136 && Y <= 158.7)&& control_B_C==0)
				{
                   	MovePen(579.15,153.7);
	                B.Circle=durushuzi();
	                while(control_B_C==0)
	                {
	                	if(B.Circle<0||B.Circle>1)
	                	{
	                		MovePen(579.15,153.7);
	                		Clear_number(B.Circle);
	                       	MovePen(579.15,153.7);
	                        B.Circle=durushuzi();	                		
						}
						else
						{
							input_record++;
							control_B_C=1;
						}
					}	                
	                
				}
				/*����C���˶����� */
                if( (X >= 566.6 && X <= 651.7) && (Y >= 102 && Y <= 119)&&	 control_C_C==0 )
				{
	                MovePen(579.15,116);
	                C.Circle=durushuzi();
	                while(control_C_C==0)
	                {
	                    if(C.Circle<0||C.Circle>1)
	                    {
	                		MovePen(579.15,116);
	                		Clear_number(C.Circle);
	                       	MovePen(579.15,116);
	                        C.Circle=durushuzi();                		
				    	}
					    else
					    {
							input_record++;
							control_C_C=1;
					    }
					}	                
				}
			    if((X >= 566.6 && X <= 663) && (Y >= 17 && Y <= 56.6)&&input_record==13)//�ڸ�ֵȫ�����������£����OK��ť ,����ͼ�λ����� 
				{	SetActiveEgg(InputPicture);
					ShowEgg(0);
				  	return 1;
			    }				
			}
		}
	}
				 
	
		
}

/*��ʼ��������  */
void OriginalTrain()
{


	StayTime=0;
	
	A.speed=4;
	B.speed=2;
	C.speed=2;

	A.startTime=0;
	B.startTime=0;
	C.startTime=0;
	
	
	A.startLoc=0;
	B.startLoc=0;
	C.startLoc=0;
	
	A.Circle=1;
	B.Circle=0;
	C.Circle=0;

}


/*��ʼ���������  */
void OriginalTrack()
{
	
	
	a.lenth=50;
	b.lenth=35;
	c.lenth=35;
	a.wide=25;
	b.wide=50;
	c.wide=25;
	
}

/*����Ϊͼ�λ��������õ��ĺ���*/
/*������ͼ�λ������ж����û������ֵ�����Ҽ�ʱ��ӡ��ͼ�λ�������*/
int durushuzi()
{
	int m=0,n=10,M,j=0; 
	double x,y;
	char s[1];	
	x=GetPenXPos();
	y=GetPenYPos(); 
    while(1)
    {
    	if(WaitForEvent() == KEYDOWN)
    	{
    		if(GetStruckKey()>=48&&GetStruckKey()<=57&&j<=2) //����0-9���ּ� 
    		{
			    M=shuzizhuanhua(GetStruckKey());
	            sprintf(s,   "%d ",   M);
                DrawString(s); //��ʱ��ӡ 
    			m=m*n+shuzizhuanhua(GetStruckKey());
    			j=j+1;
			}
			else if(GetStruckKey()==13&&j!=0)//���»س��������� 
			{
				return m;//����ֵΪ����ֵ 
			}
			else if(GetStruckKey()==8)//����backspace�� 
			{
				MovePen(x,y);
				Clear_number(m);
				m=0;
				j=0;
				n=10;
				MovePen(x,y);
			}
		}
	}
	
}
/*����������벻��ȷ��ֵ*/
void Clear_number(int m)
{
	int q,j=0;
	char s[2];
	s[0]=' ';//�������ô�ģ�������գ� 
	s[1]=' ';
	if(m==0)
	{
		j=1;
	}
	else
	{
	    for(q=m;q>0;q=q/10)
	    {
		    j=j+1;
	    }		
	}
	while(j>0)
	{
		j=j-1;
        DrawString(s);
	}
}
/*��durushuzi()�����е��ã�������0-9��Ӧ��ASCIIת��Ϊ����0-9*/
int shuzizhuanhua(int m)
{
	switch (m)
	{
		case 48:
			return 0;
		case 49:
		    return 1;
		case 50:
		    return 2;
		case 51:
		    return 3;
		case 52:
		    return 4;
		case 53:
		    return 5;
		case 54:
		    return 6;
		case 55:
		    return 7;
		case 56:
		    return 8;
		case 57:
		    return 9;  
	}
}

