#include <stdio.h>
#include "alist.h"

#include "CppUTest/TestHarness.h"
#include "CppUTest/CommandLineTestRunner.h"

TEST_GROUP(FirstTestGroup) {

    void setup() {

    }

    void teardown() {

    }
};

TEST(FirstTestGroup, init_add) {
    List *alist = list_init();
    CHECK(NULL != alist);
    int data[2] = {1, 2};
    CHECK(0 == list_add_next(alist, &data[0]));
    CHECK(0 == list_add_next(alist, &data[1]));
    CHECK(0 == list_destroy(alist));
}

int main(int ac, char** av) {
    return CommandLineTestRunner::RunAllTests(ac, av);
}
