# Les langages fonctionnels – approche pratique

**Structure d'un programme, syntaxe et exemples en OCaml**

*Par Lucas – Anthelme – Reda – Yassine*

---

## 🧑‍🏫 Paradigmes de programmation

### Paradigmes principaux :

- **Impératif** : instructions séquentielles
- **Orienté objet (POO)** : classes et objets
- **Fonctionnel** : fonctions et expressions

> 📌 **Focus de cette présentation :** Le paradigme fonctionnel

### Langage utilisé pour les exemples :

**OCaml**

---

## 🧮 Instructions vs expressions

### Impératif
Suite d'instructions qui modifient des variables

### Fonctionnel
Expressions qui décrivent le résultat

> ✨ Moins de variables qui changent partout → code plus prévisible

```python
# style impératif
somme = 0
somme = somme + 1
somme = somme + 2
somme = somme + 3
```

```ocaml
(* style fonctionnel *)
let somme = 1 + 2 + 3
```

---

## ♻️ Immutabilité en pratique

### Principe :

- Une valeur ne change pas après création
- On crée une nouvelle valeur au lieu de modifier l'ancienne
- Réduit les bugs liés à l'état mutable

```ocaml
let x = 3       (* x vaut 3 *)
let y = x + 1   (* y vaut 4, x vaut toujours 3 *)
```

### Comparaison avec Python (mutable) :

```python
x = 3
x = x + 1  # x vaut maintenant 4
```

---

## 📄 Structure d'un fichier OCaml

### Organisation typique :

- Suite de définitions : valeurs (`let`)
- Définitions de fonctions
- Bloc final possible pour les I/O

> 💡 Fonctions pures au centre, effets de bord à la fin

```ocaml
let pi = 3.1415

let aire_disque r =
  pi *. r *. r

let () =
  print_float (aire_disque 2.0)
```

---

## 🧩 Définir des fonctions

### Syntaxe : `let f x y = ...`

- Types déduits automatiquement
- Une fonction renvoie la dernière expression
- Exemples de fonctions pures

```ocaml
let addition a b =
  a + b

let carre x =
  x * x

let () =
  print_int (addition 2 (carre 3))  (* 11 *)
```

---

## 🔁 Récursion au lieu de boucles

### Principes :

- Remplace souvent `for` / `while`
- Nécessite un cas de base
- Fonctions pures → transparence référentielle (mêmes entrées → même résultat)

```ocaml
let rec fact n =
  if n = 0 then 1
  else n * fact (n - 1)

let () =
  print_int (fact 5)  (* 120 *)
```

---

## 🧱 Pattern matching sur les listes

### Décompose une valeur selon sa forme

Cas typiques pour une liste :

- `[]` : liste vide
- `x :: xs` : tête + reste

> 💡 Permet d'écrire des fonctions claires sur les listes

```ocaml
let rec somme_liste l =
  match l with
  | [] -> 0
  | x :: xs -> x + somme_liste xs

let () =
  print_int (somme_liste [1; 2; 3; 4])  (* 10 *)
```

---

## 📚 Listes en OCaml

### Manipulation de base :

- Liste d'entiers : `[1; 2; 3]`
- Ajouter en tête : `x :: l`
- Récupérer la tête avec pattern matching

```ocaml
let l = [1; 2; 3]
let l2 = 0 :: l    (* [0; 1; 2; 3] *)

let head l =
  match l with
  | [] -> failwith "liste vide"
  | x :: _ -> x
```

---

## 🔧 List.map et List.filter

- **map** : applique une fonction à chaque élément
- **filter** : garde les éléments qui vérifient un prédicat

> 📌 Illustration des fonctions d'ordre supérieur

```ocaml
let l = [1; 2; 3; 4]

let l_doubles =
  List.map (fun x -> x * 2) l
(* [2; 4; 6; 8] *)

let l_pairs =
  List.filter (fun x -> x mod 2 = 0) l
(* [2; 4] *)
```

---

## 🧮 List.fold_left : réduire une liste

### Principe :

Combine tous les éléments en une valeur

Prend :
- une fonction
- une valeur initiale
- une liste

```ocaml
let l = [1; 2; 3; 4]

let somme =
  List.fold_left (fun acc x -> acc + x) 0 l

(* Optionnel : *)
let max_liste l =
  List.fold_left max min_int l
```

---

## 🚰 Composer les opérations : pipelines

- On enchaîne `filter`, `fold`, etc.
- Opérateur `|>` : passe le résultat à la fonction suivante
- Lecture plus déclarative

```ocaml
let notes = [12.0; 9.5; 15.0; 7.0; 18.0]

let moyenne_admis =
  notes
  |> List.filter (fun n -> n >= 10.0)
  |> List.fold_left ( +. ) 0.0
  |> fun s -> s /. 3.0
```

---

## 🎯 Mini-programme : traitement de notes

### Objectif :

On veut :
- Une liste de notes sur 20
- Garder les notes admissibles (≥ 10)
- Calculer la moyenne des admissibles
- Afficher :
  - le nombre d'admissibles
  - leur moyenne

> **Flux :** Notes → Filtre → Somme + Moyenne → Affichage

---

## ✅ Étape 1 – Filtrer les admissibles

- Fonction pure `est_admissible`
- Utilisation de `List.filter`
- On illustre immutabilité + fonctions pures

```ocaml
let est_admissible note =
  note >= 10.0

let notes = [12.0; 9.5; 15.0; 7.0; 18.0]

let admissibles =
  List.filter est_admissible notes
(* [12.0; 15.0; 18.0] *)
```

---

## 📊 Étape 2 – Moyenne des admissibles

- `somme_liste` avec `fold_left`
- `moyenne` avec pattern matching
- Toujours des fonctions pures

```ocaml
let somme_liste l =
  List.fold_left ( +. ) 0.0 l

let moyenne l =
  match l with
  | [] -> 0.0
  | _ ->
      let s = somme_liste l in
      s /. float_of_int (List.length l)

let moyenne_admissibles =
  moyenne admissibles
```

---

## 🖨️ Étape 3 – Afficher le résultat

- Regroupe les effets de bord
- Utilise `let () =` comme "main"
- La logique reste pure, l'affichage est séparé

```ocaml
let () =
  let nb = List.length admissibles in
  let moy = moyenne admissibles in
  Printf.printf "Nombre d'admissibles : %d\n" nb;
  Printf.printf "Moyenne des admissibles : %.2f\n" moy
```

---

## 🧵 Conclusion

### En pratique, un langage fonctionnel c'est :

- Des valeurs **immuables**
- Des fonctions **pures**
- Des fonctions d'ordre supérieur (`map`, `filter`, `fold`)

### Structure typique :

- Cœur du programme pur
- Effets de bord regroupés à la fin

> **Applications :** Très utilisé pour le traitement de données, la fiabilité, le parallélisme

---

## 📖 Ressources

- [Documentation officielle OCaml](https://ocaml.org/)
- [Real World OCaml](https://dev.realworldocaml.org/)
- [OCaml Programming: Correct + Efficient + Beautiful](https://cs3110.github.io/textbook/)

---

**Fin de la présentation**

*Lucas – Anthelme – Yassine – Reda*