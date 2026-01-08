#include<stdio.h>

int main(void)
{
int num;

printf("Printing ASCII values Table...\n\n");

num = 1;

while(num<=255)

{

printf("\nValue:%d = ASCII Character:%c\n", num, num); /*This change has been made as per the comment. Thank you anonymous Blog Viewer ... */

num++;

}

printf("\n\nEND\n");
return 0;
}
