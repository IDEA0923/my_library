#include "default.hpp"

//for the work with net
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

#include <cstring>
#include <threads.h>

int start(int port){
    int sock = socket(AF_INET , SOCK_STREAM , 0);
    sockaddr_in  setting ;
    setting.sin_family = AF_INET ;
    setting.sin_port = htons(port);
    
}