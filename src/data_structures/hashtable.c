#include "hashtable.h"


/**
* ht_new - allocate memory for the hashtable and initialize the members
*
* @capacity: the maximum number of elements allowed to be stored in the hashtable
*
* Returns: the initialized hashtable
*/
hashtable *ht_new(size_t capacity) {
    hashtable *table = malloc(sizeof(hashtable) + capacity * sizeof(member));

    if (table == NULL) {
        fprintf(stderr, "%s\n", "Could not allocate memory for the hashtable.");
        exit(EXIT_FAILURE);
    }

    table->size = capacity;
    table->count = 0;

    for (size_t i = 0; i < capacity; i++) {
        table->members[i].key = 0;
        table->members[i].value = NULL;
    }

    return table;
}


/**
* ht_resize - double the size of the hashtable passed as an argument
*
* @table: a pointer to a pointer to the hashtable to resize
* @capacity: the size of the reallocated hashtable
*
* Returns: void
*/
void ht_resize(hashtable **table, size_t capacity) {
    size_t size = (*table)->size;
    size_t count = (*table)->count;

    hashtable *temp = realloc(*table, sizeof(hashtable) + sizeof(member) * capacity);

    if (temp == NULL) {
        fprintf(stderr, "%s\n", "Could not reallocate memory for the hashtable.");
        exit(EXIT_FAILURE);
    }

    temp->size = capacity;
    temp->count = count;

    for (size_t i = size; i < temp->size; i++) {
        temp->members[i].key = 0;
        temp->members[i].value = NULL;
    }

    *table = temp;
}


/**
 * hash - create a new hash value from the given key
 *
 * @key: the key to insert into the hash table
 *
 * Returns: a size_t of the hash value
 *
 * The hash algorithm used in this hash function is djb2:
 * http://www.cse.yorku.ca/~oz/hash.html
 */
size_t hash(void *key) {
    unsigned char *string = (unsigned char*) key;
    size_t hash_value = 5381;

    int c = 0;
    while ((c = *string++)) {
        hash_value = ((hash_value << 5) + hash_value) + c;
    }

    return hash_value;
}


/**
* ht_insert - insert a key and corresponding value into the hashtable
*
* @table: the hashtable in which to insert the key and value
* @key: the key to store inside the hashtable
* @value: the value to store alongside the given key
*
* Returns: void
*/
void ht_insert(hashtable *table, void *key, void *value) {
    size_t i = 0;
    size_t hash_value = hash(key);
    size_t index = ((hash_value % table->size) + i * i) % table->size;

    if (table->count < table->size) {
        if (table->members[index].value != NULL && table->members[index].key != key) {
            while (table->members[index].value != NULL) {
                i += 1;
                index = ((hash_value % table->size) + i * i) % table->size;
            }
        }

        table->members[index].key = key;
        table->members[index].value = value;
        table->count += 1;
    }
}


/**
* ht_remove - remove a key and corresponding value from the hashtable
*
* @table: the hashtable in which to remove the given key
* @key: the key to remove from the hashtable
*
* Returns: void
*/
void ht_remove(hashtable *table, void *key) {
    size_t i = 0;
    size_t hash_value = hash(key);
    size_t index = ((hash_value % table->size) + i * i) % table->size;

    if (table->members[index].key != key) {
        size_t count = 0;
        while (count < table->size && table->members[index].key != key) {
            i += 1;
            index = ((hash_value % table->size) + i * i) % table->size;
            count += 1;
        }
    }

    table->members[index].key = 0;
    table->members[index].value = NULL;
}


/**
* ht_search - find the value associated with the given key
*
* @table: the hashtable whose contents to search
* @key: the key whose value to find
*
* Returns: a string associated with the given key or NULL
*/
void *ht_search(hashtable *table, void *key) {
    size_t i = 0;
    size_t hash_value = hash(key);
    size_t index = ((hash_value % table->size) + i * i) % table->size;

    if (table->members[index].key != key) {
        size_t count = 0;
        while (count < table->size && table->members[index].key != key) {
            i += 1;
            index = ((hash_value % table->size) + i * i) % table->size;
            count += 1;
        }
    }

    if (table->members[index].key == key) {
        return table->members[index].value;
    } else {
        return NULL;
    }

}


/**
* destroy_table - free the memory allocated for the hashtable
*
* @table: the hashtable to whose memory to free
*
* Returns: void
*/
void ht_destroy(hashtable **table) {
    if (table != NULL && *table != NULL) {
        free(*table);
        *table = NULL;
    }
}
