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

int list_add_to_end(List *alist, void *const data) {

    if ((!alist) || (!data)) {
        return -1;
    }

    list_elem *elem = malloc(sizeof(list_elem));

    if ((!alist->head) && (!alist->tail)) {
        //List is empty, add first element
        alist->head = elem;
        alist->tail = elem;
    }
    else {
        if ((alist->head) && (alist->tail)) {
            //List is not empty, add new element after tail
            list_elem * old_tail = alist->tail;
            alist->tail = elem;
            old_tail->next = alist->tail;
        }
        else {
            assert(0);
        }
    }

    alist->tail->data = data;
    alist->tail->next = NULL;
    alist->num_elements++;

    return 0;
}

int list_add_to_front(List *alist, void *const data) {

    if ((!alist) || (!data)) {
        return -1;
    }

    list_elem *elem = malloc(sizeof(list_elem));

    if ((!alist->head) && (!alist->tail)) {
        //List is empty, add first element
        alist->head = elem;
        alist->tail = elem;
        alist->tail->next = NULL;
    }
    else {
        if ((alist->head) && (alist->tail)) {
            //List is not empty, add new element in front of head
            list_elem * old_head = alist->head;
            alist->head = elem;
            elem->next = old_head;
        }
        else {
            assert(0);
        }
    }

    alist->head->data = data;
    alist->num_elements++;

    return 0;
}

size_t list_size(const List * const alist) {

    if (!alist) {
        return 0;
    }
    else {
        return alist->num_elements;
    }
}

list_elem * list_head(const List * const alist) {

    if (!alist) {
        return NULL;
    }
    else {
        return alist->head;
    }
}

list_elem * list_tail(const List * const alist) {

    if (!alist) {
        return NULL;
    }
    else {
        return alist->tail;
    }
}

list_elem * list_next(const list_elem * const elem) {

    if (!elem) {
        return NULL;
    }
    else {
        return elem->next;
    }
}

void * list_data(const list_elem * const elem) {

    if (!elem) {
        return NULL;
    }
    else {
        return elem->data;
    }
}

int list_destroy(List ** alist) {

    if (!(*alist)) {
        return -1;
    }

    list_elem *curr = (*alist)->head;

    while (curr) {
        list_elem *next = curr->next;
        free(curr);
        curr = next;
    }

    free(*alist);
    *alist = NULL;

    return 0;
}
