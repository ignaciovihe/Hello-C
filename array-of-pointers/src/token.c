#include "token.h"
#include <stdlib.h>

token_t **create_token_pointer_array(token_t *tokens, size_t count) {
    token_t **token_pointers = malloc(count * sizeof(token_t *));
    if (token_pointers == NULL) {
        exit(1);
    }
    for (size_t i = 0; i < count; ++i) {
        token_t *token = malloc(sizeof(token_t)); /*Allocates memory for a token_t in the heap*/
        if (token == NULL) {
            exit(1);
        }
        *token = tokens[i]; /*Copy the original token(memory in stack) to the heap*/
        token_pointers[i] = token; /*Points the first element of token_pointers ** to the new token copied in the heap*/
    }
    return token_pointers;
}