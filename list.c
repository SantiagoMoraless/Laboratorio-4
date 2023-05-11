#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>

#include "list.h"

struct _Node {
    list_elem elem;
    struct _Node *next;
};



list empty(void){
    list l;
    l = NULL;
    return l;
}

list addl(list l, list_elem e) {
    list l2;
    l2 = malloc(sizeof(list));

    l2->elem = e;
    l2->next = l;

    l = l2;
    return l;
}

void destroy(list l){
    list l2;
    while(l != NULL){
        l2 = l->next;
        free(l);
        l = l2;
    }
}

bool is_empty(list l){
    bool b;
    b = l == NULL;
    return b;
}

list_elem head(list l){
    assert(!is_empty(l));
    list_elem e;
    e = l->elem;
    return e;
}

list tail(list l){
    assert(!is_empty(l));
    list l2;
    l2 = l;
    l = l->next;
    free(l2);
    return l;
}

list addr(list l, list_elem e){
    list l2,l3;
    l3 = malloc(sizeof(list));
    l3->elem = e;
    l3->next = NULL;

    if(!is_empty(l)){
        l2 = l;
        while (l2->next != NULL){
            l2 = l2->next;
        }
        l2->next = l3;
    } else {
        l = l3;
    }
    return l;
}

unsigned int length(list l){
    list l2;
    unsigned int n = 0;
    l2 = l;

    while(l2 != NULL){
        n += 1;
        l2 = l2->next;
    }
    return n;
}

list concat(list l1, list l2){
    list ultimo;
    ultimo = malloc(sizeof(list));

    if (l1 == NULL){
        l1 = l2;
    } else {
        ultimo = l1;
        while(ultimo -> next != NULL){
            ultimo = ultimo->next;
        }
        ultimo->next = l2;
    }

    return l1;
}

list_elem index(list l, unsigned int n){
    assert(length(l) > n);
    list_elem e;
    list l2;
    l2 = l;
    while(n != 0){
        n -= 1;
        l2 = l2->next;
    }
    e = l2->elem;

    return e;
}

list take(list l, unsigned int n){
    list l2,l3;
    if(n = 0){
        destroy(l);
        l = empty();
    } else {
        l2 = l;

        while(n != 1){
            l2 = l2->next;
            n -= 1;
        }

        l3 = l2->next;
        l2->next = NULL;
        destroy(l3);
    }

    return l;
}

list drop(list l, unsigned int n){
    list l2;

    while(n != 0){
        n -= 1;
        l2 = l;
        l = l->next;
        freep(l2);
    }

    return l;
}

list copy_list(list l1){
    list l2,l3,l4;

    l2 = l1;
    l3 = malloc(sizeof(list));
    l4 = l3;

    while(l2->next != NULL){
        l3->elem = l2->elem;
        l3->next = l2->next;

        l2 = l2->next;
        l3 = l3->next;
    }

    return l4;
    
}