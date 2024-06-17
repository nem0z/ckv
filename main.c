#include <stdlib.h>
#include <stdio.h>

#include "ckv/ckv.h"

int main(void) {

    HashMap * hashmap = map_new(2);

    map_set(hashmap, "Key1", "Value1");
    map_set(hashmap, "Key2", "Value2");
    map_set(hashmap, "Key3", "Value3");
    map_set(hashmap, "Key4", "Value4");
    map_set(hashmap, "Key5", "Value5");

    map_delete(hashmap, "Key2");

    char * kvp1 = map_get(hashmap, "Key1");
    char * kvp2 = map_get(hashmap, "Key2");
    char * kvp3 = map_get(hashmap, "Key3");

    printf("%s - %s - %s\n", kvp1, kvp2, kvp3);

    map_display(hashmap);

    map_free(hashmap);

    return EXIT_SUCCESS;
}

