#ifndef _ALIST_PRIVATE_H_
#define _ALIST_PRIVATE_H_

#ifdef __cplusplus
extern "C" {
#endif // #ifdef __cplusplus

#include "alist.h"

struct list_elem {
    void *data;
    list_elem *next;
};

struct List {
    list_elem *head;
    list_elem *tail;
    size_t num_elements;
    void (*destroy_elem)(void *data);
    int (*match)(const void *elem1, const void *elem2);
};

#ifdef __cplusplus
}
#endif // #ifdef __cplusplus

#endif // #define _ALIST_PRIVATE_H_
