#include <stdlib.h>
#include <assert.h>
#include "stack.h"

struct _s_stack {
    stack_elem *elems;      // Arreglo de elementos
    unsigned int size;      // Cantidad de elementos en la pila
    unsigned int capacity;  // Capacidad actual del arreglo elems
};

stack stack_empty(){
    stack s = malloc(sizeof(struct _s_stack));

    s->capacity = 1;
    s->size = 0;
    s->elems = malloc(sizeof(stack_elem)*s->capacity*2);

    return(s);
}

stack stack_push(stack s, stack_elem e){
    

    s->size++;  
    if(s->size > s->capacity){ 
        s->elems = realloc(s->elems,sizeof(stack_elem)*s->capacity*2); 
        s->capacity *= 2; 
    }
    s->elems[s->size-1] = e;
    return s;
}

stack stack_pop(stack s){

    assert(s != NULL);

    s->size = s->size-1;

    return s;

}

unsigned int stack_size(stack s){
    if (s==NULL){
        return 0;
    }
    else{
        return (s->size);
    }
}

stack_elem stack_top(stack s){
    
    assert(s!=NULL);

    stack_elem e = s->elems[0];

    return e;
}

bool stack_is_empty(stack s){
    return(s == NULL);
}

stack_elem *stack_to_array(stack s){

    stack_elem *res;

    res = (stack_elem*)calloc(s->size, sizeof(stack_elem));

    for( unsigned int i = 0; i < s->size ;i++){
        res[i] = s->elems[i];
    }

    return res;
}

stack stack_destroy(stack s){

    free(s->elems);
    free(s);
    s = NULL;

    return s;
}