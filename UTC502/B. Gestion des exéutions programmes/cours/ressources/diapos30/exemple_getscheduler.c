
/*
Voir pour le code le livre BLAESS, page 273.
*/


#include <sched.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
	int i;
	int ordonnancement;
	int pid;

	for (i = 0; i < argc; ++i)
	{
		fprintf(stdout, "%s : ", argv[i]);
		if ((sscanf(argv[i], "%d", &pid) != 1) || (ordonnancement = sched_getscheduler(pid)) < 0)
		{
			fprintf(stdout, "Invalide\n");
			continue;
		}
		switch(ordonnancement)
		{
			case SCHED_RR : fprintf(stdout, "RR\n"); break;
			case SCHED_FIFO : fprintf(stdout, "FIFO\n"); break;	
			case SCHED_OTHER : fprintf(stdout, "RR\n"); break;
			default : fprintf(stdout, "???\n"); break;
		}
		
	}

	return 0;
}


/*
Objectif du programme
=====================

Le programme sert a illustrer l'utilisation de l'appel système sched_getscheduler()

*/


/*

Commentaire sur le code
======================

 #include <sched.h>
int sched_getscheduler(pid_t pid)

Il renvoie -1 en cas d'erreur, sinon, il renvoie l'une des trois constanes :
- SCHED_RR
- SCHED_FIFO
- SCHED_OTHER
en fonction de l'ordonnancement du processus dont on fournit le PID, 
si on passe un PID nul, cette fonction renvoie la politique du processus appelant.

/*

Sortie du programme
===================

L'exécution permet de vérifier  la politique d'ordonnacement des processus courant.


(base) ┌──(komo㉿kali)-[~/…/B. Gestion des exécutions programmes/cours/ressources/diapos30]
└─$ ./exemple_getscheduler 1 2 3 4 $$
./exemple_getscheduler : Invalide
1 : RR
2 : RR
3 : RR
4 : RR
712130 : RR

La variable $$ représente le PID du shell courant (712130)

*/