#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#define SLEEPTIME 1

int main() {
    int pid = fork();
    int x = 2;
    if (pid == -1)
    {
        return (1);
    }
    if (pid == 0)
        x++;
    sleep(1);
    printf("the value of x: %d\n", x);
    if (pid != 0)
    {
        wait(NULL);
    }
    return 0;
}