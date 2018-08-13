// filename: soft_break.c

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int wait_flag;

void stop() {
    wait_flag = 0;
}

int main() {
    int pid1, pid2;

    signal(3, stop);
    pid1 = fork();
    // Create a new process
    
    if(pid1 == -1) {
        printf("Failed Creating New Process!");
        return 0;
    }
    if(pid1 > 1) {
        pid2 = fork();

        if(pid2 == -1) {
            printf("Failed Creating New Process!");
            return 0;
        }

        if(pid2 > 0) {
            // all the three process will get into track.
            wait_flag = 1;
            sleep(5);
            kill(pid1, 16);
            kill(pid2, 17);
            wait(0);
            wait(0);
            printf("\n Parent process is killed!!\n");
            return 0;
        }
        else {
            wait_flag = 1;
            signal(17, stop);
            printf("\n Child process 2 is killed by parent!!\n");
            return 0;
        }
    }
    else {
        wait_flag = 1;
        signal(16, stop);
        printf("\n Child process 1 is killed by parent!!\n");
        return 0;
    }
    return 0;
}
