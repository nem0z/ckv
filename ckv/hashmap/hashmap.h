#ifndef HASHMAP_H
#define HASHMAP_H

#include <stdlib.h>
#include <stdio.h>

#include "../linkedlist/linkedlist.h"

typedef struct HashMap {
    LinkedList ** bucket;
    size_t size;
} HashMap;

HashMap * map_new(size_t size);
size_t map_compute_index(char * key, size_t bucket_size);

void map_set(HashMap * hashmap, char * key, char * value);
char * map_get(HashMap * hashmap, char * key);
bool map_delete(HashMap * hashmap, char * key);

void map_display(HashMap * map);

#endif // HASHMAP_H