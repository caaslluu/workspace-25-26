public class Ex1 {
    public static int somme(int[] tab) {
        int s = 0;
        for (int i = 0; i < tab.length; i++) {
            s += tab[i];
        }
        return s;
    }

    public static void main(String[] args) {
        int[] tab = {1, 2, 3, 4, 5};
        System.out.println("La somme est : " + somme(tab));
    }
}

