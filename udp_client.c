
/* Roll: 24157142024 Service Type: A d = 0 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define SIZE 2048
#define ROLL "24157142024"

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in server;
    socklen_t server_len = sizeof(server);
    char input[SIZE], message[SIZE + 32], response[SIZE];

    if (argc != 3) {
        printf("Usage: %s <server_ip> <roll>\n", argv[0]);
        return 1;
    }

    if (strcmp(argv[2], ROLL) != 0) {
        printf("Roll number must be %s\n", ROLL);
        return 1;
    }

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    if (sockfd < 0) {
        perror("Socket creation failed");
        return 1;
    }

    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(30024);

    if (inet_pton(AF_INET, argv[1], &server.sin_addr) != 1) {
        printf("Invalid server IP address\n");
        close(sockfd);
        return 1;
    }

    printf("UDP client started. Commands: UP|text, LOW|text, REV|text\n");

    while (1) {
        printf("\nEnter command (or EXIT): ");

        if (fgets(input, sizeof(input), stdin) == NULL) {
            strcpy(input, "EXIT");
        } else {
            input[strcspn(input, "\n")] = '\0';
        }

        snprintf(message, sizeof(message), "%s#%s", ROLL, input);

        if (sendto(sockfd, message, strlen(message), 0,
                   (struct sockaddr *)&server, server_len) < 0) {
            perror("sendto failed");
            break;
        }

        if (strcmp(input, "EXIT") == 0)
            break;

        ssize_t n = recvfrom(sockfd, response, sizeof(response) - 1,
                             0, (struct sockaddr *)&server, &server_len);

        if (n < 0) {
            perror("recvfrom failed");
            break;
        }

        response[n] = '\0';
        printf("Server response: %s\n", response);
    }

    close(sockfd);
    printf("Client terminated.\n");

    return 0;
}
