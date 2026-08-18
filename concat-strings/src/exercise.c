#include "exercise.h"
#include <stdio.h>

void concat_strings(char *str1, const char *str2) {
    char *end = str1;
    while (*end != '\0') {
        end++;
    }
    while (*str2 != '\0') {
        *end = *str2;
        end++;
        str2++;
    }
    *end = '\0';
}