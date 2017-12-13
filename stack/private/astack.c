#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "astack_private.h"

Stack *stack_init() {

    Stack *astack = malloc(sizeof(Stack));

    if (!astack) {
        return NULL;
    }

    astack->alist = list_init();

    if (!astack->alist) {
        free(astack);
        return NULL;
    }

    return astack;
}

void stack_destroy(Stack *astack) {

    if (!astack) {
        return;
    }

    if (!astack->alist) {
        return;
    }

    (void)list_destroy(&astack->alist);
    free(astack);
}
