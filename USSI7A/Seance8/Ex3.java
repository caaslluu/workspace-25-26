public class Ex3 {
    public static int[] copie(int[] tab) {
        int[] copie = new int[tab.length];
        for (int i = 0; i < tab.length; i++) {
            copie[i] = tab[i];
        }
        return copie;
    }

    public static void main(String[] args) {
        int[] original = {10, 20, 30, 40};
        int[] copie = copie(original);

        System.out.print("Tableau copié : ");
        for (int val : copie) {
            System.out.print(val + " ");
        }
    }
}

