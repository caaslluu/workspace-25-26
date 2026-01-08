public class Ville {
	String nomVille;
	String nomPays;
	int nbreHabitants;
	
	public Ville(){
		System.out.println("Creation d'une ville !");
		nomVille = "Inconnu";
		nomPays = "Inconnu";
		nbreHabitants = 0;
	}
	
	public Ville(String pNom, int pNbre, String pPays)
	{
		System.out.println("Création d'une ville avec des parametres !");
		nomVille = pNom;
		nomPays = pPays;
		nbreHabitants = pNbre; 
	}
	public static void main(String[] args) {
		Ville ville = new Ville();
		Ville Ville2 = new Ville("Marseille",123456,"France");
		Ville ville3 = new Ville();
		ville3.nomPays = "Lyon";
		System.out.println(ville3.nomPays);
	}
}
