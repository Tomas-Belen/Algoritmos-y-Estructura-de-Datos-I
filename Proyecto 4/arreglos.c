#include <stdio.h>

int pedirEnteros(char* nombre)
{
 int x;   
 printf ("Ingrese una valor para %s\n", nombre);
 scanf ("%d" , &x);
 return x;
}

void pedir_arreglo(int n_max, int a[])
{
 printf ("Ingresa %d argumentos\n" , n_max);
 int i = 0;
 while (i < n_max) 
  {
  scanf ("%d" , &a[i]);
  i++;
  }
}

void imprimir_arreglo(int n_max, int a[])
{
  int i = 0;
  while (i < n_max)
  {
    printf ("%d ", a[i]);
    i++;
  } 
   printf ("\n");
}

int main ()
{
 int tamArreglo = pedirEnteros ("tamArreglo");
 int arr[tamArreglo];
 pedir_arreglo(tamArreglo, arr);  
 imprimir_arreglo(tamArreglo, arr);  

 return 0;
}