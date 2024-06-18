#ifndef UTILS_H
#define UTILS_H

#include <stdlib.h>
#include <stdbool.h>

size_t strlen(const char * str);
char * safecpy(const char * source);
bool safeeq(const char * a, const char * b);

#endif // UTILS_H