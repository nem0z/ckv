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

KVPair * kvpair_new(char * key, char * value) {
    KVPair * kvp = malloc(sizeof(KVPair));
    kvp->key = key;
    kvp->value = value;

    return kvp;
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
    KVPair * kvp = kvpair_new(key, value);
    list_push(hashmap->bucket[index], kvp);
}

char * map_get(HashMap * hashmap, char * key) {
    size_t index = map_compute_index(key, hashmap->size);
    LinkedList * list = hashmap->bucket[index];

    if(list == NULL || list->head == NULL) return NULL;

    for(Node * n = list->head; n != NULL; n = n->next) {
        if(n->data == NULL) continue;
        KVPair * kvp = (KVPair *)n->data;
        if(strcmp(kvp->key, key) == 0) return kvp->value; // strncomp
    }

    return NULL;
}

// void map_delete(HashMap * hashmap, char * key) {
//     size_t index = map_compute_hash(key, hashmap->size);
//     LinkedList * list = hashmap->bucket[index];

//     if(list == NULL || list->head == NULL) return;

//     Node * prev = NULL;
//     for(Node * n = list->head; n != NULL; n = n->next) {
//         if(n->data == NULL) continue;
//         KVPair * kvp = (KVPair *)n->data;
//         if(strcmp(kvp->key, key) == 0) { // strncomp
//             prev->next = n->next;
//             free(kvp);
//             free(n);
//             return;
//         }

//         prev = n;
//     }

//     return;
// }