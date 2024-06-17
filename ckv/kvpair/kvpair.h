#ifndef KVPAIR_H
#define KVPAIR_H

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct KVPair {
    char * key;
    char * value;
} KVPair;

KVPair * kvpair_new(char * key, char * value);
void kvpair_free(KVPair * pair);
bool kvpair_eq(KVPair * pair, char * key);

#endif // KVPAIR_H