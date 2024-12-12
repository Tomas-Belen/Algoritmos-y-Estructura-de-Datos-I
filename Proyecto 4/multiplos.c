#include <stdio.h>
#include <stdbool.h>

int pedirEntero (char* nombre)
{
  int x;
  printf ("Ingrese un valor para %s\n", nombre);
  scanf ("%d", &x);
  return x;  
}

int imprimirEntero (char* nombre, int x)
{
 printf ("%s es: %d (Recordar que 0 es false y 1 es True) \n", nombre, x);
}

void pedirArreglo (int n_max, int a[])
{

 printf ("Ingrese %d argumentos\n", n_max);
 int i = 0;
 while (i < n_max)
 {
  scanf ("%d", &a[i]);
  i++;
 }

}

bool todos_pares(int tam, int a[])
{
 int i = 0;
 while (i < tam)
 {
  if ( a[i] % 2 != 0)
  {
    return false;
  }
  i++; 
 }
 return true;
}

bool existe_multiplo(int m, int tam, int a[])
{
 int i = 0;
 while (i < tam)
 {
  if (a[i] % m != 0)
  {
   return false;
  }
  i++;
 }
  return true;
}

int main ()
{
 int tamA = pedirEntero ("tamA");
 int arr[tamA];
 int m = pedirEntero ("m");
 pedirArreglo (tamA, arr);  
 int par = todos_pares (tamA, arr);
 int mult = existe_multiplo (m, tamA, arr);
 imprimirEntero ("par", par);
 imprimirEntero ("mult", mult);
 return 0;
}