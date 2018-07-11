import java.util.*;
import java.math.*;
public class page_re {
	private static int frame_size;
	private static int process_size;
	public static void main(String []args)
	{	Scanner sc=new Scanner(System.in);
		System.out.println("please input the frame number:");
		frame_size=sc.nextInt();
		System.out.println("please input the process number:");
		process_size=sc.nextInt();
		
		frame[] frque=new frame[frame_size];//盛放每次替换好的帧序列
		
		int[] proque=new int[process_size];//进程序列
		int[][]result=new int[process_size][frame_size];//结果表格
		//initial
		for(int i=0;i<frame_size;i++)//对象数组初始化
		{
			frque[i]=new frame();
		}
		for(int i=0;i<frque.length;i++)
		{
			frque[i].num=-1;
			frque[i].time=-1;
		}
		for(int i=0;i<proque.length;i++)
		{	proque[i]=-1;
		}
		for(int i=0;i<frque.length;i++)
		{
			for(int j=0;j<proque.length;j++)
			{
				result[j][i]=-1;
			}	
		}
		
		//get process queue
		System.out.println("the process queue is:");
		for(int i=0;i<proque.length;i++)
		{
			proque[i]=(int)(0+Math.random()*(9-0+1));//随机数
			System.out.print(proque[i]+" ");
		}
		System.out.println();
		System.out.println("please choose the algorithm:1-FIFO 2-LRU");
		int chooseAl=sc.nextInt();
		int timecount=0;
		int OKflag;
		int pagefault=0;
		
		switch(chooseAl)
		{
		case 1://FIFO
			for(int i=0;i<proque.length;i++)//开始一一处理进程序列
			{	timecount++;
				OKflag=0;//该进程有无处理完毕
				for(int j=0;j<frque.length;j++)//看该帧序列中是否已经有了所需页
				{
					if(frque[j].num==proque[i])//有了
					{
						OKflag=1;
						break;
					}
				}	
				if(OKflag==0)//缺页处理
				{	pagefault++;
					for(int j=0;j<frque.length;j++)//看有无空位置
					{
						if(frque[j].num==-1)//有的话加进去
						{
							frque[j].num=proque[i];
							frque[j].time=timecount;
							OKflag=1;//该进程处理完毕
							break;
						}
					}
					if(OKflag==0)
					{
						//先进先出：
						frame temp;
						int tempnum;
						temp=frque[0];
						tempnum=0;
						for(int j=0;j<frque.length;j++)//找出最早进入
						{
							if(frque[j].time<temp.time)
							{
								tempnum=j;
								temp=frque[j];
							}
						}
						//把最旧的页换掉
						frque[tempnum].num=proque[i];
						frque[tempnum].time=timecount;
						OKflag=1;
					}
				}
				
				if(OKflag==1)
				{
					for(int j=0;j<frque.length;j++)
					{
						result[i][j]=frque[j].num;//导入结果
					}
				}
				
				
			}
			System.out.println("the FIFO result is:");
			{
				for(int i=0;i<proque.length;i++)
				{
					System.out.print(proque[i]+"	");
				}
				System.out.println();
				for(int j=0;j<frque.length;j++)
				{
					for(int i=0;i<proque.length;i++)
					{
						if(result[i][j]==-1)
						{
							System.out.print(" "+"	");
						}
						else
						{
							System.out.print(result[i][j]+"	");
						}
						}
					System.out.println();
				}
				System.out.println(pagefault+"page fault occurs");
				
			}
			break;
		case 2://LRU
			for(int i=0;i<proque.length;i++)//开始一一处理进程序列
			{	timecount++;
				OKflag=0;//该进程有无处理完毕
				for(int j=0;j<frque.length;j++)//看该帧序列中是否已经有了所需页
				{
					if(frque[j].num==proque[i])//有了
					{
						OKflag=1;
						frque[j].time=timecount;//更新时间
						break;
					}
				}	
				if(OKflag==0)//缺页处理
				{	pagefault++;
					for(int j=0;j<frque.length;j++)//看有无空位置
					{
						if(frque[j].num==-1)//有的话加进去
						{
							frque[j].num=proque[i];
							frque[j].time=timecount;
							OKflag=1;//该进程处理完毕
							break;
						}
					}
					if(OKflag==0)
					{
						//最旧未使用
						frame temp;
						int tempnum;
						temp=frque[0];
						tempnum=0;
						for(int j=0;j<frque.length;j++)//找出最旧未使用
						{
							if(frque[j].time<temp.time)
							{
								tempnum=j;
								temp=frque[j];
							}
						}
						//把最早未使用的页换掉
						frque[tempnum].num=proque[i];
						frque[tempnum].time=timecount;
						OKflag=1;
					}
				}
				
				if(OKflag==1)
				{
					for(int j=0;j<frque.length;j++)
					{
						result[i][j]=frque[j].num;//导入结果
					}
				}
				
				
			}
			System.out.println("the LRU result is:");
			{
				for(int i=0;i<proque.length;i++)
				{
					System.out.print(proque[i]+"	");
				}
				System.out.println();
				for(int j=0;j<frque.length;j++)
				{
					for(int i=0;i<proque.length;i++)
					{
						if(result[i][j]==-1)
						{
							System.out.print(" "+"	");
						}
						else
						{
							System.out.print(result[i][j]+"	");
						}
					}
					System.out.println();
				}
				System.out.println(pagefault+"page fault occurs");
				
			}
			
			break;
		default:
			System.out.println("wrong input!");
			break;
		
		}
		
	}
	
}
