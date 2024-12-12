#include <stdio.h>
#include <stdbool.h>
#define N 5

void pedir_arreglo(int n_max, int a[]) {
    int i = 0;
    int aux;
		while (i < n_max) {
        printf ("Ingrese el valor en la posicion %d: ", i);
        scanf ("%d", &aux);
        a[i] = aux;
        i++;
    	}
        
}

struct cinco_t{
    int primero;
    int segundo;
    int tercero;
    int cuarto;
    int quinto;
};

int es_primo(int x){
	int i = 2;
    bool res = true;

	while (i < x && res){
		res = res && ((x % i) != 0);
        i++;
    }

    if(res){
        x = x;
    }
    else{
        x = -1;
    }

    return x;
}

struct cinco_t cinco_primos(int a[]){

    struct cinco_t p;
        p.primero = es_primo(a[0]);
        p.segundo = es_primo(a[1]);
        p.tercero = es_primo(a[2]);
        p.cuarto = es_primo(a[3]);
        p.quinto = es_primo(a[4]);
    
    return p;
}

void imprimir_arreglo(int i,int p){
    printf("La posicion %d del arreglo vale %d.\n", i,p);
}

int main(){
    int a[N];
    pedir_arreglo(N,a);
    struct cinco_t m;
    m = cinco_primos(a);
    imprimir_arreglo(0,m.primero);
    imprimir_arreglo(1,m.segundo);
    imprimir_arreglo(2,m.tercero);
    imprimir_arreglo(3,m.cuarto);
    imprimir_arreglo(4,m.quinto);

}
