#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "amath.h"

#include "CppUTest/TestHarness.h"
#include "CppUTest/CommandLineTestRunner.h"

TEST_GROUP(FirstTestGroup) {

    void setup() {

    }

    void teardown() {

    }
};

int main(int ac, char** av) {
    return CommandLineTestRunner::RunAllTests(ac, av);
}
