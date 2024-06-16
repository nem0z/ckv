#ifndef HASHMAP_H
#define HASHMAP_H

#include <stdlib.h>
#include <string.h>

#include "../linkedlist/linkedlist.h"

typedef struct KVPair {
    char * key;
    char * value;
} KVPair;

typedef struct HashMap {
    LinkedList ** bucket;
    size_t size;
} HashMap;

HashMap * map_new(size_t size);
KVPair * kvpair_new(char * key, char * value);

size_t map_compute_hash(char * key, size_t bucket_size);

void map_set(HashMap * hashmap, char * key, char * value);
char * map_get(HashMap * hashmap, char * key);
void map_delete(HashMap * hashmap, char * key);

#endif // HASHMAP_H