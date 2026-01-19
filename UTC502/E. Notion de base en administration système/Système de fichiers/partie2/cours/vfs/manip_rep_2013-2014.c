/********************************************************************************************/
/* Exemple de manipulation d'un répertoire                                                  */
/********************************************************************************************/

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>

main(){
	char nom[50]; //Attention à la longueur du chemin vers le répertoire, sinon => Erreur de segmentation
	struct dirent *entree;
	DIR *fd;

	getcwd(nom,50);
	printf("Mon répertoire courant est %s\n", nom);

	fd = opendir(nom);
	entree = readdir(fd);
	while(entree != NULL){
		printf("Le numéro d'inode de l'entree est %d  et le nom de fichier correspondant est %s\n", entree -> d_ino, entree -> d_name);
		entree = readdir(fd);
	}
	closedir(fd);
}


/*
Référence : Programmation système en C sous Linux, page 531-532.
-----------

Au niveau applicatif, les fonctions opendir(), readdir(), closedir() nous permettent
d’accéder au contenu d’un répertoire sous forme de structures dirent. Pour assurer la portabilité d’une application, nous nous limiterons à l’utilisation des deux seuls champs qui soient définis par SUSv3, char d_name[], qui contient le nom du fichier ou du sous-répertoire et ino_t d_ino, le numéro d’i-nœud du fichier (ce dernier champ est accessible si la constante symbolique _XOPEN_SOURCE contient la valeur 500).

Ces fonctions sont définies dans <dirent.h> :
DIR * opendir (const char * repertoire);
struct dirent * readdir (DIR * dir);
int closedir(DIR * dir);

Le type DIR, défini dans <sys/types.h>, la fonction readdir() renvoie l’entrée suivante ou NULL une fois arrivée à la fin du répertoire. Lorsqu’on a fini d’utiliser le répertoire, on le referme avec closedir().
*/
