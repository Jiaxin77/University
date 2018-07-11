#include<iostream>
#include<time.h>

const int REPEAT = 1000;//�Լ��� 
 
using namespace std; 
//�����Ǵ�1��ʼ��ģ����� 

//���η�
 int firstSolution(int A[],int top,int nf,int n,int sf,int sum[]) //
 /*A[]-������ԭ���飬top-��ǰ��������Ԫ�ص���ţ�nf-��ǰtopԪ������������n-������Ԫ��������sf-�������ܲ�����sum-��ǰ��ú�*/
 {
 	int left,right;
 	if(top>=n-sf+1&&top<=n)//topԪ��λ�����һ��
	 	return(sum[top]=A[top]);
	else
	{
		left=firstSolution(A,top+nf,nf+1,n,sf,sum);
		right=firstSolution(A,top+nf+1,nf+1,n,sf,sum);
	    //�͵���top��Ԫ�غ�����֮�����Ǹ����
	 	if(left>right)
	 	{
	 		return(sum[top]=left+A[top]); 
		 }
		else
		{
			return(sum[top]=right+A[top]);
		}
	 }
 } 
 
 //��ӡ������ 
 void PrintfPy(int A[],int total,int sf)//totalΪԪ��������sfΪ�ܲ��� 
 {
 
 	int n,i,j,k=0;
 	int m;
 	int o=sf;
 	cout<<endl; 
 	for(n=1,i=1;n<=total&&i<=total;i++,o--)
 	{
 		for(m=o;m!=0;--m)
 			{
 				cout<<" ";
			 }
		for(j=1;j<=i;j++,n++)
		{
			cout<<A[n]<<" ";
		}
		cout<<endl;
		k++;
	 }
//	 cout<<k<<endl;
  } 
 
 
 //�����ݹ� 
  int secondSolution(int A[],int n,int sf,int sum[]) //�����ݹ飬�ӵ������� 
  //*A[]-������ԭ���飬n-��������Ԫ��������sf-�������ܲ�����sum-��ǰ��ú�*/
{
  	int i;
  	int nf;//��ǰ���� 
  	
  	for(i=(sf*(sf-1)/2)+1;i<=n;i++)//���һ��
	  {
	  	sum[i]=A[i];
	  }
	  nf=sf-1;
	for(i=sf*(sf-1)/2;i>=1;i--)
	{
		if(sum[i+nf]>=sum[i+nf+1])
		{
			sum[i]=A[i]+sum[i+nf];
		}
		else
		{
			sum[i]=A[i]+sum[i+nf+1];
		}
		
		if(i==(nf*(nf-1)/2)+1)
		{
			nf--;//����ÿ�п�ͷ��������-1����Ϊ��һ��Ԫ�ؾ�����һ�е��� 
		}
	 } 
  	return sum[1];
  	
}
  //ȥ��sum���� 
  int thirdSolution(int A[],int n,int sf)//ֱ�Ӵ�A�����У�����sum���� 
{
  	int i,nf;
  	nf=sf-1; 
  	if(sf==1)//ֻ��һ�� 
  	{
  		return A[1];
	  }
	  
	else
	{
		for(i=n-sf;i>=1;i--)
		{
			if(A[i+nf]>=A[i+nf+1])
			{
				A[i]=A[i]+A[i+nf];
			}
			else
			{
				A[i]=A[i]+A[i+nf+1];
			}
			if(i==(nf*(nf-1)/2)+1)
			{
				nf--;//����ÿ�п�ͷ��������-1����Ϊ��һ��Ԫ�ؾ�����һ�е��� 
			}
			
		}
		
	}
	return A[1]; 
} 
 
 //Ѱ��·�� 
 void findway(int sum[],int A[],int sf)
 {
	int *way;
	way=new int[sf+1];
	int k=1;
 	for(int i=1;i<=sf;i++)//iΪ��ǰ����
	 {
	 	if(sum[k+i]>=sum[k+i+1])//��ߴ�
		 {
		 	way[i]=A[k+i];
		 	k+=i;
		 }
		else
		{
			way[i]=A[k+i+1];
			k+=i+1;
		}
		  
	  } 
	  way[0]=A[1];//��һ�����뾭��
	  cout<<"·��"<<endl; 
	  for(int j=0;j<sf;j++)
	  {
	  	cout<<way[j]<<" ";
	   } 
	   cout<<endl;
 }
 
 
 main()
 {	int floor;
 
 	cout<<"�ظ�����"<<REPEAT<<endl;
 	cout<<"����������������ֲ���"<<endl;
 	cin>>floor;
 	int total;
 	total=floor*(floor+1)/2;//���ݲ���������� 
 	int *AT;//ԭ������ 
 	AT=new int [total+1];
 	int *Sum;
 	Sum=new int [total+1];
 	clock_t start,finish;
 	float duration;
 	

	
	for(int i=1;i<=total;i++)
	{
		AT[i]=i;//������Ϊ��1������Ԫ������˳������ 
		Sum[i]=0;//��ʼ�� 
	 } 

	// PrintfPy(AT,total,floor);//��ӡ������ 
	 cout<<endl;
	 int FinalSum=0;
	 cout<<"���η�"<<endl;
	 
	 start=clock();
	 for(int n=0;n<REPEAT;n++)//��Ϊÿ�ζ�Ҫ���¸���ֵ�����Բ����ʱ������Ե� 
	 {
	 		for(int i=1;i<=total;i++)
			{
				Sum[i]=0;//��ʼ�� 
	 		} 

		 FinalSum=firstSolution(AT,1,1,total,floor,Sum);
	 }
	 finish=clock();
	 duration=(finish-start)/1000;
	 cout<<"����ʱ��:"<<duration<<endl;
	 
	// findway(Sum,AT,floor);
	 cout<<FinalSum<<endl;
	 
	 FinalSum=0;
	 cout<<"�����ݹ�"<<endl;
	 for(int i=1;i<=total;i++)
	{
		AT[i]=i;//������Ϊ��1������Ԫ������˳������ 
		Sum[i]=0;//��ʼ�� 
	 } 
	
	start=clock();
	 for(int n=0;n<REPEAT;n++)//��Ϊÿ�ζ�Ҫ���¸���ֵ�����Բ����ʱ������Ե� 
	 {
	 		for(int i=1;i<=total;i++)
			{
				Sum[i]=0;//��ʼ�� 
	 		} 

		 FinalSum=secondSolution(AT,total,floor,Sum);
	 }
	 finish=clock();
	 duration=finish-start;
	 cout<<"����ʱ��:"<<duration<<endl;

	 //findway(Sum,AT,floor);
	 cout<<FinalSum<<endl;
	 
	 FinalSum=0;
	 cout<<"�����ݹ��ʡ�ռ�"<<endl;
/*	 for(int i=1;i<=total;i++)
	{
		AT[i]=i;//������Ϊ��1������Ԫ������˳������ 
	 } 
*/	 
	start=clock();
	 for(int n=0;n<REPEAT;n++)//��Ϊÿ�ζ�Ҫ���¸���ֵ�����Բ����ʱ������Ե� 
	 {
	 		for(int i=1;i<=total;i++)
			{
				AT[i]=i;
				//��ʼ�� 
	 		} 
		FinalSum=thirdSolution(AT,total,floor); 
		 
	 }
	 finish=clock();
	 duration=finish-start;//��Ϊ�������㷨����Ƚ�С��������msΪ��λ 
	 cout<<"����ʱ��:"<<duration<<endl;

	 
//	 findway(Sum,AT,floor);
	 cout<<FinalSum<<endl;
	 
	 system("pause");
	 return 0;
 }
 
