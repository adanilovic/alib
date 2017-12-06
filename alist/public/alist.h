#ifndef _ALIST_H_
#define _ALIST_H_

#ifdef __cplusplus
extern "C" {
#endif // #ifdef __cplusplus

typedef struct List List;
List * list_init();
int list_add_next(List * alist, const void * const data);
int list_destroy(List *alist);

#ifdef __cplusplus
}
#endif // #ifdef __cplusplus

#endif // #define _ALIST_H_
