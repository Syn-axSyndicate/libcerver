//Defining include guard
#ifndef SERVER_H
#define SERVER_H
#include <sys/socket.h>
#include<netinet/in.h>
//defining our structure 
struct Cerver_Struct{
    int domain;
    int service;
    int protocol;
    unsigned long int interface;
    int port;
    int backlog;
    struct sockaddr_in address;
    void (*run)(struct Cerver_Struct *server);
    int socket;
}typedef Var_cerver;

Var_cerver Server_build(int domain, int service, int protocol, int unsigned long interface, int port, int backlog, void(*run)(Var_cerver *server));

#endif