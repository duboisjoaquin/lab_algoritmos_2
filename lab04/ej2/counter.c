#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>

#include "counter.h"

struct _counter {
    unsigned int count;
};

counter counter_init(void) {

    counter c;
    c = malloc(sizeof(unsigned int));
    c->count = 0;

    return c;
}

void counter_inc(counter c) {

    c->count = c->count+1;
    
}

bool counter_is_init(counter c) {
    bool b = (c->count == 0u);

    return b;
}

void counter_dec(counter c) {

    assert(!counter_is_init(c));

    c->count = c->count-1;

}

counter counter_copy(counter c) {

    counter copy = counter_init();
    copy->count = c->count;
    return copy;
}

void counter_destroy(counter c) {
    
    free(c);

}
