#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

static void merge(int inputA[], size_t lengthA, int inputB[], size_t lengthB, int output[]) {

    int i = 0;
    int j = 0;
    int k = 0;

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

void mergesort(int input[], int output[], size_t num_input_elements) {

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
        int * firsthalf = input;
        int * secondhalf = input + firsthalf_size;

        int * firsthalf_output = (int *)malloc(firsthalf_size);
        int * secondhalf_output = (int *)malloc(secondhalf_size);

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
