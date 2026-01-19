// ------------------------------------------------------------------
// exemple-get-priority-min-max.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// Page 311 (pdf)
// ------------------------------------------------------------------

#include <sched.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main (void)
{
	fprintf(stdout, "Scheduling FIFO :\n  %d <= prio <= %d\n",
		sched_get_priority_min(SCHED_FIFO),
		sched_get_priority_max(SCHED_FIFO));
	fprintf(stdout, "Scheduling RR :\n  %d <= prio <= %d\n",
		sched_get_priority_min(SCHED_RR),
		sched_get_priority_max(SCHED_RR));
	fprintf(stdout, "Scheduling OTHER :\n  %d <= prio <= %d\n",
		sched_get_priority_min(SCHED_OTHER),
		sched_get_priority_max(SCHED_OTHER));
	return EXIT_SUCCESS;
}


/*
Objectif du programme
=====================

Il est important, pour respecter la portabilité d'un programme, 
d'utiliser les appels systèmes sched_get_priority_min() et 	sched_get_priority_max(),
qui donneent respectivement les valeurs minimales et maximales des priorités associées 
à une politiqe d'ordonnancement donnée.

Commentaire sur le code
========================
<sys/wait.h> sont :
 int sched_get_priority_min(int policy);
 int sched_get_priority_max(int policy); 
policy, la politique d'ordonnancement concernée :
- SCHED_FIFO
- SCHED_RR
- SCHED_OTHER

Sortie du programme
===================

Scheduling FIFO :
  1 <= prio <= 99
Scheduling RR :
  1 <= prio <= 99
Scheduling OTHER :
  0 <= prio <= 0

Nous voyons que la priorité temps réel d'une tâche ordonnancé en OTHER est
toujours nulle, mais qu'elle est pondérée par la valeur de nice afin de 
permettre de calculer la priorité dynamique.

*/