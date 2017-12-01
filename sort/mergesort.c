#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "amath.h"

static void merge_int(const int inputA[], size_t lengthA, const int inputB[], size_t lengthB, int output[]) {

    size_t i = 0;
    size_t j = 0;
    size_t k = 0;

    for(k = 0; (k < lengthA + lengthB); ++k) {

        if(i < lengthA) {
            if(j < lengthB) {
                if(inputA[i] < inputB[j]) {
                    output[k] = inputA[i];
                    ++i;
                }
                else {
                    output[k] = inputB[j];
                    ++j;
                }
            }
            else {
                output[k] = inputA[i];
                ++i;
            }
        }
        else {
            if(j < lengthB) {
                output[k] = inputB[j];
                ++j;
            }
            else {
                //all done
            }
        }


    }
}

void mergesort_int(const int input[], int output[], size_t num_input_elements) {

    if(num_input_elements == 0) {
        return;
    }
    else if(num_input_elements == 1) {
        output[0] = input[0];
        return;
    }
    else {
        bool is_odd = num_input_elements % 2;
        size_t firsthalf_size = is_odd ? ((num_input_elements / 2) + 1) : (num_input_elements / 2);
        size_t secondhalf_size = num_input_elements / 2;
        const int * firsthalf = input;
        const int * secondhalf = input + firsthalf_size;

        int * const firsthalf_output = (int *)malloc(firsthalf_size * 4);
        int * const secondhalf_output = (int *)malloc(secondhalf_size * 4);

        if((!firsthalf_output) || (!secondhalf_output)) {
            printf("NULL pointer, abort\n");
            exit(-1);
        }

        mergesort_int(firsthalf,  firsthalf_output,  firsthalf_size);
        mergesort_int(secondhalf, secondhalf_output, secondhalf_size);
        merge_int(firsthalf_output, firsthalf_size,
              secondhalf_output, secondhalf_size,
              output);

        free(firsthalf_output);
        free(secondhalf_output);
    }
}

static void merge(const void *inputA, size_t lengthA, const void *inputB, size_t lengthB, void *output,
                  int (*compare)(const void *elem1, const void* elem2),
                  size_t size_of_each_element) {

    size_t i = 0;
    size_t j = 0;
    size_t k = 0;

    const char *a = (const char *)inputA;
    const char *b = (const char *)inputB;
    char *o = (char *)output;

    printf("AD - merge, a = %d, b = %d\n", *(int *)a, *(int *)b);

    for(k = 0; (k < lengthA + lengthB); ++k) {

        if(i < lengthA) {
            if(j < lengthB) {
                if(-1 == compare(&a[i * size_of_each_element], &b[j * size_of_each_element])) {
                    memcpy(&o[k], &a[i], size_of_each_element);
                    printf("AD - merge output, o = %d\n", (int)o[k]);
                    ++i;
                }
                else {
                    memcpy(&o[k], &b[j], size_of_each_element);
                    printf("AD - merge output, o = %d\n", (int)o[k]);
                    ++j;
                }
            }
            else {
                memcpy(&o[k], &a[i], size_of_each_element);
                printf("AD - merge output, o = %d\n", (int)o[k]);
                ++i;
            }
        }
        else {
            if(j < lengthB) {
                memcpy(&o[k], &b[j], size_of_each_element);
                printf("AD - merge output, o = %d\n", (int)o[k]);
                ++j;
            }
            else {
                //all done
            }
        }


    }
}

static int _mergesort(const void *input_data, void *output_data,
    size_t num_input_elements,
    size_t size_of_each_element,
    int (*compare)(const void *elem1, const void* elem2)) {

    const char *a = input_data;

    if(num_input_elements == 0) {
        printf("AD - num elements 0\n");
        return 0;
    }
    else if(num_input_elements == 1) {
        printf("AD - num elements 1\n");
        char *b = output_data;
        memcpy(&b[0], &a[0], size_of_each_element);
        return 0;
    }
    else {
        bool is_odd = num_input_elements % 2;
        size_t firsthalf_size = is_odd ? ((num_input_elements / 2) + 1) : (num_input_elements / 2);
        size_t secondhalf_size = num_input_elements / 2;

        printf("AD - firsthalf_size = %08lx, secondhalf_size  = %08lx\n", firsthalf_size, secondhalf_size );

        const void * firsthalf = input_data;
        const void * secondhalf = (void *)((char *)input_data + (firsthalf_size * size_of_each_element));

        void * const firsthalf_output = (void *)malloc(firsthalf_size * size_of_each_element);
        void * const secondhalf_output = (void *)malloc(secondhalf_size * size_of_each_element);

        if((!firsthalf_output) || (!secondhalf_output)) {
            printf("NULL pointer, return -1\n");
            return -1;
        }

        _mergesort(firsthalf,  firsthalf_output,  firsthalf_size, size_of_each_element, compare);
        _mergesort(secondhalf, secondhalf_output, secondhalf_size, size_of_each_element, compare);
        merge(firsthalf_output, firsthalf_size,
              secondhalf_output, secondhalf_size,
              output_data,
              compare,
              size_of_each_element);

        free(firsthalf_output);
        free(secondhalf_output);
    }

    return 0;
}

int mergesort(void *data,
    size_t num_input_elements,
    size_t size_of_each_element,
    int (*compare)(const void *elem1, const void* elem2)) {

    if(will_mul_size_t_overflow(num_input_elements, size_of_each_element)) {
        return -1;
    }

    void *output = calloc(num_input_elements * size_of_each_element, 1);

    if(!output) {
        return -1;
    }

    int ret = _mergesort(data, output, num_input_elements, size_of_each_element, compare);

    if(!ret) {
        memcpy(output, data, num_input_elements * size_of_each_element);
    }

    if(output) {
        free(output);
    }

    return ret;
}
