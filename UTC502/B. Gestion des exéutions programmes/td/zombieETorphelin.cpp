#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    int pid;
    pid = fork();
    if (pid == 0){
        printf("je suis le fils zombi\n");
    }
    else
    {
	    printf("Je suis le pére\n");
	    sleep(10);
        pid = fork();
        if (pid == 0)
        {
            for (;;)
                printf("je suis le fils orphelin\n");
        }
    }
    return 0;
}


/*
 Pour les tests :
 - ouvrir un autre terminal et  executer la commande watch (ps -lu komo | grep zombieETorpheli) 
 */
