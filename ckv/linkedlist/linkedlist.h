#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct Node {
    struct Node * next;
    void * data;
} Node;

typedef struct LinkedList {
    Node * head;
} LinkedList;

LinkedList * list_new();
void list_push(LinkedList * list, void * item);
void * list_find(LinkedList * list, bool (*func)(void *));
void * list_remove(LinkedList * list, bool (*func)(void *));
void list_display(LinkedList * list);

#endif // LINKEDLIST_H