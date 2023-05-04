
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "array_helpers.h"


unsigned int array_from_file(int array[], unsigned int max_size, const char *filepath) {
    
    FILE *file = fopen(filepath, "r");

    unsigned int size;

    if (file == NULL){
        printf("Error: null file\n");
        exit(EXIT_FAILURE);
    }
//file es el archivo que va a leer?, %u es por que el primer elemento es el size, y debee ser positivo, &size es el lugar donde se almacena el primer elemento del archivo que se lee

    fscanf(file, "%u", &size);
    
    if (size != 0){

        if (size < max_size){

        unsigned int i = 0;

        while(i<size){
            int aux = fscanf(file, "%d", &array[i]);
            if(aux!=1){
                printf("ERROR: invalid length\n");
                exit(EXIT_FAILURE);
            }
            i++;
        }
        fclose(file);

        return size;
        }
        else{
            printf("Error: Size over limits");
            exit(EXIT_FAILURE);
        }

    }
    else{
        printf("[]");
        exit(EXIT_FAILURE);
    }
}

void array_dump(int a[], unsigned int length) {
    
    if (length>0){
        printf("[");
        for (unsigned int i = 0; i<length-1; i++){
            printf("%d", a[i]);
            printf("%c", ',');
        }
        printf("%d", a[length-1]);
        printf("] \n");
    }

}

bool array_is_sorted(int a[],unsigned int length){
    
    bool res = 1;
    unsigned int i;

    if (length > 1){
        for(i=0; i<length-1; i++){
            if (a[i] > a[i+1]){
                res = 0;
            }
        }
    }
    return res;
}