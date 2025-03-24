#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>

int main() {

    char *ip = "127.0.0.1";
    int port = 8080;

    int server_sock,client_sock;
    struct sockaddr_in server,client; 
    socklen_t addr_size;
    char buffer[1024];
    int n;
    // Create the server socket
    server_sock = socket(AF_INET, SOCK_STREAM, 0);
    if(server_sock < 0) {
        perror("Socket creation failed");
        exit(1);
    }
    printf("[+]TCP Server Socket Created\n");
    
    memset(&server, '\0', sizeof(server)); 
    server.sin_family = AF_INET;
    server.sin_port = port
    server.sin_addr.s_addr = inet_addr(ip);
    
    // Bind the socket
    n = bind(server_sock, (struct sockaddr*)&server, sizeof(server));
    if(n < 0) {
        perror("Binding failed");
        exit(1);
    }
    printf("Bind to port %d\n", port);

    // Listen for incoming connections
    listen(server_sock, 5);
    printf("Listening...\n");
    
    while(1){
        addr_size = sizeof(client);
        client_sock = accept(server_sock, (struct sockaddr*)&client, &addr_size);
        printf("Client connected\n");

        bzero(buffer,1024);
        recv(client_sock, buffer, sizeof(buffer), 0);
        printf("Client: %s\n", buffer);

        bzero(buffer,1024);
        strcpy(buffer, "Hello.This is server, How you doing?");
        printf("Server: %s\n", buffer);
        send(client_sock, buffer, strlen(buffer), 0);

        close(client_sock);
        printf("Client disconnected\n");
    }

    return 0;
}