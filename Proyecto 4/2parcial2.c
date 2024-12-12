#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#define N 5

int pedir_entero(void) {
    int res;
    scanf("%d", &res);
    return res;
}

void pedir_arreglo(int tam, int a[]) {
    int i=0;
    while (i < tam) {
        printf("Ingrese elemento entero [%d/%d]: ", i+1, tam);
        a[i] = pedir_entero();
        i = i + 1;
    } 
}

void imprimirEntero (char*nombre, int x)
{
 printf ("%s --> %d\n", nombre,x);
}

struct datos {
bool esta_ordenado_asc;
int maximo;
};

struct datos esta_ordenado_asc(int tam, int a[])
{
 struct datos res;
 int i = 0;
 res.maximo = a[0];
 res.esta_ordenado_asc = true;
 while (i < tam)
  {{
    if (a[i] > res.maximo)
    res.maximo = a[i];
  }
  {
    if (i < tam - 1)
    res.esta_ordenado_asc = res.esta_ordenado_asc && a[i] < a[i+1]; 
  }
  i++;}
 return res; 
}

int main ()
{
int a[N];
struct datos dep;
pedir_arreglo (N, a);
dep = esta_ordenado_asc (N,a);
imprimirEntero ("res.maximo", dep.maximo);
imprimirEntero ("res.esta_ordenado", dep.esta_ordenado_asc);
return 0;
}
