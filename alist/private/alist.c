#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>

#include "alist_private.h"

void list_print_each(const List * const alist) {

    if ((!alist) || (!alist->head) || (!alist->tail)) {
        return;
    }

    const list_elem * elem = alist->head;

    while (elem != NULL) {
        printf("%d ", *(int *)(elem->data));
        elem = elem->next;
    }
    printf("\n");
}

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

void * list_remove_from_end(List *alist) {

    if ((!alist) ||
        (alist->num_elements == 0) ||
        (!alist->tail) ||
        (!alist->head)) {
        return NULL;
    }

    //head -> elem1              head -> tail -> elem1
    //          next = elem2                       next = NULL
    //        elem2
    //          next = elem3
    //elem->  elem3
    //          next = elem4
    //tail -> elem4
    //          next = NULL

    list_elem * elem = alist->head;

    while ((elem) && ((elem->next)) && ((elem->next->next))) {
        elem = elem->next;
    }

    //elem is now the last, or 2nd to last element

    void * data = alist->tail->data;

    if (!(elem->next)) {
        //elem is the last element
        free(alist->tail);
        alist->tail = NULL;
        alist->head = NULL;
    }
    else{
        //elem is 2nd to last element
        free(alist->tail);
        alist->tail = elem;
        alist->tail->next = NULL;
    }

    alist->num_elements--;

    return data;
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

void * list_remove_from_front(List *alist) {

    if ((!alist) ||
        (alist->num_elements == 0) ||
        (!alist->tail) ||
        (!alist->head)) {
        return NULL;
    }

    void * data = alist->head->data;

    if (!(alist->head->next)) {
        assert(alist->head == alist->tail);
        free(alist->head);
        alist->head = NULL;
        alist->tail = NULL;
    }
    else {
        list_elem * new_head = alist->head->next;
        free(alist->head);
        alist->head = new_head;
    }

    alist->num_elements--;

    return data;
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

size_t list_num_elements(const List * const alist) {

    if (!alist) {
        return 0;
    }
    else {
        return alist->num_elements;
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

    list_elem *elem = (*alist)->head;

    while (elem) {
        list_elem *next = elem->next;
        free(elem);
        elem = next;
    }

    free(*alist);
    *alist = NULL;

    return 0;
}
