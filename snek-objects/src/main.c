#include "snekobject.h"
#include <stdio.h>

int main(void) {

    // =========================================
    // 1. INTEGER + INTEGER
    // =========================================

    snek_object_t *int1 = new_snek_integer(10);
    snek_object_t *int2 = new_snek_integer(20);

    snek_object_t *int_result = snek_add(int1, int2);

    printf("INTEGER + INTEGER:\n");
    printf("10 + 20 = %d\n\n", int_result->data.v_int);


    // =========================================
    // 2. INTEGER + FLOAT
    // =========================================

    snek_object_t *float1 = new_snek_float(2.5f);

    snek_object_t *float_result = snek_add(int1, float1);

    printf("INTEGER + FLOAT:\n");
    printf("10 + 2.5 = %.2f\n\n", float_result->data.v_float);


    // =========================================
    // 3. STRING + STRING
    // =========================================

    snek_object_t *str1 = new_snek_string("Hello ");
    snek_object_t *str2 = new_snek_string("Snek!");

    snek_object_t *str_result = snek_add(str1, str2);

    printf("STRING + STRING:\n");
    printf("\"Hello \" + \"Snek!\" = \"%s\"\n\n",
        str_result->data.v_string);


    // =========================================
    // 4. VECTOR3 + VECTOR3
    // =========================================

    snek_object_t *x1 = new_snek_integer(1);
    snek_object_t *y1 = new_snek_integer(2);
    snek_object_t *z1 = new_snek_integer(3);

    snek_object_t *x2 = new_snek_integer(10);
    snek_object_t *y2 = new_snek_integer(20);
    snek_object_t *z2 = new_snek_integer(30);

    snek_object_t *vec1 = new_snek_vector3(x1, y1, z1);
    snek_object_t *vec2 = new_snek_vector3(x2, y2, z2);

    snek_object_t *vec_result = snek_add(vec1, vec2);

    printf("VECTOR3 + VECTOR3:\n");
    printf("(%d, %d, %d) + (%d, %d, %d)\n",
        x1->data.v_int,
        y1->data.v_int,
        z1->data.v_int,
        x2->data.v_int,
        y2->data.v_int,
        z2->data.v_int);

    printf("Resultado: (%d, %d, %d)\n\n",
        vec_result->data.v_vector3.x->data.v_int,
        vec_result->data.v_vector3.y->data.v_int,
        vec_result->data.v_vector3.z->data.v_int);


    // =========================================
    // 5. ARRAY + ARRAY
    // =========================================

    snek_object_t *array1 = new_snek_array(2);
    snek_array_set(array1, 0, int1);
    snek_array_set(array1, 1, int2);

    snek_object_t *a3 = new_snek_integer(30);
    snek_object_t *a4 = new_snek_integer(40);

    snek_object_t *array2 = new_snek_array(2);
    snek_array_set(array2, 0, a3);
    snek_array_set(array2, 1, a4);

    snek_object_t *array_result = snek_add(array1, array2);

    printf("ARRAY + ARRAY:\n");

    printf("[");

    for (size_t i = 0; i < array_result->data.v_array.size; i++) {

        snek_object_t *value = snek_array_get(array_result, i);

        printf("%d", value->data.v_int);

        if (i < array_result->data.v_array.size - 1) {
            printf(", ");
        }
    }

    printf("]\n\n");


    // =========================================
    // 6. INCOMPATIBLE TYPES
    // =========================================

    snek_object_t *invalid = snek_add(str1, int1);

    printf("STRING + INTEGER:\n");

    if (invalid == NULL) {
        printf("NULL (tipos incompatibles)\n");
    }


    return 0;
}