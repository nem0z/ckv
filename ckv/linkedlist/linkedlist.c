#include "linkedlist.h"

LinkedList * list_new() {
    LinkedList * list = malloc(sizeof(LinkedList));
    list->head = NULL;

    return list;
}

void node_free(Node * node) {
    kvpair_free(node->pair);
    free(node);
}

void list_push(LinkedList * list, KVPair * pair) {
    if(list == NULL) return;

    Node * node = malloc(sizeof(Node));
    node->next = list->head;
    node->pair = pair;

    list->head = node;
}

KVPair * list_find(LinkedList * list, char * key) {
    if(list == NULL || list->head == NULL) return NULL;
    if(key == NULL) return NULL;

    for(Node * n = list->head; n != NULL; n = n->next) {
        if(kvpair_eq(n->pair, key)) {
            return n->pair;
        }
    }
    
    return NULL;
}

bool list_remove(LinkedList * list, char * key) {
    if(list == NULL || list->head == NULL) return false;
    if(key == NULL) return false;

    Node * prev = NULL;
    for(Node * n = list->head; n != NULL; n = n->next) {
        if(kvpair_eq(n->pair, key)) {
            prev->next = n->next;
            node_free(n);
            return true;
        }
            
        prev = n;
    }
    
    return false;
}

void list_display(LinkedList * list) {
    if(list == NULL) {
        printf("List is NULL\n");
        return;
    }

    if(list->head == NULL) {
        printf("List is empty\n");
        return;
    }

    Node * current = list->head;
    for(size_t i = 0; current != NULL; current = current->next, ++i) {
        if(current->pair == NULL) {
            printf("List(%zu) : NULL", i);
            continue;
        }

        printf("List(%zu) : %s => %s\n", i, current->pair->key, current->pair->value);
    }
}