THis is a simple lib for work with network at C++ linux 

(sorry , but righ now for use this lib you need copy "idea_lib" folder for your project )

righ now work :
    net.hpp
    net_https.hpp

examples :
net.hpp :

    #include "net.hpp"

    int main(){
        int sock = connect("192.168.0.1" , 80);
        cout<<"YS"<<endl;
        cout<<"M";
        string request =
        "GET /ticker HTTP/1.1\r\n"
        "Host: 192.168.0.1\r\n"
        "Connection: close\r\n"
        "\r\n";
        int a = send(sock ,request);
        cout<<"RECV";
        cout<<recv(sock);
    }

net_https.hpp : 

    #include "idea_lib/net_https.hpp"

    int main(){
        https nt("216.58.209.174" , 443);
        cout<<"INIT"<<endl;
        string request =
        "GET / HTTP/1.1\r\n"
        "Host: google.com\r\n"
        "User-Agent: curl/7.88.1\r\n"
        "Accept: */*\r\n"
        "Accept-Encoding: identity\r\n"
        "Connection: close\r\n"
        "\r\n";
        cout<<"SND START"<<endl;
        nt.send(request);
        cout<<"SND END"<<endl;
        
        cout<<nt.recv()<<endl;
    }