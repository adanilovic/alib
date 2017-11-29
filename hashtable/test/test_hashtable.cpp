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
        char char_in_string;
        char char_not_in_string;
    } test_string;
  
    const test_string strings[] = {
        {"abcda",  5, 1, 'a', 'z'},
        {"abcdab", 6, 2, 'a', 'z'},
        {"abcdef", 6, 0, 'a', 'z'},
        {"abcdefghijklmnopqrstuvwxyz", 26, 0, 'a', 'Z'},
        {"abcdefghijklmnopqrstuvwxyzz", 27, 1, 'a', 'Z'},
        {"aaaaaaaaaaaaaaaaaaaa",  20, 19, 'a', 'z'},
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
        CHECK_EQUAL(true, hashtable_get(strings[i].char_in_string));
        CHECK_EQUAL(false, hashtable_get(strings[i].char_not_in_string));
    }

}

/*TEST(FirstTestGroup, unable_to_insert) {

    typedef struct {
        const char *string;
        int string_len;
        int num_dup;
        char char_in_string;
        char char_not_in_string;
    } test_string;

    const test_string strings[] = {
        {"aaaaaaaaaaaaaaaaaaaaa",  21, 19, 'a', 'z'},
    };

    for(unsigned int i = 0; i < (sizeof(strings)/sizeof(strings[0])); ++i) {

        int dup_count = 0;

        hashtable_init();

        int j = 0;
        for(j = 0; j < strings[i].string_len - 1; ++j) {
            if(hashtable_insert(strings[i].string[j])) {
                dup_count++;
            }
        }

        CHECK_EQUAL(strings[i].num_dup, dup_count);
        CHECK_EQUAL(true, hashtable_get(strings[i].char_in_string));
        CHECK_EQUAL(false, hashtable_get(strings[i].char_not_in_string));

        j++;
        CHECK(-1 == hashtable_insert(strings[i].string[j]));
    }

}*/

int main(int ac, char** av) {
    return CommandLineTestRunner::RunAllTests(ac, av);
}
