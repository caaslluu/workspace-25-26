#include <stdio.h>

/*On peut consulter le fichier /usr/include/limits.h pour connaître les valeurs limites des différents types.


Type             Occupation mémoire               Plage de valeur

char             1 octet                         –128 to 127

int              2 à 4 octets                    
		         selon implémentation                                    

short            2 octet                         –32,768 to 32,767

long             4 octet                         –2,147,483,648 to 2,147,483,647

unsigned char    1 octet                         0 to 255

unsigned int     2 à 4 octets 
                 selon implémentation                   

unsigned short   2 octet                         0 to 65,535

unsigned long    4 octet                         0 to 4,294,967,295

float            4 octet                         ±3.4 x 10e38 to ±3.4 x 10e–38

double           8 octet                         ±1.7 x 10e–308 to ±1.7 x 10e308

long double      10 octet                        ±3.4 x 10e–4932 to ±3.4 x 10e4932
 
*/
int main(){
       int entier = 4294967292;
       int entier2 = 129; // sur 4 octets de 0 a 2147483647 et de -1 a -2147483648
       char car = 'A'; //sur un octet de 0 a 127 et de -1 a -128
      
       printf(" taille car= %d\n", sizeof( car ));
       printf(" taille short = %d\n", sizeof( short ));
       printf(" taille unsigned short = %d\n", sizeof( unsigned short ));
       printf(" taille int = %d\n", sizeof( int ));
       printf(" taille unsigned int = %d\n", sizeof( unsigned int ));
       printf(" taille long int = %d\n", sizeof( long int ));
       printf(" taille unsigned long int = %d\n", sizeof( unsigned long int ));
       printf(" taille long long int = %d\n", sizeof( long long int ));
       printf(" taille unsigned long long int = %d\n", sizeof( unsigned long long int ));
       
       printf("4 et 4294967292    en tant que nombre sans signe : %u %u\n", 4, entier);
       printf("4 et 4294967292    en tant que nombre avec signe : %d %d\n", 4, entier); 

/* 
4294967292 -> 11111111111111111111111111111100
complément à 2 : 00000000000000000000000000000011 + 1 = 00000000000000000000000000000100 -> -4
*/       
     
       
       /*entier2 = car;
       printf("entier = %d\n", entier);*/
       
       car = entier2;
       printf("car = %d\n", car);

//       printf("A = %x\n", car); //en hexa
//     printf("A = %d\n", car); //en decimal

return 0;


      
       }
