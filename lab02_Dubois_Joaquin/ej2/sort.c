#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"


/*
proc quick_sort_rec(in/out a: array[1..n] of T, in lft,rgt: nat)
    var ppiv: nat
    if rgt > lft --> partition(a,lft,rgt,ppiv)
        quick_sort_rec(a,lft,ppv-1)
        quick_sort_rec(a,ppiv+1,rgt)
    fi
end proc
*/

static void quick_sort_rec(int a[], unsigned int izq, unsigned int der) {
    unsigned int ppiv;
    if (der>izq){
        ppiv = partition (a,izq,der);

        if (ppiv>izq){
        quick_sort_rec(a,izq,ppiv-1);
        quick_sort_rec(a,ppiv+1,der);
        }
        else{
        quick_sort_rec(a,izq,ppiv);
        quick_sort_rec(a,ppiv+1,der);
        }
    }
}

void quick_sort(int a[], unsigned int length) {
    quick_sort_rec(a, 0u, (length == 0u) ? 0u : length - 1u);
}

