#include<stdio.h>
#include<stdlib.h>
#include<math.h>
main()
{
	printf("Please input three float numbers:");
	float a,b,c,f1,f2,y,x,x1,x2;
	scanf("%f %f %f",&a,&b,&c);
	if(a==0)/*��һԪ���η���*/
	{printf("The equation is not quadratic.");
	}
	else{
		f1=b*b;
		f2=4*a*c; 
		/*��y��ʾ��ʽ*/ 
		if((f1-f2)<0)/*�б�ʽС����*/ 
		{
		y=sqrt(f2-f1);
		
		/*�����ʽ*/ 
		x1=(-b)/(2*a);
		x2=y/(2*a);
	
	printf("The equation has two complex roots:%.4f+%.4fiand%.4f-%.4fi",x1,x2,x1,x2);//�䲻�������������������� 

		}
		else{
		
		if(fabs(f1-f2)<=1e-6)/*�б�ʽ������*/ 
		{
		x=(-b)/(2*a);
	
		printf("The equation has two equal roots:%.4f",x);/*�����ȸ�*/ 
	
	}
	else{/*�б�ʽ������*/ 
		y=sqrt(f1-f2);
		x1=((-b)+y)/(2*a);
		x2=((-b)-y)/(2*a);
	printf("The equation has two distinct real roots:%.4fand%.4f",x1,x2);
	}
	}	}system("pause");
return 0;
 } 
