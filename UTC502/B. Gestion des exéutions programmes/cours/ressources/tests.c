/* snprintf example */
#include <stdio.h>

int main()
{
	char buffer[100];
	int cx;

	cx = snprintf(buffer, 100, "The half of %d is %d", 60, 60 / 2);

	if (cx >= 0 && cx < 100) // check returned value

		snprintf(buffer + cx, 100 - cx, ", and the half of that is %d.", 60 / 2 / 2);

	puts(buffer);


	int tab[3], val2;
	val2 = *(tab + 2) = 100;
	printf("val2 = %d\n", val2);
	printf("val2 = %d\n", tab[2]);

	return 0;
}