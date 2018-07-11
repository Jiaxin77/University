#include <WINSOCK2.H>  
#include <STDIO.H>  
#include<iostream>
#include<cstring>
using namespace std; 
#pragma  comment(lib,"ws2_32.lib")  
  
int main(int argc, char* argv[])  
{  
    WORD sockVersion = MAKEWORD(2,2);  
    WSADATA data;   
    if(WSAStartup(sockVersion, &data) != 0)  
    {  
        return 0;  
    }  
  	while(true){
	  
    SOCKET sclient = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);  
    if(sclient == INVALID_SOCKET)  
    {  
        printf("invalid socket !");  
        return 0;  
    }  
  
    sockaddr_in serAddr;  
    serAddr.sin_family = AF_INET;  
    serAddr.sin_port = htons(8888);  
    serAddr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");   
    if (connect(sclient, (sockaddr *)&serAddr, sizeof(serAddr)) == SOCKET_ERROR)  
    {  //连接失败 
        printf("connect error !");  
        closesocket(sclient);  
        return 0;  
    }  
    string data;
    cin>>data;
    const char * sendData ; 
    sendData=data.c_str();
   // const char * sendData = "你好，TCP服务端，我是客户端!\n";  
    send(sclient, sendData, strlen(sendData), 0);  
  
    char recData[255];  
    int ret = recv(sclient, recData, 255, 0);  
    if(ret > 0)  
    {  
        recData[ret] = 0x00;  
        printf(recData);  
    }  
    closesocket(sclient);  
} 
    WSACleanup();  
    return 0;  
}  
