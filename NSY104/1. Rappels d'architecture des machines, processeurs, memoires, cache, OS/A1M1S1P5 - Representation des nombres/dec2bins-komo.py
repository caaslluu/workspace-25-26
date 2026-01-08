#!/usr/bin/python
# -*- coding: utf-8 -*-


def dec2bin(d,nb=0):
    """dec2bin(d,nb=0): conversion nombre entier positif ou nul -> chaîne binaire (si nb>0, complète à gauche par des zéros)"""
    if d==0:
        b="0"
    else:
        b=""
        while d!=0:
            b="01"[d&1]+b
            d=d>>1
    return b.zfill(nb)
 


def dec2bins(d,nb=0):
    """dec2bins(d,nb=0): conversion nombre entier signé d -> chaîne binaire pour un mot de nb bits (=0 par defaut) """
    # calcul de la taille mini du mot permettant de représenter la valeur signée d (signe compris)
    n=1
    if d>=0:
        x=d
    else:
        x=-d-1
    while (1<<n)<=x:
        n+=1
    n+=1
    # valeur de nb à prendre pour la suite des calculs (si nb<n, le nb donné est trop faible pour le d donné)
    if (nb==0) or (nb<n):
        nb=n
    # calculs
    if d>=0:
        # on renvoie la chaîne normale, complétée par des "0" à gauche et par le bit de signe = "0"
        b='0' + dec2bin(d,nb-1)
    else:
        # on renvoie la chaîne signée, complétée par des "1" à gauche et par le bit de signe "1"
        b='1' + dec2bin((1<<(nb-1))+d,(nb-1))
    return b
 
# Exemple d'utilisation:
#print dec2bins(4294967292,32)


#komo

entier = int(input('Donner le nombre entier à convertir : '))
form =  int(input('Donner le format de conversion : '))
print dec2bins(entier,form)
