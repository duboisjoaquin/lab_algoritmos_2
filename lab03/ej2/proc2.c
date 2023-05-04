#include <stdlib.h>
#include <stdio.h>

void absolute(int x, int *y){

    if (x >= 0){
        *y = x;
    } 
    else{
        *y = -x;
    }

}

int main(void) {

    int a=0, res=0;  // No modificar esta declaración
    a = -10;
    int *p = NULL;

    p = &res;

    absolute(a, p);

    printf("%d\n", res);
    return EXIT_SUCCESS;
}

/*Para pensar:
● El parámetro int *y de absolute() es de tipo in, de tipo out o de tipo in/out

in/out

●¿Qué tipo de parámetros tiene disponibles C para sus funciones?
○ Parámetros in         si
○ Parámetros out        si
○ Parámetros in/out     si?
*/
