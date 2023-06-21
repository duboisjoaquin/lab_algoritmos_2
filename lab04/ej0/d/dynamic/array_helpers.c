#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>



void array_dump(int a[], size_t length) {
    fprintf(stdout, "length: %zu\n", length);
    fprintf(stdout, "[ ");
    for (size_t i = 0u; i < length; ++i) {
        fprintf(stdout, "%d", a[i]);
        if (i < length - 1) {
            fprintf(stdout, ", ");
        }
    }
    fprintf(stdout, "]\n");
}


int * array_from_file(const char *filepath, size_t *length) {
    FILE *file = NULL;
    file = fopen(filepath, "r");
    if (file == NULL) {
        fprintf(stderr, "File does not exist.\n");
        exit(EXIT_FAILURE);
    }
    unsigned int i = 0u;
    size_t size = 0;
    int res = 0;
    res = fscanf(file, " %zu ", &size);
    if (res != 1) {
        fprintf(stderr, "Invalid array.\n");
        exit(EXIT_FAILURE);
    }

    int *array=NULL;

    
    array = malloc(size * sizeof(int)); //debo multiplicar la cantidad de elementos del array por la cantidad de memoria que ocupa cada entero 
    *length = size; //el valor de donde apunta el puntero  


    if (size > 0 && array == NULL) {
        fprintf(stderr, "Not enough memory\n");
        exit(EXIT_FAILURE);
    }
    while (i < size) {
        res = fscanf(file," %d ", &(array[i]));
        if (res != 1) {
            fprintf(stderr, "Invalid array.\n");
            exit(EXIT_FAILURE);
        }
       ++i;
    }
    fclose(file);
    return array;
}

