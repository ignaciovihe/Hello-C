#include <stdio.h>

#include "sneknew.h"
#include "vm.h"

int main(void) {
    printf("=== Mark and Sweep Garbage Collector ===\n\n");

    vm_t *vm = vm_new();

    frame_t *f1 = vm_new_frame(vm);
    frame_t *f2 = vm_new_frame(vm);
    frame_t *f3 = vm_new_frame(vm);

    // Each frame references its own string.
    snek_object_t *s1 = new_snek_string(vm, "This string belongs to frame 1");
    frame_reference_object(f1, s1);

    snek_object_t *s2 = new_snek_string(vm, "This string belongs to frame 2");
    frame_reference_object(f2, s2);

    snek_object_t *s3 = new_snek_string(vm, "This string belongs to frame 3");
    frame_reference_object(f3, s3);

    // Create a vector containing three integer objects.
    snek_object_t *i1 = new_snek_integer(vm, 69);
    snek_object_t *i2 = new_snek_integer(vm, 420);
    snek_object_t *i3 = new_snek_integer(vm, 1337);

    snek_object_t *v = new_snek_vector3(vm, i1, i2, i3);

    // The same vector is reachable from two different frames.
    frame_reference_object(f2, v);
    frame_reference_object(f3, v);

    printf("Objects created: %zu\n", vm->objects->count);
    printf("Active frames:   %zu\n\n", vm->frames->count);

    /*
     * Current reference graph:
     *
     * f1 ---> s1
     *
     * f2 ---> s2
     *  |
     *  +----> vector ---> i1
     *           |-------> i2
     *           +-------> i3
     *         ^
     *         |
     * f3 -----+
     *  |
     *  +----> s3
     */

    printf("Removing frame 3...\n");
    frame_free(vm_frame_pop(vm));

    printf("Running garbage collector...\n");
    vm_collect_garbage(vm);

    printf("Objects remaining: %zu\n", vm->objects->count);
    printf("Active frames:     %zu\n\n", vm->frames->count);

    /*
     * s3 was only reachable through f3, so it has been collected.
     *
     * The vector survives because f2 still references it.
     * Because the vector survives, i1, i2 and i3 also survive.
     */

    printf("Removing frames 2 and 1...\n");
    frame_free(vm_frame_pop(vm));
    frame_free(vm_frame_pop(vm));

    printf("Running garbage collector again...\n");
    vm_collect_garbage(vm);

    printf("Objects remaining: %zu\n", vm->objects->count);
    printf("Active frames:     %zu\n\n", vm->frames->count);

    vm_free(vm);

    printf("Garbage collection complete.\n");

    return 0;
}