#ifndef KVPAIR_H
#define KVPAIR_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <errno.h>

#include "../utils/utils.h"

typedef struct KVPair {
    char * key;
    char * value;
} KVPair;

KVPair * kvpair_new(char * key, char * value);
void kvpair_free(KVPair * pair);
bool kvpair_eq(KVPair * pair, char * key); 
char * kvpair_copy_value(KVPair * pair);
bool kvpair_fwrite(KVPair * pair, FILE * stream);

#endif // KVPAIR_H