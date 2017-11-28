#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "stack.h"

int stack_init(Stack *stack) {

    stack->sf_p = malloc(sizeof(stack_frame_meta));

    if (!stack->sf_p) {
        return -1;
    }

    stack->sf_p->data_p = NULL;
    stack->sf_p->size_of_stack_frame_data = 0;

    return 0;
}
