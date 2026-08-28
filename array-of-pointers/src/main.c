#include "token.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    token_t tokens[3] = {
        {"foo", 1, 1},
        {"bar", 2, 5},
        {"baz", 3, 10},
    };

    token_t **result = create_token_pointer_array(tokens, 3);

    printf("Original tokens:\n");

    for (size_t i = 0; i < 3; ++i) {
        printf(
            "tokens[%zu]: literal=%s, line=%d, column=%d, address=%p\n",
            i,
            tokens[i].literal,
            tokens[i].line,
            tokens[i].column,
            (void *)&tokens[i]
        );
    }

    printf("\nCopied tokens in heap:\n");

    for (size_t i = 0; i < 3; ++i) {
        printf(
            "result[%zu]: literal=%s, line=%d, column=%d, address=%p\n",
            i,
            result[i]->literal,
            result[i]->line,
            result[i]->column,
            (void *)result[i]
        );
    }

    for (size_t i = 0; i < 3; ++i) {
        free(result[i]);
    }

    free(result);

    return 0;
}