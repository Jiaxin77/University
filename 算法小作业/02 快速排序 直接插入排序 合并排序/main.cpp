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

	//平均情况
	cout<<"平均情况"<<endl;
	*afile<<"平均情况"<<endl;
	Rands(a,size);
	copy1(b,a,size);
	//快速排序 
	cout<<"快速排序"<<endl;
	*afile<<"快速排序"<<endl;

	for(count=1;count<=10;count++)//10次 求平均
	{	copy1(b,a,size); 
		ComCount=0,MoveCount=0; 
		start=clock();
		QuickSort1(b,1,size,ComCount,MoveCount);
		stop=clock();
	
		duration[count]=((double)(stop-start))/CLK_TCK; 
		cout<<"腾挪次数："<<MoveCount<<endl<<"比较次数"<<ComCount<<endl;
		cout<<"第"<<count<<"次时间为"<<duration[count]<<"秒"<<endl; 
		*afile<<"腾挪次数："<<MoveCount<<endl<<"比较次数"<<ComCount<<endl;
		*afile<<"第"<<count<<"次时间为"<<duration[count]<<"秒"<<endl; 
		//正确性 需要生成数据时 
		
	/*	cout<<"原数据："<<endl; 
		for(k=1;k<=size;k++)
		{	cout<<a[k]<<" ";
		 } 
		cout<<endl<<"排序之后的："<<endl;
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
	cout<<"快速排序在数据规模为"<<size<<"时的平均时间为"<<FinalDuration<<"秒"<<endl; 
	*afile<<"快速排序在数据规模为"<<size<<"时的平均时间为"<<FinalDuration<<"秒"<<endl;
	
	cout<<endl<<endl<<endl;
	*afile<<endl<<endl<<endl;
	
	//合并排序 
	
	for(k=0;k<=size;k++)
	{	b[k]=0;
	}//清空排序后的数组 
	copy1(b,a,size);
	ComCount=0;MoveCount=0;
	
	cout<<"合并排序"<<endl;
	*afile<<"合并排序"<<endl;
	
	for(count=1;count<=10;count++)//10次 求平均
	{ 	copy1(b,a,size);
		ComCount=0,MoveCount=0; 
		start=clock();
		
		MergeSort(b,size+1,ComCount,MoveCount);//也可以多做几次？
		stop=clock();
	
		duration[count]=((double)(stop-start))/CLK_TCK; 
		cout<<"腾挪次数："<<MoveCount<<endl<<"比较次数"<<ComCount<<endl;
		cout<<"第"<<count<<"次时间为"<<duration[count]<<"秒"<<endl; 
		*afile<<"腾挪次数："<<MoveCount<<endl<<"比较次数"<<ComCount<<endl;
		*afile<<"第"<<count<<"次时间为"<<duration[count]<<"秒"<<endl; 
		//正确性
	/*	
		cout<<"原数据："<<endl; 
		for(k=1;k<=size;k++)
		{	cout<<a[k]<<" ";
		 } 
		cout<<endl<<"排序之后的："<<endl;
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
	cout<<"合并排序在数据规模为"<<size<<"时的平均时间为"<<FinalDuration<<"秒"<<endl; 
	*afile<<"合并排序在数据规模为"<<size<<"时的平均时间为"<<FinalDuration<<"秒"<<endl;
	
	cout<<endl<<endl<<endl;
	*afile<<endl<<endl<<endl;
	
	
	//插入排序 
	for(k=0;k<=size;k++)
	{	b[k]=0;
	}//清空排序后的数组 
	copy1(b,a,size);
	ComCount=0;MoveCount=0;
	 
	cout<<"插入排序"<<endl;
	*afile<<"插入排序"<<endl;
	
	for(count=1;count<=10;count++)//10次 求平均
	{ 	ComCount=0,MoveCount=0; 
		copy1(b,a,size);
		start=clock();
		insertsort(b,size,ComCount,MoveCount);//也可以多做几次？ 
		stop=clock();
	
		duration[count]=((double)(stop-start))/CLK_TCK; 
		cout<<"腾挪次数："<<MoveCount<<endl<<"比较次数"<<ComCount<<endl;
		cout<<"第"<<count<<"次时间为"<<duration[count]<<"秒"<<endl; 
		*afile<<"腾挪次数："<<MoveCount<<endl<<"比较次数"<<ComCount<<endl;
		*afile<<"第"<<count<<"次时间为"<<duration[count]<<"秒"<<endl; 
		//正确性
		/*
		cout<<"原数据："<<endl; 
		for(k=1;k<=size;k++)
		{	cout<<a[k]<<" ";
		 } 
		cout<<endl<<"排序之后的："<<endl;
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
	cout<<"插入排序在数据规模为"<<size<<"时的平均时间为"<<FinalDuration<<"秒"<<endl; 
	*afile<<"插入排序在数据规模为"<<size<<"时的平均时间为"<<FinalDuration<<"秒"<<endl;
	
	cout<<endl<<endl<<endl;
	*afile<<endl<<endl<<endl;
	

	//最好情况 
	cout<<"最好情况"<<endl;
	*afile<<"最好情况"<<endl;
	
	
	//快速排序 
	//快速排序最好情况为随机数列，每次几乎平均划分 通过随机取划分点 
	for(k=0;k<=size;k++)
	{	b[k]=0;
		a[k]=0;
	}
	Rands(a,size); 
	copy1(b,a,size);
	cout<<"快速排序"<<endl;
	*afile<<"快速排序"<<endl;
	
	for(count=1;count<=10;count++)//10次 求平均
	{ 	ComCount=0,MoveCount=0; 
		copy1(b,a,size);
		start=clock();	
		QuickSort2(b,1,size,ComCount,MoveCount);
		stop=clock();
	
		duration[count]=((double)(stop-start))/CLK_TCK; 
		cout<<"腾挪次数："<<MoveCount<<endl<<"比较次数"<<ComCount<<endl;
		cout<<"第"<<count<<"次时间为"<<duration[count]<<"秒"<<endl; 
		*afile<<"腾挪次数："<<MoveCount<<endl<<"比较次数"<<ComCount<<endl;
		*afile<<"第"<<count<<"次时间为"<<duration[count]<<"秒"<<endl; 
		//正确性
	
		/*
		cout<<"原数据："<<endl; 
		for(k=1;k<=size;k++)
		{	cout<<a[k]<<" ";
		 } 
		cout<<endl<<"排序之后的："<<endl;
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

	cout<<"快速排序在数据规模为"<<size<<"时的最好时间为"<<FinalDuration<<"秒"<<endl; 
	*afile<<"快速排序在数据规模为"<<size<<"时的最好时间为"<<FinalDuration<<"秒"<<endl;
	
	cout<<endl<<endl<<endl;
	*afile<<endl<<endl<<endl;
	
	//合并排序  最好情况和平均一样，所以可以取多次排序的时间最小值得到 
	
	for(k=0;k<=size;k++)
	{	b[k]=0;
		a[k]=0;
	}
	Rands(a,size);
	copy1(b,a,size);
	ComCount=0;MoveCount=0;
	
	cout<<"合并排序"<<endl;
	*afile<<"合并排序"<<endl;
	
	for(count=1;count<=10;count++)//10次 求平均
	{ 	ComCount=0,MoveCount=0; 
			copy1(b,a,size);
		start=clock();			
		MergeSort(b,size+1,ComCount,MoveCount);
		stop=clock();
	
		duration[count]=((double)(stop-start))/CLK_TCK; 
		cout<<"腾挪次数："<<MoveCount<<endl<<"比较次数"<<ComCount<<endl;
		cout<<"第"<<count<<"次时间为"<<duration[count]<<"秒"<<endl; 
		*afile<<"腾挪次数："<<MoveCount<<endl<<"比较次数"<<ComCount<<endl;
		*afile<<"第"<<count<<"次时间为"<<duration[count]<<"秒"<<endl; 
		//正确性
		/*
		cout<<"原数据："<<endl; 
		for(k=1;k<=size;k++)
		{	cout<<a[k]<<" ";
		 } 
		cout<<endl<<"排序之后的："<<endl;
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
	cout<<"合并排序在数据规模为"<<size<<"时的最好时间为"<<FinalDuration<<"秒"<<endl; 
	*afile<<"合并排序在数据规模为"<<size<<"时的最好时间为"<<FinalDuration<<"秒"<<endl;
	
	cout<<endl<<endl<<endl;
	*afile<<endl<<endl<<endl;
	
	
	//插入排序  //最好为升序序列 
	for(k=0;k<=size;k++)
	{	b[k]=0;
		a[k]=0;
	}//清空排序后的数组 

	UpSorted(a,size); 
	copy1(b,a,size);
	ComCount=0;MoveCount=0;
	 
	cout<<"插入排序"<<endl;
	*afile<<"插入排序"<<endl;
	
	for(count=1;count<=10;count++)//10次 求平均
	{ 	ComCount=0,MoveCount=0; 
		copy1(b,a,size);
		start=clock();			
		insertsort(b,size+1,ComCount,MoveCount);
		stop=clock();
	
		duration[count]=((double)(stop-start))/CLK_TCK; 
		cout<<"腾挪次数："<<MoveCount<<endl<<"比较次数"<<ComCount<<endl;
		cout<<"第"<<count<<"次时间为"<<duration[count]<<"秒"<<endl; 
		*afile<<"腾挪次数："<<MoveCount<<endl<<"比较次数"<<ComCount<<endl;
		*afile<<"第"<<count<<"次时间为"<<duration[count]<<"秒"<<endl; 
		//正确性
		/*
		cout<<"原数据："<<endl; 
		for(k=1;k<=size;k++)
		{	cout<<a[k]<<" ";
		 } 
		cout<<endl<<"排序之后的："<<endl;
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

	cout<<"插入排序在数据规模为"<<size<<"时的最好时间为"<<FinalDuration<<"秒"<<endl; 
	*afile<<"插入排序在数据规模为"<<size<<"时的最好时间为"<<FinalDuration<<"秒"<<endl;
	
	cout<<endl<<endl<<endl;
	*afile<<endl<<endl<<endl;
	
	
	cout<<"最坏情况"<<endl;
	*afile<<"最坏情况"<<endl;
	
	
	//快速排序 
	//快速排序最坏为升序/降序已排列好的
	for(k=0;k<=size;k++)
	{	b[k]=0;
		a[k]=0;
	}
	UpSorted(a,size);
	copy1(b,a,size);
	cout<<"快速排序"<<endl;
	*afile<<"快速排序"<<endl;
	
	for(count=1;count<=10;count++)//10次 求平均
	{ 	ComCount=0,MoveCount=0; 
		copy1(b,a,size);
		start=clock();
		QuickSort1(b,1,size,ComCount,MoveCount);
		stop=clock();
	
		duration[count]=((double)(stop-start))/CLK_TCK; 
		cout<<"腾挪次数："<<MoveCount<<endl<<"比较次数"<<ComCount<<endl;
		cout<<"第"<<count<<"次时间为"<<duration[count]<<"秒"<<endl; 
		*afile<<"腾挪次数："<<MoveCount<<endl<<"比较次数"<<ComCount<<endl;
		*afile<<"第"<<count<<"次时间为"<<duration[count]<<"秒"<<endl; 
		//正确性
	
		/* 
		cout<<"原数据："<<endl; 
		for(k=1;k<=size;k++)
		{	cout<<a[k]<<" ";
		 } 
		cout<<endl<<"排序之后的："<<endl;
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

	cout<<"快速排序在数据规模为"<<size<<"时的最坏时间为"<<FinalDuration<<"秒"<<endl; 
	*afile<<"快速排序在数据规模为"<<size<<"时的最坏时间为"<<FinalDuration<<"秒"<<endl;
	
	cout<<endl<<endl<<endl;
	*afile<<endl<<endl<<endl;
	
	//合并排序  最坏情况和平均一样，所以可以取多次排序的时间最大值得到 
	
	for(k=0;k<=size;k++)
	{	b[k]=0;
		a[k]=0;
	}
	Rands(a,size);
	copy1(b,a,size);
	ComCount=0;MoveCount=0;
	
	cout<<"合并排序"<<endl;
	*afile<<"合并排序"<<endl;
	
	for(count=1;count<=10;count++)//10次 求平均
	{ 	ComCount=0,MoveCount=0; 
		copy1(b,a,size);
		start=clock();	
		MergeSort(b,size+1,ComCount,MoveCount);
		stop=clock();
	
		duration[count]=((double)(stop-start))/CLK_TCK; 
		cout<<"腾挪次数："<<MoveCount<<endl<<"比较次数"<<ComCount<<endl;
		cout<<"第"<<count<<"次时间为"<<duration[count]<<"秒"<<endl; 
		*afile<<"腾挪次数："<<MoveCount<<endl<<"比较次数"<<ComCount<<endl;
		*afile<<"第"<<count<<"次时间为"<<duration[count]<<"秒"<<endl; 
		//正确性
		/*
		cout<<"原数据："<<endl; 
		for(k=1;k<=size;k++)
		{	cout<<a[k]<<" ";
		 } 
		cout<<endl<<"排序之后的："<<endl;
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
	cout<<"合并排序在数据规模为"<<size<<"时的最坏时间为"<<FinalDuration<<"秒"<<endl; 
	*afile<<"合并排序在数据规模为"<<size<<"时的最坏时间为"<<FinalDuration<<"秒"<<endl;
	
	cout<<endl<<endl<<endl;
	*afile<<endl<<endl<<endl;
	
	
	//插入排序  //最坏为降序序列 
	for(k=0;k<=size;k++)
	{	b[k]=0;
		a[k]=0;
	}//清空排序后的数组 

	DownSorted(a,size); 
	copy1(b,a,size);
	ComCount=0;MoveCount=0;
	 
	cout<<"插入排序"<<endl;
	*afile<<"插入排序"<<endl;
	
	for(count=1;count<=10;count++)//10次 求平均
	{ 	ComCount=0,MoveCount=0; 
		copy1(b,a,size);
		start=clock();
		insertsort(b,size+1,ComCount,MoveCount);
		stop=clock();
	
		duration[count]=((double)(stop-start))/CLK_TCK; 
		cout<<"腾挪次数："<<MoveCount<<endl<<"比较次数"<<ComCount<<endl;
		cout<<"第"<<count<<"次时间为"<<duration[count]<<"秒"<<endl; 
		*afile<<"腾挪次数："<<MoveCount<<endl<<"比较次数"<<ComCount<<endl;
		*afile<<"第"<<count<<"次时间为"<<duration[count]<<"秒"<<endl; 
		//正确性
		/*
		cout<<"原数据："<<endl; 
		for(k=1;k<=size;k++)
		{	cout<<a[k]<<" ";
		 } 
		cout<<endl<<"排序之后的："<<endl;
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

	cout<<"插入排序在数据规模为"<<size<<"时的最坏时间为"<<FinalDuration<<"秒"<<endl; 
	*afile<<"插入排序在数据规模为"<<size<<"时的最坏时间为"<<FinalDuration<<"秒"<<endl;
	
	cout<<endl<<endl<<endl;
	*afile<<endl<<endl<<endl;
	
	
	afile->close();
	
	system("pause");
	return 0; 
}
