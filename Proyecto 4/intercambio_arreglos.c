#include <stdio.h>
#include <assert.h>

int pedirEntero (char* nombre)
{
 int x;
 printf ("Ingrese un valor para %s\n", nombre);
 scanf ("%d", &x);
 return x;
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

void imprimirArreglo (int n_max, int a[])
{
 int i = 0;
 while (i < n_max)
 {
  printf ("%d ", a[i]);
  i++;
 }
} 

void intercambiar(int tam, int a[], int i, int j)
{
 assert(i >= 0 && i < tam && j >= 0 && j < tam);
 int z = a[i];
 a[i] = a[j];
 a[j] = z;
}

int main ()
{
 int tamA = pedirEntero ("tamA");
 int a[tamA];
 pedirArreglo (tamA, a);
 printf ("Ingrese los valores a en las posiciones a cambiar\n");
 int i = pedirEntero ("i");
 int j = pedirEntero ("j");
 intercambiar (tamA, a , i, j);
 imprimirArreglo (tamA, a);

 return 0;

}