#include "net.hpp"

int main(){
    int sock = connect("104.16.144.212" , 80);
    cout<<"YS"<<endl;
    cout<<"M";
    string request =
    "GET /ticker HTTP/1.1\r\n"
    "Host: blockchain.info\r\n"
    "Connection: close\r\n"
    "\r\n";
    int a = send(sock ,request);
    cout<<"RECV";
    cout<<recv(sock);
}