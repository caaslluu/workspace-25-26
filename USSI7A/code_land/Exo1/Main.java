public class Main{
	public static void main(String[] args)
	{
		int a,b;
		a = 5;
		b = 8;
		int somme = a + b;
		int difference = a - b;
		int produit = a * b;
		double quotient = a / b;

		System.out.format("Exercice 1:\nSomme: %d\nDifference: %d\nProduit: %d\nQuotient: %f\n------------\n",somme,difference,produit,quotient);
		int r = 10;
		int diametre = r*2;
		double pi = 3.14159265358979;
		double circonference = 2*pi*r;
		double air = pi*r*r;

		System.out.format("\nExercice 2:\nDiametre: %d\nCirconference: %f\nAir: %f\n------------\n",diametre,circonference,air);
		String str;
		str = "licence cyber";
		System.out.format("\nExercice 3:\n%s\n",str);
	}
}
