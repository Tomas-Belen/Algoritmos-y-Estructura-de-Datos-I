#include <stdio.h>

int pedirEntero (char* nombre)
{
 int x;
 printf ("Ingrese un valor para %s\n", nombre);
 scanf ("%d", &x);
 return x;
}

int imprimirEntero (char* nombre, int x)
{
 printf ("El tramo mas largo de %s es de %d elementos\n", nombre, x);
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

int prim_iguales(int tam, int a[])
{
 int i = 0;
 while (a[i] == a[i +1] && i < tam)
 {
    i++;
 }
 return i+1;
 
}

int main ()
{
 int largoArreglo = pedirEntero ("largoArreglo");
 int a[largoArreglo];
 pedirArreglo (largoArreglo, a);
 int iguales = prim_iguales (largoArreglo, a);
 imprimirEntero ("iguales", iguales);

 return 0;
}