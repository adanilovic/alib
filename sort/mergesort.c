#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

/*static int _mergesort(void *data,
    size_t num_input_elements,
    size_t size_of_each_element,
    int (*compare)(const void *elem1, const void* elem2)) {

    return 0;
}*/

int mergesort(void *data,
    size_t num_input_elements,
    size_t size_of_each_element,
    int (*compare)(const void *elem1, const void* elem2)) {

    char * a = data;

    compare(&a[0], &a[1 * size_of_each_element]);

    return will_mul_size_t_overflow(num_input_elements, size_of_each_element);

    //void *output = malloc(num_input_elements * size_of_each_element);

    //_mergesort();
}

