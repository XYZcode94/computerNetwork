
/* Roll: 24157142024 Service Type: A d = 0 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define PORT 30024
#define SIZE 2048
#define ROLL "24157142024"

int main(void) {
    int sockfd;
    struct sockaddr_in server, client;
    socklen_t client_len;
    char buffer[SIZE], response[SIZE];

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    if (sockfd < 0) {
        perror("Socket creation failed");
        return 1;
    }

    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(PORT);

    if (bind(sockfd, (struct sockaddr *)&server,
             sizeof(server)) < 0) {
        perror("Bind failed");
        close(sockfd);
        return 1;
    }

    printf("Server running on port %d\n", PORT);

    while (1) {
        client_len = sizeof(client);

        ssize_t n = recvfrom(sockfd, buffer, SIZE - 1, 0,
                             (struct sockaddr *)&client,
                             &client_len);

        if (n < 0) {
            perror("recvfrom failed");
            continue;
        }

        buffer[n] = '\0';

        char ip[INET_ADDRSTRLEN];
        inet_ntop(AF_INET, &client.sin_addr, ip, sizeof(ip));

        printf("\nClient: %s:%d\n", ip, ntohs(client.sin_port));
        printf("Received: %s\n", buffer);

        char *sep = strchr(buffer, '#');

        if (sep == NULL) {
            strcpy(response, "ERROR: Unauthorized client");
        } else {
            *sep = '\0';

            if (strcmp(buffer, ROLL) != 0) {
                strcpy(response, "ERROR: Unauthorized client");
            } else {
                char *message = sep + 1;

                if (strcmp(message, "EXIT") == 0) {
                    strcpy(response, "Server shutting down");
                    sendto(sockfd, response, strlen(response), 0,
                           (struct sockaddr *)&client, client_len);

                    printf("Exit command received. Stopping server.\n");
                    close(sockfd);
                    return 0;
                }

                char *bar = strchr(message, '|');

                if (bar == NULL) {
                    strcpy(response, "ERROR: Invalid command");
                } else {
                    *bar = '\0';
                    char *command = message;
                    char *text = bar + 1;

                    if (strcmp(command, "UP") == 0) {
                        for (int i = 0; text[i]; i++)
                            text[i] = toupper((unsigned char)text[i]);

                        snprintf(response, sizeof(response), "%s", text);
                    } else if (strcmp(command, "LOW") == 0) {
                        for (int i = 0; text[i]; i++)
                            text[i] = tolower((unsigned char)text[i]);

                        snprintf(response, sizeof(response), "%s", text);
                    } else if (strcmp(command, "REV") == 0) {
                        size_t len = strlen(text);

                        for (size_t i = 0; i < len; i++)
                            response[i] = text[len - 1 - i];

                        response[len] = '\0';
                    } else {
                        strcpy(response, "ERROR: Unknown command");
                    }
                }
            }
        }

        sendto(sockfd, response, strlen(response), 0,
               (struct sockaddr *)&client, client_len);

        printf("Sent response: %s\n", response);
    }

    close(sockfd);
    return 0;
}
