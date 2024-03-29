#pragma once

#include <stdbool.h>
#include <stddef.h>

// An item in the hash table
// Multiple items can have the same hash value
// so each they are chained together in a linked list within the bucket
typedef struct item item_t;

// A hash table of items
typedef struct ht ht_t;

// Initialise a new hash table with n buckets
ht_t *htab_create(ht_t *h, size_t n);

// Destroy and free mamory allocated for hash table
void htab_destroy(ht_t *h);

// The Bernstein hash function
size_t djb_hash(char *s);

// Calculathe offset for the bucket for any key in the hash table
size_t htab_index(ht_t *h, char *key);

// Find the pointer to the head of list for key in hash table
item_t *htab_bucket(ht_t *h, char *key);

// Find the item for key in hash table
// return the item or NULL if the item does not exist
item_t *htab_find(ht_t *h, char *key);

// Add an item to the hash table
// OR update value if exists
// allocate memory for the item and add it to the hash table
bool htab_set(ht_t *h, char *key, void *value, size_t size);

// Remove an item from the hash table
// free the memory allocated for the item
bool htab_remove(ht_t *h, char *key);

// Increase the size of the hash table to 2n+1
bool htab_resize(ht_t *h);

// get the value of a particular key
void *htab_get(ht_t *h, char *key);

// get the value of an item
void *item_get(item_t *item);

// hashtable metadata
// total capacity
size_t htab_capacity(ht_t *h);

// number of items
size_t htab_size(ht_t *h);
