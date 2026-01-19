// ------------------------------------------------------------------
// exemple-boucle-temps-reel.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2010 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------

#include <sched.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main(void)
{
	struct sched_param param;

	param.sched_priority = 99;
	if (sched_setscheduler(0, SCHED_FIFO, & param) != 0) {
		perror("SCHED_FIFO");
		exit(1);
	}

	alarm(20); // On recevra SIGALRM dans 20 secondes
	while (1) // Boucle infinie
		;
	return 0;
}

/*
Objectif du programme
=====================

Le programme sert a illustrer l'utilisation de l'appel système sched_setscheduler().

Pour passer un processus en temps-réel (SCHED_RR ou SCHED_FIFO), 
il faut que l'appelant dispose de la capacité CAP_SYS_NICE ousoit exécuté en root.

La politique d'ordonnancement est héritée au travers d'un fork() ou d'un exec().
Il est donc possible pour un processus de modifier sa propre politique, puis de lancer une commande indépendante.

la structure sched_param contient le champ sched_priority, qui représente la priorité du procesus.

Le programme permet de vérifier le fonctionnement de l'ordonnacement temps-réel. 
Le programme exécute une boucle consommatrice de CPU, à une priorité élevée, 
mais se termine au bout de 20 secondes sur réception d'un signal d'alarme qu'il ne gére pas.

*/

/*

Commentaire sur le code
======================

 #include <sched.h>
int sched_setscheduler(pid_t pid, int policy, const struct sched_param*param)

Le second paramètre est le type d'ordonnancement désiré :
- SCHED_RR
- SCHED_FIFO
- SCHED_OTHER

 */

/*

Sortie du programme
===================
Il faut une machine avec 2 proesseurs !

1er terminal
============

root@moddebian:/home/user/projects/Programmation de processus : l’exemple de LINUX/diapos30# echo -1 > /proc/sys/kernel/sched_rt_runtime_us
root@moddebian:/home/user/projects/Programmation de processus : l’exemple de LINUX/diapos30# sleep 5; taskset -c 0 ./exemple_setscheduler.exe

2nd terminal
============
root@moddebian:/home/user/projects/Programmation de processus : l’exemple de LINUX/diapos30# sleep 5; taskset -c 1 ./exemple_setscheduler.exe


On peut par exemple, lancer une vidéo et constater que le système se fige pendant 20 secondes, seules nos boucles sont exécutés.
Une fois le délai écoulé, le fonctionnement reprend normalement.


*/