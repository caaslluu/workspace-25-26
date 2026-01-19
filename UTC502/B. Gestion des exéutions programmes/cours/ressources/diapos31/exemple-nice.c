// ------------------------------------------------------------------
// exemple-nice.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// Page 299 (pdf)
// ------------------------------------------------------------------

#define _GNU_SOURCE
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

volatile long counter = 0;
static int    nice_value;

void signal_handler(int numero)
{
	if (counter != 0) {
		fprintf(stdout, "Child %ld (nice %2d) Counter = %10ld\n",
		                 (long) getpid(), nice_value, counter);
		exit(EXIT_SUCCESS);
	}
}

#define NB_CHILD    5

int main (void)
{
	pid_t   pid;
	int     child;

	/* Creation d'un nouveau groupe de processus */
	setpgid(0, 0);

	signal(SIGUSR1, signal_handler);
	for (child = 0; child < NB_CHILD; child ++) {
		if ((pid = fork()) < 0) {
			perror("fork");
			exit(EXIT_FAILURE);
		}
		if (pid != 0)
			continue;
		nice_value = child * (20 / (NB_CHILD - 1));
		if (nice(nice_value) < 0) {
			perror("nice");
			exit(EXIT_FAILURE);
		}
		/* attente signal de demarrage */
		pause();
		/* comptage */
		while (1)
			counter ++;
	}
	/* processus parent */
	signal(SIGUSR1, SIG_IGN);
	sleep(1);
	kill(-getpgid(0), SIGUSR1);
	sleep(5);
	kill(-getpgid(0), SIGUSR1);
	while (wait(NULL) > 0)
		;
	exit(EXIT_SUCCESS);
}

/*
Objectif du programme
=====================
Le programme va lancé 5 processus fils, chacun d'eux prenant une valeur de gentillesse différente et
se mettant à boucler sur un comptage.
Le processus père les laisse travailler pendant 5 seconde et les arrête.
Pour synchroniser le début et la fin du comptage pour les différents fils, 
nous utilisons un signal émis par le pére à distination du groupe de processus.
Pour être sûr que les fils ont tous démarré avant d'envoyer le signal, le père respecte un petit sommeil d'1 seconde.

Commentaire sur le code
========================
classe de stockage :
volatile : Ce mot-clé sert à spécifier au compilateur que la variable peut être modifiée à son insu. 
Cela annule toute optimisation que le compilateur pourrait faire, et l'oblige à procéder à chaque lecture 
ou écriture dans une telle variable tel que le programmeur l'a écrit dans le code. Ceci a de multiples utilisations : 
pour de la programmation avec de multiples fils d'exécution qui doivent communiquer entre eux ;

static aura pour effet de limiter la portée de la variable ou de la fonction au seul fichier où elle est déclarée, 
toujours dans le but de garantir un certain niveau d'encapsulation.

A REVOIR !!

Sortie du programme
===================

Child 869004 (nice 15) Counter = 3785578801
Child 869003 (nice 10) Counter = 4074547191
Child 869005 (nice 20) Counter = 3036907423
Child 869001 (nice  0) Counter = 5352589894
Child 869002 (nice  5) Counter = 5175319224

*/