#include "hashmap.h"

HashMap * map_new(size_t size) {
    LinkedList ** bucket = malloc(size * sizeof(LinkedList *));
    for(size_t i = 0; i < size; ++i) {
        bucket[i] = list_new();
    }

    HashMap * hashmap = malloc(sizeof(hashmap));
    hashmap->bucket = bucket;
    hashmap->size = size;

    return hashmap;
}

size_t map_compute_index(char * key, size_t bucket_size) {
    size_t cpt = 0;
    for(size_t i = 0; key[i] != '\0'; ++i) {
        cpt += key[i];
    }

    return cpt % bucket_size;
}

void map_set(HashMap * hashmap, char * key, char * value) {
    size_t index = map_compute_index(key, hashmap->size);
    KVPair * pair = kvpair_new(key, value);

    list_push(hashmap->bucket[index], pair);
}

char * map_get(HashMap * hashmap, char * key) {
    size_t index = map_compute_index(key, hashmap->size);
    LinkedList * list = hashmap->bucket[index];

    KVPair * pair = list_find(list, key);
    return pair->value;
}

bool map_delete(HashMap * hashmap, char * key) {
    size_t index = map_compute_index(key, hashmap->size);
    LinkedList * list = hashmap->bucket[index];

    return list_remove(list, key);
}

void map_display(HashMap * map) {
    if(map == NULL) {
        printf("Map is NULL\n");
        return;
    }

    if(map->bucket == NULL) {
        printf("Bucket is NULL\n");
        return;
    }

    for(size_t i = 0; i < map->size; ++i) {
        printf("Map (%zu)\n", i);
        list_display(map->bucket[i]);
        printf("\n");
    }
}