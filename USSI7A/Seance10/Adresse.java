public class Adresse {
    private String rue;
    private String codePostal;
    private String ville;

    public Adresse(String rue, String codePostal, String ville) {
        this.rue = rue;
        this.codePostal = codePostal;
        this.ville = ville;
    }

    public Adresse(String rue, String codePostal) {
        this.rue = rue;
        this.codePostal = codePostal;
        this.ville = trouverVilleParCodePostal(codePostal);
    }

    public String getRue() { return this.rue; }
    public void setRue(String rue) { this.rue = rue; }

    public String getCodePostal() { return this.codePostal; }
    public void setCodePostal(String codePostal) { 
        this.codePostal = codePostal; 
        this.ville = trouverVilleParCodePostal(codePostal);
    }

    public String getVille() { return this.ville; }
    public void setVille(String ville) { this.ville = ville; }

    private String trouverVilleParCodePostal(String codePostal) {
        if (codePostal.equals("75001")) return "Paris";
        if (codePostal.equals("13001")) return "Marseille";
        if (codePostal.equals("69001")) return "Lyon";
        return "Inconnue";
    }

    public static void main(String[] args) {
        Adresse a1 = new Adresse("10 rue de Rivoli", "75001", "Paris");
        Adresse a2 = new Adresse("20 rue Paradis", "13001");

        System.out.println(a1.getRue() + ", " + a1.getCodePostal() + ", " + a1.getVille());
        System.out.println(a2.getRue() + ", " + a2.getCodePostal() + ", " + a2.getVille());
    }
}

