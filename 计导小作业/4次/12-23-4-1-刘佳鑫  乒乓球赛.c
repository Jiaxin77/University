#include<stdio.h>
#include<stdlib.h>
main()
{     int count;
      char i,j,k,l;
      count=0;//������ 
      printf("The result of ballot is:\n");
      for(i='W';i<='Z';i++)//��A�Կ��Ķ� 
      for(j='W';j<='Z';j++) //��B�Կ��Ķ� 
          {   if(i!=j)//��AB�Կ��Ĳ�����ͬ 
              {  for(k='W';k<='Z';k++)//��C�Կ��Ķ� 
                 {   if((i!=k)&&(j!=k))//��ABC�Կ��Ĳ�����ͬ 
                     {  for(l='W';l<='Z';l++)//��D�Կ��Ķ� 
                        {   if((i!=l)&&(j!=l)&&(k!=l))//��ABCD�Կ��Ĳ�����ͬ 
                          {  if((i!='X')&&(k!='X')&&(k!='Z')&&(l!='W'))//A����X������C����XZ������D����W���� 
                             {  count++;//������һ 
                                printf("Group %d:\n",count);//��ӡ���� 
                                printf("A VS %c \nB VS %c \nC VS %c \nD vs %c \n",i,j,k,l);//��ӡ��� 
                             }
                          }
                        }
                      }
                  } 
              }
          }         
          printf("There are %d ways to assign the players.",count);
      system("pause");
      return 0;
}
