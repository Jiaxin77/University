#include <stdio.h>  
#include <winsock2.h>  
  
#pragma comment(lib,"ws2_32.lib")  
  
int main(int argc, char* argv[])  
{  




    //��ʼ��WSA  
    
    
    
    WORD sockVersion = MAKEWORD(2,2);  
    WSADATA wsaData;  
    if(WSAStartup(sockVersion, &wsaData)!=0)  
    {  
        return 0;  
    }  
  
    //�����׽���  
    SOCKET slisten = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);  
    if(slisten == INVALID_SOCKET)  
    {  
        printf("socket error !");  
        return 0;  
    }  
  
    //��IP�Ͷ˿�  
    sockaddr_in sin;  
    sin.sin_family = AF_INET;  
    sin.sin_port = htons(8888);  
    sin.sin_addr.S_un.S_addr = INADDR_ANY;   
    if(bind(slisten, (LPSOCKADDR)&sin, sizeof(sin)) == SOCKET_ERROR)  
    {  
        printf("bind error !");  
    }  
  
    //��ʼ����  
    if(listen(slisten, 5) == SOCKET_ERROR)  
    {  
        printf("listen error !");  
        return 0;  
    }  
  
  //��ʼ������
   int choose=-1;
	int flag=1;
	int logoFlag=0;
	Player c[playerNum];//const��һ��
	Admin a[adminNum];
	word w[wordNum];
	int PTotal=0,ATotal=0,WTotal=0;
	int PlayFlag=1;
	int AdminFlag=1;
	PTotal=ReadPlayerFile(c);
	ATotal=ReadAdminFile(a);
	WTotal=ReadWordFile(w);
	/*for(int j=0;j<PTotal;j++)
	{	cout<<j<<endl<<endl<<c[j].getname()<<endl<<c[j].getpassword()<<endl<<c[j].getWStage()<<endl<<c[j].getWPassedNum()<<endl<<c[j].getWrank()<<endl;
	 }*/ 
	ATotal=ReadAdminFile(a);
	int *PTotalptr=&PTotal;
	int *ATotalptr=&ATotal;
	int *WTotalptr=&WTotal;
	///////////////////////////////////////////////

  	const char * sendData = "��ã�TCP�ͻ��ˣ�\n����ѡ����Ҫ���еĲ�����\n0-�˳� 1-��¼ 2-ע��\n";  
    send(sClient, sendData, strlen(sendData), 0);  
    closesocket(sClient); 
  
    //ѭ����������  
    SOCKET sClient;  
    sockaddr_in remoteAddr;  
    int nAddrlen = sizeof(remoteAddr);  
    char revData[255];   
    while (true)  
    {  
        printf("�ȴ�����...\n");  
        sClient = accept(slisten, (SOCKADDR *)&remoteAddr, &nAddrlen);  
        if(sClient == INVALID_SOCKET)  
        {  
            printf("accept error !");  
            continue;  
        }  
        printf("���ܵ�һ�����ӣ�%s \r\n", inet_ntoa(remoteAddr.sin_addr));  
          
        //��������  
        int ret = recv(sClient, revData, 255, 0);         
        if(ret > 0)  
        {  
            revData[ret] = 0x00;  
            printf(revData);  
        }  
  
        //��������  
        const char * sendData = "��ã�TCP�ͻ��ˣ�\n";  
        send(sClient, sendData, strlen(sendData), 0);  
        closesocket(sClient);  
    }  
      
    closesocket(slisten);  
    WSACleanup();  
    return 0;  
} 
