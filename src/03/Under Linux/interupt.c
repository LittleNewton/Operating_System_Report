#include<stdio.h>
#include<signal.h>

int wait_flag;

void stop() {
    wait_flag = 0;
}

int main(int argc, char *argv[]) {
    signal(SIGINT, stop);
    printf("wait_flag = %d", wait_flag);
    return 0;
}