#include <stdio.h>
/**
    operacion binaria con el operador and "&" 
    en las tablas de verdad tenemos esta definición
    |-----------
    | 0 | 1 | 0 |
    | 0 | 1 | 0 |
    | 1 | 0 | 0 |
    | 1 | 1 | 1 |   

    una suma se resolveria de la siguiente forma
    00010111 (23)
 &  01011010 (90)
    --------
    00010010 (18)

    si se utiliza el operador & en un condicional devolvera si hay un 1 en la operacion 
*/
int main(){
    char a = 75;
    char b = 8;
    char resultado;

    printf("a = %d b= %d ",a, b);
    // resultado = a & b;
    if( a & b) {
        printf("%s", "se ha encontrado un valor 1 en la variable b");

    }else{
        printf("%s", "no hay ningun 1 solo 0 ");
    }
    printf(" resultado = %d", resultado);
}