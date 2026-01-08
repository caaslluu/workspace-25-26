Configuration de l'IDE Cursor
Installer les outils pour le débugger

    Installer le paquet gdb

sudo apt update
sudo apt install gdb

    Installer le plugin C/C++ Debug (gdb).


    Compiler le projet en ligne de commande

~/programmation/cpp/monProjet/src$ g++ main.cpp utils.cpp -I ../include -o programme

Utilisation

Pour créer un nouveau projet :

    Copier le dossier MonProjet/ et le renommer avec le nom du nouveau projet.
    Ouvrir le projet dans Cursor.
    Appuyer sur F5, pour compiler et exécuter le nouveau projet.


