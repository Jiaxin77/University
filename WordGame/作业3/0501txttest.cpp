
#include <fstream>
#include <winsock2.h>  

#include <iostream>
#include <string>
#include<string.h> 
#include<stdlib.h>
#include<stdio.h>
#include"logresign.h"
#include"PlayerClass.h"
#include "file.h"
#include "userbox.h" 
#include"WordClass.h"
#include"mytype.h"
#include"start.h" 


 
#pragma comment(lib,"ws2_32.lib")  
#include"Recsend.h"
#include<sstream>
using namespace std;

 
 	Player c[playerNum];
	Admin a[adminNum];
	word w[wordNum];
	int PTotal=0,ATotal=0,WTotal=0;
	int *PTotalptr=&PTotal;
	int *ATotalptr=&ATotal;
	int *WTotalptr=&WTotal;
	
 
 DWORD WINAPI startGameThread(LPVOID IpParameter)
 {
 	SOCKET sClient=(SOCKET)IpParameter;
 	int j;
	 j=start(sClient,c,a,w,PTotalptr,ATotalptr,WTotalptr);//进入游戏系统 
 	if(j==0)
 	{
 		return 0;
	 }
 }

DWORD WINAPI WaitAcceptThread(LPVOID IpParameter)
{	

	
	SOCKET slisten=(SOCKET)IpParameter; 
	while(true)
	{	SOCKET sClient;
		sockaddr_in remoteAddr;
	
		int nAddrlen = sizeof(remoteAddr);
	
			cout<<"继续监听"<<endl;
		sClient = accept(slisten, (SOCKADDR *)&remoteAddr, &nAddrlen);
			if(sClient == INVALID_SOCKET)  
        {  
            cout<<"accept()错误！"<<endl;
            WSACleanup();
            return -1;
        }  
		
		char t[10];
		cout<<inet_ntoa(remoteAddr.sin_addr)<<":"<< remoteAddr.sin_port<<"上线"<<endl;
		HANDLE bufferMain=CreateSemaphore(NULL,1,1,NULL);
	
         HANDLE startThread;
	   startThread=CreateThread(NULL,0,startGameThread,(LPVOID)sClient,0,NULL); 
	
	
		string t1=t;
	
	
	}
} 
  




main()
{	
	
	PTotal=ReadPlayerFile(c);
	ATotal=ReadAdminFile(a);
	WTotal=ReadWordFile(w);
	/*********socket部分*********************/
	HANDLE bufferMutex;//令其能互斥成功正常通信的信号量句柄 


//加载套接字库，创建套接字（WSAStartup()/socket()）
	WORD sockVersion = MAKEWORD(2,2);  
    WSADATA wsaData;  
    if(WSAStartup(sockVersion, &wsaData)!=0)  
    {  	cout<<"WSAtartup失败！"<<endl;
        return -1;  
    }  
  
    //创建套接字  
    SOCKET slisten = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);  
    if(slisten == INVALID_SOCKET)  
    {  
        cout<<"socket error !"<<endl;  
        WSACleanup();
        return -1;  
    }  
  
    //绑定IP和端口  
    sockaddr_in sin;  
    sin.sin_family = AF_INET;  
    sin.sin_port = htons(8888);  
    sin.sin_addr.S_un.S_addr = INADDR_ANY;   
    if(bind(slisten, (LPSOCKADDR)&sin, sizeof(sin)) == SOCKET_ERROR)  
    {  
        cout<<"bind error !"<<endl;
		closesocket(slisten);
		WSACleanup();
		return -1;  
    }  
  
    //开始监听  
    if(listen(slisten, 10) == SOCKET_ERROR)  
    {  
        cout<<"listen error !"<<endl;  
        closesocket(slisten);
        WSACleanup();
		return -1;  
    }  
    
  
	///////////////////////////////////////////////
 
    char revData[255];   
    SOCKET sClient;
        cout<<"TCP服务器开始监听"<<endl; 
        bufferMutex=CreateSemaphore(NULL,1,1,NULL);//是个函数 
         HANDLE acceptThread;
	   acceptThread=CreateThread(NULL,0,WaitAcceptThread,(LPVOID)slisten,0,NULL); 
	
		  WaitForSingleObject(acceptThread, INFINITE);
		  CloseHandle(bufferMutex);
		

	/*************socket部分*******************/ 
	
	
	
	
	 WSACleanup();
	system("pause");
	return 0;
}
