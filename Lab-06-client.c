
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define SIZE 2048

struct Request {
    char id[20];
    char data[SIZE];
};

int main() {
    int sock;
    struct sockaddr_in server;
    struct Request req;
    char response[256];

    FILE *fp = fopen("data.txt", "r");

    if (fp == NULL) {
        perror("File error");
        return 1;
    }

    size_t n = fread(req.data, 1, SIZE - 1, fp);
    req.data[n] = '\0';
    fclose(fp);

    printf("Enter Student ID to search: ");
    scanf("%19s", req.id);

    sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock < 0) {
        perror("Socket error");
        return 1;
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (connect(sock, (struct sockaddr *)&server,
                sizeof(server)) < 0) {
        perror("Connection error");
        close(sock);
        return 1;
    }

    if (write(sock, &req, sizeof(req)) != sizeof(req)) {
        perror("Send error");
        close(sock);
        return 1;
    }

    ssize_t bytes = read(sock, response, sizeof(response));

    if (bytes > 0) {
        response[bytes < sizeof(response) ? bytes :
                 sizeof(response) - 1] = '\0';
        printf("Server Response: %s\n", response);
    }

    close(sock);
    return 0;
}
