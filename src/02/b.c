// filename: Program_FORK_2

#include <stdio.h>
#include <unistd.h>

int main() {
    int p1, p2, i;
    p1 = fork();
    if(p1 == -1) {
        printf("Failed Create New Process!");
        return 0;
    }

    if (p1 == 0) {
        for (i = 0; i < 10; i++) {
            printf("%d\tdaughter-----%d\n",getpid(), i);
        }
    }
    else {
        p2 = fork();
        if (p2 == -1) {
            printf("Failed Create New Process!");
            return 0;
        }

        if (p2 == 0) {
            for (i = 0; i < 10; i++) {
                printf("%d\tson----------%d\n",getpid(), i);
            }
        }
        else {
            for (i = 0; i < 10; i++) {
                printf("%d\tparent-------%d\n",getpid(), i);
            }
        }
    }
    return 0;
}
