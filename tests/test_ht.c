#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

#include "greatest.h"

#include "../src/data_structures/hashtable.c"


TEST test_hashtable(void) {
    hashtable *table = ht_new(5);

    char *values[] = {"abc", "cba", "dkhga", "aahfa", "dskjha", "ashf", "gda", "ah", "ha", "haa"};

    for (size_t i = 0; i < 5; i++) {
        ht_insert(table, values[i], (intptr_t*) i);
    }

    ht_remove(table, "dkhga");
    ht_resize(&table, 10);

    for (size_t j = 5; j < 10; j++) {
        ht_insert(table, values[j], (intptr_t*) j);
    }

    ASSERT_EQ((intptr_t) ht_search(table, "abc"), 0);
    ASSERT_EQ((intptr_t) ht_search(table, "haa"), 9);

    ht_destroy(&table);
    PASS();
}


SUITE(hash_table) {
    RUN_TEST(test_hashtable);
}
