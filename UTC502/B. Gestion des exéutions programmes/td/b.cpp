/*
Pour i de 1 à 2
{
ret = fork();
if (ret == 0) execl("/home/calcul", "calcul", “5”, “7”, NULL);
}
wait();
*/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>


int main()
{
    for (size_t i = 0; i < 2; i++)
    {
        pid_t ret = fork();
        if (ret == 0)
        {
            fprintf(stdout, "Le fils : %d\n", i);
        }
        fprintf(stdout, "Le pére : %d\n", ret);
    }
    
    wait(NULL);
    return 0;
}
