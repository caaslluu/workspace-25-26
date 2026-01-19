/******************************************************************/
/* Création d’un processus fils */
/******************************************************************/
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <sys/wait.h>

int main()
{
    pid_t ret;
    ret = fork();
    if (ret == 0)
    {
        printf("je suis le fils; mon pid est %d\n", getpid());
        printf("pid de mon père, %d\n", getppid());
        return 0;
    }
    else
    {
        printf("je suis le père; mon pid est %d\n", getpid());
        printf("pid de mon fils, %d\n", ret);
        wait(NULL); // Pour attendre la fin d'exécution du fils.
        return 0;
    }


}
