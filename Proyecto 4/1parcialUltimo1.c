#include <stdio.h>
#include <assert.h>

int pedirEntero (char* nombre)
{
 int x;
 printf ("Ingresa el valor para %s = ", nombre);
 scanf ("%d", &x);
 return x;
}

void imprimirEntero (char* nombre, int x)
{
 printf ("%s --> %d\n", nombre, x);
}

int main ()
{
 int x = pedirEntero ("x");
 int y = pedirEntero ("y");

 int auxX;
 int auxY;
 auxX = x;
 auxY = y;
 
 assert (x != y);

 if (x > y) {
   y = 0;  
   x = auxX - auxY;
 }
 else {
   x = 0;
   y = auxY - auxX;  
 }


 imprimirEntero ("x", x);
 imprimirEntero ("y", y);
 assert ( x >= 0 && y >= 0);

 return 0;

}

/* Ingresa el valor para x = 3
Ingresa el valor para y = 2
x --> 1
y --> 0 */