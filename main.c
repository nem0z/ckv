#include <stdlib.h>
#include <stdio.h>

#include "ckv/ckv.h"

int main(void) {

    HashMap * hashmap = map_new(2);

    map_set(hashmap, "Key1", "Value1");
    map_set(hashmap, "Key2", "Value2");
    map_set(hashmap, "Key3", "Value3");

    char * kvp1 = map_get(hashmap, "Key1");
    char * kvp2 = map_get(hashmap, "Key2");
    char * kvp3 = map_get(hashmap, "Key3");

    list_display(hashmap->bucket[0]);
    list_display(hashmap->bucket[1]);

    printf("%s - %s - %s\n", kvp1, kvp2, kvp3);

    LinkedList * list = list_new();
    list_push(list, "Value1");
    list_push(list, "Value2");
    list_push(list, "Value3");

    list_display(list);

    return EXIT_SUCCESS;
}

