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

bool kvpair_fwrite(KVPair * pair, FILE * stream) {
    if(pair == NULL || stream == NULL) return false;

    if(fwrite(pair->key, strlen(pair->key)+1, 1, stream) != 1) {
        fprintf(stderr, "Error writting key ! %d", errno);
        return false;
    }

    if(fwrite(pair->value, strlen(pair->value)+1, 1, stream) != 1) {
        fprintf(stderr, "Error writting value ! %d\n", errno);
        return false;
    }

    return true;
}