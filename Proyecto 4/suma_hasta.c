#include <stdio.h>

int suma_hasta(int n) {
    return n * (n + 1) / 2;
}

int main() {
    int n;
    printf("Ingrese un numero entero positivo: ");
    scanf("%d", &n);
    if (n < 0) {
        printf("Error: el numero no puede ser negativo.\n");
    } else {
        printf("La suma de los primeros numeros naturales es %d.\n", suma_hasta(n));
    }
    return 0;
}
