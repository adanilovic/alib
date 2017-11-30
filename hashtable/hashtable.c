#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "hashtable.h"

#define table_size 20
static char table[table_size][table_size] = {0};

#if 0
static void print_table() {
    for(int i = 0; i < table_size; ++i) {
        for(int j = 0; j < table_size; ++j) {
            printf("%c ", table[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
#endif // #if 0

static int hash(char c) {
    return (int)c % table_size;
}

void char_hashtable_init() {
    memset(table, 0, sizeof(table));
}

/*! \brief Insert an char into the hashtable
 *
 *
 *
 */
int char_hashtable_insert(char c) {

    int h = hash(c);
    
    for(int i = 0; i < table_size; ++i) {

        #if 0
        print_table();
        #endif // #if 0

        if(table[h][i] == c) {
            //char already present
            return 1;
        }
        else {
            if(table[h][i] == 0) {
                table[h][i] = c;
                //successful insert
                return 0;
            }
        }
    }

    //unable to insert into hash table, allocate more memory
    return -1;
}

bool char_hashtable_get(char c) {

    int h = hash(c);

    for(int i = 0; i < table_size; ++i) {

        if(table[h][i] == c) {
            //char already present
            return 1;
        }
    }

    return 0;
}
