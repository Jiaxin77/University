
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
	 j=start(sClient,c,a,w,PTotalptr,ATotalptr,WTotalptr);//������Ϸϵͳ 
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
	
			cout<<"��������"<<endl;
		sClient = accept(slisten, (SOCKADDR *)&remoteAddr, &nAddrlen);
			if(sClient == INVALID_SOCKET)  
        {  
            cout<<"accept()����"<<endl;
            WSACleanup();
            return -1;
        }  
		
		char t[10];
		cout<<inet_ntoa(remoteAddr.sin_addr)<<":"<< remoteAddr.sin_port<<"����"<<endl;
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
	/*********socket����*********************/
	HANDLE bufferMutex;//�����ܻ���ɹ�����ͨ�ŵ��ź������ 


//�����׽��ֿ⣬�����׽��֣�WSAStartup()/socket()��
	WORD sockVersion = MAKEWORD(2,2);  
    WSADATA wsaData;  
    if(WSAStartup(sockVersion, &wsaData)!=0)  
    {  	cout<<"WSAtartupʧ�ܣ�"<<endl;
        return -1;  
    }  
  
    //�����׽���  
    SOCKET slisten = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);  
    if(slisten == INVALID_SOCKET)  
    {  
        cout<<"socket error !"<<endl;  
        WSACleanup();
        return -1;  
    }  
  
    //��IP�Ͷ˿�  
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
  
    //��ʼ����  
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
        cout<<"TCP��������ʼ����"<<endl; 
        bufferMutex=CreateSemaphore(NULL,1,1,NULL);//�Ǹ����� 
         HANDLE acceptThread;
	   acceptThread=CreateThread(NULL,0,WaitAcceptThread,(LPVOID)slisten,0,NULL); 
	
		  WaitForSingleObject(acceptThread, INFINITE);
		  CloseHandle(bufferMutex);
		

	/*************socket����*******************/ 
	
	
	
	
	 WSACleanup();
	system("pause");
	return 0;
}
