#include <stdio.h>
#include <stdbool.h>

int pedirEntero (char*nombre)
{
 int x;
 printf ("Ingrese un valor para %s:\n", nombre);
 scanf ("%d", &x);
 return x;
}

int imprimirEntero (char*nombre, int x)
{
 printf ("%s --> %d\n", nombre, x);
}

struct triangulo {
int l1;
int l2;
int l3;
};

struct caract_triangulo {
bool es_equilatero;
int perimetro;
};

struct caract_triangulo averiguar_caract(struct triangulo t)
{
struct caract_triangulo res;
res.es_equilatero = (t.l1 == t.l2) && (t.l2 = t.l3);
res.perimetro = t.l1 + t.l2 + t.l3;
return res;
}

int main ()
{
struct triangulo t;
struct caract_triangulo res;
t.l1 = pedirEntero ("l1");
t.l2 = pedirEntero ("l2");
t.l3 = pedirEntero ("l3");
res = averiguar_caract (t);
imprimirEntero ("esEquilatero", res.es_equilatero);
imprimirEntero ("perimetro", res.perimetro);

return 0;
}

