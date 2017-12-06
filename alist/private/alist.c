#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>

#include "alist_private.h"

List *list_init() {

    List *alist = malloc(sizeof(List));

    if (!alist) {
        return NULL;
    }

    alist->head = NULL;
    alist->tail = NULL;
    alist->num_elements = 0;
    alist->destroy_elem = NULL;
    alist->match = NULL;

    return alist;
}

int list_add_next(List *alist, const void *const data) {

    if ((!alist) || (!data)) {
        return -1;
    }

    list_elem *elem = malloc(sizeof(list_elem));

    if ((!alist->head) && (!alist->tail)) {
        //List is empty, add first element
        printf("1st\n");
        alist->head = elem;
        alist->tail = elem;
    }
    else {
        if ((alist->head) && (alist->tail)) {
            //List is not empty, add new element after tail
            printf("2nd\n");
            list_elem * old_tail = alist->tail;
            alist->tail = elem;
            old_tail->next = alist->tail;
        }
        else {
            assert(0);
        }
    }

    alist->tail->data = data;
    alist->num_elements++;

    return 0;
}

int list_destroy(List *alist) {

    if (!alist) {
        return -1;
    }
    list_elem *curr = alist->head;

    while (curr) {
        list_elem *next = curr->next;
        free(curr);
        curr = next;
    }

    free(alist);

    return 0;
}
