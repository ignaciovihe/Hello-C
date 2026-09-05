#include "stack.h"

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    size_t capacity = 2;

    stack_t *stack = stack_new(capacity);

    if (stack == NULL) {
        printf("Error creating stack\n");
        return 1;
    }

    printf("Initial count: %zu\n", stack->count);
    printf("Initial capacity: %zu\n\n", stack->capacity);

    // ----- First int -----
    int *a = malloc(sizeof(int));
    *a = 10;
    stack_push(stack, a);

    printf("Pushed: %d\n", *a);
    printf("Count: %zu\n", stack->count);
    printf("Capacity: %zu\n\n", stack->capacity);

    // ----- Second int -----
    int *b = malloc(sizeof(int));
    *b = 20;
    stack_push(stack, b);

    printf("Pushed: %d\n", *b);
    printf("Count: %zu\n", stack->count);
    printf("Capacity: %zu\n\n", stack->capacity);

    // ----- Third element: triggers realloc -----
    float *c = malloc(sizeof(float));
    *c = 3.14f;
    stack_push(stack, c);

    printf("Pushed: %.2f\n", *c);
    printf("Count: %zu\n", stack->count);
    printf("Capacity: %zu\n\n", stack->capacity);

    // ----- POP: LIFO -----

    float *popped_c = stack_pop(stack);
    printf("Popped float: %.2f\n", *popped_c);
    free(popped_c);

    int *popped_b = stack_pop(stack);
    printf("Popped int: %d\n", *popped_b);
    free(popped_b);

    int *popped_a = stack_pop(stack);
    printf("Popped int: %d\n", *popped_a);
    free(popped_a);

    printf("\nFinal count: %zu\n", stack->count);

    // We have already freed the objects.
    // Now we free the stack structure and its data.
    stack_free(stack);

    return 0;
}