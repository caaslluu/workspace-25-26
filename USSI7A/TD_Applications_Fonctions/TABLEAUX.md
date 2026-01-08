# Exercices Java - Tableaux

## Exercice 1 : Tableau d'entiers

**Tableau initialisé** : `{12, 15, 13, 10, 8, 9, 13, 14}`

### Question 1 : Recherche appartenance (oui/non)
```java
int[] tab = {12, 15, 13, 10, 8, 9, 13, 14};
Scanner sc = new Scanner(System.in);

System.out.print("Entrez un entier : ");
int nombre = sc.nextInt();

boolean trouve = false;
for (int i = 0; i < tab.length; i++) {
    if (tab[i] == nombre) {
        trouve = true;
        break;
    }
}

if (trouve) {
    System.out.println("Oui, " + nombre + " appartient au tableau");
} else {
    System.out.println("Non, " + nombre + " n'appartient pas au tableau");
}
```

### Question 2 : Recherche avec dernier indice
```java
int indice = -1;
for (int i = 0; i < tab.length; i++) {
    if (tab[i] == nombre) {
        indice = i; // Continue pour avoir le dernier
    }
}

if (indice != -1) {
    System.out.println(nombre + " trouvé à l'indice " + indice);
}
```

### Question 3 : Recherche avec premier indice
```java
int indice = -1;
for (int i = 0; i < tab.length; i++) {
    if (tab[i] == nombre) {
        indice = i;
        break; // Stop au premier
    }
}
```

### Question 4 : Modifier une case
```java
System.out.print("Entrez un entier : ");
int nombre = sc.nextInt();

System.out.print("Entrez un indice : ");
int indice = sc.nextInt();

if (indice >= 0 && indice < tab.length) {
    tab[indice] = nombre;
    System.out.println("Modification effectuée");
} else {
    System.out.println("Indice incorrect");
}
```

### Question 5 : Échanger deux valeurs
```java
System.out.print("Entrez le premier indice : ");
int ind1 = sc.nextInt();

System.out.print("Entrez le deuxième indice : ");
int ind2 = sc.nextInt();

if (ind1 >= 0 && ind1 < tab.length && ind2 >= 0 && ind2 < tab.length) {
    int temp = tab[ind1];
    tab[ind1] = tab[ind2];
    tab[ind2] = temp;
}
```

---

## Exercice 2 : Tableau saisi au clavier

### Question 1 : Saisir et afficher 6 entiers
```java
int[] tab = new int[6];
Scanner sc = new Scanner(System.in);

System.out.println("Saisissez 6 entiers :");
for (int i = 0; i < tab.length; i++) {
    System.out.print("Entier " + (i+1) + " : ");
    tab[i] = sc.nextInt();
}

System.out.println("Contenu du tableau :");
for (int i = 0; i < tab.length; i++) {
    System.out.print(tab[i] + " ");
}
```

### Question 2 : Recherche du maximum (entiers)
```java
int[] tab = new int[6];
// Saisie...

int max = tab[0];
for (int i = 1; i < tab.length; i++) {
    if (tab[i] > max) {
        max = tab[i];
    }
}

System.out.println("Le plus grand élément est : " + max);
```

### Question 3 : Recherche du maximum (caractères)
```java
char[] tab = new char[6];
Scanner sc = new Scanner(System.in);

System.out.println("Saisissez 6 caractères :");
for (int i = 0; i < tab.length; i++) {
    System.out.print("Caractère " + (i+1) + " : ");
    tab[i] = sc.next().charAt(0);
}

char max = tab[0];
for (int i = 1; i < tab.length; i++) {
    if (tab[i] > max) {
        max = tab[i];
    }
}

System.out.println("Le plus grand caractère est : " + max);
```

### Question 4 : Calcul de la moyenne
```java
int[] tab = new int[6];
// Saisie...

int somme = 0;
for (int i = 0; i < tab.length; i++) {
    somme += tab[i];
}

double moyenne = (double) somme / tab.length;
System.out.println("La moyenne est : " + moyenne);
```
**Note** : Cast en `double` nécessaire car moyenne n'est pas un entier

### Question 5 : Tableau de taille variable
```java
Scanner sc = new Scanner(System.in);

System.out.print("Entrez la taille du tableau : ");
int n = sc.nextInt();

char[] tab = new char[n];

System.out.println("Saisissez " + n + " caractères :");
for (int i = 0; i < tab.length; i++) {
    System.out.print("Caractère " + (i+1) + " : ");
    tab[i] = sc.next().charAt(0);
}
```

---

## Exercice 3 : Nombre de lettres dans un tableau

### Question 1 : Compter majuscules et lettres (sans accents)
```java
char[] tab = new char[10];
Scanner sc = new Scanner(System.in);

System.out.println("Saisissez 10 caractères :");
for (int i = 0; i < tab.length; i++) {
    System.out.print("Caractère " + (i+1) + " : ");
    tab[i] = sc.next().charAt(0);
}

int nbMajuscules = 0;
int nbLettres = 0;

for (int i = 0; i < tab.length; i++) {
    char c = tab[i];
    
    // Vérifier si c'est une lettre
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
        nbLettres++;
        
        // Vérifier si c'est une majuscule
        if (c >= 'A' && c <= 'Z') {
            nbMajuscules++;
        }
    }
}

System.out.println("Nombre de majuscules : " + nbMajuscules);
System.out.println("Nombre de lettres : " + nbLettres);
```

**Logique** :
- Une lettre : `(c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')`
- Une majuscule : `c >= 'A' && c <= 'Z'`

---

## Utilisation du programme complet

```bash
javac ExercicesTableaux.java
java ExercicesTableaux
```

**Menu interactif** :
```
=== EXERCICES SUR LES TABLEAUX ===

Choisissez un exercice :
Exercice 1 : 1.1, 1.2, 1.3, 1.4, 1.5
Exercice 2 : 2.1, 2.2, 2.3, 2.4, 2.5
Exercice 3 : 3.1

Votre choix (ex: 1.1) : 
```

---

## Points clés

- **break** : Sortir d'une boucle dès qu'on trouve
- **Validation d'indice** : `indice >= 0 && indice < tab.length`
- **Échange de valeurs** : Utiliser une variable temporaire
- **Cast double** : `(double) somme / tab.length` pour moyenne
- **charAt(0)** : Récupérer le premier caractère d'une String
- **Ordre caractères** : 'A' < 'B' < ... < 'Z' < ... < 'a' < 'b' < ... < 'z'