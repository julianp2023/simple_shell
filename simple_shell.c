#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024

int main(void) {
    char *buffer;
    size_t bufsize = BUFFER_SIZE;
    ssize_t characters;
    char *prompt = "#cisfun$ ";
    char *args[2];
    pid_t child_pid;
    int status;

    buffer = (char *)malloc(bufsize * sizeof(char));
    if (buffer == NULL) {
        perror("Unable to allocate buffer");
        exit(1);
    }

    while (1) {
        printf("%s", prompt);

        characters = getline(&buffer, &bufsize, stdin);
        if (characters == -1) {
            printf("\n");
            break;
        }

        // Remove trailing newline character
        buffer[strcspn(buffer, "\n")] = '\0';

        // Fork a child process
        child_pid = fork();

        if (child_pid == -1) {
            perror("Fork failed");
            exit(1);
        }

        if (child_pid == 0) {
            // Child process
            args[0] = buffer;
            args[1] = NULL;
            if (execve(args[0], args, NULL) == -1) {
                perror("Command not found");
                exit(EXIT_FAILURE);
            }
        } else {
            // Parent process
            wait(&status);
        }
    }

    free(buffer);
    return 0;
}

