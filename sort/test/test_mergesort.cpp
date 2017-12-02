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

    mergesort_int(input_unsorted, output, size_of_array);

    for(size_t i = 0; i < size_of_array; ++i) {
        CHECK_EQUAL(input_sorted[i], output[i]);
    }
}

TEST(FirstTestGroup, int_3array_test) {

    const size_t size_of_array = 3;

    int input_unsorted[size_of_array] = {1, 5, 4};
    int output[size_of_array] = {0};
    int input_sorted[size_of_array]   = {1, 4, 5};

    mergesort_int(input_unsorted, output, size_of_array);

    for(size_t i = 0; i < size_of_array; ++i) {
        CHECK_EQUAL(input_sorted[i], output[i]);
    }
}

TEST(FirstTestGroup, large_int_array_test) {

    const size_t size_of_array = 40;

    int input_unsorted[size_of_array] = {
        1, 3, 5, 7,  9, 11, 13, 15, 17, 19,
        2, 4, 6, 8, 10, 12, 14, 16, 18, 20,
        21, 31, 51, 71,  91, 111, 131, 151, 171, 191,
        21, 41, 61, 81, 101, 121, 141, 161, 181, 201};

    int output[size_of_array] = {0};

    int input_sorted[size_of_array]   = {
        1,   2,  3,  4,  5,  6,  7,  8,  9, 10,
        11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
        21, 21, 31, 41,  51, 61, 71, 81, 91, 101,
        111, 121, 131, 141, 151, 161, 171, 181, 191, 201};

    mergesort_int(input_unsorted, output, size_of_array);

    for(size_t i = 0; i < size_of_array; ++i) {
        CHECK_EQUAL(input_sorted[i], output[i]);
    }
}

int compare_int(const void *a, const void *b) {

    const int *_a = (const int *)a;
    const int *_b = (const int *)b;

    if(*_a == *_b) {
        return 0;
    }
    else if(*_a > *_b) {
        return 1;
    }

    return -1;
}

TEST(FirstTestGroup, generic_int_test) {

    const int a = 0;
    const int b = 1;
    const int c = -1;

    CHECK(0  == compare_int(&a, &a));
    CHECK(1  == compare_int(&b, &a));
    CHECK(-1 == compare_int(&a, &b));

    CHECK(1  == compare_int(&a, &c));
    CHECK(-1 == compare_int(&c, &a));

    const size_t size_of_array = 40;

    int input_unsorted[size_of_array] = {
        1, 3, 5, 7,  9, 11, 13, 15, 17, 19,
        2, 4, 6, 8, 10, 12, 14, 16, 18, 20,
        21, 31, 51, 71,  91, 111, 131, 151, 171, 191,
        21, 41, 61, 81, 101, 121, 141, 161, 181, 201};

    int input_sorted[size_of_array]   = {
        1,   2,  3,  4,  5,  6,  7,  8,  9, 10,
        11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
        21, 21, 31, 41,  51, 61, 71, 81, 91, 101,
        111, 121, 131, 141, 151, 161, 171, 181, 191, 201};

    mergesort(input_unsorted, size_of_array, sizeof(int), compare_int);

    for(size_t i = 0; i < size_of_array; ++i) {
        CHECK_EQUAL(input_unsorted[i], input_sorted[i]);
    }
}

int main(int ac, char** av) {
    return CommandLineTestRunner::RunAllTests(ac, av);
}
