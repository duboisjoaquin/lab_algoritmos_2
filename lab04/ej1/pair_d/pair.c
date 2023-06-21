#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "pair.h"

struct s_pair_t {
    elem fst;
    elem snd;
};

pair_t pair_new(elem x, elem y){

    pair_t res;

    res = malloc(sizeof(elem) + sizeof(elem));    //necesito espacio para 2 enteros distelemos

    res->fst = x;
    res->snd = y;

    assert(res->fst == x && res->snd == y);

    return res;

}

elem pair_first(pair_t p){

    assert(p != NULL );                         //assert para chequear que sea distelemo de vacio 

    elem res = p->fst;

    assert(res = p->fst);
    return res;
}

elem pair_second(pair_t p){

    assert(p != NULL );
    elem res = p->snd;

    assert(res = p->snd);
    return res;

}

pair_t pair_swapped(pair_t p){

    assert(p != NULL);
    elem first = p->fst;
    elem second = p->snd;
    pair_t q = pair_new(second,first);

    assert(p->fst == q->snd && p->snd == q->fst);
    
    return q;
}

pair_t pair_destroy(pair_t p){
    
    free(p);
    p = NULL;

    return p;
}