// ------------------------------------------------------------------
// exemple-getpriority.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// Page 303 (pdf)
// ------------------------------------------------------------------

#include <ctype.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>

void syntax (char * nom)
{
	fprintf(stderr, "Syntax : %s <class> <ident> \n", nom);
	fprintf(stderr, "   <class> = P (PID)\n");
	fprintf(stderr, "             G (PGID)\n");
	fprintf(stderr, "             U (UID)\n");
	exit(EXIT_FAILURE);
}

int main (int argc, char * argv[])
{
	int  class;
	int  id;
	int  priority;

	if (argc != 3)
		syntax(argv[0]);
	if (toupper(argv[1][0]) == 'P')
		class = PRIO_PROCESS;
	else if (toupper(argv[1][0]) == 'G')
		class = PRIO_PGRP;
	else if (toupper(argv[1][0]) == 'U')
		class = PRIO_USER;
	else
		syntax(argv[0]);
	if (sscanf(argv[2], "%d", &id) != 1)
		syntax(argv[0]);
	errno = 0;
	priority = getpriority(class, id);
	if ((priority == -1) && (errno != 0))
		perror(argv[2]);
	
	else
		fprintf(stderr, "%d : %d\n", id, priority);
	return EXIT_SUCCESS;
}


/*
Objectif du programme
=====================

Le programme sert a illustrer l'utilisation de l'appel système int getpriority().


Commentaire sur le code
========================
#include <sys/wait.h>
int getpriority(int classe, int id);

En fonction de la classe indiquée en premier argument, l'id fourni en second est interprété différemment :
- PRIO_PROCESS : PID du processus visé.
- PRIO_PGRP : PGID du groupe de processus concerné.
- PRIO_USER : UID de l'utilisateur dont on vise tous les processus.
La valuer de retour de getpriority correspond à la priorité statique du proessus, qui s'étend entre PRIO_MIN (-20) et PRIO_MAX (20)


Sortie du programme
===================

(base) ┌──(komo㉿kali)-[~/…/B. Gestion des exécutions programmes/cours/ressources/diapos31]
└─$ ./exemple-getpriority P 10
10 : -20

*/