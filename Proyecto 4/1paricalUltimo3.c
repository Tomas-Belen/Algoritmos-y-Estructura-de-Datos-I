#include <stdio.h>
#include <stdbool.h>

float pedirEntero (char* nombre)
{
float x;
printf ("Ingrese un valor para el color %s:\n", nombre);
scanf ("%f", &x);
return x;
}

void imprimirEntero (char*nombre, int x)
{
 printf ("%s --> %d\n", nombre, x);
}

struct color_rgb {
    int rojo;
    int verde;
    int azul;
};

struct color_YCbCr {
    int luma;
    int croma_azul;
    int croma_rojo;
    bool es_oscuro;
};

struct color_YCbCr transformar_color(struct color_rgb c)

{
 struct color_YCbCr res;
 res.luma = ((30 * c.rojo + 59 * c.verde + 11 * c.azul) / 100);
 res.croma_azul = (128 + ((50 * c.azul - 42 * c.verde - 17 * c.rojo)) / 100);
 res.croma_rojo = (128 + ((50 * c.rojo - 42 * c.verde - 8 * c.azul)) / 100); 
 res.es_oscuro = res.luma < 128; 
 return res;
}

int main ()
{
 struct color_rgb c;
 struct color_YCbCr col;
 c.rojo = pedirEntero ("rojo");
 c.verde = pedirEntero ("verde");
 c. azul = pedirEntero ("azul");
 col = transformar_color (c);
 imprimirEntero ("Luma", col.luma);   
 imprimirEntero ("Croma Azul", col.croma_azul);
 imprimirEntero ("Croma Rojo", col.croma_rojo);    
 imprimirEntero ("Oscuro", col.es_oscuro);

 return 0;  
}

// Ingrese un valor para el color rojo:
// 255
// Ingrese un valor para el color verde:
// 0
// Ingrese un valor para el color azul:
// 255
// Luma --> 104
// Croma Azul --> 212
// Croma Rojo --> 235
// Oscuro --> 1