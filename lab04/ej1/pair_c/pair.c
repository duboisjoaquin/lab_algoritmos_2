#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "pair.h"

struct s_pair_t {
    int fst;
    int snd;
};

pair_t pair_new(int x, int y){

    pair_t res;

    res = malloc(sizeof(int) + sizeof(int));    //necesito espacio para 2 enteros distintos

    res->fst = x;
    res->snd = y;

    assert(res->fst == x && res->snd == y);

    return res;

}

int pair_first(pair_t p){

    assert(p != NULL );                         //assert para chequear que sea distinto de vacio 

    int res = p->fst;

    assert(res = p->fst);
    return res;
}

int pair_second(pair_t p){

    assert(p != NULL );
    int res = p->snd;

    assert(res = p->snd);
    return res;

}

pair_t pair_swapped(pair_t p){

    assert(p != NULL);
    int first = p->fst;
    int second = p->snd;
    pair_t q = pair_new(second,first);

    assert(p->fst == q->snd && p->snd == q->fst);
    
    return q;
}

pair_t pair_destroy(pair_t p){
    
    free(p);
    p = NULL;

    return p;
}