#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

#include "list.h"

struct _node
{
    list_elem elem;
    struct _node *next; 

};

list empty(){

    list l = NULL;
    
    return l;

}

list addl(list_elem e, list l){

    list l2 = malloc(sizeof(list));
    l2->elem = e;
    l2->next = l;
    l = l2;
    return l;
}

void destroy (list l){
    
    if(l!=NULL){
        list p,q;
        p = l;
        while(p->next!=NULL){
            q = p;
            p = p->next;
            free(q);
        }
        free(p);
    }

}

bool is_empty (list l){

    //printf("\n IS_EMPTY FUNCIONA \n");
    return (l == NULL);


}

list_elem head(list l){

    assert(!is_empty(l));
    list_elem e = l->elem;

    //printf("\n HEAD FUNCIONA \n");

    return e;

    
}

list tail (list l){
    assert(!is_empty(l));

    list p;

    p = l;
    l = l->next;

    free(p);

    return l;
}

list addr(list l, list_elem e){
    list p;
    list q;

    q = malloc(sizeof(list));

    p=l;

    q->elem = e;
    q->next = NULL;

    if (is_empty(l)){
        l = q;
    }
    else{
        while(p->next!=NULL){
            p=p->next;
        }
        p->next = q;
    }

    return l;
}

unsigned int lenght (list l){
    list p;
    unsigned int n = 0;
    p = l;
    while (p!=NULL){
        p=p->next;
        n=n+1;
    }

    return n;
}

list concat ( list l, list l0){

    list p;
    p = l;
    while (p->next!=NULL){
        p=p->next;
    }
    p->next = l0;

    return l;
}

list_elem index(list l, unsigned int n){

    assert(lenght(l) >= n);

    unsigned int aux = 0;
    list_elem res;
    list p = l;

    while(aux<n){
        p=p->next;
        aux+=1;
    }
    res = p->elem;

    return res;
}

list take(list l, unsigned int n){

    unsigned int i = 0;
    list p = l,q, j=l;
    while(i<n){
        p=p->next;
        i++;
        j=j->next;
    }
    while(p->next!=NULL){
            q = p;
            p = p->next;
            free(q);
    }
    j->next = NULL;
    free(p);

    return l;
}

list drop(list l, unsigned int n){
    unsigned int i = 0;
    list p;

    while(i<n){
        p=l;
        l=l->next;
        free(p);
        i++;
    }


    return l;
}

list copy_list(list l){
    list copy = NULL,p;
    p = l;


    if(is_empty(l)){
        return copy;
    }
    else{
        copy = addr(copy, l->elem);
        p = p->next;
        while(p!=NULL){
            copy = addr(copy,p->elem);
            p = p->next;
        }

        return copy;
    }

}

