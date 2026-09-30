#include "snekobject.h"
#include <stdio.h>

int main(void) {

    printf("\n========== REFERENCE COUNTING ==========\n\n");

    // 1. Create an object
    snek_object_t *num = new_snek_integer(42);

    printf("1. Create num\n");
    printf("   num = %d\n", num->data.v_int);
    printf("   refcount(num) = %d\n\n", num->refcount);


    // 2. Create an array
    snek_object_t *array = new_snek_array(2);

    printf("2. Create array\n");
    printf("   refcount(array) = %d\n\n", array->refcount);


    // 3. The array starts pointing to num
    snek_array_set(array, 0, num);

    printf("3. Store num in array[0]\n");
    printf("   num still points to the object\n");
    printf("   array[0] also points to the object\n");
    printf("   refcount(num) = %d\n\n", num->refcount);


    // 4. Another array position points to the SAME object
    snek_array_set(array, 1, num);

    printf("4. Store the SAME num in array[1]\n");
    printf("   Now we have:\n");
    printf("      num -----\\\n");
    printf("      array[0] ---> object 42\n");
    printf("      array[1] ---/\n");
    printf("   refcount(num) = %d\n\n", num->refcount);


    // 5. Replace array[0]
    snek_object_t *other = new_snek_integer(100);

    printf("5. Create other = 100\n");
    printf("   refcount(other) = %d\n\n", other->refcount);

    snek_array_set(array, 0, other);

    printf("6. Replace array[0]: num -> other\n");
    printf("   array[0] no longer points to num\n");
    printf("   refcount(num)   = %d\n", num->refcount);
    printf("   refcount(other) = %d\n\n", other->refcount);


    // 6. We no longer need our direct reference to "other"
    refcount_dec(other);

    printf("7. Stop using 'other' directly\n");
    printf("   But array[0] still keeps it alive\n");
    printf("   refcount(other) = %d\n\n",
        snek_array_get(array, 0)->refcount);


    // 7. We no longer need our direct reference to num
    refcount_dec(num);

    printf("8. Stop using 'num' directly\n");
    printf("   But array[1] still keeps it alive\n");
    printf("   refcount(num) = %d\n\n",
        snek_array_get(array, 1)->refcount);


    printf("9. Now free the array\n");
    printf("   refcount(array) = %d -> 0\n", array->refcount);
    printf("   When destroyed, it calls DEC on array[0] and array[1]\n");
    printf("   Both integers reach 0 and are freed.\n\n");

    refcount_dec(array);

    /*
     * IMPORTANT:
     *
     * From this point on, we DO NOT use:
     *
     * num
     * other
     * array
     *
     * because all three objects have already been freed.
     */

    printf("========== EVERYTHING FREED ==========\n\n");

    return 0;
}