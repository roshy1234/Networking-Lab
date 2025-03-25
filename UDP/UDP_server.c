#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv) {
    
    if(argc < 2) {
        printf("Usage: %s <port>\n", argv[0]);
        exit(0);
    }

    char *ip = "127.0.0.1";
    int port = atoi(argv[1]);

    int sockfd;
    struct sockaddr_in server,client; 
    socklen_t addr_size;
    char buffer[1024];
    int n;

    // Create the server socket
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if(sockfd < 0) {
        perror("Socket creation failed");
        exit(1);
    }

        memset(&server, '\0', sizeof(server)); /
    server.sin_family = AF_INET;
    server.sin_port = port
    server.sin_addr.s_addr = inet_addr(ip);
    // Bind the socket
    n = bind(sockfd, (struct sockaddr*)&server, sizeof(server));
    if(n < 0) {
        perror("Binding failed");
        exit(1);
    } 

    bzero(buffer,1024);
    addr_size = sizeof(client);
    recvfrom(sockfd, buffer, 1024, 0, (struct sockaddr*)&client, &addr_size);
    printf("Data received: %s\n", buffer);

    bzero(buffer,1024);
    strcpy(buffer, "Hello.This is server");
    sendto(sockfd, buffer, 1024, 0, (struct sockaddr*)&client, &addr_size);
    printf("Data Send: %s\n", buffer);   

    return 0;
}
