#include <stdlib.h>
#include <stdio.h>

void absolute(int x, int y) {
    
    if (x >= 0){
        y = x;
    } 
    else{
        y = -x;
    }
}

int main(void) {
    int a=0, res=0;
    a = -10;

    absolute(a, res);
    
    printf("%d\n", res);

    // Utilizando abs1, no se modifica el valor de res y continua siendo 0 

    return EXIT_SUCCESS;
}

