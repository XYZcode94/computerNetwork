
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <signal.h>

#define PORT 8080
#define SIZE 2048

struct Request {
    char id[20];
    char data[SIZE];
};

int main() {
    int server_fd, client_fd;
    struct sockaddr_in server, client;
    socklen_t len = sizeof(client);

    server_fd = socket(AF_INET, SOCK_STREAM, 0);

    if (server_fd < 0) {
        perror("Socket error");
        exit(1);
    }

    int opt = 1;
    setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR,
               &opt, sizeof(opt));

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&server,
             sizeof(server)) < 0) {
        perror("Bind error");
        close(server_fd);
        exit(1);
    }

    if (listen(server_fd, 5) < 0) {
        perror("Listen error");
        close(server_fd);
        exit(1);
    }

    signal(SIGCHLD, SIG_IGN);

    printf("Server waiting for clients...\n");

    while (1) {
        client_fd = accept(server_fd,
                           (struct sockaddr *)&client, &len);

        if (client_fd < 0) {
            perror("Accept error");
            continue;
        }

        pid_t pid = fork();

        if (pid == 0) {
            struct Request req;
            char response[256];
            char *line, *saveptr;
            int found = 0;

            close(server_fd);

            if (read(client_fd, &req, sizeof(req))
                == sizeof(req)) {

                req.data[SIZE - 1] = '\0';

                line = strtok_r(req.data, "\n", &saveptr);

                while (line != NULL) {
                    char id[20];

                    if (sscanf(line, "%19s", id) == 1 &&
                        strcmp(id, req.id) == 0) {
                        snprintf(response, sizeof(response),
                                 "Record Found: %s", line);
                        found = 1;
                        break;
                    }

                    line = strtok_r(NULL, "\n", &saveptr);
                }

                if (!found) {
                    strcpy(response, "Record Not Found");
                }

                write(client_fd, response, sizeof(response));
            }

            close(client_fd);
            _exit(0);
        }

        close(client_fd);
    }

    close(server_fd);
    return 0;
}
