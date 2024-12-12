#include <stdio.h>

int main ()
{
 int x;

 printf ("Ingrese un numero:\n");
 scanf ("%d", &x);

 if (x >= 0){
   printf ("El valor absoluto es: %d", x);
 } else { 
   printf ("El valor absoluto es: %d", -x);   
 }

 return 0;
}

// gcc -Wall -Wextra -std=c99 miarchivo.c -o miprograma
// ./miprograma