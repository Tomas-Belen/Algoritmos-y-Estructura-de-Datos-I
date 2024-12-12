#include <stdio.h>

int main() 
{
    int x, y, z;

    printf("Ingrese el primer numero:\n");
    scanf("%d", &x);

    printf("Ingrese el segundo numero:\n");
    scanf("%d", &y);

    z = x; 

    if (z > y) { 
     z = y;
    }

    printf("El minimo entre %d y %d es %d\n", x, y, z);

    return 0;
  
}
