#include <stdio.h>
#include <stdbool.h>


bool es_primo(int x)
{
    int i = 2;
    bool res = true;

    while ((i < x) && res)
    {
        res = res && ((x % i) != 0);
        i = i + 1;
    }

    return res;
}

int nesimo_primo(int N)
{
    int c = 0;
    int i = 2;
    while (i <= N)
    {
        if (es_primo(i))
        {
            c = c + 1;
        }
        i = i + 1;
    }
    return c;
}

int pedirEntero(char y)
{
    int x;
    printf("Ingrese un valor numerico positivo para %c:\n", y);
    scanf("%d", &x);
    return x;
}

int main()
{
    int r;
    int n = pedirEntero('n');
    while (n < 0)
    {
        printf("numero invalido\n");
        n = pedirEntero('n');
    }
    if (n == 0 || n == 1)
    {
        r = 0;
    }else
    {
        r = nesimo_primo(n);
    }
    printf("nesimo primo de N = %d", r);
    return 0;
}


