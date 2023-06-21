#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "pair.h"

pair_t pair_new(int x, int y){

    pair_t res;

    res.fst = x;
    res.snd = y;

    assert(res.fst == x && res.snd == y);

    return res;

}

int pair_first(pair_t p){

    assert(p.fst == p.fst && p.snd == p.snd);

    int res = p.fst;

    assert(res == p.fst);
    return res;
}

int pair_second(pair_t p){

    assert(p.fst == p.fst && p.snd == p.snd);

    int res = p.snd;

    assert(res = p.snd);
    return res;

}

pair_t pair_swapped(pair_t p){

    assert(p.fst == p.fst && p.snd == p.snd);

    //auxiliares para el assert
    int first = p.fst;
    int second = p.snd;

    //swap

    int aux;
    aux = p.fst;
    p.fst = p.snd;
    p.snd = aux;

    assert(p.fst == second && p.snd == first);

    return p;
}

pair_t pair_destroy(pair_t p){
    
    return p;
    
}
