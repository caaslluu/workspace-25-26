/******************************************************************/
/* Utilisation des primitives liées à l’ordonnancement */
/******************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sched.h>
#include <sys/wait.h>
#include <errno.h>
//#include <ctype.h>
#include <sys/resource.h>

int main(){
    pid_t ret,pid;
    int politique, status, priorite;
    struct timespec quantum;
    struct sched_param param;
    ret = fork();
    if (ret == 0)
    {
        pid = getpid();
        printf("je suis le fils, ma priorité d’ordonnancement est: %d\n", getpriority(PRIO_PROCESS, pid));
        politique = sched_getscheduler (pid);
        if (politique == SCHED_RR)
           printf("je suis le fils, ma politique d’ordonnancement est SCHED_RR\n");
       if (politique == SCHED_FIFO)
           printf("je suis le fils, ma politique d’ordonnancement est SCHED_FIFO\n");
       if (politique == SCHED_OTHER)
           printf("je suis le fils, ma politique d’ordonnancement est SCHED_OTHER\n");
       param.sched_priority = 10;
       setpriority(PRIO_PROCESS, pid, 10);
       if (sched_setscheduler(pid, SCHED_FIFO, &param) == -1)
           perror ("pb setsceduler");
       priorite= getpriority(PRIO_PROCESS, pid);
       printf("je suis le fils, ma priorité d’ordonnancement est: %d\n", priorite);
       politique = sched_getscheduler (pid);
       if (politique == SCHED_RR)
           printf("je suis le fils, ma nouvelle politique d’ordonnancement est SCHED_RR\n");
       if (politique == SCHED_FIFO)
           printf("je suis le fils, ma nouvelle politique d’ordonnancement est SCHED_FIFO\n");
       if (politique == SCHED_OTHER)
           printf("je suis le fils, ma nouvelle politique d’ordonnancement est SCHED_OTHER\n");
        //exit(0);
   }
   else
   {
    printf ("Voici les priorités min et max de la politique SCHED_FIFO, %d, %d\n",
       sched_get_priority_min(SCHED_FIFO),
       sched_get_priority_max (SCHED_FIFO));
    printf ("Voici les priorités min et max de la politique SCHED_RR, %d, %d\n",
       sched_get_priority_min (SCHED_RR),
       sched_get_priority_max (SCHED_RR));
    sched_rr_get_interval(getpid(),&quantum);
    printf ("Voici les la valeur du quantum de la politique SCHED_RR, %d seconde, %d nanosecondes\n",quantum.tv_sec, quantum.tv_nsec);
    wait(&status); 
    return 0;
}
}


/*
Objectif du programme
=====================

/!\ Donner en eval ? /!\


Nous donnons l’exemple suivant qui utilise les primitives liées à l’ordonnancement
des processus. Dans cet exemple, le processus père affiche les valeurs de priorités
minimum et maximum pour les politiques SCHED_FIFO et SCHED_RR, ainsi que la
valeur du quantum pour la politique SCHED_RR. Le processus fils quant à lui affiche
sa politique d’ordonnancement ainsi que sa priorité statique, puis il change de poli-
tique d’ordonnancement et de priorité. Afin que ce changement de politique puisse
être réalisé, le programme suivant est exécuté par le super-utilisateur. 


Commentaire sur le code
=======================
synthèse des programmes précédents



Sortie du programme
===================

Voici les priorités min et max de la politique SCHED_FIFO, 1, 99
Voici les priorités min et max de la politique SCHED_RR, 1, 99
Voici les la valeur du quantum de la politique SCHED_RR, 0 seconde, 8000000 nanosecondes
je suis le fils, ma priorité d’ordonnancement est: 0
je suis le fils, ma politique d’ordonnancement est SCHED_OTHER
pb setsceduler: Operation not permitted
je suis le fils, ma priorité d’ordonnancement est: 10
je suis le fils, ma nouvelle politique d’ordonnancement est SCHED_OTHER


*/