# Exercices Java - Fonctions

## Exercice 1 : Fonction f(x)

### Question a - Afficher f(0)
```java
public static int f(int x) {
    int resultat;
    resultat = -x * x + 3 * x - 2;
    return resultat;
}

public static void main(String[] args) {
    System.out.println("f(0) = " + f(0));
}
```

### Question b - Boucle de -5 à 5
```java
public static void main(String[] args) {
    for (int x = -5; x <= 5; x++) {
        System.out.println("f(" + x + ") = " + f(x));
    }
}
```

### Question c - Trouver le maximum
```java
public static void main(String[] args) {
    int max = f(-5);
    int xMax = -5;
    
    for (int x = -5; x <= 5; x++) {
        int valeur = f(x);
        if (valeur > max) {
            max = valeur;
            xMax = x;
        }
    }
    
    System.out.println("Le maximum : f(" + xMax + ") = " + max);
}
```

---

## Exercice 2 : Erreurs de compilation

### a) Incompatibilité de types
**Problème** : Fonction `max(int, int)` appelée avec des `double`

**Correction** : Utiliser `int` ou créer `max(double, double)`

### b) Type de retour incorrect
**Problème** : 
- Fonction retourne `int` mais `m` est `float`
- Logique inversée (`>` au lieu de `<`)

**Correction** :
```java
public static int max(int a, int b) {
    int m = a;
    if (m < b) m = b;
    return m;
}
```

### c) Variable non initialisée
**Problème** : `v2` utilisée sans valeur

**Correction** :
```java
System.out.print("Entrer une valeur : ");
v2 = Lire.i();
v1 = menu(v2);
```

### d) Manque type de retour
**Problème** : `void` implicite mais `return c;` présent

**Correction** :
```java
public static int menu(int c) {
    switch (c) { ... }
    return c;
}
```

---

## Exercice 3 : Fonction pourcentage()

### Fonction
```java
public static double pourcentage(int nombrePaiement, int nombreTotal) {
    return (double) nombrePaiement / nombreTotal * 100;
}
```

### Programme complet
```java
import java.util.Scanner;

public class Exercice3 {
    
    public static double pourcentage(int nombrePaiement, int nombreTotal) {
        return (double) nombrePaiement / nombreTotal * 100;
    }
    
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int nbCarteBleue, nbCheques, nbVirements, total;
        double pourcCB, pourcCheques, pourcVirements;
        
        System.out.print("Nombre de paiement par Carte Bleue : ");
        nbCarteBleue = scanner.nextInt();
        
        System.out.print("Nombre de cheques emis : ");
        nbCheques = scanner.nextInt();
        
        System.out.print("Nombre de virements automatiques : ");
        nbVirements = scanner.nextInt();
        
        total = nbCarteBleue + nbCheques + nbVirements;
        
        pourcCB = pourcentage(nbCarteBleue, total);
        pourcCheques = pourcentage(nbCheques, total);
        pourcVirements = pourcentage(nbVirements, total);
        
        System.out.println("Vous avez emis " + total + " ordres de debit dont " 
                          + pourcCB + " % par Carte Bleue");
        System.out.println("\t " + pourcCheques + " % par cheque");
        System.out.println("\t " + pourcVirements + " % par virement");
        
        scanner.close();
    }
}
```

### Exemple d'exécution
```
Nombre de paiement par Carte Bleue : 5
Nombre de cheques emis : 10
Nombre de virements automatiques : 5
Vous avez emis 20 ordres de debit dont 25.0 % par Carte Bleue
     50.0 % par cheque
     25.0 % par virement
```