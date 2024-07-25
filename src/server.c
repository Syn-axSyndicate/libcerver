#include"server.h"
#include <stdlib.h>
#include<stdio.h>

Var_cerver Server_build(int domain, int service, int protocol, int unsigned long interface, int port, int backlog, void(*run)(Var_cerver *server)){
    Var_cerver server;
    server.domain=domain;
    server.service=service;
    server.protocol=protocol;
    server.interface=interface;
    server.port=port;
    server.backlog=backlog;
    server.address.sin_family=domain;
    server.address.sin_port=htons(port);
    server.address.sin_addr.s_addr=htonl(interface);
    server.socket=socket(domain,service,protocol);//this will create a socket to the network
    if(server.socket==0){
        perror("Socket build failure...\n");
        exit(1);
    }
    if(bind(server.socket,(struct sockaddr *)&server.address,sizeof(server.address))<0){
        perror("Socket bind failure...\n");
        exit(1);
    }
    if(listen(server.socket,server.backlog)<0){
        perror("Socket Listen Failure");
        exit(1);
    }
    server.run=run ;
    return server;
}