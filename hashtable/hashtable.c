#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "hashtable.h"

#define table_size 200
char table[table_size][table_size] = {0};

static int hash(char c) {
    return (int)c;
}

void hashtable_init() {
    memset(table, 0, sizeof(table));
}

/*! \brief Insert an char into the hashtable
 *
 *
 *
 */
int hashtable_insert(char c) {

    int h = hash(c);
    
    for(int i = 0; i < table_size; ++i) {

        if(table[h][i] == c) {
            //char already present
            return 1;
        }
        else {
            table[h][i] = c;
            return 0;
        }
    }

    return 0;
}

void hashtable_get() {

}
