/*gcc -Wall -Wextra -Werror -std=c99 archivo.c -o ejecutable*/

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

//#define l (4)

typedef struct{
    bool is_upperbound;
    bool is_lowerbound;
    bool exists;
    unsigned int where;
}bound_data ;

bound_data check_bound(int v, int arr[], unsigned int length) {
    bound_data res;
    unsigned int i;
    res.is_upperbound = 1;
    res.is_lowerbound = 1;
    res.exists = 0;

    bool flag = 0;

    for (i = 0; i < length; i++){

    
        if (v < arr[i]){
            res.is_upperbound = 0;
        }
        if (v > arr[i]){
            res.is_lowerbound = 0;
        }
        if (flag == 0){

            if (v == arr[i]){
                res.exists = 1;
                res.where = i;
                flag = 1;
        }
        }
        
    }

    return res;
}

int pedirEntero (void){
    int n;
    printf ("Ingrese un numero entero: ");
    scanf("%d", &n);
    return n;
} 


void pedirArreglo (int a[], int n_max){
    
    int i = 0;
    
    while (i < n_max){
        
        a[i] = pedirEntero();
        i += 1;
    }
    
}

int main(void) {

    // Pedir largo del arreglo
    int l;
    printf("Inserte el largo de la lista: ");
    scanf("%d", &l);
    
    //declarar arreglo de largo l
    int a[l];
    
    //pedir numeros que componen el arreglo
    pedirArreglo (a, l);

    //pedir valor a chequear con la funcion
    int v;
    printf("Inserte valor a chequear en el arreglo: ");
    scanf("%d", &v);

    bound_data result = check_bound(v, a, l);


    printf("%d", result.is_upperbound); 
    printf("\n");
    printf("%d", result.is_lowerbound); 
    printf("\n");
    printf("%u", result.exists);        
    printf("\n");
    if (result.exists == 1){
    printf("%u", result.where);         
    }
    printf("\n");

    return EXIT_SUCCESS;
}

