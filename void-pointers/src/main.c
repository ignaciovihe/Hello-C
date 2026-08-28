#include "exercise.h"
#include <stdio.h>

int main(void) {
    snek_int_t integer;
    snek_float_t float_num;
    snek_bool_t boolean;

    integer.value = -100;
    float_num.value = -99.99f;
    boolean.value = 255;

    printf("Before:\n");
    printf("Integer: %d\n", integer.value);
    printf("Float:   %f\n", float_num.value);
    printf("Bool:    %u\n", boolean.value);

    snek_zero_out(&integer, INTEGER);
    snek_zero_out(&float_num, FLOAT);
    snek_zero_out(&boolean, BOOL);

    printf("\nAfter:\n");
    printf("Integer: %d\n", integer.value);
    printf("Float:   %f\n", float_num.value);
    printf("Bool:    %u\n", boolean.value);

    return 0;
}