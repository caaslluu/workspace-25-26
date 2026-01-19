/****************************************************************************************/
/* Exemple de manipulation d'un fichier : création, positionnment, fermeture            */ 
/* Les primitives offertes pour l'utilisateur par le VFS concernent d'une part la       */
/* manipulation des fichiers , d'autre part la manipulation des répertoires.             */
/* Un trosième groupe de primitives permet de manipuler les liens symboliques.          */  
/* Enfin, un quatrième groupe de primitives concerne les partitions.                    */
/*                                                                                      */
/* Références :                                                                         */
/* Livre : Développement système sous Linux page 586, 615                               */
/*                                                                                      */
/*                                                                                      */
/*                                                                                      */
/****************************************************************************************/


#include <stdio.h>
#include <sys/types.h> // pour le type de retour des fonction read, write, lseek
#include <sys/stat.h> // pour S_IRUSR, S_IWUSR
#include <fcntl.h> // pour les prototypes de open, ainsi que les constantes 0_RDWR, O_CREAT
#include <unistd.h> //pour fonctions read, write, close

main(){

	struct eleve{ // Définition de l'enregistrement eleve
		char nom[10];
		int note;
	};
	int fd, i, ret;
	struct eleve un_eleve;

	fd = open("./fichnotes.txt",O_RDWR|O_CREAT,S_IRUSR|S_IWUSR);
	if(fd == -1) perror("prob open");
	i = 0;
	while(i < 4){
		printf("Donnez le nom de l'élève \n");
		scanf("%s", un_eleve.nom); //remarque pas de & car tableau
		printf("Donnez la note de l'élève \n");
		scanf("%d", &un_eleve.note);
		write(fd, &un_eleve, sizeof(un_eleve)); //fd incrémenté du nombre d'octets écrits (pas tous a fait vrai. cf Livre : Développement système sous Linux page 629 (task_struct -> files_struct -> file). Ecriture de l'enregistrement eleve dans le fichier.
		i++;
	}
	/* Les lectures et les écritures sur un fichier s'effectue de façon
	séquentielle. Il est cependant possible de modifier la position
	courante du pointeur de fichier à l'aide de la primitive lseek() */
	ret = lseek(fd, 0, SEEK_SET); //le pointeur fd est modifié d'une valeur égale à 0 octets selon une base SEEK_SET(=début du fichier)
	if(ret == -1)  perror("prob lseek");
	printf("La nouvelle position est %d\n", ret);
	i = 0;
	while(i < 4){
		read(fd, &un_eleve, sizeof(un_eleve));//fd incrémenté du nombre d'octets lus
		printf("Le nom et la note de l'élève sont %s, %d\n", un_eleve.nom, un_eleve.note
		);
		i++;
	}
	close(fd);
}


/* Commentaire sur le code :

Il existe en tout six appels-système pour lire ou écrire des données, dont quatre sont rarement employés et sont en fait des dérivés des deux principaux.
• ssize_t read (int descripteur, void * bloc, size_t taille);
• ssize_t readv (int descripteur, const struct iovec * vecteurs, int nombre);
• ssize_t pread (int descripteur, void * bloc, size_t taille, off_t position);
• ssize_t write (int descripteur, const void * bloc, size_t taille);
• ssize_t writev (int descripteur, const struct iovec * vecteur, int nombre);
• ssize_t pwrite (int descripteur, const void * bloc, size_t taille, off_t position);


Appels système : open
int open (const char * nom_fichier, int attributs, ... , [mode_t mode]);
La fonction open() prend en premier argument le nom d’un fichier à ouvrir. 
Le second argument est une combinaison de plusieurs éléments assemblés par un OU binaire.
Tout d’abord, il faut impérativement utiliser l’une des trois constantes suivantes :
• O_RDONLY : fichier ouvert en lecture seule ;
• O_WRONLY : fichier ouvert en écriture seule ;
• O_RDWR : fichier ouvert à la fois en lecture et en écriture.


• O_CREAT : pour créer le fichier s’il n’existe pas.

Le troisième argument de l’appel open() ne sert que lors d’une création de fichier. Il faut donc
que l’attribut O_CREAT ait été indiqué. Cette valeur, de type mode_t, sert à signaler les autorisations d’accès au fichier nouvellement créé.
• S_IRUSR 00400 Autorisation de lecture pour le propriétaire du fichier.
• S_IWUSR 00200 Autorisation d’écriture pour le propriétaire du fichier.

Appels système : lseek
Il n’existe qu’un seul appel-système, nommé lseek(), permettant de consulter ou de modifier la position courante dans un descripteur de fichier :
Son prototype est déclaré dans <unistd.h> : off_t lseek (int descripteur, off_t position, int debut);
Le positionnement dans un descripteur est mémorisé dans la table des fichiers et non dans la table des descripteurs.





• <fcntl.h> Contient les prototypes de open() et de creat(), ainsi que les constantes O_xxx.
• sys/stat.h> Contient les constantes de mode S_Ixxx.
• <sys/types.h> Pas obligatoire sous Linux, ce fichier peut être nécessaire sous d’autres versions d’Unix pour obtenir la définition de mode_t.
• <unistd.h> Contient la déclaration de close(). Cette fonction n’est en effet pas limitée aux fichiers, mais sert pour tous les descripteurs Unix.

*/



