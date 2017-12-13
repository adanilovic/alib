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

int stack_push(Stack *astack, void * data) {

    if (!astack) {
        return -1;
    }

    return list_add_to_front(astack->alist, data);
}

void * stack_peek(Stack *astack) {

    if (!astack) {
        return NULL;
    }

    return list_data(list_head(astack->alist));
}

size_t stack_size(Stack *astack) {

    if (!astack) {
        return 0;
    }

    return list_size(astack->alist);
}

void * stack_pop(Stack *astack) {

    if (!astack) {
        return NULL;
    }

    return list_remove_from_front(astack->alist);
}

int stack_destroy(Stack *astack) {

    if (!astack) {
        return -1;
    }

    if (!astack->alist) {
        return -1;
    }

    (void)list_destroy(&astack->alist);
    free(astack);

    return 0;
}
