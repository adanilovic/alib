#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int *_input = NULL;
int *_output = NULL;
size_t _num_input_elements = 0;

void print_all() {
    for(int i = 0; i < _num_input_elements; ++i) {
        printf("merge, input[%02x] = %d\n", i, _input[i]);
    }

    for(int i = 0; i < _num_input_elements; ++i) {
        printf("merge, output[%02x] = %d\n", i, _output[i]);
    }
}

void merge(int inputA[], size_t lengthA, int inputB[], size_t lengthB, int output[]) {

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

    for(int i = 0; i < lengthA; ++i) {
        printf("merge, inputA[%02x] = %d\n", i, inputA[i]);
    }

    for(int i = 0; i < lengthB; ++i) {
        printf("merge, inputB[%02x] = %d\n", i, inputB[i]);
    }

    for(int i = 0; i < (lengthA + lengthB); ++i) {
        printf("merge, output[%02x] = %d\n", i, output[i]);
    }

    printf("temp\n");
}

void __mergesort(int input[], int output[], size_t num_input_elements) {

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

        print_all();
        __mergesort(firsthalf,  firsthalf_output,  firsthalf_size);
        print_all();
        __mergesort(secondhalf, secondhalf_output, secondhalf_size);
        print_all();
        merge(firsthalf_output, firsthalf_size,
              secondhalf_output, secondhalf_size,
              output);
        print_all();

        free(firsthalf_output);
        free(secondhalf_output);
    }
}



void mergesort(int input[], int output[], size_t num_input_elements) {
    _input = input;
    _output = output;
    _num_input_elements = num_input_elements;
    __mergesort(input, output, num_input_elements);

}
