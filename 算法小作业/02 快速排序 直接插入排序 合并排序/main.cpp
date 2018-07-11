#include<iostream>
#include<stdlib.h>
#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>
#include<time.h> 


#include"data.h"
#include"Insert.h"
#include"Merge.h"
#include"QuickSort.h"

using namespace std;

main()
{	clock_t start,stop;
	double duration[20];
	
	ofstream *afile;
	string fileName = "Result.txt";        
	afile = new ofstream(fileName.c_str(),ios::out|ios::app);	
	long int ComCount=0,MoveCount=0; 
	const int size=1000;

	int a[size+2];
	int b[size+2];
	int count;
	int k;
	double FinalDuration=0;

	//ƽ�����
	cout<<"ƽ�����"<<endl;
	*afile<<"ƽ�����"<<endl;
	Rands(a,size);
	copy1(b,a,size);
	//�������� 
	cout<<"��������"<<endl;
	*afile<<"��������"<<endl;

	for(count=1;count<=10;count++)//10�� ��ƽ��
	{	copy1(b,a,size); 
		ComCount=0,MoveCount=0; 
		start=clock();
		QuickSort1(b,1,size,ComCount,MoveCount);
		stop=clock();
	
		duration[count]=((double)(stop-start))/CLK_TCK; 
		cout<<"��Ų������"<<MoveCount<<endl<<"�Ƚϴ���"<<ComCount<<endl;
		cout<<"��"<<count<<"��ʱ��Ϊ"<<duration[count]<<"��"<<endl; 
		*afile<<"��Ų������"<<MoveCount<<endl<<"�Ƚϴ���"<<ComCount<<endl;
		*afile<<"��"<<count<<"��ʱ��Ϊ"<<duration[count]<<"��"<<endl; 
		//��ȷ�� ��Ҫ��������ʱ 
		
	/*	cout<<"ԭ���ݣ�"<<endl; 
		for(k=1;k<=size;k++)
		{	cout<<a[k]<<" ";
		 } 
		cout<<endl<<"����֮��ģ�"<<endl;
		for(k=1;k<=size;k++)
		{	cout<<b[k]<<" ";
		}
		cout<<endl;
		*/
	}
	
	FinalDuration=0;
	for(count=1;count<=10;count++)
	{	FinalDuration=FinalDuration+duration[count];
	}
	FinalDuration=FinalDuration/10;
	cout<<"�������������ݹ�ģΪ"<<size<<"ʱ��ƽ��ʱ��Ϊ"<<FinalDuration<<"��"<<endl; 
	*afile<<"�������������ݹ�ģΪ"<<size<<"ʱ��ƽ��ʱ��Ϊ"<<FinalDuration<<"��"<<endl;
	
	cout<<endl<<endl<<endl;
	*afile<<endl<<endl<<endl;
	
	//�ϲ����� 
	
	for(k=0;k<=size;k++)
	{	b[k]=0;
	}//������������� 
	copy1(b,a,size);
	ComCount=0;MoveCount=0;
	
	cout<<"�ϲ�����"<<endl;
	*afile<<"�ϲ�����"<<endl;
	
	for(count=1;count<=10;count++)//10�� ��ƽ��
	{ 	copy1(b,a,size);
		ComCount=0,MoveCount=0; 
		start=clock();
		
		MergeSort(b,size+1,ComCount,MoveCount);//Ҳ���Զ������Σ�
		stop=clock();
	
		duration[count]=((double)(stop-start))/CLK_TCK; 
		cout<<"��Ų������"<<MoveCount<<endl<<"�Ƚϴ���"<<ComCount<<endl;
		cout<<"��"<<count<<"��ʱ��Ϊ"<<duration[count]<<"��"<<endl; 
		*afile<<"��Ų������"<<MoveCount<<endl<<"�Ƚϴ���"<<ComCount<<endl;
		*afile<<"��"<<count<<"��ʱ��Ϊ"<<duration[count]<<"��"<<endl; 
		//��ȷ��
	/*	
		cout<<"ԭ���ݣ�"<<endl; 
		for(k=1;k<=size;k++)
		{	cout<<a[k]<<" ";
		 } 
		cout<<endl<<"����֮��ģ�"<<endl;
		for(k=1;k<=size;k++)
		{	cout<<b[k]<<" ";
		}
		cout<<endl;
		*/
	}
	
	 FinalDuration=0;
	for(count=1;count<=10;count++)
	{	FinalDuration=FinalDuration+duration[count];
	}
	FinalDuration=FinalDuration/10;
	cout<<"�ϲ����������ݹ�ģΪ"<<size<<"ʱ��ƽ��ʱ��Ϊ"<<FinalDuration<<"��"<<endl; 
	*afile<<"�ϲ����������ݹ�ģΪ"<<size<<"ʱ��ƽ��ʱ��Ϊ"<<FinalDuration<<"��"<<endl;
	
	cout<<endl<<endl<<endl;
	*afile<<endl<<endl<<endl;
	
	
	//�������� 
	for(k=0;k<=size;k++)
	{	b[k]=0;
	}//������������� 
	copy1(b,a,size);
	ComCount=0;MoveCount=0;
	 
	cout<<"��������"<<endl;
	*afile<<"��������"<<endl;
	
	for(count=1;count<=10;count++)//10�� ��ƽ��
	{ 	ComCount=0,MoveCount=0; 
		copy1(b,a,size);
		start=clock();
		insertsort(b,size,ComCount,MoveCount);//Ҳ���Զ������Σ� 
		stop=clock();
	
		duration[count]=((double)(stop-start))/CLK_TCK; 
		cout<<"��Ų������"<<MoveCount<<endl<<"�Ƚϴ���"<<ComCount<<endl;
		cout<<"��"<<count<<"��ʱ��Ϊ"<<duration[count]<<"��"<<endl; 
		*afile<<"��Ų������"<<MoveCount<<endl<<"�Ƚϴ���"<<ComCount<<endl;
		*afile<<"��"<<count<<"��ʱ��Ϊ"<<duration[count]<<"��"<<endl; 
		//��ȷ��
		/*
		cout<<"ԭ���ݣ�"<<endl; 
		for(k=1;k<=size;k++)
		{	cout<<a[k]<<" ";
		 } 
		cout<<endl<<"����֮��ģ�"<<endl;
		for(k=1;k<=size;k++)
		{	cout<<b[k]<<" ";
		}
		cout<<endl;
		*/ 
	}
	FinalDuration=0;
	for(count=1;count<=10;count++)
	{	FinalDuration=FinalDuration+duration[count];
	}
	FinalDuration=FinalDuration/10;
	cout<<"�������������ݹ�ģΪ"<<size<<"ʱ��ƽ��ʱ��Ϊ"<<FinalDuration<<"��"<<endl; 
	*afile<<"�������������ݹ�ģΪ"<<size<<"ʱ��ƽ��ʱ��Ϊ"<<FinalDuration<<"��"<<endl;
	
	cout<<endl<<endl<<endl;
	*afile<<endl<<endl<<endl;
	

	//������ 
	cout<<"������"<<endl;
	*afile<<"������"<<endl;
	
	
	//�������� 
	//��������������Ϊ������У�ÿ�μ���ƽ������ ͨ�����ȡ���ֵ� 
	for(k=0;k<=size;k++)
	{	b[k]=0;
		a[k]=0;
	}
	Rands(a,size); 
	copy1(b,a,size);
	cout<<"��������"<<endl;
	*afile<<"��������"<<endl;
	
	for(count=1;count<=10;count++)//10�� ��ƽ��
	{ 	ComCount=0,MoveCount=0; 
		copy1(b,a,size);
		start=clock();	
		QuickSort2(b,1,size,ComCount,MoveCount);
		stop=clock();
	
		duration[count]=((double)(stop-start))/CLK_TCK; 
		cout<<"��Ų������"<<MoveCount<<endl<<"�Ƚϴ���"<<ComCount<<endl;
		cout<<"��"<<count<<"��ʱ��Ϊ"<<duration[count]<<"��"<<endl; 
		*afile<<"��Ų������"<<MoveCount<<endl<<"�Ƚϴ���"<<ComCount<<endl;
		*afile<<"��"<<count<<"��ʱ��Ϊ"<<duration[count]<<"��"<<endl; 
		//��ȷ��
	
		/*
		cout<<"ԭ���ݣ�"<<endl; 
		for(k=1;k<=size;k++)
		{	cout<<a[k]<<" ";
		 } 
		cout<<endl<<"����֮��ģ�"<<endl;
		for(k=1;k<=size;k++)
		{	cout<<b[k]<<" ";
		}
		cout<<endl;
		*/
	}
	
	FinalDuration=duration[1]; 
	for(count=1;count<=10;count++)
	{	if(duration[count]<FinalDuration)
			FinalDuration=duration[count];
	}

	cout<<"�������������ݹ�ģΪ"<<size<<"ʱ�����ʱ��Ϊ"<<FinalDuration<<"��"<<endl; 
	*afile<<"�������������ݹ�ģΪ"<<size<<"ʱ�����ʱ��Ϊ"<<FinalDuration<<"��"<<endl;
	
	cout<<endl<<endl<<endl;
	*afile<<endl<<endl<<endl;
	
	//�ϲ�����  ��������ƽ��һ�������Կ���ȡ��������ʱ����Сֵ�õ� 
	
	for(k=0;k<=size;k++)
	{	b[k]=0;
		a[k]=0;
	}
	Rands(a,size);
	copy1(b,a,size);
	ComCount=0;MoveCount=0;
	
	cout<<"�ϲ�����"<<endl;
	*afile<<"�ϲ�����"<<endl;
	
	for(count=1;count<=10;count++)//10�� ��ƽ��
	{ 	ComCount=0,MoveCount=0; 
			copy1(b,a,size);
		start=clock();			
		MergeSort(b,size+1,ComCount,MoveCount);
		stop=clock();
	
		duration[count]=((double)(stop-start))/CLK_TCK; 
		cout<<"��Ų������"<<MoveCount<<endl<<"�Ƚϴ���"<<ComCount<<endl;
		cout<<"��"<<count<<"��ʱ��Ϊ"<<duration[count]<<"��"<<endl; 
		*afile<<"��Ų������"<<MoveCount<<endl<<"�Ƚϴ���"<<ComCount<<endl;
		*afile<<"��"<<count<<"��ʱ��Ϊ"<<duration[count]<<"��"<<endl; 
		//��ȷ��
		/*
		cout<<"ԭ���ݣ�"<<endl; 
		for(k=1;k<=size;k++)
		{	cout<<a[k]<<" ";
		 } 
		cout<<endl<<"����֮��ģ�"<<endl;
		for(k=1;k<=size;k++)
		{	cout<<b[k]<<" ";
		}
		cout<<endl;
		*/
	}
	 
	 FinalDuration=duration[1]; 
	for(count=1;count<=10;count++)
	{	if(duration[count]<FinalDuration)
			FinalDuration=duration[count];
	}	
	cout<<"�ϲ����������ݹ�ģΪ"<<size<<"ʱ�����ʱ��Ϊ"<<FinalDuration<<"��"<<endl; 
	*afile<<"�ϲ����������ݹ�ģΪ"<<size<<"ʱ�����ʱ��Ϊ"<<FinalDuration<<"��"<<endl;
	
	cout<<endl<<endl<<endl;
	*afile<<endl<<endl<<endl;
	
	
	//��������  //���Ϊ�������� 
	for(k=0;k<=size;k++)
	{	b[k]=0;
		a[k]=0;
	}//������������� 

	UpSorted(a,size); 
	copy1(b,a,size);
	ComCount=0;MoveCount=0;
	 
	cout<<"��������"<<endl;
	*afile<<"��������"<<endl;
	
	for(count=1;count<=10;count++)//10�� ��ƽ��
	{ 	ComCount=0,MoveCount=0; 
		copy1(b,a,size);
		start=clock();			
		insertsort(b,size+1,ComCount,MoveCount);
		stop=clock();
	
		duration[count]=((double)(stop-start))/CLK_TCK; 
		cout<<"��Ų������"<<MoveCount<<endl<<"�Ƚϴ���"<<ComCount<<endl;
		cout<<"��"<<count<<"��ʱ��Ϊ"<<duration[count]<<"��"<<endl; 
		*afile<<"��Ų������"<<MoveCount<<endl<<"�Ƚϴ���"<<ComCount<<endl;
		*afile<<"��"<<count<<"��ʱ��Ϊ"<<duration[count]<<"��"<<endl; 
		//��ȷ��
		/*
		cout<<"ԭ���ݣ�"<<endl; 
		for(k=1;k<=size;k++)
		{	cout<<a[k]<<" ";
		 } 
		cout<<endl<<"����֮��ģ�"<<endl;
		for(k=1;k<=size;k++)
		{	cout<<b[k]<<" ";
		}
		cout<<endl;
		*/
	}
	 
	 FinalDuration=duration[1];
	for(count=1;count<=10;count++)
	{	if(duration[count]<FinalDuration)
			FinalDuration=duration[count];
	}	

	cout<<"�������������ݹ�ģΪ"<<size<<"ʱ�����ʱ��Ϊ"<<FinalDuration<<"��"<<endl; 
	*afile<<"�������������ݹ�ģΪ"<<size<<"ʱ�����ʱ��Ϊ"<<FinalDuration<<"��"<<endl;
	
	cout<<endl<<endl<<endl;
	*afile<<endl<<endl<<endl;
	
	
	cout<<"����"<<endl;
	*afile<<"����"<<endl;
	
	
	//�������� 
	//���������Ϊ����/���������кõ�
	for(k=0;k<=size;k++)
	{	b[k]=0;
		a[k]=0;
	}
	UpSorted(a,size);
	copy1(b,a,size);
	cout<<"��������"<<endl;
	*afile<<"��������"<<endl;
	
	for(count=1;count<=10;count++)//10�� ��ƽ��
	{ 	ComCount=0,MoveCount=0; 
		copy1(b,a,size);
		start=clock();
		QuickSort1(b,1,size,ComCount,MoveCount);
		stop=clock();
	
		duration[count]=((double)(stop-start))/CLK_TCK; 
		cout<<"��Ų������"<<MoveCount<<endl<<"�Ƚϴ���"<<ComCount<<endl;
		cout<<"��"<<count<<"��ʱ��Ϊ"<<duration[count]<<"��"<<endl; 
		*afile<<"��Ų������"<<MoveCount<<endl<<"�Ƚϴ���"<<ComCount<<endl;
		*afile<<"��"<<count<<"��ʱ��Ϊ"<<duration[count]<<"��"<<endl; 
		//��ȷ��
	
		/* 
		cout<<"ԭ���ݣ�"<<endl; 
		for(k=1;k<=size;k++)
		{	cout<<a[k]<<" ";
		 } 
		cout<<endl<<"����֮��ģ�"<<endl;
		for(k=1;k<=size;k++)
		{	cout<<b[k]<<" ";
		}
		cout<<endl;
		*/
	}
	FinalDuration=0;
	for(count=1;count<=10;count++)
	{	if(duration[count]>FinalDuration)
			FinalDuration=duration[count];
	}

	cout<<"�������������ݹ�ģΪ"<<size<<"ʱ���ʱ��Ϊ"<<FinalDuration<<"��"<<endl; 
	*afile<<"�������������ݹ�ģΪ"<<size<<"ʱ���ʱ��Ϊ"<<FinalDuration<<"��"<<endl;
	
	cout<<endl<<endl<<endl;
	*afile<<endl<<endl<<endl;
	
	//�ϲ�����  ������ƽ��һ�������Կ���ȡ��������ʱ�����ֵ�õ� 
	
	for(k=0;k<=size;k++)
	{	b[k]=0;
		a[k]=0;
	}
	Rands(a,size);
	copy1(b,a,size);
	ComCount=0;MoveCount=0;
	
	cout<<"�ϲ�����"<<endl;
	*afile<<"�ϲ�����"<<endl;
	
	for(count=1;count<=10;count++)//10�� ��ƽ��
	{ 	ComCount=0,MoveCount=0; 
		copy1(b,a,size);
		start=clock();	
		MergeSort(b,size+1,ComCount,MoveCount);
		stop=clock();
	
		duration[count]=((double)(stop-start))/CLK_TCK; 
		cout<<"��Ų������"<<MoveCount<<endl<<"�Ƚϴ���"<<ComCount<<endl;
		cout<<"��"<<count<<"��ʱ��Ϊ"<<duration[count]<<"��"<<endl; 
		*afile<<"��Ų������"<<MoveCount<<endl<<"�Ƚϴ���"<<ComCount<<endl;
		*afile<<"��"<<count<<"��ʱ��Ϊ"<<duration[count]<<"��"<<endl; 
		//��ȷ��
		/*
		cout<<"ԭ���ݣ�"<<endl; 
		for(k=1;k<=size;k++)
		{	cout<<a[k]<<" ";
		 } 
		cout<<endl<<"����֮��ģ�"<<endl;
		for(k=1;k<=size;k++)
		{	cout<<b[k]<<" ";
		}
		cout<<endl;
		*/
	}
	 FinalDuration=0;
	for(count=1;count<=10;count++)
	{	if(duration[count]>FinalDuration)
			FinalDuration=duration[count];
	}	
	cout<<"�ϲ����������ݹ�ģΪ"<<size<<"ʱ���ʱ��Ϊ"<<FinalDuration<<"��"<<endl; 
	*afile<<"�ϲ����������ݹ�ģΪ"<<size<<"ʱ���ʱ��Ϊ"<<FinalDuration<<"��"<<endl;
	
	cout<<endl<<endl<<endl;
	*afile<<endl<<endl<<endl;
	
	
	//��������  //�Ϊ�������� 
	for(k=0;k<=size;k++)
	{	b[k]=0;
		a[k]=0;
	}//������������� 

	DownSorted(a,size); 
	copy1(b,a,size);
	ComCount=0;MoveCount=0;
	 
	cout<<"��������"<<endl;
	*afile<<"��������"<<endl;
	
	for(count=1;count<=10;count++)//10�� ��ƽ��
	{ 	ComCount=0,MoveCount=0; 
		copy1(b,a,size);
		start=clock();
		insertsort(b,size+1,ComCount,MoveCount);
		stop=clock();
	
		duration[count]=((double)(stop-start))/CLK_TCK; 
		cout<<"��Ų������"<<MoveCount<<endl<<"�Ƚϴ���"<<ComCount<<endl;
		cout<<"��"<<count<<"��ʱ��Ϊ"<<duration[count]<<"��"<<endl; 
		*afile<<"��Ų������"<<MoveCount<<endl<<"�Ƚϴ���"<<ComCount<<endl;
		*afile<<"��"<<count<<"��ʱ��Ϊ"<<duration[count]<<"��"<<endl; 
		//��ȷ��
		/*
		cout<<"ԭ���ݣ�"<<endl; 
		for(k=1;k<=size;k++)
		{	cout<<a[k]<<" ";
		 } 
		cout<<endl<<"����֮��ģ�"<<endl;
		for(k=1;k<=size;k++)
		{	cout<<b[k]<<" ";
		}
		cout<<endl;
		*/
	}
	 FinalDuration=0;
	for(count=1;count<=10;count++)
	{	if(duration[count]>FinalDuration)
			FinalDuration=duration[count];
	}	

	cout<<"�������������ݹ�ģΪ"<<size<<"ʱ���ʱ��Ϊ"<<FinalDuration<<"��"<<endl; 
	*afile<<"�������������ݹ�ģΪ"<<size<<"ʱ���ʱ��Ϊ"<<FinalDuration<<"��"<<endl;
	
	cout<<endl<<endl<<endl;
	*afile<<endl<<endl<<endl;
	
	
	afile->close();
	
	system("pause");
	return 0; 
}
