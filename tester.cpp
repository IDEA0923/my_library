#include "net.hpp"
int main(){
    int sock= connect("192.168.0.1" , 80);
    cout<<"CONNECT"<<endl;
    if(send(sock  , "GET / HTTP/1.1 \r\nHost: 192.168.0.1\r") < 0){
        cout<<"ERROR"<<endl;
    }
    cout<<"RECV start"<<endl;
    cout<<recv(sock)<<endl;
    cout<<"END"<<endl;
    close(sock);
}