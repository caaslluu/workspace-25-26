
import java.util.Scanner;

public class Main{
	public static void main(String[] args){
		int a;
		String res;
		Scanner sc = new Scanner(System.in);
		System.out.println("Veuillez saisir un nombre : ");
		a = sc.nextInt();
		System.out.println("Vous avez saisi : " + a);
		
		do {
			System.out.println("*".repeat(a));
			a++;
		}
		while(a<10);
		Scanner nsc = new Scanner(System.in);
		System.out.println("Etes vous satisfait ? ");
		res = nsc.nextLine();
		if(res.charAt(0) == 'O')
		{
			System.out.println("Super");
		}
		else{
			System.out.println("dommage");
		}
	}
}
