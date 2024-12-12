#include <stdio.h>
#include <stdbool.h>
#define N 5

int pedirEntero(char *nombre)
{
    int x;
    printf("Ingresa el valor para %s = ", nombre);
    scanf("%d", &x);
    return x;
}

void pedir_arreglo(int n_max, int a[])
{
    int i = 0;
    int x;
    while (i < n_max)
    {
        printf("Ingrese el valor en la posicion %d: ", i);
        scanf("%d", &x);
        a[i] = x;
        i++;
    }
}

void imprimeEntero(char *nombre, int x)
{
    printf("%s --> %d\n", nombre, x);
}

struct numeros_info
{
    int suma;
    bool algun_impar;
    bool todos_iguales;
};

struct numeros_info analizar_numeros(int tam, int a[])
{
    struct numeros_info res;
    int i = 0;
    res.suma = 0;
    res.algun_impar = false;
    res.todos_iguales = true;

    while (i < tam)
    {
         res.suma = res.suma + a[i];
            
            if (a[i] % 2 != 0)
            {
                res.algun_impar = true;
            }
            if (i < tam - 1)
            {
                res.todos_iguales = res.todos_iguales && a[i] == a[i + 1];
            }
            i++;
        
        
    }
    return res;
}

    int main()
    {

        int a[N];
        struct numeros_info res;
        pedir_arreglo(N, a);
        res = analizar_numeros(N, a);
        imprimeEntero("res.suma", res.suma);
        imprimeEntero("res.algun_impar", res.algun_impar);
        imprimeEntero("res.todos_iguales", res.todos_iguales);
        return 0;
    }
