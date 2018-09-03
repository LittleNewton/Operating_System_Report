// filename: a.c

#include <stdio.h>
#include <unistd.h>

int main() {
    printf("%d-----HEAD BEGIN?\n",getpid());
    int p1, p2;
    // the process ID we will need
    p1 = fork();
    if (p1 == -1) {
        printf("Failed Create New Process!");
        return 0;
    }

    // if not failed, p1 == ProcessID(in father prcess) or 0(in child process)
    if (p1 == 0) {
        printf("%d\tb\n",getpid());
        // child process 
    }
    else {
        // father process
        p2 = fork();
        if (p2 == -1) {
            printf("Failed Create New Process");
            return 0;
        }
     
        if (p2 == 0) {
            printf("%d\tc\n",getpid());
        }
        else {
            printf("%d\ta\n",getpid());
        }
    printf("\t%d\n",getpid());
    }
    return 0;
}
