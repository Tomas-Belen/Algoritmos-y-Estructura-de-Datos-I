#include <stdio.h>

int pedirEntero (char* nombre)
{
 int x;
 printf ("De un valor para %s:\n" , nombre);
 scanf ("%d", &x);
 
return x; 
}

void imprimirEntero (char* nombre, int x)
{
  printf  ("\n%s --> %d", nombre, x);
}

int main ()
{
  int x = pedirEntero ("x");
  int y = pedirEntero ("y");
  int z = pedirEntero ("z");  
  int xAux;
  int yAux;
  int zAux;
  xAux = x;
  yAux = y;
  zAux = z;

  x = yAux;
  y = y + xAux + zAux;
  z = yAux + xAux;

 imprimirEntero ("x", x);
 imprimirEntero ("y", y);
 imprimirEntero ("z", z);

return 0; 
}