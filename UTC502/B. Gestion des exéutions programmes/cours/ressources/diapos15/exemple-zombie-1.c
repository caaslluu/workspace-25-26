// ------------------------------------------------------------------
// exemple-zombie-1.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2010 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main (void)
{
	pid_t pid;
	char  commande[128];

	if ((pid = fork()) < 0) {
		fprintf(stderr, "echec fork()\n");
		exit(EXIT_FAILURE);
	}

	if (pid == 0) {
		/* processus fils */
		sleep(2);
		fprintf(stdout, "Le processus fils %ld se termine\n", (long) getpid());
		exit(EXIT_SUCCESS);

	} else {
		/* processus pere */
		snprintf(commande, 128, "ps %ld", (long)pid); // commande = "ps pid"
		system(commande); // Execute the given line as a shell command.
		sleep(1);
		system(commande);
		sleep(1);
		system(commande);
		sleep(1);
		system(commande);
		sleep(1);
		system(commande);
		sleep(1);
		system(commande);
	}
	return EXIT_SUCCESS;
}

/*
Objectif du programme
=====================

Le processus fils attend 2 secondes avant de se terminer, tandis que le proessus père 
affiche régulièrement l'état de son fils en invoquant la ommande ps.
*/

/*
Commentaire sur le code
=======================

Le S en deuxième colonne indique que le processus fils est endormi au début (sleep)
puis il se termine exit(EXIT_SUCCESS) et passe à l'état zombie Z.
Lorsque le processus père se finit, on invoque manuellement la commande ps, et
on s'aperçoit que le fils a disparu. Dans ce cas, le processus numéro 1, init,
adopte le processus fils orphelin et lit son code retour, ce qui provoque sa disparition.
*/

/*
Sortie du programme
===================

(base) ┌──(komo㉿kali)-[~/…/B. Gestion des exécutions programmes/cours/ressources/diapos15]
└─$ ./exemple-zombie-1.exe
    PID TTY      STAT   TIME COMMAND
 733056 pts/14   S+     0:00 ./exemple-zombie-1.exe
    PID TTY      STAT   TIME COMMAND
 733056 pts/14   S+     0:00 ./exemple-zombie-1.exe
Le processus fils 733056 se termine
    PID TTY      STAT   TIME COMMAND
 733056 pts/14   Z+     0:00 [exemple-zombie-] <defunct>
    PID TTY      STAT   TIME COMMAND
 733056 pts/14   Z+     0:00 [exemple-zombie-] <defunct>
    PID TTY      STAT   TIME COMMAND
 733056 pts/14   Z+     0:00 [exemple-zombie-] <defunct>
    PID TTY      STAT   TIME COMMAND
 733056 pts/14   Z+     0:00 [exemple-zombie-] <defunct>
                                                                                                                                                                                    
(base) ┌──(komo㉿kali)-[~/…/B. Gestion des exécutions programmes/cours/ressources/diapos15]
└─$ ps 733056
    PID TTY      STAT   TIME COMMAND
*/