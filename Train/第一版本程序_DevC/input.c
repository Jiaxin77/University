#include<stdio.h>
#include"varible.h"

int getTrain()
{   int r;//���ڼ�¼�û��Ƿ��������� 
	int m;//�����ж��û��Ƿ��������� 
	printf("��ӭʹ��С�𳵵���ϵͳ(���)!\n12GС��ף����;���~\n\n");
	printf("�������λ��Ϊ:A���10-16������B���5-11����,A���18-26������C���12-20���֡�\n\n");

	printf("���й����У�\n����A��ֹͣ-������ A\n����A����������-������a\n����B��ֹͣ-������B\n����B����������-������b\n����C��ֹͣ-������C\n����C����������-������c\n");
	printf("\n�������ݽ����������ĵȴ�3s��������\n");
	printf("�������ݾ�Ϊ����,��Գ���Ա�Ѻ�:)   ����С��ֻ�ϵ�һλ�����ޣ�\n\n");
	printf("С��Ĭ�����ݣ�\nA.speed=4\tB.speed=2\tC.speed=2\nA.StartLoc=0\tB.StartLoc=0\tC.StartLoc=0\nA.StartTime=0\tB.StartTime=0\tC.StartTime=0\nA.Circle=1\tB.Circle=0\tB.Circle=0\nStayTime=0\n\n");
	printf("̽���λ��Ĭ����ÿ�ι����������\n\n"); 

	printf("\n�����Ƿ��޸�Ĭ��ֵ�����ǻظ�1����ظ�0��");
	m=0;
 	fflush(stdin);//��ջ��� 
	m=scanf("%d",&r);
	while(((r!=1)&&(r!=0))||m==0)
	{	printf("������0��1:");
	    fflush(stdin);//��ջ��� 
		m=scanf("%d",&r);
	    
	}
	if(r==1)//����û�Ҫ�������� 

	{	
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
    printf("[A Speed](1-5֮������):");
    fflush(stdin);//��ջ��� 
	m=scanf("%d",&A.speed);
	while((A.speed>5)||(A.speed<1)||m==0)
	{		printf("��ע���ٶȷ�Χ�ޣ�\n");
			
			printf("[A Speed](1-5֮������):");
			fflush(stdin);
			m=scanf("%d",&A.speed);	
	}
	
	printf("\n");
	printf("[B Speed](1-5֮������):");
	fflush(stdin);//��ջ��� 
	m=scanf("%d",&B.speed);
	while((B.speed>5)||(B.speed<1)||m==0)
	{		printf("��ע���ٶȷ�Χ�ޣ�\n");
			printf("[B Speed](1-5֮������):");
			fflush(stdin);
			m=scanf("%d",&B.speed);
	}
	
	printf("\n");
	printf("[C Speed](1-7֮������):");
	fflush(stdin);//��ջ��� 
	m=scanf("%d",&C.speed);
	while((C.speed>7)||(C.speed<1)||m==0)
	{		printf("��ע���ٶȷ�Χ�ޣ�\n");
			printf("[C Speed](1-7����):");
			fflush(stdin);
			m=scanf("%d",&C.speed);
	}

	printf("\n");
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
	printf("[A StartPoint](0-29������) :");
	fflush(stdin);//��ջ��� 
	m=scanf("%d",&A.startLoc);
	while(A.startLoc>29||A.startLoc<0||m==0)
	{	printf("��ע����ʼ�㷶Χ��~\n");
		printf("[A StartPoint](0-29������) :");
		fflush(stdin);
		m=scanf("%d",&A.startLoc);
	}
	printf("\n");
	if((A.startLoc>10)&&(A.startLoc<16))
		printf("B��ʼ�㲻����5-11,�������������ޣ�\n"); 
	printf("[B StartPoint](0-29������) :");
	fflush(stdin);//��ջ��� 
	m=scanf("%d",&B.startLoc);
	if((A.startLoc>10)&&(A.startLoc<16))
	{	while((B.startLoc>=5&&B.startLoc<=11)||m==0)
			{	printf("����Ҫ����ˣ���Գ���Ա�Ѻã�΢Ц��\n");
				printf("[B StartPoint](0-29������) :");
				fflush(stdin);
				m=scanf("%d",&B.startLoc);
				
			}
	}
		while(B.startLoc>29||B.startLoc<0||m==0)
	{	printf("��ע����ʼ�㷶Χ��~\n");
		printf("[B StartPoint](0-29������) :");
		fflush(stdin);
		m=scanf("%d",&B.startLoc);
	}
	printf("\n");
		if((A.startLoc>18)&&(A.startLoc<26))
		printf("C��ʼ�㲻����12-20,�������������ޣ�\n");
	printf("[C StartPoint](0-23������) :");
	fflush(stdin);//��ջ��� 
	m=scanf("%d",&C.startLoc);
	if((A.startLoc>18)&&(A.startLoc<26))
	{	while((C.startLoc>=12&&C.startLoc<=20)||m==0)
			{	printf("����Ҫ����ˣ���Գ���Ա�Ѻã�΢Ц��\n");
				printf("[C StartPoint](0-29������) :");
				fflush(stdin);
				m=scanf("%d",&C.startLoc);
				
			}
	} 
	while(C.startLoc>23||C.startLoc<0||m==0)
	{	printf("��ע����ʼ�㷶Χ��~\n");
		printf("[C StartPoint](0-23������) :");
		fflush(stdin);
		m=scanf("%d",&C.startLoc);
	}
	printf("\n");
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
	//̽���λ��Ĭ�ϡ� 
	return 1;}
	if(r==0)//����û����������� 
		return 0;
	
}


void OriginalTrain()//��ʼ�������� 
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

void OriginalTrack()//��ʼ��������� 
{
	
	
	a.lenth=10;
	b.lenth=7;
	c.lenth=7;
	a.wide=5;
	b.wide=10;
	c.wide=5;
	
}

