#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "astack_private.h"

Stack *stack_init() {

    Stack *astack = malloc(sizeof(Stack));

    if (!astack) {
        return NULL;
    }

    astack->sf_p = malloc(sizeof(stack_frame_meta));

    if (!astack->sf_p) {
        return NULL;
    }

    astack->sf_p->data_p = NULL;
    astack->sf_p->size_of_stack_frame_data = 0;

    return astack;
}

void stack_destroy(Stack *astack) {

    if (!astack) {
        return;
    }

    if (!astack->sf_p) {
        return;
    }

    free(astack->sf_p);
    free(astack);
}
