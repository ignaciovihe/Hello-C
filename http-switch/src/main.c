#include <stdio.h>
#include "http.h"

int main(void) {
    printf("%s\n", http_to_str(HTTP_BAD_REQUEST));
    printf("%s\n", http_to_str(HTTP_UNAUTHORIZED));
    printf("%s\n", http_to_str(HTTP_NOT_FOUND));
    printf("%s\n", http_to_str(HTTP_TEAPOT));
    printf("%s\n", http_to_str(HTTP_INTERNAL_SERVER_ERROR));

    return 0;
}