#include <stdio.h>
#include <stdbool.h>

char pedirLetra ()
{
  char x;  
  printf ("Ingrese una letra vocal:\n");
  scanf ("%c", &x);
  
  return x;  
}

bool es_vocal(char letra)
{
 letra = tolower(letra);
 return letra == 'a' || letra == 'e' || letra == 'i' || letra == 'o' || letra == 'u';
}

int main (){
char x = pedirLetra ();
 if (es_vocal (x))
 {
 printf ("La letra %c si es una vocal\n", x);
 }
 else {
 printf ("La letra %c no es una vocal\n", x);
 }

return 0;
}