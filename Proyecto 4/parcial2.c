#include <stdio.h>
#include <stdbool.h>

bool todos_pares(int a[], int tam, int pos1, int pos2){
    if(a[pos1] % 2 == 0 && a[pos2] % 2 == 0){
        return true;
    }
    else{
        return false;
    }
}

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

int imprimirEnteros (char*nombre, int x)
{
  printf ("Las posiciones de %s son:\n", nombre);  
}

void pedirArreglo(int a[], int tam){
    for(int i = 0; i < tam; i++){
        a[i] = pedirEnteros("Ingrese un número: ");
    }
}

int main(){
    int tam = 5; 
    int a[tam]; 
    pedirArreglo(a, tam);
    int pos1 = pedirEnteros("Ingrese la primera posición a verificar: ");
    int pos2 = pedirEnteros("Ingrese la segunda posición a verificar: ");
    bool resultado = todos_pares(a, tam, pos1, pos2);
    int p;
    p = todos_pares (a, tam, pos1, pos2);
    imprimirEnteros ("todos_pares", todos_pares);
    return 0;
}
