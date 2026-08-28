#include "exercise.h"

void snek_zero_out(void *ptr, snek_object_kind_t kind) {
    if(kind == INTEGER) {
    ((snek_int_t*)ptr)->value = 0;
    } else if(kind == FLOAT) {
    ((snek_float_t*)ptr)->value = 0.0;
    } else if(kind == BOOL) {
    ((snek_bool_t*)ptr)->value = 0;
    }
}

/*
When working with pointers and dereferencing them, parentheses usage is essential. Consider the following examples:

((some_struct_t*)ptr)->field means casting is applied to ptr and then the field is obtained.
(some_struct_t*)ptr->field means casting is applied to ptr->field.
*/