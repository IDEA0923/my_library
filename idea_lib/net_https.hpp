#include "default.hpp"

#include <unistd.h>
#include <netdb.h>
#include <arpa/inet.h>

//for the HTTPS
#include <openssl/ssl.h>
#include <openssl/err.h>

class https{
    public:

    int sock =0;
    sockaddr_in srv;
    SSL_CTX* ctx;
    SSL * ssl;

    https(string ip , int port){
        sock = socket(AF_INET , SOCK_STREAM , 0);

        srv.sin_family= AF_INET;
        srv.sin_port = htons(port);
        srv.sin_addr.s_addr = inet_addr(ip.c_str());

        if(connect(sock , (struct sockaddr*) &srv , sizeof(srv)) < 0){
        cout<<"ERROR CONNECT"<<endl;
        return ;
        }  


        //WARNING ! writed with AI ( i hadn't so much time for read doc about SSL and i deside write with AI)
        //writed with AI
        SSL_library_init();
        SSL_load_error_strings();
        const SSL_METHOD* method = TLS_client_method();
        ctx = SSL_CTX_new(method);

        ssl =  SSL_new(ctx);
        SSL_set_fd(ssl  , sock);

        if(SSL_connect(ssl) <= 0 ){
            cout<<"ERROR : SSL_connect()"<<endl;
            //ERR_print_errors_fp(stderr);
            return ;
        }
    }

    https(string ip , int port , string host){
        sock = socket(AF_INET , SOCK_STREAM , 0);

        srv.sin_family= AF_INET;
        srv.sin_port = htons(port);
        srv.sin_addr.s_addr = inet_addr(ip.c_str());

        if(connect(sock , (struct sockaddr*) &srv , sizeof(srv)) < 0){
        cout<<"ERROR CONNECT"<<endl;
        return ;
        }  


        //WARNING ! writed with AI ( i hadn't so much time for read doc about SSL and i deside write with AI)
        //writed with AI
        SSL_library_init();
        SSL_load_error_strings();
        const SSL_METHOD* method = TLS_client_method();
        ctx = SSL_CTX_new(method);

        ssl =  SSL_new(ctx);
        SSL_set_fd(ssl  , sock);

        SSL_set_tlsext_host_name(ssl, host.c_str()); 
    
        if(SSL_connect(ssl) <= 0 ){
            cout<<"ERROR : SSL_connect()"<<endl;
            //ERR_print_errors_fp(stderr);
            return ;
        }
    }
    

    int send(string request){
        int a = SSL_write(ssl , request.c_str() , request.length());
        return a;
    }

    string recv(){
        char buff[1024];
        string ans = "";
        int a;
        while((a = SSL_read(ssl  , buff , 1024))> 0){
            for(int ind = 0; ind < a ; ind ++){
                ans = ans  + buff[ind];
            }
        }
        return ans;
    }

    ~https(){
        SSL_shutdown(ssl);
        SSL_free(ssl);
        close(sock);
        SSL_CTX_free(ctx);
    }
};