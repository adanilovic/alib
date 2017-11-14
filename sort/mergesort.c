#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

static void merge(const int inputA[], size_t lengthA, const int inputB[], size_t lengthB, int output[]) {

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

void mergesort(const int input[], int output[], size_t num_input_elements) {

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

        mergesort(firsthalf,  firsthalf_output,  firsthalf_size);
        mergesort(secondhalf, secondhalf_output, secondhalf_size);
        merge(firsthalf_output, firsthalf_size,
              secondhalf_output, secondhalf_size,
              output);

        free(firsthalf_output);
        free(secondhalf_output);
    }
}
