#include <stdbool.h>
#include <assert.h>

#include "fixstring.h"


unsigned int fstring_length(fixstring s) {
    
    bool quit = 1;
    unsigned int i = 0; 
    
    while (quit){
        if (s[i] != '\0'){
            i ++;
        }
        else{
            quit = 0;
        }
    }

    return i;
}

bool fstring_eq(fixstring s1, fixstring s2) {
    
    bool res = 1; 
    if (fstring_length(s1) == fstring_length(s2)){
        for (unsigned int i = 0; i <= fstring_length(s1); i++){
            if(s1[i] != s2[i]){
                res = 0;
            }
        }
    }
    else{
        res = 0;
    }

    return res;
}

bool fstring_less_eq(fixstring s1, fixstring s2) {
        bool res = 1;
    bool quit = 1;

    if (fstring_length(s1) >= fstring_length(s2)){      
        for (unsigned int i=0; i < fstring_length(s1) && quit; i++){      
            if (s1[i]>s2[i]){                                   
                res = 0;
            }
            else if (s1[i]<s2[i]){
                quit = 0;
            }
            /*If s1[i] == s2[i] -> Skip, vuelve a ejecutar el bucle de nuevo y compara la siguiente letra*/
        }
    }
    else{ 
        for (unsigned int i=0; i < fstring_length(s2) && quit; i++){      
            if (s1[i]>s2[i]){                                   
                res = 0;
            }
            else if (s1[i]<s2[i]){
                quit = 0;
            }
        }
    }


    return res;
}

void fstring_set(fixstring s1, const fixstring s2) {
    int i=0;
    while (i<FIXSTRING_MAX && s2[i]!='\0') {
        s1[i] = s2[i];
        i++;
    }
    s1[i] = '\0';
}

void fstring_swap(fixstring s1,  fixstring s2) {
    fixstring aux;

    fstring_set(aux,s1);
    fstring_set(s1,s2);
    fstring_set(s2,aux);

    
}


