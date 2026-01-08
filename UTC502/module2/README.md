 Module 2 : Gestion des exécutions programmes : processus, ordonnancement, threads
Plan du cours

    NOTION DE PROCESSUS
    ORDONNANCEMENT SUR L’UNITÉ CENTRALE
    SYNCHRONISATION ET COMMUNICATION ENTRE PROCESSUS
    COMPLÉMENT : NOTION DE PROCESSUS LÉGER OU THREAD

TP/TD

    TD Processus et ordonnancement

Évaluation

    QCM :
        Livre Architecture…
            12.6 QU’AVEZ-VOUS RETENU ? page 380 (pdf)
        Livre programmation système et réseau DELACROIX :
            Qu’avez-vous retenu ? page 69 (pdf)
    Programmation :
        Programme 1 – Un processus offre deux services aux utilisateurs :
            un premier service effectuant l’addition entre deux nombres entiers x et y
            et un second service effectuant la multiplication entre deux nombres flottants f et g.

Chaque service est rendu par un processus fils distincts Fils1 et Fils2. Les étapes sont les suivantes :

    le père demande le type d’opération à effectuer (multiplication ou addition) et les deux valeurs sur lesquelles réaliser l’opération.
    le père crée un fils pour réaliser ce service.
    selon le type d’opération, le fils écrase le code de son père, soit par le code exécutable du service Fils1, soit par le code exécutable du service Fils2. Ce code exécutable effectue l’opération demandée, affiche le résultat puis se termine. Le fils renvoie une valeur de status nulle à son père si le service a été correctement rendu et sinon une valeur positive.
    le père attend son fils et affiche la valeur renvoyée par celui-ci.

    Programme 2 – Même énoncé, mais en utilisant des threads pour rendre les deux services Fils1 et Fils2.


