#include <stdio.h>
#include "mergesort.h"

#include "CppUTest/TestHarness.h"
#include "CppUTest/CommandLineTestRunner.h"

TEST_GROUP(FirstTestGroup) {

    void setup() {

    }

    void teardown() {

    }
};

TEST(FirstTestGroup, int_6array_test) {

    const size_t size_of_array = 6;

    int input_unsorted[size_of_array] = {1, 5, 4, 6, 7, 2};
    int output[size_of_array] = {0};
    int input_sorted[size_of_array]   = {1, 2, 4, 5, 6, 7};

    mergesort(input_unsorted, output, size_of_array);

    for(size_t i = 0; i < size_of_array; ++i) {
        CHECK_EQUAL(input_sorted[i], output[i]);
    }
}

TEST(FirstTestGroup, int_3array_test) {

    const size_t size_of_array = 3;

    int input_unsorted[size_of_array] = {1, 5, 4};
    int output[size_of_array] = {0};
    int input_sorted[size_of_array]   = {1, 4, 5};

    mergesort(input_unsorted, output, size_of_array);

    for(size_t i = 0; i < size_of_array; ++i) {
        CHECK_EQUAL(input_sorted[i], output[i]);
    }
}

int main(int ac, char** av) {
    return CommandLineTestRunner::RunAllTests(ac, av);
}
