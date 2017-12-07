#ifndef _ALIST_H_
#define _ALIST_H_

#ifdef __cplusplus
extern "C" {
#endif // #ifdef __cplusplus

typedef struct List List;
typedef struct list_elem list_elem;

List * list_init();
int list_add_to_end(List *alist, void * const data);
int list_add_to_front(List *alist, void *const data);
size_t list_size(const List * const alist);
list_elem * list_head(const List * const alist);
list_elem * list_tail(const List * const alist);
list_elem * list_next(const list_elem * const elem);
void * list_data(const list_elem * const elem);
int list_destroy(List ** alist);

#ifdef __cplusplus
}
#endif // #ifdef __cplusplus

#endif // #define _ALIST_H_
