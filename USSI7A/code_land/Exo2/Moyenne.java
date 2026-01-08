public class Moyenne {
	public static void main(String[] args){
		float moyenne;
		float note1 = 2;
		float note2 = 20;
		float note3 = 18;

		moyenne = note1 + note2 + note3;
		double moyenne_principale;
		moyenne_principale = (double) moyenne / 3;
		if(moyenne_principale > 18 && moyenne_principale < 20)
		{
			System.out.format("Vous etes excellenti: %f",moyenne_principale);
		}
		if(moyenne_principale > 16 && moyenne_principale < 18){
			System.out.format("Vous avez echouez: %f",moyenne_principale);
		}
	}
}
