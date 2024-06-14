#include <stdlib.h>
#include <stdio.h>

#include "ckv/haspmap/hashmap.h"

int main(void) {

    HashMap * hashmap = new_hashmap(128);

    set(hashmap, "Key1", "Value1");
    set(hashmap, "Key2", "Value2");
    set(hashmap, "Key3", "Value3");

    KVPair * kvp1 = get(hashmap, "Key1");
    KVPair * kvp2 = get(hashmap, "Key2");
    KVPair * kvp3 = get(hashmap, "Key3");

    printf("%s - %s : %s\n", kvp1->value, kvp2->value, kvp2->value);

    return EXIT_SUCCESS;
}

