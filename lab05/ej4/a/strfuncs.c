#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "strfuncs.h"


//calcula la longitud de la cadena apuntada por str
size_t string_length(const char *str){
    unsigned int count = 0u;
    size_t tamaño = 0;
    while (str[count] != '\0'){
        tamaño = tamaño + sizeof(str[count]);
        count++;
    }
    return tamaño;
}

char *string_filter(const char *str, char c){

    char *new_chain = malloc(sizeof(char)*string_length(str)+1); 
    unsigned int indNew = 0u;

    for (unsigned int i = 0u; str[i]!= '\0'; i++){
        if (str[i]!=c){
            new_chain[indNew] = str[i];
            indNew++;
        }
    }
    new_chain[indNew] = '\0';
    return new_chain;
}