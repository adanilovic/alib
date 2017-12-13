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

    int data[] = {0};

    CHECK(0 == stack_push(astack, &data[0]));
    CHECK(data[0] == *(int *)stack_peek(astack));
    CHECK(1 == stack_size(astack));
    CHECK(data[0] == *(int *)stack_pop(astack));

    CHECK(0 == stack_destroy(astack));
}
 
int main(int ac, char** av) {
    return CommandLineTestRunner::RunAllTests(ac, av);
}
