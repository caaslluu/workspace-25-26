/******************************************************************/
/* Terminaison du processus fils */
/* et affichage de sa valeur de retour */
/******************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
int main()
{
    pid_t ret, fils_mort;
    int status;
    ret = fork();
    if (ret == 0)
    {
        printf("je suis le fils; mon pid est %d\n", getpid());
        printf("pid de mon père, %d\n", getppid());
        exit(0);
    }
    else
    {
        printf("je suis le père; mon pid est %d\n", getpid());
        printf("pid de mon fils, %d\n", ret);
        fils_mort = wait(&status); // le père se met en attente de la mort de son fils 
        printf("je suis le père; le pid de mon fils mort est %d\n",
               fils_mort);
        if (WIFEXITED(status)){ // Interprétation du code status
            printf("je suis le père; le code retour de mon fils est %d\
                  n", WEXITSTATUS(status)); // vrai si le processus fils s’est terminé par un appel à la primitive exit() 
                                            //et en affiche le code de sortie de exit, ici 0.
          }

    }
}



/*
Objectif du programme
=====================

Terminaison du processus fils et affichage de sa valeur de retour.

*/


/* Commentaire sur le code
Un processus père peut se mettre en attente de la mort de l’un de ses fils, par le biais
de  la primitives 
#include <sys/wait.h>
pid_t wait (int *status);
La fonction retourne le PID du fils terminé et le code retour de celui-ci dans la variable status.

L’interprétation du contenu de la variable status se fait à l’aide des macros
WIFEEXITED, WEXITSTATUS, WIFSIGNALED, WIFSTOPPED définies dans le fichier <sys/wait.h>. Ainsi :

• WIFEEXISTED(status) est vrai si le processus fils s’est terminé par un appel à la
primitive exit() ;
• WEXITSTATUS(status) permet de récupérer le code passé par le fils au moment de
sa terminaison ;
• WIFSIGNALED(status) permet de savoir que le fils s’est terminé à cause d’un
signal ;
• WIFSTOPPED(status) indique que le fils est stoppé temporairement.

*/


/*
Sortie du programme
===================

(base) ┌──(komo㉿kali)-[~/…/B. Gestion des exécutions programmes/cours/ressources/diapos16]
└─$ ./terminaison_processus.exe 
je suis le père; mon pid est 741809
pid de mon fils, 741810
je suis le fils; mon pid est 741810
pid de mon père, 741809
je suis le père; le pid de mon fils mort est 741810
je suis le père; le code retour de mon fils est 0                  n                                                                                                                                                                                    
(base) ┌──(komo㉿kali)-[~/…/B. Gestion des exécutions programmes/cours/ressources/diapos16]
└─$ 


*/