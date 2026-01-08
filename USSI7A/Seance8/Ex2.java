public class Ex2 {
    public static int multiplication(int[] tab) {
        int m = 1;
        for (int i = 0; i < tab.length; i++) {
            m *= tab[i];
        }
        return m;
    }

    public static void main(String[] args) {
        int[] tab = {1, 2, 3, 4};
        System.out.println("La multiplication est : " + multiplication(tab));
    }
}

