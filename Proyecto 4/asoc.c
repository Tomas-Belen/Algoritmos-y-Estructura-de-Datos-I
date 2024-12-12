#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#define N 3

typedef char clave_t;
typedef int valor_t;
struct asoc 
{
    clave_t clave;
    valor_t valor;
};
void pedir_arreglo (int n_max, struct asoc a[]);
clave_t pedir_clave ();
bool asoc_existe(int tam, struct asoc a[], clave_t c);
void mensaje (clave_t c, bool b);

int main () {
    struct asoc a[N];
    pedir_arreglo (N, a);
    clave_t m=pedir_clave ();
    bool b=asoc_existe(N, a, m);
    mensaje (m, b);
    return 0;
}

void pedir_arreglo (int n_max, struct asoc a[]) {
    int i=0;
    char aux;
    int aux2;
        while (i<n_max) {
        printf ("Ingrese una clave en la posicion %d: ", i);
        scanf (" %c", &aux);
        a[i].clave = aux;
        printf ("Ingrese un valor en la posicion %d: ", i);
        scanf ("%d", &aux2);
        a[i].valor = aux2;
        i++;
    }
}

clave_t pedir_clave (){
    clave_t x;
    printf ("Ingresa una clave: ");
    scanf (" %c", &x);
    return x;
}

bool asoc_existe(int tam, struct asoc a[], clave_t c) {
    bool b=false;
    int i=0;
    while (i<tam) {
        if (a[i].clave == c) {
            b=true;
            i=tam;
        }
        else {
            i ++;
        }
    }
    return b;
}

void mensaje (clave_t c, bool b) {
    if (b) {
        printf ("Existe la clave %c en el Arreglo", c);
    }
    else {
        printf ("No existe la clave %c en el Arrglo", c);
    }
}