#include "hashtable.h"


/**
* initialize_hashtable - allocate memory for the hashtable and initialize the members
*
* @capacity: the maximum number of elements allowed to be stored in the hashtable
*
* Returns: the initialized hashtable
*/
hashtable *initialize_hashtable(size_t capacity) {
    hashtable *table = malloc(sizeof(hashtable) + capacity * sizeof(member));
    table->size = capacity;
    table->count = 0;

    for (size_t i = 0; i < capacity; i++) {
        table->members[i].key = 0;
        table->members[i].value = NULL;
    }

    return table;
}


/**
* insert_key - insert a key and corresponding value into the hashtable
*
* @table: the hashtable in which to insert the key and value
* @key: the key to store inside the hashtable
* @value: the value to store alongside the given key
*
* Returns: void
*/
void insert_key(hashtable *table, size_t key, char *value) {
    size_t i = 0;
    size_t hash = ((key % table->size) + i * i) % table->size;

    if (table->count < table->size) {
        if (table->members[hash].value != NULL && table->members[hash].key != key) {
            while (table->members[hash].value != NULL) {
                i += 1;
                hash = ((key % table->size) + i * i) % table->size;
            }
        }

        table->members[hash].key = key;
        table->members[hash].value = value;
        table->count += 1;
    }
}


/**
* remove_key - remove a key and corresponding value from the hashtable
*
* @table: the hashtable in which to remove the given key
* @key: the key to remove from the hashtable
*
* Returns: void
*/
void remove_key(hashtable *table, size_t key) {
    size_t i = 0;
    size_t hash = ((key % table->size) + i * i) % table->size;

    if (table->members[hash].key != key) {
        size_t count = 0;
        while (count < table->size && table->members[hash].key != key) {
            i += 1;
            hash = ((key % table->size) + i * i) % table->size;
            count += 1;
        }
    }

    table->members[hash].key = 0;
    table->members[hash].value = NULL;
}


/**
* find_value - find the value associated with the given key
*
* @table: the hashtable whose contents to search
* @key: the key whose value to find
*
* Returns: a string associated with the given key or "None"
*/
char *find_value(hashtable *table, size_t key) {
    size_t i = 0;
    size_t hash = ((key % table->size) + i * i) % table->size;

    if (table->members[hash].key != key) {
        size_t count = 0;
        while (count < table->size && table->members[hash].key != key) {
            i += 1;
            hash = ((key % table->size) + i * i) % table->size;
            count += 1;
        }
    }

    if (table->members[hash].key == key) {
        return table->members[hash].value;
    } else {
        return "None";
    }

}


/**
* print_table - print to stdout the contents of the hashtable
*
* @table: the hashtable whose contents to print to stdout
*
* Returns: void
*/
void print_table(hashtable *table) {
    for (size_t i = 0; i < table->size - 1; i++) {
        if (table->members[i].value != NULL) {
            printf("Key: %zu, Value: %s\n", table->members[i].key, table->members[i].value);
        }
    }
}


/**
* destroy_table - free the memory allocated for the hashtable
*
* @table: the hashtable to whose memory to free
*
* Returns: void
*/
void destroy_table(hashtable **table) {
    if (table != NULL && *table != NULL) {
        free(*table);
        *table = NULL;
    }
}
