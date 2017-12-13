#include <stdio.h>
#include "astack.h"

#include "CppUTest/TestHarness.h"
#include "CppUTest/CommandLineTestRunner.h"

TEST_GROUP(FirstTestGroup) {

    void setup() {

    }

    void teardown() {

    }
};

TEST(FirstTestGroup, stack_init_test) {
    Stack *astack = stack_init();
    CHECK(NULL != astack);
    CHECK(0 == stack_destroy(astack));
}

TEST(FirstTestGroup, stack_push_pop_test) {
    Stack *astack = stack_init();
    CHECK(NULL != astack);

    int data[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    CHECK(NULL == stack_pop(astack));

    for (size_t i = 0; i < sizeof(data)/sizeof(data[0]); ++i) {
        CHECK(i == stack_size(astack));
        CHECK(0 == stack_push(astack, &data[i]));
        CHECK((i+1) == stack_size(astack));
        CHECK(data[i] == *(int *)stack_peek(astack));
    }

    for (size_t i = 0; i < sizeof(data)/sizeof(data[0]); ++i) {
        CHECK((sizeof(data)/sizeof(data[0]) - i) == stack_size(astack));
        CHECK(data[sizeof(data)/sizeof(data[0]) - 1 - i] == *(int *)stack_pop(astack));
        CHECK((sizeof(data)/sizeof(data[0]) - i - 1) == stack_size(astack));
    }

    CHECK(0 == stack_size(astack));
    CHECK(0 == stack_destroy(astack));
}
 
int main(int ac, char** av) {
    return CommandLineTestRunner::RunAllTests(ac, av);
}
