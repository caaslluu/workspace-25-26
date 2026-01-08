import sys

def rot13(s):
    result = ""
    for c in s:
        if 'a' <= c <= 'z':
            result += chr((ord(c) - ord('a') + 13) % 26 + ord('a'))
        elif 'A' <= c <= 'Z':
            result += chr((ord(c) - ord('A') + 13) % 26 + ord('A'))
        else:
            result += c
    return result

fichier_source = sys.argv[1]

with open(fichier_source, "r") as f:
    contenu = f.readlines()

with open("userassist.txt", "w") as f:
    f.writelines(contenu)

with open("userassist_decode.txt", "w") as f:
    for ligne in contenu:
        f.write(rot13(ligne) + "\n")

