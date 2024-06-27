#include <stdlib.h>
#include <stdio.h>

#include "ckv/ckv.h"

int main(void) {
    FILE * stream = fopen("db.txt", "rb+");
    if(stream == NULL) {
        fprintf(stderr, "Cannot open file for reading\n");
        exit(EXIT_FAILURE);
    }

    HashMap * map = map_fread(stream);
    map_display(map);
    map_free(map);

    if(fclose(stream) == EOF) {
        fprintf(stderr, "Error closing the file");
        exit(EXIT_FAILURE);
    }
    stream = NULL;

    HashMap * hashmap = map_new(2);

    map_set(hashmap, "Key1", "Value1");
    map_set(hashmap, "Key2", "Value2");
    map_set(hashmap, "Key3", "Value3");
    map_set(hashmap, "Key4", "Value4");
    map_set(hashmap, "Key5", "Value5");
    map_set(hashmap, "Key3", "Value5-2");

    map_delete(hashmap, "Key2");

    char * kvp1 = map_get(hashmap, "Key1");
    char * kvp2 = map_get(hashmap, "Key2");
    char * kvp3 = map_get(hashmap, "Key3");

    printf("%s - %s - %s\n", kvp1, kvp2, kvp3);

    free(kvp1);
    free(kvp2);
    free(kvp3);

    map_display(hashmap);

    stream = fopen("db.txt", "wb+");
    if(stream == NULL) {
        fprintf(stderr, "Cannot open file for writing\n");
        exit(EXIT_FAILURE);
    }

    if(!map_fwrite(hashmap, stream)) {
        fprintf(stderr, "Error writing hashmap to file\n");
    }
    map_free(hashmap);

    if(fclose(stream) == EOF) {
        fprintf(stderr, "Error closing the file");
        exit(EXIT_FAILURE);
    }

    return EXIT_SUCCESS;
}

