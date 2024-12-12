#include <stdio.h>

int main () {

int x,y,z;

 printf ("\nIngresa un valor para x:\n");
 scanf ("%d", &x);

 printf ("Ingresa un valor para y:\n");
 scanf ("%d", &y);

 z = x;
 x = y;
 y = z;

printf ("\nDespues del intercambio quedaria asi, x = %d, y = %d\n\n" , x ,y);
return 0;

}