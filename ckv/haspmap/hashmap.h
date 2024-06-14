#ifndef HASHMAP_H
#define HASHMAP_H

#include <stdlib.h>

typedef struct KVPair {
    char * key;
    char * value;
} KVPair;

typedef struct HashMap {
    KVPair ** bucket;
    size_t size;
} HashMap;

HashMap * new_hashmap(size_t size);
KVPair * new_kvpair(char * key, char * value);

size_t compute_hash(char * key, size_t bucket_size);

void set(HashMap * hashmap, char * key, char * value);
KVPair * get(HashMap * hashmap, char * key);

#endif // HASHMAP_H