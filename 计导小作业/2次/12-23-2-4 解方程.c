#include<stdio.h>
#include<stdlib.h>
#include<math.h>
main()
{
	printf("Please input three float numbers:");
	float a,b,c,f1,f2,y,x,x1,x2;
	scanf("%f %f %f",&a,&b,&c);
	if(a==0)/*非一元二次方程*/
	{printf("The equation is not quadratic.");
	}
	else{
		f1=b*b;
		f2=4*a*c; 
		if((f1-f2)<0)/*判别式小于零*/ 
		{
		y=sqrt(f2-f1);
		x1=(-b)/(2*a);/*算实部*/
		x2=y/(2*a);/*算虚部*/ 
	
	printf("The equation has two complex roots:%.4f+%.4fi and %.4f-%.4fi",x1,x2,x1,x2);//输出虚数根

		}
		else{
		
		if(fabs(f1-f2)<=1e-6)/*判别式等于零*/ 
		{
		x=(-b)/(2*a);
	
		printf("The equation has two equal roots:%.4f",x);/*输出相等根*/ 
	
	}
	else{/*判别式大于零*/ 
		y=sqrt(f1-f2);
		x1=((-b)+y)/(2*a);
		x2=((-b)-y)/(2*a);
	printf("The equation has two distinct real roots:%.4f and %.4f",x1,x2);/*输出实数根*/ 
	}
	}	}
	system("pause");
return 0;
 } 
