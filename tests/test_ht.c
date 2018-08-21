#include <stdio.h>
#include <stdlib.h>

#include "greatest.h"

#include "../src/data_structures/hashtable.c"


TEST test_hashtable(void) {
    hashtable *table = ht_new(5);

    char *values[] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j"};
    for (int i = 0; i < 5; i++) {
        ht_insert(table, i, values[i]);
    }

    ht_remove(table, 2);
    ht_resize(&table, 10);

    for (int i = 5; i < 10; i++) {
        ht_insert(table, i, values[i]);
    }

    ASSERT_EQ_FMT(ht_search(table, 0), "a", "%s");
    ASSERT_EQ_FMT(ht_search(table, 1), "b", "%s");
    ASSERT_EQ_FMT(ht_search(table, 3), "d", "%s");
    ASSERT_EQ_FMT(ht_search(table, 4), "e", "%s");
    ASSERT_EQ_FMT(ht_search(table, 5), "f", "%s");
    ASSERT_EQ_FMT(ht_search(table, 6), "g", "%s");
    ASSERT_EQ_FMT(ht_search(table, 7), "h", "%s");
    ASSERT_EQ_FMT(ht_search(table, 8), "i", "%s");
    ASSERT_EQ_FMT(ht_search(table, 9), "j", "%s");
    ASSERT_EQ(ht_search(table, 2), NULL);

    ht_print(table);
    ht_destroy(&table);
    PASS();
}


SUITE(hash_table) {
    RUN_TEST(test_hashtable);
}
