#include <stdio.h>
#include "stack.h"

#include "CppUTest/TestHarness.h"
#include "CppUTest/CommandLineTestRunner.h"

TEST_GROUP(FirstTestGroup) {

    void setup() {

    }

    void teardown() {

    }
};

TEST(FirstTestGroup, stack_test) {
    Stack my_stack;
    CHECK(stack_init(&my_stack) == 0);
}
 
int main(int ac, char** av) {
    return CommandLineTestRunner::RunAllTests(ac, av);
}
