#include<stdio.h>
#include"server.h"
#include<string.h>
#include<unistd.h>
void run(Var_cerver *server){
    char buffer[3000];
    char *res="<h1>Hello There! </h1>";
    int new_socket;
    int addr_len=sizeof(server->address);
    while(1){
        printf("===== Waiting For Connection =====\n");
        new_socket=accept(server->socket,(struct sockaddr *)&server->address,(socklen_t *)&addr_len);
        read(new_socket,buffer,3000);
        printf("%s\n",buffer);
        write(new_socket,res,strlen(res));
        close(new_socket);
    }
}
int main(){
    printf("hello from libcerver\n");
    Var_cerver server=Server_build(AF_INET,SOCK_STREAM,0,INADDR_ANY,8080,10,run);
    server.run(&server);
}