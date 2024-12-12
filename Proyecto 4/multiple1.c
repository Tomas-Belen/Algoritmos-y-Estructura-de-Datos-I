#include <stdio.h>

int pedirEntero (char* nombre)
{
 int x;
 printf ("Ingresa un valor para %s:\n", nombre);
 scanf ("%d" , &x);
 return x;
}

void imprimirEntero (char* nombre , int x)
{
 printf ("\n%s --> %d", nombre, x);
}

int main ()
{
  int x = pedirEntero ("x");
  int y = pedirEntero ("y");
  int z;
  z = x;
  x = x + 1; 
  y = z + y;

imprimirEntero ("x", x);
imprimirEntero ("y", y);
 return 0; 
}