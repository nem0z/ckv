#include "utils.h"

size_t strlen(const char * str) {
    size_t i = 0;
    for(; str[i] != '\0'; ++i);
    return i;
}

char * safecpy(const char * source) {
    size_t len = strlen(source);
    char * copy = malloc(len * sizeof(char) + 1);

    for(size_t i = 0; i < len; ++i) {
        copy[i] = source[i];
    }

    copy[len] = '\0';

    return copy;
}

bool safeeq(const char * a, const char * b) {
    if(a == NULL || b == NULL) return false;
    
    for(size_t i = 0; a[i] == b[i]; ++i) {
        if(a[i] == '\0') return true;
    }

    return false;
}