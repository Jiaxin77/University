#include<stdio.h>
#include<stdlib.h>
main()
{     int count;
      char i,j,k,l;
      count=0;//计组数 
      printf("The result of ballot is:\n");
      for(i='W';i<='Z';i++)//与A对抗的队 
      for(j='W';j<='Z';j++) //与B对抗的队 
          {   if(i!=j)//与AB对抗的不能相同 
              {  for(k='W';k<='Z';k++)//与C对抗的队 
                 {   if((i!=k)&&(j!=k))//与ABC对抗的不能相同 
                     {  for(l='W';l<='Z';l++)//与D对抗的队 
                        {   if((i!=l)&&(j!=l)&&(k!=l))//与ABCD对抗的不能相同 
                          {  if((i!='X')&&(k!='X')&&(k!='Z')&&(l!='W'))//A不与X比赛，C不与XZ比赛，D不与W比赛 
                             {  count++;//组数加一 
                                printf("Group %d:\n",count);//打印组数 
                                printf("A VS %c \nB VS %c \nC VS %c \nD vs %c \n",i,j,k,l);//打印结果 
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
