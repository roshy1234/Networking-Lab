#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>

void write_file(int sockfd, char *data, int size) {
    int n;
    FILE *fp;
    char *filename = "file2.txt";
    char buffer[size];
    fp = fopen(filename, "w");
    if(fp == NULL) {
        perror("File creating failed");
        exit(1);

        while(1) {
            n = recv(sockfd, buffer, sizeof(buffer), 0);
            if(n <= 0) {
                break;
                return;
            }
            fprintf(fp, "%s", buffer);
            bzero(buffer, size);
        }
    }    


}

int main() {

    char *ip = "127.0.0.1";
    int port = 8080;

    int sockfd,new_sock;
    struct sockaddr_in server,new; 
    socklen_t addr_size;
    char buffer[1024];
    int n;
    // Create the server socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0) {
        perror("Socket creation failed");
        exit(1);
    }
    printf("[+]TCP Server Socket Created\n");
    
    server.sin_family = AF_INET;
    server.sin_port = port;
    server.sin_addr.s_addr = inet_addr(ip);
    
    // Bind the socket
    n = bind(server_sock, (struct sockaddr*)&server, sizeof(server));
    if(n < 0) {
        perror("Binding failed");
        exit(1);
    }
    // Listen for incoming connections
    listen(server_sock, 5);
    printf("Listening...\n");

    addr_size = sizeof(new);
    new_sock = accept(server_sock, (struct sockaddr*)&new, &addr_size);
    
    write_file(new_sock, "Hello from server", 18);
    printf("File data received successfully.\n");
}