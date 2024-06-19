#include "hashmap.h"

HashMap * map_new(size_t size) {
    LinkedList ** bucket = malloc(size * sizeof(LinkedList *));
    for(size_t i = 0; i < size; ++i) {
        bucket[i] = list_new();
    }

    HashMap * hashmap = malloc(sizeof(HashMap));
    hashmap->bucket = bucket;
    hashmap->size = size;

    return hashmap;
}

void map_free(HashMap * hashmap) {
    if(hashmap == NULL) return;
    if(hashmap->bucket == NULL) {
        free(hashmap);
        return;
    }

    for(size_t i = 0; i < hashmap->size; ++i) {
        list_free(hashmap->bucket[i]);
    }

    free(hashmap->bucket);
    free(hashmap);
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
    return pair == NULL ? NULL : kvpair_copy_value(pair);
}

bool map_delete(HashMap * hashmap, char * key) {
    size_t index = map_compute_index(key, hashmap->size);
    LinkedList * list = hashmap->bucket[index];

    return list_remove(list, key);
}

void map_display(HashMap * hashmap) {
    if(hashmap == NULL) {
        printf("Map is NULL\n");
        return;
    }

    if(hashmap->bucket == NULL) {
        printf("Bucket is NULL\n");
        return;
    }

    for(size_t i = 0; i < hashmap->size; ++i) {
        printf("Map (%zu)\n", i);
        list_display(hashmap->bucket[i]);
        printf("\n");
    }
}

bool map_fwrite(HashMap * map, FILE * stream) {
    if(map == NULL || map->bucket == NULL || stream == NULL) return false;

    for(size_t i = 0; i < map->size; ++i) {
        if(!list_fwrite(map->bucket[i], stream)) return false;
    }

    return true;
}

HashMap * map_fread(FILE * stream) {
    size_t bucket_size = 1;
    size_t i = 0;
    LinkedList ** list_bucket = malloc(bucket_size * sizeof(LinkedList *));

    for(;;) {
        LinkedList * list = list_fread(stream);
        if(list == NULL) break;

        if(i >= bucket_size) {
            bucket_size *= 2;
            list_bucket = realloc(list_bucket, bucket_size * sizeof(LinkedList *));
        }

        list_bucket[i] = list;
        ++i;
    }

    HashMap * map = map_new(i);
    for(size_t j = 0; j < i; ++j) {
        free(map->bucket[j]);
        map->bucket[j] = list_bucket[j];
    }

    free(list_bucket);
    return map;
}