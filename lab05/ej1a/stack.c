#include <stdlib.h>
#include <assert.h>
#include "stack.h"

stack stack_empty(){

    stack res = NULL; 
    return(res);

}

stack stack_push(stack s, stack_elem e){

    stack s2 = malloc(sizeof(stack));
    s2->elem = e;
    s2->next = s;
    s = s2;
    return s;

}

stack stack_pop(stack s){
    
    // assert(s =S= Null)

    stack p = malloc(sizeof(stack));

    p = s;

    s=s->next;

    free(p);

    return s;
}

unsigned int stack_size(stack s){

    stack p;
    unsigned int n = 0;
    p = s;
    while (p!=NULL){
        p=p->next;
        n=n+1;
    }

    return n;
}

stack_elem stack_top(stack s){
    
    assert(s!=NULL);

    stack_elem e = s->elem;

    return e;
}

bool stack_is_empty(stack s){
    return(s == NULL);
}

stack_elem *stack_to_array(stack s){

    stack p = s;
    unsigned int length = stack_size(s);
    stack_elem *res;

    res = (stack_elem*)calloc(length, sizeof(stack_elem));

    for(int i = length-1;i>=0;i--){
        res[i] = p->elem;
        p = p->next;
    }

    return res;
}

stack stack_destroy(stack s){

    if(s!=NULL){
        stack p,q;
        p = s;
        while(p->next!=NULL){
            q = p;
            p = p->next;
            free(q);
        }
        free(p);
    }

    return s;
}
