import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Entrez la taille (en chiffre) : ");
        int taille = scanner.nextInt();

        if (taille >= 34 && taille < 36) {
            System.out.println("Taille XS");
        } else if (taille >= 36 && taille < 38) {
            System.out.println("Taille S");
        } else if (taille >= 38 && taille < 40) {
            System.out.println("Taille SM");
        } else if (taille >= 40 && taille < 42) {
            System.out.println("Taille M");
        } else if (taille >= 42 && taille < 44) {
            System.out.println("Taille L");
        } else {
            System.out.println("Taille inconnue");
        }

        scanner.close();
    }
}
