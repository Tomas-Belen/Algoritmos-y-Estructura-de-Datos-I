#include <stdio.h>
#include <limits.h>

int pedirEntero (char* nombre)
{
 int x;
 printf ("Ingrese un valor para %s\n", nombre);
 scanf ("%d", &x);
 return x;
}

int imprimirEntero (char* nombre, int x)
{
 printf ("El minimo %s es: %d\n", nombre, x);
}

void pedirArreglo (int n_max, int a[])
{
 printf ("Ingrese %d argumentos\n", n_max);
 int i = 0;
 while ( i < n_max)
 {
  scanf ("%d", &a[i]);
  i++;
 } 
}

int minimo_pares(int tam, int a[])
{
 int i = 0;
 int min = INT_MAX;
 while (i < tam)
 {
  if ( a[i] % 2 == 0 && a[i] < min)
  {
   min = a[i];
  }
  i++;
 }
 return min == INT_MAX ? -1 : min;
}

int minimo_impares(int tam, int a[])
{
 int i = 0;
 int min = INT_MAX;
 while (i < tam)
 {
  if ( a[i] % 2 != 0 && a[i] < min)
  {
   min = a[i];
  }
  i++;
 }
 return min == INT_MAX ? -1 : min;
}

int main ()
{
 int tamA = pedirEntero ("tamA");
 int a[tamA];
 pedirArreglo (tamA, a);
 int par = minimo_pares (tamA, a);
 int impar = minimo_impares (tamA, a);
 imprimirEntero ("par", par);
 imprimirEntero ("impar",impar);

 return 0;
}
