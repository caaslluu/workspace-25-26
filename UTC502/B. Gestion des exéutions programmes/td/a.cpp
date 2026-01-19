/*
Pour i de 1 à 2
{
ret = fork();
if (ret == 0) afficher (i) ;
else afficher(ret);
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
            fprintf(stdout, "Le fils : i = %d, PID = %d, PPID = %d\n", i, getpid(), getppid());
        }
        else fprintf(stdout, "Le pére : PID = %d, PPID = %d, Le fils = %d, i = %d\n", getpid(), getppid(), ret, i);        
    }
    
    return 0;
}
