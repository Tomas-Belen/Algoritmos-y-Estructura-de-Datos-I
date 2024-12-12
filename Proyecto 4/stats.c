#include <stdio.h>
#include <limits.h>
#include <assert.h>

struct datos_t
{
    float maximo;
    float minimo;
    float promedio;
};

struct datos_t stats(float a[], int tam)
{
    struct datos_t res;
    int i = 0;
    float pro = 0;
    float max = INT_MIN;
    float min = INT_MAX;

    while (i < tam)
    {
        if (a[i] <= min)
        {
            min = a[i];
        }
        if (a[i] >= max)
        {
            max = a[i];
        }
        pro = pro + a[i];
        i = i + 1;
    }
    
    res.maximo = max;
    res.minimo = min;
    res.promedio = pro / tam;

    return res;
}

void pedirArreglo(float a[], int tam)
{
    int i = 0;
    while (i < tam)
    {
        printf("ingrese un valor para la posicion a[%d] del arreglo:\n",i);
        scanf("%f",&a[i]);
        i = i + 1;
    }
}

int main()
{
    struct datos_t res;
    int tam;
    printf("ingrese un valor entero para el tamano del arreglo:\n");
    scanf("%d",&tam);
    if (tam <= 0)
    {
        printf("el arreglo no puede ser vacio\n");
        assert (tam > 0);
    }
    

    float a[tam];
    pedirArreglo(a,tam);

    res = stats(a,tam);
    printf("el maximo del arreglo es: %f\nel minimo del arreglo es: %f\nel promedio del arreglo es: %f",res.maximo,res.minimo,res.promedio);
    return 0;
}
