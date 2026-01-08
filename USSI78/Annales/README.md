# Correction détaillée UTC 501 - Cours intégré

## 1. RELATION D'ORDRE – DIAGRAMME DE HASSE (2 pts)

### 📚 Cours : Relations d'ordre et Diagrammes de Hasse

**Relation d'ordre** : Une relation R sur un ensemble est une relation d'ordre si elle est :
- **Réflexive** : chaque élément est en relation avec lui-même (aRa)
- **Transitive** : si aRb et bRc alors aRc
- **Antisymétrique** : si aRb et bRa alors a=b

La relation « divise » (notée |) sur les entiers positifs est une relation d'ordre : a|b signifie qu'il existe k tel que b = k×a.

**Diagramme de Hasse** : C'est une représentation graphique d'une relation d'ordre où :
- On dessine les éléments sous forme de points
- On relie deux éléments a et b (a en bas, b en haut) s'il existe une relation directe (on omet les liens transitifs)
- Par exemple, on ne dessine pas le lien 2→12 si on a 2→4 et 4→12

### ✏️ Correction

**Question 1° : Ensemble des diviseurs de 36**

Pour trouver tous les diviseurs de 36, on cherche tous les nombres qui divisent 36.

Décomposition en facteurs premiers : 36 = 2² × 3²

Les diviseurs sont tous les produits de la forme 2^a × 3^b où 0 ≤ a ≤ 2 et 0 ≤ b ≤ 2.

**Div₃₆ = {1, 2, 3, 4, 6, 9, 12, 18, 36}**

**Question 2° : Diagramme de Hasse**

On représente la relation « divise » (a en bas si a|b) :
```
                36
              /    \
            18      12
            / \      / \
           9   6    4   \
            \ / \  / \   2
             3   1
```

Structure correcte :
- Les liens directs sont : 1|2, 1|3, 2|4, 2|6, 3|6, 3|9, 4|12, 6|12, 6|18, 9|18, 12|36, 18|36
- On n'affiche pas 1|4 (car 1|2|4), 1|6, etc. (relations transitives)

---

## 2. PGCD – PPCM – ALGORITHME D'EUCLIDE (3 pts)

### 📚 Cours : Algorithme d'Euclide et PGCD/PPCM

**Algorithme d'Euclide** : Pour calculer le PGCD(a,b) avec a ≥ b :
1. Diviser a par b : a = b×q + r (où r est le reste, 0 ≤ r < b)
2. Remplacer a par b et b par r
3. Répéter jusqu'à ce que r = 0
4. Le PGCD est le dernier reste non-nul

**Formule PPCM** : PPCM(a,b) = (a × b) / PGCD(a,b)

**Nombres premiers entre eux** : Deux nombres sont premiers entre eux si PGCD(a,b) = 1

### ✏️ Correction

**Question 1° : Calculer les PGCD**

**Couple 1 : PGCD(32, 6)**
```
32 = 6 × 5 + 2
6 = 2 × 3 + 0
PGCD(32, 6) = 2
```

**Couple 2 : PGCD(48, 5)**
```
48 = 5 × 9 + 3
5 = 3 × 1 + 2
3 = 2 × 1 + 1
2 = 1 × 2 + 0
PGCD(48, 5) = 1 ✓ Premiers entre eux
```

**Couple 3 : PGCD(118, 12)**
```
118 = 12 × 9 + 10
12 = 10 × 1 + 2
10 = 2 × 5 + 0
PGCD(118, 12) = 2
```

**Couple 4 : PGCD(120, 16)**
```
120 = 16 × 7 + 8
16 = 8 × 2 + 0
PGCD(120, 16) = 8
```

**Couple 5 : PGCD(149, 21)**
```
149 = 21 × 7 + 2
21 = 2 × 10 + 1
2 = 1 × 2 + 0
PGCD(149, 21) = 1 ✓ Premiers entre eux
```

**Question 2° : Couples premiers entre eux**

Couples 2 et 5 : **PGCD(48, 5) = 1 et PGCD(149, 21) = 1**

**Question 3° : PPCM des couples 1 et 2**

Pour le couple 1 : PGCD(32, 6) = 2
```
PPCM(32, 6) = (32 × 6) / 2 = 192 / 2 = 96
```

Pour le couple 2 : PGCD(48, 5) = 1
```
PPCM(48, 5) = (48 × 5) / 1 = 240
```

---

## 3. INVERSE MODULO (4 pts)

### 📚 Cours : Inverse modulo et Algorithme d'Euclide étendu

**Inverse modulo** : L'inverse de e modulo p (noté d ou e⁻¹) est un nombre d tel que :
```
e × d ≡ 1 (mod p)
```
Cela signifie que (e × d) mod p = 1.

**Condition d'existence** : L'inverse de e modulo p existe si et seulement si PGCD(e, p) = 1 (c'est pourquoi on demande e et p premiers entre eux).

**Algorithme d'Euclide étendu** : On modifie l'algorithme d'Euclide pour "remonter" et exprimer le PGCD comme combinaison linéaire :
```
PGCD(e, p) = u×e + v×p
```
Quand PGCD(e, p) = 1, on a : u×e + v×p = 1, d'où u×e ≡ 1 (mod p), donc d = u.

### ✏️ Correction

**Question 1° : Définition**

L'inverse de e modulo p est l'unique entier d dans {0, 1, ..., p-1} (ou {1, ..., p-1} selon la convention) tel que :
```
e × d ≡ 1 (mod p)
ou de manière équivalente : (e × d) mod p = 1
```

**Question 2° : Calculer les inverses par algorithme d'Euclide étendu**

**Cas 1 : e = 21, p = 149**

Algorithme d'Euclide :
- 149 = 21 × 7 + 2
- 21 = 2 × 10 + 1
- 2 = 1 × 2 + 0

Remontée (Euclide étendu) :
```
1 = 21 - 2 × 10
1 = 21 - (149 - 21 × 7) × 10
1 = 21 - 149 × 10 + 21 × 70
1 = 21 × 71 - 149 × 10
```

Donc : 71 × 21 ≡ 1 (mod 149)

**Vérification** : 21 × 71 = 1491 = 149 × 10 + 1 ✓

**Réponse : d₁ = 71**

---

**Cas 2 : e = 48, p = 5**

Algorithme d'Euclide :
- 48 = 5 × 9 + 3
- 5 = 3 × 1 + 2
- 3 = 2 × 1 + 1
- 2 = 1 × 2 + 0

Remontée :
```
1 = 3 - 2 × 1
1 = 3 - (5 - 3 × 1) × 1 = 2 × 3 - 5
1 = 2 × (48 - 5 × 9) - 5 = 2 × 48 - 19 × 5
```

Donc : 2 × 48 ≡ 1 (mod 5)

**Vérification** : 48 × 2 = 96 = 5 × 19 + 1 ✓

**Réponse : d₂ = 2**

---

**Cas 3 : e = 5, p = 48**

De la remontée précédente : 2 × 48 - 19 × 5 = 1
Donc : -19 × 5 ≡ 1 (mod 48)

d = -19 mod 48 = 48 - 19 = **29**

**Vérification** : 5 × 29 = 145 = 48 × 3 + 1 ✓

**Réponse : d₃ = 29**

---

## 4. SYSTÈME D'ÉQUATIONS LINÉAIRES – ALGORITHME DE GAUSS-JORDAN (2 pts)

### 📚 Cours : Élimination de Gauss-Jordan

**Principe** : Transformer le système en matrice augmentée et appliquer des opérations élémentaires pour obtenir une forme échelonnée réduite.

**Opérations permises** :
1. Permuter deux lignes
2. Multiplier une ligne par une constante non-nulle
3. Ajouter un multiple d'une ligne à une autre ligne

**Objectif** : Obtenir une matrice identité à gauche.

### ✏️ Correction

**Question 1° : Résolution du système**

Système initial :
```
3x₁ + 2x₂ + x₃ = 10
x₁ + 2x₂ + 3x₃ = 14
2x₁ + x₂ + 3x₃ = 13
```

Matrice augmentée :
```
[3  2  1 | 10]
[1  2  3 | 14]
[2  1  3 | 13]
```

**Étape 1** : Pivot sur la première colonne. Permuter L1 et L2 :
```
[1  2  3 | 14]
[3  2  1 | 10]
[2  1  3 | 13]
```

**Étape 2** : Éliminer x₁ des autres lignes.
- L2 ← L2 - 3×L1 : [0  -4  -8 | -32]
- L3 ← L3 - 2×L1 : [0  -3  -3 | -15]

```
[1  2  3 | 14]
[0  -4  -8 | -32]
[0  -3  -3 | -15]
```

**Étape 3** : Pivot sur la deuxième colonne. Diviser L2 par -4 :
```
[1  2  3 | 14]
[0  1  2 | 8]
[0  -3  -3 | -15]
```

**Étape 4** : Éliminer x₂ des autres lignes.
- L1 ← L1 - 2×L2 : [1  0  -1 | -2]
- L3 ← L3 + 3×L2 : [0  0  3 | 9]

```
[1  0  -1 | -2]
[0  1  2 | 8]
[0  0  3 | 9]
```

**Étape 5** : Pivot sur la troisième colonne. Diviser L3 par 3 :
```
[1  0  -1 | -2]
[0  1  2 | 8]
[0  0  1 | 3]
```

**Étape 6** : Éliminer x₃ des autres lignes.
- L1 ← L1 + 1×L3 : [1  0  0 | 1]
- L2 ← L2 - 2×L3 : [0  1  0 | 2]

```
[1  0  0 | 1]
[0  1  0 | 2]
[0  0  1 | 3]
```

**Solution : x₁ = 1, x₂ = 2, x₃ = 3**

**Question 2° : Vérification**

Equation 1 : 3(1) + 2(2) + 1(3) = 3 + 4 + 3 = 10 ✓
Equation 2 : 1(1) + 2(2) + 3(3) = 1 + 4 + 9 = 14 ✓
Equation 3 : 2(1) + 1(2) + 3(3) = 2 + 2 + 9 = 13 ✓

---

## 5. SYSTÈME LINÉAIRE – ÉQUATION NORMALE (6 pts)

### 📚 Cours : Méthode des moindres carrés

**Problème** : On a un système surdéterminé (plus d'équations que d'inconnues) qui n'a pas de solution exacte. On cherche la meilleure approximation.

**Distance euclidienne** : Pour un vecteur erreur e = Ax - b, la distance euclidienne au carré est :
```
||e||² = ||Ax - b||² = Σ(aᵢ - bᵢ)²
```

**Méthode des moindres carrés** : On minimise cette distance en résolvant l'équation normale :
```
A^T × A × x = A^T × b
```

### ✏️ Correction

**Question 1° : Poser le système S**

On veut s = x₀ + x₁ × e pour les 3 points : (2,2), (3,4), (4,4)

```
Système S:
x₀ + 2x₁ = 2
x₀ + 3x₁ = 4
x₀ + 4x₁ = 4
```

Matrice : A = [1  2], x = [x₀], b = [2]
             [1  3]      [x₁]      [4]
             [1  4]               [4]

**Question 2° : Montrer que S n'a pas de solution**

Matrice augmentée et Gauss-Jordan :
```
[1  2 | 2]      [1  2 | 2]      [1  2 | 2]
[1  3 | 4]  →   [0  1 | 2]  →   [0  1 | 2]
[1  4 | 4]      [0  2 | 2]      [0  0 | -2]
```

La dernière ligne donne : 0 = -2 **impossible** !

**Donc S n'a pas de solution** (système incompatible).

**Question 3° : Carré de distance avec x₀ = 1, x₁ = 1**

Vecteur de gauche : Ax = [1  2] [1]   = [3]
                          [1  3] [1]   = [4]
                          [1  4]       = [5]

Vecteur de droite : b = [2]
                         [4]
                         [4]

Erreur : e = Ax - b = [1]
                       [0]
                       [1]

**Distance au carré** : ||e||² = 1² + 0² + 1² = **2**

**Question 4° : Méthode des moindres carrés**

**4a. Équation normale**

A^T = [1  1  1]
      [2  3  4]

A^T × A = [3   9 ]
          [9  29 ]

A^T × b = [10]
          [32]

**Équation normale** :
```
3x₀ + 9x₁ = 10
9x₀ + 29x₁ = 32
```

**4b. Résoudre l'équation normale**

Diviser L1 par 3 : x₀ + 3x₁ = 10/3

L2 - 9×L1 : 2x₁ = 2, donc **x₁ = 1**

D'où : **x₀ = 10/3 - 3 = 1/3**

**4c. Distance euclidienne avec la solution optimale**

Ax = [1/3 + 2]    = [7/3]
     [1/3 + 3]     [10/3]
     [1/3 + 4]     [13/3]

Erreur : e = [1/3]
             [-2/3]
             [1/3]

Distance au carré : ||e||² = 1/9 + 4/9 + 1/9 = 6/9 = **2/3**

**Comparaison** : 2 > 2/3, la solution optimale est meilleure ! ✓

---

## 6. SUITE GÉOMÉTRIQUE - PROCESSUS DE NAISSANCE ET DE MORT (8 pts)

### 📚 Cours : Processus de Naissance et de Mort

**Processus de naissance et de mort** : Modèle probabiliste où la population évolue selon :
- **Taux de naissance** λ : nombre de naissances par unité de temps
- **Taux de mort** μ : nombre de morts par unité de temps
- **Ratio** ρ = λ/μ

À l'équilibre, la probabilité d'avoir n individus suit une distribution géométrique : Pₙ = P₀ρⁿ

**Propriété clé** : Σ Pₙ = 1 (probabilité totale)

### ✏️ Correction

**Question 1° : Équation que vérifie P₀**

Puisque les probabilités doivent sommer à 1 :
```
Σ(n=0 à ∞) Pₙ = 1

Σ(n=0 à ∞) P₀ρⁿ = 1

P₀ × Σ(n=0 à ∞) ρⁿ = 1
```

**P₀ × (1 + ρ + ρ² + ...) = 1**

**Question 2° : Calculer P₀**

Série géométrique (si |ρ| < 1) :
```
Σ(n=0 à ∞) ρⁿ = 1/(1-ρ)
```

Donc : **P₀ = 1 - ρ**

**Question 3° : Série pour la taille moyenne N̄**

```
N̄ = Σ(n=0 à ∞) n × Pₙ
  = Σ(n=0 à ∞) n × P₀ρⁿ
  = P₀ × Σ(n=0 à ∞) n × ρⁿ
  = (1-ρ) × (0 + ρ + 2ρ² + 3ρ³ + ...)
```

**Question 4° : Formule fermée pour N̄**

Dérivée de la série géométrique :
```
d/dρ [Σ ρⁿ] = Σ nρⁿ⁻¹

d/dρ [1/(1-ρ)] = 1/(1-ρ)²

Σ nρⁿ = ρ/(1-ρ)²
```

Donc :
```
N̄ = (1-ρ) × ρ/(1-ρ)² = ρ/(1-ρ)
```

**N̄ = ρ/(1-ρ)**

---

## 7. FILE D'ATTENTE ET GUICHET (3 pts)

### 📚 Cours : Application aux files M/M/1

Ce modèle s'applique à une file d'attente simple avec 1 guichet :
- Les clients arrivent au taux λ
- Les dossiers sont traités au taux μ
- ρ = λ/μ < 1 pour stabilité

Distribution : Pₙ = (1-ρ)ρⁿ

### ✏️ Correction

**Question 5° : Série pour le nombre moyen au guichet**

Le guichet ne peut servir qu'un client à la fois :

```
N̄ᵍ = Σ(n=1 à ∞) 1 × Pₙ
    = Σ(n=1 à ∞) (1-ρ)ρⁿ
    = (1-ρ) × (ρ + ρ² + ρ³ + ...)
    = (1-ρ) × ρ/(1-ρ) = ρ
```

**Question 6° : Expression de N̄ᵍ**

**N̄ᵍ = ρ**

(Le guichet est occupé en proportion ρ du temps)

**Question 7° : Nombre moyen en file d'attente**

```
N̄ = N̄f + N̄ᵍ

N̄f = N̄ - N̄ᵍ
   = ρ/(1-ρ) - ρ
   = [ρ - ρ(1-ρ)]/(1-ρ)
   = ρ²/(1-ρ)
```

**N̄f = ρ²/(1-ρ)**

---

## 8. APPLICATION NUMÉRIQUE - BUREAU DE POSTE (6 pts)

### ✏️ Correction

**Données** :
- Traitement : 10 min = 1/6 h → μ = 6 clients/h
- Arrivées : λ = 4 clients/h

**Question 8° : Déterminer ρ**

```
ρ = λ/μ = 4/6 = 2/3 ≈ 0.667
```

ρ < 1 ✓ (système stable)

**Question 9° : Calculer P₀ et P₁**

```
P₀ = 1 - ρ = 1 - 2/3 = 1/3

P₁ = (1 - ρ) × ρ = 1/3 × 2/3 = 2/9
```

**Question 10° : P(n ≥ 2)**

```
P(n ≥ 2) = 1 - (P₀ + P₁)
         = 1 - (1/3 + 2/9)
         = 1 - 5/9
         = 4/9 ≈ 0.444
```

44% de chance d'avoir au moins 2 clients

**Question 11° : Nombre moyen dans le bureau**

```
N̄ = ρ/(1-ρ)
  = (2/3)/(1/3)
  = 2
```

En moyenne **2 clients** dans le bureau

**Question 12° : Nombre moyen au guichet**

```
N̄ᵍ = ρ = 2/3
```

Le guichet est occupé **2/3 du temps**

**Question 13° : Nombre moyen en file d'attente**

```
N̄f = ρ²/(1-ρ)
   = (4/9)/(1/3)
   = 4/3 ≈ 1.33
```

En moyenne **1.33 clients** en attente

Vérification : 2 = 2/3 + 4/3 ✓

---

## 📌 RÉSUMÉ DES CONCEPTS CLÉS

### Mathématiques Discrètes
- **Relation d'ordre** : réflexive, transitive, antisymétrique
- **PGCD/PPCM** : l'algorithme d'Euclide est très efficace
- **Inverse modulo** : crucial en cryptographie (RSA)

### Algèbre Linéaire
- **Gauss-Jordan** : résoudre des systèmes exacts
- **Moindres carrés** : approximer quand il n'y a pas de solution exacte
- L'équation normale A^T A x = A^T b minimise ||Ax - b||²

### Probabilités et Files d'Attente
- **Processus de naissance-mort** : modèle Markovien standard
- **File M/M/1** : analyse de systèmes de service
- **Formules utiles** : N̄ = ρ/(1-ρ), N̄ᵍ = ρ, N̄f = ρ²/(1-ρ)

---

## 💡 CONSEILS POUR L'EXAMEN

1. **Montrez tous vos calculs** : pas de sauts logiques
2. **Labellisez les opérations** : "L2 ← L2 - 3×L1" aide à suivre
3. **Vérifiez vos réponses** : substitution dans l'équation originale
4. **Comprenez les formules** : plutôt que de les mémoriser
5. **Temps** : vous avez 3h, budgétisez ~25 min par problème majeur
6. **Algorithme d'Euclide étendu** : c'est long mais systématique
7. **Matrices** : écrivez clairement chaque étape de transformation
