// ------------------------------------------------------------------
// exemple-fork.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <sys/wait.h>

int main (void)
{
	pid_t child_pid;

	do {
		child_pid = fork();
	} while ((child_pid == -1) && (errno == EAGAIN));

	if (child_pid == -1) {
		fprintf(stderr, "unable to fork(), errno=%d\n", errno);
		return 1;
	}
	if (child_pid == 0) { /* child */
		fprintf(stdout, "Child:  PID=%ld, PPID=%ld\n",
		        (long)getpid(), (long)getppid());
		return 0;
	} else { /* parent */
		fprintf(stdout, "Parent: PID=%ld, PPID=%ld, child=%ld\n",
		        (long)getpid(),(long)getppid(),(long)child_pid);
		wait(NULL);
		return 0;
	}
}

/*
Remarques
=========

After a fork(), it is indeterminate which process—the parent or the child—next has access to the CPU. 
On a multiprocessor system, they may both simultaneously get access to a CPU.
Applications that implicitly or explicitly rely on a particular sequence of execution in order to achieve correct results are open to failure due to race conditions

That said, an operating system can allow you to control this order. For instance, Linux has /proc/sys/kernel/sched_child_runs_first :
0 -> père en premier
1 -> le fils en premier

Test sur la VM :
root@moddebian:/home/user# echo 1 > /proc/sys/kernel/sched_child_runs_first
root@moddebian:/home/user/projects/Programmation de processus : l’exemple de LINUX/diapos14# gcc -o exemple-fork.exe exemple-fork.c 
root@moddebian:/home/user/projects/Programmation de processus : l’exemple de LINUX/diapos14# ./exemple-fork.exe                                 
Child:  PID=4866, PPID=4865                                                                                                                     
Parent: PID=4865, PPID=4835, child=4866                                                                                                         
root@moddebian:/home/user/projects/Programmation de processus : l’exemple de LINUX/diapos14# echo 0 > /proc/sys/kernel/sched_child_runs_firstroot@moddebian:/home/user/projects/Programmation de processus : l’exemple de LINUX/diapos14# ./exemple-fork.exe 
Parent: PID=4868, PPID=4835, child=4869                                                                                                         
Child:  PID=4869, PPID=4868
=> OK on a le comportement prévu.

Test sur le host
┌──(root㉿kali)-[/home/…/B. Gestion des exécutions programmes/cours/ressources/diapos14]
└─# cat /proc/sys/kernel/sched_child_runs_first
0
                                                                                             
┌──(root㉿kali)-[/home/…/B. Gestion des exécutions programmes/cours/ressources/diapos14]
└─# ./exemple-fork.exe      
Parent: PID=716524, PPID=715734, child=716525
Child:  PID=716525, PPID=716524
                                                                                             
┌──(root㉿kali)-[/home/…/B. Gestion des exécutions programmes/cours/ressources/diapos14]
└─# echo 1 >  /proc/sys/kernel/sched_child_runs_first
                                                                                             
┌──(root㉿kali)-[/home/…/B. Gestion des exécutions programmes/cours/ressources/diapos14]
└─# cat /proc/sys/kernel/sched_child_runs_first      
1
                                                                                             
┌──(root㉿kali)-[/home/…/B. Gestion des exécutions programmes/cours/ressources/diapos14]
└─# ./exemple-fork.exe                               
Parent: PID=716811, PPID=715734, child=716812
Child:  PID=716812, PPID=716811
=> Aucun changement, c'est toujours le père qui exécuté en 1er !?
*/