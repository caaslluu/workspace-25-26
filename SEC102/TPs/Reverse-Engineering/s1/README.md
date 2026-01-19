# Reverse Engineering - Séance 1

## Prog2.exe 

dans un premier temps, on regarde le type du fichier:

```
[Jan 19, 2026 - 14:17:14 (CET)] exegol-rm Prog # file prog2.exe 
prog2.exe: PE32+ executable (console) x86-64, for MS Windows, 19 sections
[Jan 19, 2026 - 14:17:17 (CET)] exegol-rm Prog 
```

Ensuite, on ouvre le programme avec Ghidra afin d'étudier le programme dans son ensemble.

on y trouve une fonction intéressante, "verifier_cle":

```
bool verifier_cle(char *param_1,char *param_2)

{
  int iVar1;
  
  iVar1 = .text(param_1,param_2);
  return iVar1 == 0;
}
```

Ensuite, dans le main, on obtient l'appel de cette fonction de comparaison avec l'argument en entrée du programme, ainsi qu'une chaine de caractère:

```
int main(int _Argc,char **_Argv,char **_Env)

{
  bool bVar1;
  undefined7 extraout_var;
  
  __main();
  bVar1 = verifier_cle(_Argv[1],"compare");
  if ((int)CONCAT71(extraout_var,bVar1) == 0) {
    printf("Incorrecte.\n");
  }
  else {
    printf("Correcte, bravo !\n");
  }
  return 0;
}
```

On obtient donc la clé **"compare"**

## Prog3.exe

dans un premier temps, on regarde le type du fichier et ensuite on ouvre le programme avec Ghidra 

```
[Jan 19, 2026 - 14:35:39 (CET)] exegol-rm Prog # file prog3.exe && ghidra &              
prog3.exe: PE32+ executable (console) x86-64, for MS Windows, 19 sections
[Jan 19, 2026 - 14:35:44 (CET)] exegol-rm Prog # 
```

on regarde directement le pseudo-code de la fonction Main: 

```
int main(int _Argc,char **_Argv,char **_Env)

{
  bool bVar1;
  undefined7 extraout_var;
  char local_78 [104];
  undefined4 local_10;
  undefined2 local_c;
  undefined local_a;
  undefined local_9;
  
  __main();
  local_10 = 0x73647670;
  local_c = 0x7875;
  local_a = 0;
  local_9 = 1;
  deobfusquer((longlong)local_78,(char *)&local_10,1);
  bVar1 = verifier_cle(_Argv[1],local_78);
  if ((int)CONCAT71(extraout_var,bVar1) == 0) {
    printf("Incorrecte.\n");
  }
  else {
    printf("Correcte, bravo !\n");
  }
  return 0;
}
```

nous pouvons voir l'appel d'une fonction intéressante, nommée "deobfusquer" , qui prend en paramètre un buffer de 104 octets (qui est notre clé désobfusqué),  une chaine en Hexadécimal (0x73647670 + 0x7875) et "1" qui est la clé.

quand on regarde de plus près la fonction deobfusquer on obtient: 

```
void deobfusquer(longlong param_1,char *param_2,byte param_3)

{
  size_t sVar1;
  int local_c;
  
  for (local_c = 0; param_2[local_c] != '\0'; local_c = local_c + 1) {
    *(byte *)(param_1 + local_c) = param_2[local_c] ^ param_3;
  }
  sVar1 = .text(param_2);
  *(undefined *)(sVar1 + param_1) = 0;
  return;
}
```

on peut voir une boucle qui vient xoré les élèments de param_2 (donc notre chaine Hexa) avec param_3 qui est la clé 1.

on effectue le xor à la main: 

```
70 76 64 73 75 78 (hex litlle endian) = pvdsux (ascii)

et (pvdsux ^ 1) = qwerty
```
on obtient donc la clé **qwerty**


