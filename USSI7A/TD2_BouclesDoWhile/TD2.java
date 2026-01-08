import java.util.Scanner;

public class TD2{
	public static void main(String[] args)
	{
		//Exercice 1
		int num;
		System.out.println("\nExercice 1\n");
		Scanner sc = new Scanner(System.in);
		System.out.print("Veuillez saisir un nombre: ");
		num = sc.nextInt();
		for(int i=1;i<=10;i++)
		{
			System.out.format("%d * %d = %d\n",num,i,(num*i));
		}

		//Exercice 2
		System.out.println("\nExercice 2\n");
		int[][] tableau = new int[10][10];

		for(int x=0;x<10;x++)
		{
			for(int j=0;j<10;j++)
			{
				tableau[x][j] = (x+1) * (j+1);
				System.out.print(tableau[x][j] + "\t");
			}
			System.out.println();
		}

		//Exercice 3
		System.out.println("\nExercice 3\n");
		int b,n;
		Scanner sb = new Scanner(System.in);
		Scanner sn = new Scanner(System.in);
		System.out.print("Entrez b : ");
		b = sb.nextInt();
		System.out.print("Entrez n: ");
		n = sn.nextInt();
		System.out.format("%d ** %d = %.0f\n",b,n,Math.pow(b,n));

		// Exercice 4
		System.out.println("\nExercice 4\n");

		int carre;
		Scanner scarre = new Scanner(System.in);
		System.out.print("Entrez une valeur pour taille du carre: ");
		carre = scarre.nextInt();
		for(int d=0; d<=carre-1; d++)
		{
			for(int z=0; z<=carre-1; z++)
			{
				System.out.print("X ");
			}
			System.out.println();
		}
	}
}
