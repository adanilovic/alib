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

TEST(FirstTestGroup, init_add_to_end) {

    List *alist = list_init();
    CHECK(NULL != alist);
    CHECK(NULL == list_head(alist));
    CHECK(NULL == list_tail(alist));

    int data[2] = {1, 2};

    CHECK(0 == list_add_to_end(alist, &data[0]));
    CHECK(NULL == list_next(list_tail(alist)));
    CHECK(1 == list_size(alist));
    list_elem * helem = list_head(alist);
    CHECK(NULL != helem);
    CHECK(1 == *(int *)list_data(helem));
    list_elem * telem = list_tail(alist);
    CHECK(NULL != telem);
    CHECK(1 == *(int *)list_data(telem));
    CHECK(helem == telem);
    CHECK(NULL == list_next(helem));

    CHECK(-1 == list_add_to_end(NULL, &data[0]));
    CHECK(-1 == list_add_to_end(alist, NULL));

    CHECK(0 == list_add_to_end(alist, &data[1]));
    CHECK(NULL == list_next(list_tail(alist)));
    CHECK(2 == list_size(alist));
    helem = list_head(alist);
    CHECK(NULL != helem);
    CHECK(1 == *(int *)list_data(helem));
    list_elem * nelem = list_next(helem);
    CHECK(NULL != nelem);
    CHECK(2 == *(int *)list_data(nelem));
    CHECK(NULL == list_next(nelem));

    CHECK(0 == list_destroy(&alist));
    CHECK(NULL == alist);
}

TEST(FirstTestGroup, init_add_to_front) {

    List *alist = list_init();
    CHECK(NULL != alist);
    CHECK(NULL == list_head(alist));
    CHECK(NULL == list_tail(alist));

    int data[2] = {1, 2};

    CHECK(0 == list_add_to_front(alist, &data[0]));
    CHECK(NULL == list_next(list_tail(alist)));
    CHECK(1 == list_size(alist));
    list_elem * helem = list_head(alist);
    CHECK(NULL != helem);
    CHECK(1 == *(int *)list_data(helem));
    list_elem * telem = list_tail(alist);
    CHECK(NULL != telem);
    CHECK(1 == *(int *)list_data(telem));
    CHECK(helem == telem);
    CHECK(NULL == list_next(helem));

    CHECK(-1 == list_add_to_front(NULL, &data[0]));
    CHECK(-1 == list_add_to_front(alist, NULL));

    CHECK(0 == list_add_to_front(alist, &data[1]));
    CHECK(NULL == list_next(list_tail(alist)));
    CHECK(2 == list_size(alist));
    helem = list_head(alist);
    CHECK(NULL != helem);
    CHECK(2 == *(int *)list_data(helem));
    list_elem * nelem = list_next(helem);
    CHECK(NULL != nelem);
    CHECK(1 == *(int *)list_data(nelem));
    CHECK(NULL == list_next(nelem));

    CHECK(0 == list_destroy(&alist));
    CHECK(NULL == alist);
}

TEST(FirstTestGroup, init_add_to_front_end) {

    List *alist = list_init();
    CHECK(NULL != alist);
    CHECK(NULL == list_head(alist));
    CHECK(NULL == list_tail(alist));

    int data[3] = {1, 2, 3};

    CHECK(0 == list_add_to_front(alist, &data[0]));
    CHECK(NULL == list_next(list_tail(alist)));
    CHECK(1 == list_size(alist));
    list_elem * helem = list_head(alist);
    CHECK(NULL != helem);
    CHECK(1 == *(int *)list_data(helem));
    list_elem * telem = list_tail(alist);
    CHECK(NULL != telem);
    CHECK(1 == *(int *)list_data(telem));
    CHECK(helem == telem);
    CHECK(NULL == list_next(helem));

    CHECK(0 == list_add_to_end(alist, &data[1]));
    CHECK(NULL == list_next(list_tail(alist)));
    CHECK(2 == list_size(alist));
    helem = list_head(alist);
    CHECK(NULL != helem);
    CHECK(1 == *(int *)list_data(helem));
    list_elem * nelem = list_next(helem);
    CHECK(NULL != nelem);
    CHECK(2 == *(int *)list_data(nelem));
    CHECK(NULL == list_next(nelem));

    CHECK(0 == list_add_to_front(alist, &data[2]));
    CHECK(NULL == list_next(list_tail(alist)));
    CHECK(3 == list_size(alist));
    helem = list_head(alist);
    CHECK(NULL != helem);
    CHECK(3 == *(int *)list_data(helem));
    nelem = list_next(helem);
    CHECK(NULL != nelem);
    CHECK(1 == *(int *)list_data(nelem));
    nelem = list_next(nelem);
    CHECK(NULL != nelem);
    CHECK(2 == *(int *)list_data(nelem));
    CHECK(NULL == list_next(nelem));

    CHECK(0 == list_destroy(&alist));
    CHECK(NULL == alist);
}

TEST(FirstTestGroup, init_iterate_end) {

    List *alist = list_init();
    CHECK(NULL != alist);
    CHECK(NULL == list_head(alist));
    CHECK(NULL == list_tail(alist));

    int data[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    for (size_t i = 0; i < sizeof(data)/sizeof(data[0]); ++i) {
        CHECK(0 == list_add_to_end(alist, &data[i]));
    }

    list_elem * elem = list_head(alist);
    for (size_t i = 0; i < sizeof(data)/sizeof(data[0]); ++i) {
        CHECK(data[i] == *(int *)list_data(elem));
        elem = list_next(elem);
    }
    CHECK(NULL == elem);
    CHECK(0 == list_destroy(&alist));
    CHECK(NULL == alist);
}

TEST(FirstTestGroup, init_iterate_front) {

    List *alist = list_init();
    CHECK(NULL != alist);
    CHECK(NULL == list_head(alist));
    CHECK(NULL == list_tail(alist));

    int data[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    for (size_t i = 0; i < sizeof(data)/sizeof(data[0]); ++i) {
        CHECK(0 == list_add_to_front(alist, &data[i]));
    }

    list_elem * elem = list_head(alist);
    for (size_t i = 0; i < sizeof(data)/sizeof(data[0]); ++i) {
        CHECK(data[sizeof(data)/sizeof(data[0]) - 1 - i] == *(int *)list_data(elem));
        elem = list_next(elem);
    }
    CHECK(NULL == elem);
    CHECK(0 == list_destroy(&alist));
    CHECK(NULL == alist);
}

TEST(FirstTestGroup, init_iterate_end_remove_from_end) {

    List *alist = list_init();
    CHECK(NULL != alist);
    CHECK(NULL == list_head(alist));
    CHECK(NULL == list_tail(alist));

    CHECK(NULL == list_remove_from_end(alist));

    int data[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    for (size_t i = 0; i < sizeof(data)/sizeof(data[0]); ++i) {
        CHECK(i == list_size(alist));
        CHECK(0 == list_add_to_end(alist, &data[i]));
    }

    CHECK(sizeof(data)/sizeof(data[0]) == list_size(alist));

    //list_print_each(alist);

    int i = sizeof(data)/sizeof(data[0]);
    int *num = (int *)list_remove_from_end(alist);

    while (num) {
        CHECK(*num == data[i-1]);
        num = (int *)list_remove_from_end(alist);
        --i;
    }

    CHECK(!num);
    CHECK(0 == list_size(alist));
    CHECK(0 == list_destroy(&alist));
    CHECK(NULL == alist);
}

TEST(FirstTestGroup, init_iterate_end_remove_from_front) {

    List *alist = list_init();
    CHECK(NULL != alist);
    CHECK(NULL == list_head(alist));
    CHECK(NULL == list_tail(alist));

    CHECK(NULL == list_remove_from_front(alist));

    int data[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    for (size_t i = 0; i < sizeof(data)/sizeof(data[0]); ++i) {
        CHECK(i == list_size(alist));
        CHECK(0 == list_add_to_end(alist, &data[i]));
    }

    CHECK(sizeof(data)/sizeof(data[0]) == list_size(alist));

    //list_print_each(alist);

    int i = 0;
    int *num = (int *)list_remove_from_front(alist);

    while (num) {
        CHECK(*num == data[i]);
        num = (int *)list_remove_from_front(alist);
        ++i;
    }

    CHECK(i == sizeof(data)/sizeof(data[0]));
    CHECK(!num);

    CHECK(NULL == list_remove_from_front(alist));

    CHECK(0 == list_size(alist));
    CHECK(0 == list_destroy(&alist));
    CHECK(NULL == alist);
}


int main(int ac, char** av) {
    return CommandLineTestRunner::RunAllTests(ac, av);
}
