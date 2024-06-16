#include "linkedlist.h"

LinkedList * list_new() {
    LinkedList * list = malloc(sizeof(LinkedList));
    list->head = NULL;

    return list;
}

void list_push(LinkedList * list, void * item) {
    if(list == NULL) return;

    Node * node = malloc(sizeof(Node));
    node->next = list->head;
    node->data = item;

    list->head = node;
}

void * list_find(LinkedList * list, bool (*func)(void *)) {
    if(list == NULL || list->head == NULL) return NULL;
    if(func == NULL) return NULL;

    Node * current = list->head;
    for(; current != NULL; current = current->next) {
        if(func(current->data)) return current->data;
    }

    return NULL;
}

void * list_remove(LinkedList * list, bool (*func)(void *)) {
    if(list == NULL || list->head == NULL) return NULL;
    if(func == NULL) return NULL;

    Node * current = list->head;
    Node * prev = NULL;
    for(; current != NULL; current = current->next) {
        if(func(current->data)) {
            prev->next = current->next;
            void * data = current->data;
            free(current);
            return data;
        }

        prev = current;
    }

    return NULL;
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
    for(size_t i = 0; current != NULL; current = current->next) {
        printf("List element (%zu) : %p\n", ++i, current->data);
    }
}