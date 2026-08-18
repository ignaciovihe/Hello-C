#include <stdio.h>
#include "exercise.h"

int main(void) {
    char first[50] = "Snek";
    const char *second = "lang!";

    concat_strings(first, second);

    printf("%s\n", first);

    return 0;
}