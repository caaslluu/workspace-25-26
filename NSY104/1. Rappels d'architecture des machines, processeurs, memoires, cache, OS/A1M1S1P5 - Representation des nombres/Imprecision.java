

public class Imprecision {
	public static void main(String[] args) {
		test1();
		test2();
		test3();

	}//main

static void test1(){

/*Si le type double pouvait représenter parfaitement les valeurs réelles, ce programme
afficherait 0. Or, sur mon ordinateur, j’obtiens environ la valeur 7.10E−15 , qui est une valeur
très petite mais pas nulle. C’est parce que la variable racine ne peut stocker exactement
la racine de a, et donc l’expression racine * racine ne vaut pas exactement a.
*/


	double a = 37.0;
	double racine = Math.sqrt(a);
	System.out.println("test1 : " + (a - racine * racine) );
}//test1

static void test2(){

/*C’est pour ça que les tests d’égalité ou d’inégalité entre double (ou float) NE DEVRAIENT PAS ÊTRE utilisés.
Par exemple, le code suivant, n’affiche rien, contrairement à ce qu’on pourrait s’attendre.
*/

	double a = 37.0;
	double racine = Math.sqrt(a);
	if (a == racine * racine) {
		System.out.println( "test2 : ok" );
	}
	else System.out.println("test2 : pas ok !");
}//test2

static void test3(){

/*Si vous devez absolument comparer des valeurs de type double vous pouvez utiliser un test tel que celui-ci :*/

	double a = 37.0;
	double racine = Math.sqrt(a);
	double epsilon = 7.105427357601003E-15; // test1() donne pour (a - racine * racine) = 7.105427357601002E-15
	if (Math.abs(a - racine * racine) < epsilon) {
		System.out.println( "test3 : ok" );
	}

/*où epsilon est une très petite valeur et abs calcule la valeur absolue. Cette valeur de-
vrait être choisie selon la précision du type utilisé, mais comment déterminer cette valeur
idéalement sort largement du cadre de ce cours.*/

}//test3

}//class
