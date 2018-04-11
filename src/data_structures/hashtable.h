#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <stdlib.h>
#include <stdio.h>


/**
* member - the key and value pair to store inside the hashtable array
*
* @key: an unsigned integer to store as the key to the hashtable element
* @value: a string to store inside the hashtable element
*
* By default, the member's key is of type size_t and member's value is of type char *
* The types of key and value can be changed to fit the user's needs, however the
* types will need to be changed in other functions as well.
*/
typedef struct member {
    size_t key;
    char *value;
} member;


/**
* hashtable - the hashtable in which to store keys and values as members
*
* @count: the number of members stored within the hashtable
* @size: the maximum number of members allowed in the hashtable
* @members: the array of members that contain the key and value
*/
typedef struct hashtable {
    size_t count;
    size_t size;
    member members[];
} hashtable;

hashtable *ht_new(size_t capacity);

void ht_resize(hashtable **table);

void ht_insert(hashtable *table, size_t key, char *value);

void ht_remove(hashtable *table, size_t key);

char *ht_search(hashtable *table, size_t key);

void ht_print(hashtable *table);

void ht_destroy(hashtable **table);


#endif
