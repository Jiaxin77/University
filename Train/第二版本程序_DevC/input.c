#include<stdio.h>
#include"varible.h"
int shuzizhuanhua(int m);
int durushuzi();
int shuzidaozhi(int m);
void Clear_number(int m); 
/*命令行输入函数 */
int getTrain()
{   
    int n;//为让用户输入整数而加入的变量 
	int m;//用于判断用户是否输入数字 

    /*输入停靠时间 */
	printf("[StayTime]（>=0的整数）:");
	fflush(stdin);//清空缓存 
    m=scanf("%d",&StayTime);
    while(StayTime<0||m==0)
    {	printf("时光不能倒流,时间不能为负噢！\n");
		printf("[StayTime]（>=0的整数）:");
		fflush(stdin);
    	m=scanf("%d",&StayTime);
	} 
    printf("\n");
    
    /*输入A车速度 */
    printf("[A Speed](1-25之间整数):");
    fflush(stdin);//清空缓存 
	m=scanf("%d",&n);
	while((n>25)||(n<1)||m==0)
	{
			printf("请注意速度范围噢！\n");			
			printf("[A Speed](1-25之间整数):");
			fflush(stdin);
			m=scanf("%d",&n);	
	}
	A.speed=n;	
	printf("\n");
	
   /*输入B车速度 */	
	printf("[B Speed](1-25之间整数):");
	fflush(stdin);//清空缓存 
	m=scanf("%d",&n);
	while((n>25)||(n<1)||m==0)
	{		printf("请注意速度范围噢！\n");
			printf("[B Speed](1-25之间整数):");
			fflush(stdin);
			m=scanf("%d",&n);
	}
	B.speed=n;
	printf("\n");
	
	/*输入C车速度 */
	printf("[C Speed](1-35之间整数):");
	fflush(stdin);//清空缓存 
	m=scanf("%d",&n);
	while((n>35)||(n<1)||m==0)
	{		printf("请注意速度范围噢！\n");
			printf("[C Speed](1-35整数):");
			fflush(stdin);
			m=scanf("%d",&n);
	}
    C.speed=n;
    printf("\n");
    
    /*输入A车开始运动时间 */
	printf("[A StartTime] (>=0的整数):");
	fflush(stdin);//清空缓存 
	m=scanf("%d",&A.startTime);
	while(A.startTime<0||m==0)
	{	printf("时光不能倒流,时间不能为负噢！\n");
		printf("[A StartTime] (>=0的整数):");
		fflush(stdin);
		m=scanf("%d",&A.startTime); 
	}
    printf("\n");
    
     /*输入B车开始运动时间 */
	printf("[B StartTime](>=0的整数) :");
	fflush(stdin);//清空缓存 
	m=scanf("%d",&B.startTime);
	while(B.startTime<0||m==0)
	{	printf("时光不能倒流,时间不能为负噢！\n");
		printf("[B StartTime] (>=0的整数):");
		fflush(stdin);
		m=scanf("%d",&B.startTime); 
	}
	printf("\n");
	
	/*输入C车开始运动时间*/
	printf("[C StartTime](>=0的整数):");
	fflush(stdin);//清空缓存 
	m=scanf("%d",&C.startTime);
	while(C.startTime<0||m==0)
	{	printf("时光不能倒流,时间不能为负噢！\n");
		printf("[C StartTime] (>=0的整数):");
		fflush(stdin);
		m=scanf("%d",&C.startTime); 
	}
	printf("\n");
	
	/*输入A车位置 */
	printf("[A StartPoint](0-149的整数) :");
	fflush(stdin);//清空缓存 
	m=scanf("%d",&n);
	while(n>149||n<0||m==0)
	{	printf("请注意起始点范围噢~\n");
		printf("[A StartPoint](0-149的整数) :");
		fflush(stdin);
		m=scanf("%d",&n);
	}
	A.startLoc=n;
	printf("\n");
	
	/*输入B车位置 */
	if((A.startLoc>50)&&(A.startLoc<75))
		printf("B起始点不能在25-50,否则两车会打架噢！\n"); 
	printf("[B StartPoint](0-149的整数) :");
	fflush(stdin);//清空缓存 
	m=scanf("%d",&n);	
	while(n>149||n<0||m==0)
	{	printf("请注意起始点范围噢~\n");
		printf("[B StartPoint](0-149的整数) :");
		fflush(stdin);
		m=scanf("%d",&n);
	    if((A.startLoc>50)&&(A.startLoc<75))
	    {	
	        while((n>25&&n<50)||m==0)
		   {	printf("两车要打架了！请对程序员友好（微笑）\n");
			    printf("[B StartPoint](0-149的整数) :");
			    fflush(stdin);
			    m=scanf("%d",&n);		
	    	}
	    }		
	}	
	B.startLoc=n;
	printf("\n");
	
	/*输入C车位置 */
	if((A.startLoc>90)&&(A.startLoc<125))
		printf("C起始点不能在60-95,否则两车会打架噢！\n");
	printf("[C StartPoint](0-119的整数) :");
	fflush(stdin);//清空缓存 
	m=scanf("%d",&n); 
	while(n>119||n<0||m==0)
	{	printf("请注意起始点范围噢~\n");
		printf("[C StartPoint](0-119的整数) :");
		fflush(stdin);
		m=scanf("%d",&n);
	    if((n>90)&&(n<125))
	    {	while((n>60&&n<95)||m==0)
			{	printf("两车要打架了！请对程序员友好（微笑）\n");
				printf("[C StartPoint](0-119的整数) :");
				fflush(stdin);
				m=scanf("%d",&n);
				
			}
	    }		
	}
	
	C.startLoc=n;
	printf("\n");
	
	/*输入A车运动方向 */
	printf("[A Direction](顺时针为0，逆时针为1) :");
	fflush(stdin);//清空缓存 
	m=scanf("%d",&A.Circle);
	while((A.Circle!=1&&A.Circle!=0)||m==0)
	{	printf("只能用1或0表示噢！\n");
		printf("[A Direction](顺时针为0，逆时针为1) :");
		fflush(stdin);
		m=scanf("%d",&A.Circle);
	}
	printf("\n");
	
	/*输入B车运动方向 */
	printf("[B Direction](顺时针为0，逆时针为1) :");
	fflush(stdin);//清空缓存 
	m=scanf("%d",&B.Circle);
	while((B.Circle!=1&&B.Circle!=0)||m==0)
	{	printf("只能用1或0表示噢！\n");
		printf("[B Direction](顺时针为0，逆时针为1) :");
		fflush(stdin);
		m=scanf("%d",&B.Circle);
	}
	printf("\n");
	
	/*输入C车运动方向 */
	printf("[C Direction](顺时针为0，逆时针为1) :");
	fflush(stdin);//清空缓存 
	m=scanf("%d",&C.Circle);
	while((C.Circle!=1&&C.Circle!=0)||m==0)
	{	printf("只能用1或0表示噢！\n");
		printf("[C Direction](顺时针为0，逆时针为1) :");
		fflush(stdin);
		m=scanf("%d",&C.Circle);
	}
	printf("\n");
	printf("输入完毕，请耐心等待3s!\n"); 
	return 1;
}



/*图形化输入函数 */
int Inputpicture()
{

	int input_record=0;//记录输入变量的个数 
	int control_staytime=0,control_A_speed=0,control_B_speed=0,control_C_speed=0,control_A_ST=0,control_B_ST=0,control_C_ST=0;
	int control_A_SL=0,control_B_SL=0,control_C_SL=0,control_A_C=0,control_B_C=0,control_C_C=0;//分别用来表明需要输入的变量已经输入 
	InputPicture=LayEgg();
	DrawBitmap("输入框.bmp");
	while(1)
	{
		if (WaitForEvent() == KEYDOWN)
        {
    	    if(GetStruckKey() == VK_LBUTTON) //鼠标左键被按下
            {
                double  X = GetMouseX();
                double  Y = GetMouseY();
                /*输入停靠时间 */
                if( (X >= 289 && X <= 362.7) && (Y >= 368.3 && Y <= 385.3)&&control_staytime==0 )
                {
                	
 	                MovePen(295.85,380.3);
	                StayTime=durushuzi();//初次输入 
	                while(control_staytime==0)
	                {
	                	if(StayTime<0) //输入不正确 
	                	{
	                		MovePen(295.85,380.3);
                            Clear_number(StayTime); //清空数字 
                            MovePen(295.85,380.3);
	                        StayTime=durushuzi(); //再次输入                       
                        }
                        else//输入正确 
                        {
                            input_record++;
							control_staytime=1;//开关启动 
						}

					}					              	
				}
				/*输入A车速度 */
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
				/*输入B车速度 */
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
				/*输入C车速度 */
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
				/*输入A车启动时间 */
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
				/*输入B车启动时间 */								
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
				/*输入C车启动时间 */
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
				/*输入A车开始位置 */
                if( (X >= 623 && X <= 702.7) && (Y >= 294.6 && Y <= 317.3)&&control_A_SL==0 )
				{
	                MovePen(632.85,312.3);
	                A.startLoc=durushuzi();	//初次输入 
	                while(control_A_SL==0)
	                {
	                	if(A.startLoc<0||A.startLoc>149)//若不在A的范围里 
	                	{
	                		MovePen(632.85,312.3);
	                		Clear_number(A.startLoc);
	                        MovePen(632.85,312.3);
	                        A.startLoc=durushuzi();//重新输入                		
						}
						else if(control_B_SL==1&&(A.startLoc>50&&A.startLoc<75)&&(B.startLoc>25&&B.startLoc<50))//在B已经输入且占用AB公共轨道的情况下，若输入的A也在公共轨道 
						{
	                		MovePen(632.85,312.3);
	                		Clear_number(A.startLoc);
	                        MovePen(632.85,312.3);
	                        A.startLoc=durushuzi();//重新输入 						
						}
						else if(control_C_SL==1&&(A.startLoc>90&&A.startLoc<125)&&(C.startLoc>60&&C.startLoc<95))//在C已经输入且占用AC公共轨道的情况下，若输入的A也在公共轨道 
						{
	                		MovePen(632.85,312.3);
	                		Clear_number(A.startLoc);
	                        MovePen(632.85,312.3);
	                        A.startLoc=durushuzi();						
						}
						else
						{
							input_record++;
							control_A_SL=1;//输入完成 
						}
					}	                
				}
				/*输入B车开始位置 */
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
				/*输入C车开始位置 */
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
				/*输入A车运动方向 */																																
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
				/*输入B车运动方向 */
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
				/*输入C车运动方向 */
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
			    if((X >= 566.6 && X <= 663) && (Y >= 17 && Y <= 56.6)&&input_record==13)//在各值全部输入的情况下，点击OK按钮 ,结束图形化输入 
				{	SetActiveEgg(InputPicture);
					ShowEgg(0);
				  	return 1;
			    }				
			}
		}
	}
				 
	
		
}

/*初始化火车数据  */
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


/*初始化轨道数据  */
void OriginalTrack()
{
	
	
	a.lenth=50;
	b.lenth=35;
	c.lenth=35;
	a.wide=25;
	b.wide=50;
	c.wide=25;
	
}

/*以下为图形化输入中用到的函数*/
/*用来在图形化输入中读入用户输入的值，并且即时打印在图形化界面上*/
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
    		if(GetStruckKey()>=48&&GetStruckKey()<=57&&j<=2) //按下0-9数字键 
    		{
			    M=shuzizhuanhua(GetStruckKey());
	            sprintf(s,   "%d ",   M);
                DrawString(s); //即时打印 
    			m=m*n+shuzizhuanhua(GetStruckKey());
    			j=j+1;
			}
			else if(GetStruckKey()==13&&j!=0)//按下回车结束输入 
			{
				return m;//返回值为输入值 
			}
			else if(GetStruckKey()==8)//按下backspace键 
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
/*用来清除输入不正确的值*/
void Clear_number(int m)
{
	int q,j=0;
	char s[2];
	s[0]=' ';//这里改怎么改，才能清空？ 
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
/*在durushuzi()函数中调用，用来将0-9对应的ASCII转化为数字0-9*/
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

