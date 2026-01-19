#include <stdio.h>
#include <unistd.h>
int main()
{
    int pid;
    pid = fork(); //Commenter
    if (pid == 0) // Commenter
    {
        for (;;)
            printf("je suis le fils\n");
    }
    else
    {
        for (;;)
            printf("je suis le père\n");
    }
    return 0;
}
