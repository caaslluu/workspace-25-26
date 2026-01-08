public class VilleGetterSetter {
    private String nomVille;
    private String nomPays;
    private int nbreHabitants;

    public VilleGetterSetter() {
        System.out.println("Création d'une ville !");
        nomVille = "Inconnu";
        nomPays = "Inconnu";
        nbreHabitants = 0;
    }

    public VilleGetterSetter(String nom, int nbre, String pays) {
        System.out.println("Création d'une ville avec des paramètres !");
        nomVille = nom;
        nomPays = pays;
        nbreHabitants = nbre;
    }

    public String getNomVille() { return nomVille; }
    public void setNomVille(String nvNomVille) { nomVille = nvNomVille; }
    public String getNomPays() { return nomPays; }
    public void setNomPays(String nvNomPays) { nomPays = nvNomPays; }
    public int getNbreHabitants() { return nbreHabitants; }
    public void setNbreHabitants(int nvNbreHabitants) { nbreHabitants = nvNbreHabitants; }

    public static void main(String[] args) {
        VilleGetterSetter ville = new VilleGetterSetter();
        VilleGetterSetter ville2 = new VilleGetterSetter("Marseille", 123456, "France");
        VilleGetterSetter ville3 = new VilleGetterSetter();

        ville3.setNomVille("Lyon");
        ville3.setNomPays("France");
        ville3.setNbreHabitants(500000);

        System.out.println(ville3.getNomVille());
        System.out.println(ville3.getNomPays());
        System.out.println(ville3.getNbreHabitants());
    }
}

