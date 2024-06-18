#include "kvpair.h"

KVPair * kvpair_new(char * key, char * value) {
    KVPair * pair = malloc(sizeof(KVPair));
    pair->key = safecpy(key);
    pair->value = safecpy(value);

    return pair;
}

void kvpair_free(KVPair * pair) {
    if(pair == NULL) return;
    free(pair->key);
    free(pair->value);
    free(pair);
}

bool kvpair_eq(KVPair * pair, char * key) {
    if(pair == NULL) return false;
    return safeeq(pair->key, key);
}

char * kvpair_copy_value(KVPair * pair) {
    if(pair == NULL) return NULL;
    return safecpy(pair->value);
}