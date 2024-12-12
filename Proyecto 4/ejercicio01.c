#include <stdio.h>
#include <assert.h>

int pedirEntero ()
{
   int x;
   printf ("Ingresa la cantidad de veces que aprezca en pantalla:\n");
   scanf ("%d", &x);
   return x;
}

void hola_hasta(int n) 
{
 int i = 0;
    while (i < n) 
    {
     printf("feliz cumple hermanito querido bueno nose te quiero¿\n");
     i++;
    }
}

int main() 
{
 int x;
 x = pedirEntero ();
 assert(x > 0);
 hola_hasta(x);
return 0;
}
