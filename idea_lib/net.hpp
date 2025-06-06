#include "default.hpp"

//to work with network
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <arpa/inet.h>

#include <cstring>


int connect(string ip , int port){
    int sock = socket(AF_INET , SOCK_STREAM , 0);
    //AF_INET - ip v4
    //SOCK_STREAM - TCP

    sockaddr_in server ;
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    char  ip_in_char [ip.size() + 1];
    // for(int ind = 0; ind < ip.size(); ind++){
    //     ip_in_char[ind] = ip[ind];
    // }
    // ip_in_char[ip.size()] =  '\0';
    server.sin_addr.s_addr = inet_addr(ip.c_str());
    if(connect(sock , (struct sockaddr*) &server , sizeof(server)) < 0){
        cout<<"ERROR CONNECT"<<endl;
        return -1;
    }
    return sock;
}

int connect(string ip , int port , string host){
    int sock = socket(AF_INET , SOCK_STREAM , 0);
    //AF_INET - ip v4
    //SOCK_STREAM - TCP

    sockaddr_in server ;
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    char  ip_in_char [ip.size() + 1];
    // for(int ind = 0; ind < ip.size(); ind++){
    //     ip_in_char[ind] = ip[ind];
    // }
    // ip_in_char[ip.size()] =  '\0';
    server.sin_addr.s_addr = inet_addr(ip.c_str());
    if(connect(sock , (struct sockaddr*) &server , sizeof(server)) < 0){
        cout<<"ERROR CONNECT"<<endl;
        return -1;
    }
    return sock;
}


int send(int socket , string message){
    char mess [message.size() + 1];
    for(int ind = 0; ind < message.size(); ind ++){
        mess[ind]= message[ind];
    }   
    mess[message.size()] = '\0';

    int a = send(socket ,mess , strlen(mess) , 0 );
    return a;
}

string recv(int socket){
    string ans = "";
    char buff[1024];
    int a;
    while((a =recv(socket , buff ,1024 , 0))> 0){
        for(int ind = 0; ind < a ; ind ++){
            ans = ans  + buff[ind];
        }
    }
    return ans;
}