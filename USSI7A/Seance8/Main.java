public class Main {
	public static void main(String[] args)
	{
		int tab[] = {0,1,2,3};
		for(int i=0;i<4;i++)
		{
			System.out.println(tab[i]);
		}
		System.out.print(tab[tab.length - 1]);

		int tab2[][] = {{0,1,2,3},{0,1,2,3}};
		for(int i=0; i<2; i++)
		{
			for(int y=0; y<4; y++)
			{
				System.out.println(tab2[i][y]);
			}
		}
	}
}
