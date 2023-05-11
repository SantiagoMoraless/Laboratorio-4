#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>

#include "counter.h"

struct _counter {
    unsigned int count;

};

counter counter_init(void) {
    counter c;
    c = malloc(sizeof(counter));
    c->count = 0;
    assert(counter_is_init(c));
    return c;
}



void counter_inc(counter c) {
    c->count += 1;
}

bool counter_is_init(counter c) {
    bool b;
    b = (c->count == 0);
    return b;
}

void counter_dec(counter c) {
    assert(!counter_is_init(c));
    c->count -= 1;
}

counter counter_copy(counter c) {
    counter c2;
    c2 = counter_init();
    c2->count = c->count;
    return c2;
}

void counter_destroy(counter c) {
    free(c);
}

