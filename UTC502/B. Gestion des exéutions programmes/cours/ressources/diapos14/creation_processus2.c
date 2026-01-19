/******************************************************/
/* Création d'un processus fils */
/******************************************************/

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <sys/wait.h>


void affiche(const char*, pid_t);

int main()
{
    pid_t ret;
    ret = fork();
    printf("--TEST-- %d\n", ret);

    if (ret == 0)
    {
        //code exécuté par le fils
        affiche("je suis le fils; mon pid est %d\n", getpid());
        affiche("pid de mon père, %d\n", getppid());
        return 0;
    }

    else
    {
        //code exécuté par le père
        affiche("je suis le père; mon pid est %d\n", getpid());
        affiche("pid de mon fils, %d\n", ret);
        wait(NULL); // Pour attendre la fin d'exécution du fils.
        return 0;
    }


}

void affiche(const char* msg, pid_t val){
    printf(msg, val);
}
