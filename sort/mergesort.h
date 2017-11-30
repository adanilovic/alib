#ifndef _MERGESORT_H_
#define _MERGESORT_H_

#ifdef __cplusplus
extern "C" {
#endif // #ifdef __cplusplus

void mergesort_int(int input[], int output[], size_t num_input_elements);

int mergesort(void *data,
    size_t num_elements,
    size_t size_of_each_element,
    int (*compare)(const void *elem1, const void* elem2));

#ifdef __cplusplus
}
#endif // #ifdef __cplusplus

#endif // #define _MERGESORT_H_
