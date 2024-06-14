#include "hashmap.h"

HashMap * new_hashmap(size_t size) {
    void * bucket = malloc(size * sizeof(void *));

    HashMap * hashmap = malloc(sizeof(hashmap));
    hashmap->bucket = bucket;
    hashmap->size = size;

    return hashmap;
}

KVPair * new_kvpair(char * key, char * value) {
    KVPair * kvp = malloc(sizeof(KVPair));
    kvp->key = key;
    kvp->value = value;

    return kvp;
}

size_t compute_index(char * key, size_t bucket_size) {
    size_t cpt = 0;
    for(size_t i = 0; key[i] != '\0'; ++i) {
        cpt += key[i];
    }

    return cpt % bucket_size;
}

void set(HashMap * hashmap, char * key, char * value) {
    size_t index = compute_index(key, hashmap->size);
    KVPair * kvp = new_kvpair(key, value);
    hashmap->bucket[index] = kvp;
}

KVPair * get(HashMap * hashmap, char * key) {
    size_t index = compute_index(key, hashmap->size);
    return hashmap->bucket[index];
}