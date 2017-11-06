#include <stdio.h>
#include <stdbool.h>

void my_assert() {
    printf("assert\n");
}

void merge(int inputA[], size_t lengthA, int inputB[], size_t lengthB, int output[]) {

    int i = 0;
    int j = 0;
    int k = 0;

    for(k = 0; (k < lengthA) && (k < lengthB); ++k) {
        if(inputA[i] < inputB[j]) {
            output[k] = inputA[i];
            i++;
        }
        else {
            output[k] = inputB[j];
            j++;
        }
    }

    if(i < lengthA) {
        output[k] = inputA[i];
    }
    else if(j < lengthB) {
        output[k] = inputB[j];
    }
    else {
        my_assert();
    }
}

void mergesort(int input[], int output[], size_t num_input_elements) {

    if(num_input_elements == 0) {
        return;
    }
    else if(num_input_elements == 1) {
        return;
    }
    else {
        bool is_odd = num_input_elements % 2;
        size_t firsthalf_size = is_odd ? ((num_input_elements / 2) + 1) : (num_input_elements / 2);
        size_t secondhalf_size = num_input_elements / 2;
        int * firsthalf = input;
        int * secondhalf = input + firsthalf_size;
        mergesort(firsthalf,  output,  firsthalf_size);
        mergesort(secondhalf, output + firsthalf_size, secondhalf_size);
        merge(firsthalf, firsthalf_size,
              secondhalf, secondhalf_size,
              output);
    }
}
