#include<iostream>
#include<time.h>

const int REPEAT = 1000;//自己改 
 
using namespace std; 
//数组是从1开始存的！！！ 

//分治法
 int firstSolution(int A[],int top,int nf,int n,int sf,int sum[]) //
 /*A[]-金字塔原数组，top-当前处于塔顶元素的序号，nf-当前top元素所处层数，n-金字塔元素总数，sf-金字塔总层数，sum-当前求得和*/
 {
 	int left,right;
 	if(top>=n-sf+1&&top<=n)//top元素位于最后一行
	 	return(sum[top]=A[top]);
	else
	{
		left=firstSolution(A,top+nf,nf+1,n,sf,sum);
		right=firstSolution(A,top+nf+1,nf+1,n,sf,sum);
	    //和等于top处元素和左右之间大的那个相加
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
 
 //打印金字塔 
 void PrintfPy(int A[],int total,int sf)//total为元素总数，sf为总层数 
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
 
 
 //消除递归 
  int secondSolution(int A[],int n,int sf,int sum[]) //消除递归，从底往上走 
  //*A[]-金字塔原数组，n-金字塔总元素总数，sf-金字塔总层数，sum-当前求得和*/
{
  	int i;
  	int nf;//当前层数 
  	
  	for(i=(sf*(sf-1)/2)+1;i<=n;i++)//最后一行
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
			nf--;//到了每行开头，则行数-1，因为下一个元素就是上一行的了 
		}
	 } 
  	return sum[1];
  	
}
  //去掉sum数组 
  int thirdSolution(int A[],int n,int sf)//直接存A数组中，不用sum数组 
{
  	int i,nf;
  	nf=sf-1; 
  	if(sf==1)//只有一层 
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
				nf--;//到了每行开头，则行数-1，因为下一个元素就是上一行的了 
			}
			
		}
		
	}
	return A[1]; 
} 
 
 //寻找路径 
 void findway(int sum[],int A[],int sf)
 {
	int *way;
	way=new int[sf+1];
	int k=1;
 	for(int i=1;i<=sf;i++)//i为当前层数
	 {
	 	if(sum[k+i]>=sum[k+i+1])//左边大
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
	  way[0]=A[1];//第一个必须经过
	  cout<<"路径"<<endl; 
	  for(int j=0;j<sf;j++)
	  {
	  	cout<<way[j]<<" ";
	   } 
	   cout<<endl;
 }
 
 
 main()
 {	int floor;
 
 	cout<<"重复次数"<<REPEAT<<endl;
 	cout<<"请您输入金字塔数字层数"<<endl;
 	cin>>floor;
 	int total;
 	total=floor*(floor+1)/2;//根据层数算出总数 
 	int *AT;//原金字塔 
 	AT=new int [total+1];
 	int *Sum;
 	Sum=new int [total+1];
 	clock_t start,finish;
 	float duration;
 	

	
	for(int i=1;i<=total;i++)
	{
		AT[i]=i;//金字塔为从1到所有元素依次顺序序列 
		Sum[i]=0;//初始化 
	 } 

	// PrintfPy(AT,total,floor);//打印金字塔 
	 cout<<endl;
	 int FinalSum=0;
	 cout<<"分治法"<<endl;
	 
	 start=clock();
	 for(int n=0;n<REPEAT;n++)//因为每次都要重新赋下值，所以测出的时间是相对的 
	 {
	 		for(int i=1;i<=total;i++)
			{
				Sum[i]=0;//初始化 
	 		} 

		 FinalSum=firstSolution(AT,1,1,total,floor,Sum);
	 }
	 finish=clock();
	 duration=(finish-start)/1000;
	 cout<<"所用时间:"<<duration<<endl;
	 
	// findway(Sum,AT,floor);
	 cout<<FinalSum<<endl;
	 
	 FinalSum=0;
	 cout<<"消除递归"<<endl;
	 for(int i=1;i<=total;i++)
	{
		AT[i]=i;//金字塔为从1到所有元素依次顺序序列 
		Sum[i]=0;//初始化 
	 } 
	
	start=clock();
	 for(int n=0;n<REPEAT;n++)//因为每次都要重新赋下值，所以测出的时间是相对的 
	 {
	 		for(int i=1;i<=total;i++)
			{
				Sum[i]=0;//初始化 
	 		} 

		 FinalSum=secondSolution(AT,total,floor,Sum);
	 }
	 finish=clock();
	 duration=finish-start;
	 cout<<"所用时间:"<<duration<<endl;

	 //findway(Sum,AT,floor);
	 cout<<FinalSum<<endl;
	 
	 FinalSum=0;
	 cout<<"消除递归节省空间"<<endl;
/*	 for(int i=1;i<=total;i++)
	{
		AT[i]=i;//金字塔为从1到所有元素依次顺序序列 
	 } 
*/	 
	start=clock();
	 for(int n=0;n<REPEAT;n++)//因为每次都要重新赋下值，所以测出的时间是相对的 
	 {
	 		for(int i=1;i<=total;i++)
			{
				AT[i]=i;
				//初始化 
	 		} 
		FinalSum=thirdSolution(AT,total,floor); 
		 
	 }
	 finish=clock();
	 duration=finish-start;//因为后两个算法差距会比较小，所以以ms为单位 
	 cout<<"所用时间:"<<duration<<endl;

	 
//	 findway(Sum,AT,floor);
	 cout<<FinalSum<<endl;
	 
	 system("pause");
	 return 0;
 }
 
