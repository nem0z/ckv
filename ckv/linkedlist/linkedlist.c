#include "linkedlist.h"

LinkedList * list_new() {
    LinkedList * list = malloc(sizeof(LinkedList));
    list->head = NULL;

    return list;
}

void list_free(LinkedList * list) {
    if(list == NULL) return;

    Node * prev = list->head;
    if(prev == NULL) {
        free(list);
        return;
    }

    for(Node * n = prev->next; n != NULL; n = n->next) {
        node_free(prev);
        prev = n;
    }

    node_free(prev);
    free(list);
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

bool list_fwrite(LinkedList * list, FILE * stream) {   
    if(list == NULL || stream == NULL) return false;

    for(Node * n = list->head; n != NULL; n = n->next) {
        if(!kvpair_fwrite(n->pair, stream)) return false;
    }

    char * end = malloc(sizeof(char));
    end[0] = LIST_ENDLINE;

    if(fwrite(end, 1, 1, stream) != 1) {
        fprintf(stderr, "Error writing list endline ! %d\n", errno);
        free(end);
        return false;
    }

    free(end);
    return true;
}

LinkedList * list_fread(FILE * stream) {
    if(stream == NULL) return NULL;

    char * line = NULL;
    size_t len = 0;
    ssize_t read = getline(&line, &len, stream);
    if(read == -1) {
        free(line);
        return NULL;
    }

    LinkedList * list = list_new();

    char * key;
    char * value;

    for(size_t i = 0; i < (size_t)(read-1); ++i) {
        key = line + i;

        while(line[++i] != '\0');
        value = line + i + 1;
    
        while(line[++i] != '\0');

        KVPair * pair = kvpair_new(key, value);
        list_push(list, pair);
    }

    free(line);
    return list;
}