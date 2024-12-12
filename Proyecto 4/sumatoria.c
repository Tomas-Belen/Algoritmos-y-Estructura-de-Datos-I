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
 printf ("El %s es %d\n", nombre, x);
}

void pedirArreglo(int n_max, int a[])
{
  printf ("Ingrese %d arguementos\n", n_max);
  int i = 0;   
  while (i < n_max)
  {
   scanf ("%d", &a[i]);
   i++;
  }
}

void imprimeArreglo (int n_max, int a[])
{
 int i = 0;   
 while (i < n_max)
 {
  printf ("%d", a[i]);
  i++;
 }
}

int sumatoria(int tam, int a[])
{
 int i = 0;
 int res = 0;

 while (i < tam)
  {
   res += a[i];
   i++; 
  }
 return res;    
}

int main ()
{
  int tamArreglo = pedirEntero ("tamArreglo");
  int a[tamArreglo];
  pedirArreglo (tamArreglo, a);
  int resultado = sumatoria (tamArreglo, a);
  imprimirEntero ("resultado", resultado);

 return 0; 
}












