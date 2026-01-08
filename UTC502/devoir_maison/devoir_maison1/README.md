```
kvm-02@kvm-02:~/temp$ ll
total 20
drwxrwxr-x  2 kvm-02 kvm-02 4096 oct.   3 14:37 ./
drwxrwxrwx 14 kvm-02 kvm-02 4096 oct.   3 14:37 ../
-rwxrwxr-x  1 kvm-02 kvm-02   92 oct.   3 14:37 init.sh*
-rwxrwxr-x  1 kvm-02 kvm-02  743 oct.   3 14:27 restore.sh*
-rwxrwxr-x  1 kvm-02 kvm-02  361 oct.   3 14:26 save.sh*
kvm-02@kvm-02:~/temp$ ./init.sh 
kvm-02@kvm-02:~/temp$ ll
total 28
drwxrwxr-x  4 kvm-02 kvm-02 4096 oct.   3 14:37 ./
drwxrwxrwx 14 kvm-02 kvm-02 4096 oct.   3 14:37 ../
-rwxrwxr-x  1 kvm-02 kvm-02   92 oct.   3 14:37 init.sh*
drwxrwxr-x  2 kvm-02 kvm-02 4096 oct.   3 14:37 rep_dest/
drwxrwxr-x  2 kvm-02 kvm-02 4096 oct.   3 14:37 rep_src/
-rwxrwxr-x  1 kvm-02 kvm-02  743 oct.   3 14:27 restore.sh*
-rwxrwxr-x  1 kvm-02 kvm-02  361 oct.   3 14:26 save.sh*
kvm-02@kvm-02:~/temp$ ll rep_src/
total 12
drwxrwxr-x 2 kvm-02 kvm-02 4096 oct.   3 14:37 ./
drwxrwxr-x 4 kvm-02 kvm-02 4096 oct.   3 14:37 ../
-rw-rw-r-- 1 kvm-02 kvm-02   40 oct.   3 14:37 file.txt
kvm-02@kvm-02:~/temp$ cat rep_src/file.txt 
petit test pour voir si ça marche bien
kvm-02@kvm-02:~/temp$ ./save.sh 
Sauvegarde de rep_src dans rep_dest/svg._251003-143820.tar.bz2
tar: Option --newer-mtime: Treating date '1 day ago' as 2025-10-02 14:38:20.029479966
rep_src/
rep_src/file.txt
Sauvegarde terminee.
kvm-02@kvm-02:~/temp$ ll rep_dest/
total 12
drwxrwxr-x 2 kvm-02 kvm-02 4096 oct.   3 14:38 ./
drwxrwxr-x 4 kvm-02 kvm-02 4096 oct.   3 14:37 ../
-rw-rw-r-- 1 kvm-02 kvm-02  213 oct.   3 14:38 svg._251003-143820.tar.bz2
kvm-02@kvm-02:~/temp$ ./restore.sh 
Archives disponibles :
0 - svg._251003-143820.tar.bz2
Choisir l'archive à restaurer : 0
Restauration de svg._251003-143820.tar.bz2...
rep_src/
rep_src/file.txt
Restauration terminée.
kvm-02@kvm-02:~/temp$ ll rep_src/
total 12
drwxrwxr-x 2 kvm-02 kvm-02 4096 oct.   3 14:37 ./
drwxrwxr-x 4 kvm-02 kvm-02 4096 oct.   3 14:37 ../
-rw-rw-r-- 1 kvm-02 kvm-02   40 oct.   3 14:37 file.txt
kvm-02@kvm-02:~/temp$ rm rep_src/file.txt 
kvm-02@kvm-02:~/temp$ ./restore.sh 
Archives disponibles :
0 - svg._251003-143820.tar.bz2
Choisir l'archive à restaurer : 0
Restauration de svg._251003-143820.tar.bz2...
rep_src/
rep_src/file.txt
Restauration terminée.
kvm-02@kvm-02:~/temp$ ll rep_src/
total 12
drwxrwxr-x 2 kvm-02 kvm-02 4096 oct.   3 14:37 ./
drwxrwxr-x 4 kvm-02 kvm-02 4096 oct.   3 14:37 ../
-rw-rw-r-- 1 kvm-02 kvm-02   40 oct.   3 14:37 file.txt
kvm-02@kvm-02:~/temp$ 

```

# Consignes
Partie 1 : sauvegarde
Objectif : Mettre en place un système de sauvegarde simple locale. Pour cela, nous allons faire les choix suivants :

utilisation de tar avec la compression bzip2 des données modifiées depuis moins de 24 heures ;
stockage sur la même machine (pour l'évaluation, bien sûr, ce serait inenvisageable en production !) dans un répertoire dédié : rep_dest ;
sauvegarde d'un dossier rep_src
Étape 1
⇒ Créer un nouveau projet bash avec votre éditeur préféré.



Étape 2
⇒ Adapter le fichier save.sh suivant, pour qu'il puisse répondre aux besoins :

#!/usr/bin/env bash #Script de sauvegarde   #Dossier à sauvegarder DATA_TO_BACKUP="repToSave" #A Modifier   #Partition recevant la sauvegarde BACKUP_DEV=/dev/sdb1 #A Modifier BACKUP_DIR=/sauvegarde #A Modifier   #Définition de la date du jour afin de pouvoir récupérer (a adapter) #l'année ($6), le mois ($2) et le jour ($3) pour nommer le fichier de sauvegarde IFS=/ set $(date +%D) annee=$3 mois=$2 jour=$1   unset IFS   #Sauvegarde des données echo "Sauvegarde de $DATA_TO_BACKUP dans $BACKUP_DIR/svg_$annee$mois$jour.tar.bz2" tar cvjf $BACKUP_DIR/svg._$annee$mois$jour.tar.bz2 --newer-mtime '1 day ago' "$DATA_TO_BACKUP"
Étape 3
⇒ Créer les répertoires rep_src et rep_dest.
⇒ Créer un fichier file.txt avec un texte simple dans le répertoire rep_src.
⇒ Exécuter le script save.sh.

Étape 4
⇒ Vérification de la création de l'archive svg._date.tar.bz2 (date = date de création de l'archive) dans le répertoire rep_dest.
⇒ On supprime le répertoire rep_src.
⇒ Détarer l'archive svg._date.tar.bz2
⇒ Vérifier la restitution du répertoire rep_src a l'emplacement d'origine.

Partie 2 : restauration

Objectif : fournir un script de restauration aux opérateurs de sauvegarde.

Étape 5
Lancer trois fois le script de sauvegarde, celui-ci crée trois archives de sauvegarde.
le script de restauration liste les archives disponibles dans le répertoire rep_dest ;
Étape 6
l'opérateur de sauvegarde entre l'archive à restaurer ;
Étape 7
le script restaure l'archive.
Étape 8
Améliorer le script en proposant à l'opérateur un menu listant les différentes archives à restaurer. Voir ci-dessous un exemple de session.
Exemple d'exécution
a. On a perdu nos données, la commande ls ne renvoie rien !

~/Sauvegarde$ ls DATA_TO_BACKUP/ ~/Sauvegarde$
b. Mais heureusement, on a des sauvegardes et un script de restauration, restore.sh :

~/Sauvegarde$ ./restore.sh 0-svg._220615-205631.tar.bz2 1-svg._220615-205633.tar.bz2 2-svg._220615-205635.tar.bz2   Choisir l'archive à restaurer : 2
On a trois archives ! L'opérateur choisit de restaurer l'archive 2.

b. Et voilà !

~/Sauvegarde$ ls DATA_TO_BACKUP/ file.txt
La restauration s'est déroulée correctement, la preuve… le fichier file.txt est de nouveau présent dans le répertoire source !

Bien sûr, c'est un script minimal, et on peut l'améliorer à l'envi !
