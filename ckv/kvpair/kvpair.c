#include "kvpair.h"

KVPair * kvpair_new(char * key, char * value) {
    KVPair * pair = malloc(sizeof(KVPair));
    pair->key = key;
    pair->value = value;

    return pair;
}

void kvpair_free(KVPair * pair) {
    free(pair);
}

bool kvpair_eq(KVPair * pair, char * key) {
    if(pair == NULL || key == NULL) return false;
    return strcmp(pair->key, key) == 0;
}