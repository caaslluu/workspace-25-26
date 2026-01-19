#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    int pid;
    pid = fork();
    if (pid == 0)
    {
        for (;;)
            printf("je suis le fils\n");
    }
    else
    {
        printf("je suis le père\n");
        wait(NULL);
        return (0);
    }
    return (EXIT_SUCCESS);
}