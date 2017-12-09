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

TEST(FirstTestGroup, stack_test) {
    Stack *my_stack = stack_init();
    CHECK(NULL != my_stack);
    stack_destroy(my_stack);
}
 
int main(int ac, char** av) {
    return CommandLineTestRunner::RunAllTests(ac, av);
}
