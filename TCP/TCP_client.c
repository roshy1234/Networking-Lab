#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>

int main() {

    char *ip = "127.0.0.1";
    int port = 8080;

    int sock;
    struct sockaddr_in addr; 
    socklen_t addr_size;
    char buffer[1024];
    int n;
    // Create the server socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock < 0) {
        perror("Socket creation failed");
        exit(1);
    }
    printf("[+]TCP Server Socket Created\n");
    
    memset(&addr, '\0', sizeof(addr)); /
    addr.sin_family = AF_INET;
    addr.sin_port = port
    addr.sin_addr.s_addr = inet_addr(ip);

    connect(sock, (struct sockaddr*)&addr, sizeof(addr));
    printf("Connected to the server\n");

    bzero(buffer,1024);
    strcpy(buffer, "Hello.This is client");
    printf("Client: %s\n", buffer);
    send(sock,buffer,strlen(buffer),0);

    bzero(buffer,1024);
    recv(sock, buffer, sizeof(buffer), 0);
    printf("Server: %s\n", buffer);

    close(sock);
    printf("Disconnected from server\n");
    return 0;
}