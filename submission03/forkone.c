#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/wait.h>


void giveTime(char a[]);

void waitSeconds(int t);

int main(int number_of_arguments, char **array_with_arguments_in_it) {
    giveTime("Start\0");

    int k = 0;
    pid_t parent_process_pid;
    pid_t pid = fork();

    // Child Process
    if (pid == 0) {
        int k = atoi(array_with_arguments_in_it[1]);
        for (int i = 0; i < k; i++) {
            printf("%d %d %d\n", getpid(), parent_process_pid, i + 1);
            waitSeconds(1);
        }
        return (getpid() + k) % 100;
    }
        // Parent Process
    else {
        int status;
        waitpid(0, &status, 0);
    }
    giveTime("Ende\0");

    return EXIT_SUCCESS;
}

void giveTime(char a[]) {
    time_t currentTime = time(NULL);
    printf("%s: %s", a, ctime(&currentTime));
}

void waitSeconds(int t) {
    sleep(t);
}