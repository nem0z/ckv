#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "../kvpair/kvpair.h"

typedef struct Node {
    struct Node * next;
    KVPair * pair;
} Node;

typedef struct LinkedList {
    Node * head;
} LinkedList;

LinkedList * list_new();
void node_free(Node * node);

void list_push(LinkedList * list, KVPair * pair);
KVPair * list_find(LinkedList * list, char * key);
bool list_remove(LinkedList * list, char * key);
void list_display(LinkedList * list);

#endif // LINKEDLIST_H