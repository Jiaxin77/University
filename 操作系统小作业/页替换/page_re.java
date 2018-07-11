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
		
		frame[] frque=new frame[frame_size];//ʢ��ÿ���滻�õ�֡����
		
		int[] proque=new int[process_size];//��������
		int[][]result=new int[process_size][frame_size];//������
		//initial
		for(int i=0;i<frame_size;i++)//���������ʼ��
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
			proque[i]=(int)(0+Math.random()*(9-0+1));//�����
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
			for(int i=0;i<proque.length;i++)//��ʼһһ�����������
			{	timecount++;
				OKflag=0;//�ý������޴������
				for(int j=0;j<frque.length;j++)//����֡�������Ƿ��Ѿ���������ҳ
				{
					if(frque[j].num==proque[i])//����
					{
						OKflag=1;
						break;
					}
				}	
				if(OKflag==0)//ȱҳ����
				{	pagefault++;
					for(int j=0;j<frque.length;j++)//�����޿�λ��
					{
						if(frque[j].num==-1)//�еĻ��ӽ�ȥ
						{
							frque[j].num=proque[i];
							frque[j].time=timecount;
							OKflag=1;//�ý��̴������
							break;
						}
					}
					if(OKflag==0)
					{
						//�Ƚ��ȳ���
						frame temp;
						int tempnum;
						temp=frque[0];
						tempnum=0;
						for(int j=0;j<frque.length;j++)//�ҳ��������
						{
							if(frque[j].time<temp.time)
							{
								tempnum=j;
								temp=frque[j];
							}
						}
						//����ɵ�ҳ����
						frque[tempnum].num=proque[i];
						frque[tempnum].time=timecount;
						OKflag=1;
					}
				}
				
				if(OKflag==1)
				{
					for(int j=0;j<frque.length;j++)
					{
						result[i][j]=frque[j].num;//������
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
			for(int i=0;i<proque.length;i++)//��ʼһһ�����������
			{	timecount++;
				OKflag=0;//�ý������޴������
				for(int j=0;j<frque.length;j++)//����֡�������Ƿ��Ѿ���������ҳ
				{
					if(frque[j].num==proque[i])//����
					{
						OKflag=1;
						frque[j].time=timecount;//����ʱ��
						break;
					}
				}	
				if(OKflag==0)//ȱҳ����
				{	pagefault++;
					for(int j=0;j<frque.length;j++)//�����޿�λ��
					{
						if(frque[j].num==-1)//�еĻ��ӽ�ȥ
						{
							frque[j].num=proque[i];
							frque[j].time=timecount;
							OKflag=1;//�ý��̴������
							break;
						}
					}
					if(OKflag==0)
					{
						//���δʹ��
						frame temp;
						int tempnum;
						temp=frque[0];
						tempnum=0;
						for(int j=0;j<frque.length;j++)//�ҳ����δʹ��
						{
							if(frque[j].time<temp.time)
							{
								tempnum=j;
								temp=frque[j];
							}
						}
						//������δʹ�õ�ҳ����
						frque[tempnum].num=proque[i];
						frque[tempnum].time=timecount;
						OKflag=1;
					}
				}
				
				if(OKflag==1)
				{
					for(int j=0;j<frque.length;j++)
					{
						result[i][j]=frque[j].num;//������
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
