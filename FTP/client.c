#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>

void send_file(FILE *fp, int sockfd) {
    int n;
    char data[1024] = {0};

    while(fgets(data, 1024, fp) != NULL) {
        if(send(sockfd, data, sizeof(data), 0) == -1) {
            perror("[-]Error in sending file.");
            exit(1);
        }
        bzero(data, 1024);
    }
    printf("[+]File data sent successfully.\n");
}       


int main() {

    char *ip = "127.0.0.1";
    int port = 8080;

    int sock;
    struct sockaddr_in addr; 
    socklen_t addr_size;
    char buffer[1024];
    int n;

    int sockfd;
    struct sockaddr_in server;
    FILE *fp;
    char *filename = "file1.txt";


    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0) {
        perror("Socket creation failed");
        exit(1);
    }
    printf("[+]TCP Server Socket Created\n");

    server.sin_family = AF_INET;
    server.sin_port = port;
    server.sin_addr.s_addr = inet_addr(ip);

    e = connect(sockfd, (struct sockaddr*)&server, sizeof(server));
    if (e < 0) {
        perror("Connection failed");
        exit(1);
    }
    printf("Connected to the server\n");

    fp = fopen(filename, "r");
    if(fp == NULL) {
        perror("File open failed");
        exit(1);
    }

    send_file(fp, sockfd);
    printf("File data sent successfully.\n");
    close(sockfd);
    printf("Disconnected from server\n");

    return 0;
}