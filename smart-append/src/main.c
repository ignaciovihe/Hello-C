#include <stdio.h>
#include "exercise.h"

int main(void) {
    TextBuffer dest = {
        .length = 5,
        .buffer = "Hello"
    };

    const char *src = " World";

    int result = smart_append(&dest, src);

    printf("Buffer: %s\n", dest.buffer);
    printf("Length: %zu\n", dest.length);
    printf("Result: %d\n", result);

    return 0;
}