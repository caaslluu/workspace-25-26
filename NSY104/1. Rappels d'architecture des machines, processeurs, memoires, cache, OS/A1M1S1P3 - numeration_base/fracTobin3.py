#!/usr/bin/python3

''' conversion partie fractionnaire d'un nombre décimal en binaire '''

def calcul(nbDec):
    digit = []
    nbDec = nbDec - int(nbDec)
    while nbDec != 0:
        nbDec *= 2
        digit.append((int(nbDec)))
        nbDec = nbDec - int(nbDec)
    return digit            

if __name__ == '__main__':
    nbDec = float(input("Donner le nombre décimal à convertir : "))
    print(calcul(nbDec))
