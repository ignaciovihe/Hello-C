#include "exercise.h"
#include <string.h>

int smart_append(TextBuffer *dest, const char *src) {
    if (!dest || !src) {
        return 1;
    }
    const int max_buffer_size = 64;
    size_t src_len = strlen(src);
    size_t available_space_in_dest = (max_buffer_size - dest->length) - 1;
    if (src_len > available_space_in_dest) {
        strncat(dest->buffer, src, available_space_in_dest);
        dest->length = max_buffer_size - 1;
        return 1;
    } else {
        strcat(dest->buffer, src);
        dest->length += src_len;
        return 0;
    }
}