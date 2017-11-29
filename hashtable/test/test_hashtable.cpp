#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "hashtable.h"

#include "CppUTest/TestHarness.h"
#include "CppUTest/CommandLineTestRunner.h"

TEST_GROUP(FirstTestGroup) {

    void setup() {

    }

    void teardown() {

    }
};

TEST(FirstTestGroup, count_duplicate_chars) {
  
    typedef struct {
        const char *string;
        int string_len;
        int num_dup;
    } test_string;
  
    const test_string strings[] = {
        {"abcda",  5, 1},
        {"abcdab", 6, 2},
        {"abcdef", 6, 0},
        {"abcdefghijklmnopqrstuvwxyz", 25, 0}
    };

    for(unsigned int i = 0; i < (sizeof(strings)/sizeof(strings[0])); ++i) {

        int dup_count = 0;

        hashtable_init();
        for(int j = 0; j < strings[i].string_len; ++j) {
            if(hashtable_insert(strings[i].string[j])) {
                dup_count++;
            }
        }
        
        CHECK_EQUAL(strings[i].num_dup, dup_count);
        CHECK_EQUAL(true, hashtable_get('a'));
        CHECK_EQUAL(false, hashtable_get('Z'));
    }

}

int main(int ac, char** av) {
    return CommandLineTestRunner::RunAllTests(ac, av);
}
