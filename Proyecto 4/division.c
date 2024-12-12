#include <stdio.h>

int pedirEnteros (char* nombre)
{
  int x;
  printf ("Ingrese el valor para %s:\n", nombre);
  scanf ("%d", &x);
  return x;
}

void imprimeEnteros (char* nombre, int x)
{
  printf ("\n%s --> %d", nombre, x);
}

typedef struct 
{
  int cociente;
  int resto;
} div_t;

div_t division (int x, int y)
{
  div_t res;
  res.cociente = x / y;
  res.resto = x % y;
  return res;
}

int main ()
{
 int x = pedirEnteros ("x");
 int y = pedirEnteros ("y");
 
 if (y == 0)
 {
    printf ("Error: Se esta tratando de dividir por 0");
 } 
 else 
 {
 div_t res = division (x,y);
 imprimeEnteros ("res.cociente", res.cociente);
 imprimeEnteros ("res.resto", res.resto);
 }
 return 0;
} 