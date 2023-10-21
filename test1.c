#include "types.h"
#include "stat.h"
#include "user.h"

int main(void) {
    int i;
    int pid;
    int run_duration = 1000000;

    for (i = 0; i < 10; i++) {
        pid = fork();

        if (pid < 0) {
            printf(1, "Fork failed\n");
            exit();
        }

        if (pid == 0) { // Child process
            if (i < 5) {
                setnice(getpid(), 10);
            } else {
                setnice(getpid(), 0);
            }

            // Simulate some CPU intensive task
            for (int j = 0; j < run_duration; j++) {
            }

            printf(1, "Process %d with nice value %d finished.\n", getpid(), i < 5 ? 0 : 10);
            ps(0);
            exit();
        }
    }

    for (i = 0; i < 10; i++) {
        wait();
    }

    printf(1, "All child processes have finished.\n");
    exit();
}
