/*
Ce programme initialise la variable n à 10, et l’élève au carré plusieurs fois. Les valeurs
affichées devraient donc être toutes des puissances de 10, mais en exécutant le programme,
vous verrez que ce n’est pas le cas pour les dernières valeurs, qui sont trop grandes pour
être représentées correctement par le type int. Vous pouvez également changer le type de
n de int à long et short pour voir l’impact sur les valeurs calculées.
Soyez donc vigilants quand votre programme doit travailler avec de grandes valeurs !

Les entiers :
byte : 1 octet de – 128 à 127
short : 2 octets de – 32 768 à 32 767
int : 4 octets de – 2 147 483 648 à 2 147 483 647
long : 8 octets de – 9 223 372 036 854 775 808 à 9 223 372 036 854 775 807

Les réels :
float : 4 octets de 1.40239846e-45F à 3.402823347e38F
double : 8 octets de 4.94065645841246544e-324D à 1.79769313486231570e308D

Note : Pour utiliser les valeurs limites en Java, on peut utiliser les constantes suivantes :
- Integer.MAX_VALUE
- Double.MAX_VALUE

*/


public class Depassement {

	public static void main(String[] args) {
		int n = 10;
		System.out.println( n );
		for (int i = 0; i < 5; i++){
			n = n * n;
			System.out.println( n );
		}
	}
}
