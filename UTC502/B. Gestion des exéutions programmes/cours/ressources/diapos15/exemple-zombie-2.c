// ------------------------------------------------------------------
// exemple-zombie-2.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main (void)
{
	int   i;
	pid_t pid;

	if ((pid = fork()) < 0) {
		fprintf(stderr, "error during fork()\n");
		exit(EXIT_FAILURE);
	}

	if (pid != 0) {
		fprintf(stdout, "Parent : my PID is %ld\n", (long)getpid());
		sleep(2);
		fprintf(stdout, "Parent : terminating\n");
		exit(EXIT_SUCCESS);

	} else {
		for (i = 0; i < 5; i ++) {
			fprintf(stdout, "Child : my parent is %ld\n", (long)getppid());
			sleep(1);
		}
	}
	return EXIT_SUCCESS;
}

/*
Objectif du programme
=====================

Le processus père va se termine au bout de 2 secondes, alors que le fils va 
continuer à afficher régulièrement le PID de son père.
*/


/* Commentaire sur le code

Lexécution montre bien que le processus 1 (init) adopte le processus fils dès que le
père se termine. Au passage, on remarquera que, aussitôt le processus père
terminé, le shell reprend la main et affiche le prompt.
*/


/*
Sortie du programme
===================

(base) ┌──(komo㉿kali)-[~/…/B. Gestion des exécutions programmes/cours/ressources/diapos15]
└─$ ./exemple-zombie-2.exe
Parent : my PID is 737973
Child : my parent is 737973
Child : my parent is 737973
Parent : terminating
Child : my parent is 1
                                                                                                                                                                                    
(base) ┌──(komo㉿kali)-[~/…/B. Gestion des exécutions programmes/cours/ressources/diapos15]
└─$ Child : my parent is 1
Child : my parent is 1

                                                                                                                                                                                    
(base) ┌──(komo㉿kali)-[~/…/B. Gestion des exécutions programmes/cours/ressources/diapos15]
└─$ 

*/