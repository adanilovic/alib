#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "astack_private.h"

Stack * stack_init() {

    astack->sf_p = malloc(sizeof(stack_frame_meta));

    if (!astack->sf_p) {
        return -1;
    }

    astack->sf_p->data_p = NULL;
    astack->sf_p->size_of_stack_frame_data = 0;

    return 0;
}

void stack_destroy(Stack *astack) {
    free(astack->sf_p);
}
