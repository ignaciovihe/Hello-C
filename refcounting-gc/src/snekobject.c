#include "snekobject.h"
#include "assert.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

snek_object_t *snek_add(snek_object_t *a, snek_object_t *b) {
    if (a == NULL || b == NULL) {
        return NULL;
    }
    
    if (a->kind == INTEGER) {
        if (b->kind == INTEGER) {
        return new_snek_integer(a->data.v_int + b->data.v_int);
        } else if (b->kind == FLOAT) {
        return new_snek_float(a->data.v_int + b->data.v_float);
        } else {
        return NULL;
        }
    }

    if (a->kind == FLOAT) {
        if (b->kind == INTEGER) {
        return new_snek_float(a->data.v_float + b->data.v_int);
        } else if (b->kind == FLOAT) {
        return new_snek_float(a->data.v_float + b->data.v_float);
        } else {
        return NULL;
        }
    }

    if (a->kind == STRING) {
        if (b->kind != STRING) {
        return NULL;
        } else {
        size_t new_length = strlen(a->data.v_string) + strlen(b->data.v_string) + 1;
        char *dst = calloc(new_length, sizeof(char));
        if (dst == NULL) {
            return NULL;
        }
        strcat(dst, a->data.v_string);
        strcat(dst, b->data.v_string);
        snek_object_t *new_str = new_snek_string(dst);
        free(dst);
        return new_str;
        } 
    }

    if (a->kind == VECTOR3) {
        if (b->kind != VECTOR3) {
        return NULL;
        } else {
        snek_object_t *new_vector3 = new_snek_vector3(snek_add(a->data.v_vector3.x, b->data.v_vector3.x), snek_add(a->data.v_vector3.y, b->data.v_vector3.y), snek_add(a->data.v_vector3.z, b->data.v_vector3.z));
        return new_vector3;
        } 
    }

    if (a->kind == ARRAY) {
        if (b->kind != ARRAY) {
        return NULL;
        } else {
        size_t len_a = snek_length(a);
        size_t len_b = snek_length(b);
        snek_object_t *new_array = new_snek_array(len_a + len_b);
        for (size_t i = 0; i < len_a; i++) {
            snek_object_t *value = snek_array_get(a, i);
            snek_array_set(new_array, i, value);
        }
        for (size_t i = 0; i < len_b; i++) {
            snek_object_t * value = snek_array_get(b, i);
            snek_array_set(new_array, i + len_a, value);
        }
        return new_array;
        } 
    }
    else {
        return NULL;
    }
}

void refcount_dec(snek_object_t *obj) {
    if (obj == NULL) {
        return;
    }
    obj->refcount--;
    if (obj->refcount == 0) {
        refcount_free(obj);
    }
}

void refcount_free(snek_object_t *obj) {
    switch (obj->kind) {
    case INTEGER:
    case FLOAT:
        break;
    case STRING:
        free(obj->data.v_string);
        break;
    case VECTOR3: 
        snek_vector_t vec = obj->data.v_vector3;
        refcount_dec(vec.x);
        refcount_dec(vec.y);
        refcount_dec(vec.z);
        break;
    case ARRAY:
        for (int i = 0; i < (obj->data.v_array.size); i++) {
        refcount_dec(obj->data.v_array.elements[i]);
        }
        free(obj->data.v_array.elements);
        break;
    default:
        assert(false);
    }
    free(obj);
}

void refcount_inc(snek_object_t *obj) {
    if (obj == NULL) {
        return;
    }
    obj->refcount += 1;
}

snek_object_t *_new_snek_object(void) {
    snek_object_t *obj = calloc(1, sizeof(snek_object_t));
    if (obj == NULL) {
        return NULL;
    }
    obj->refcount = 1;
    return obj;
}


int snek_length(snek_object_t *obj) {
    if (obj == NULL) {
        return -1;
    }

    switch (obj->kind) {
    case INTEGER:
        return 1;
    case FLOAT:
        return 1;
    case STRING:
        return strlen(obj->data.v_string);
    case VECTOR3:
        return 3;
    case ARRAY:
        return obj->data.v_array.size;
    default:
        return -1;
    }
}
snek_object_t *new_snek_array(size_t size) {
    snek_object_t *obj = _new_snek_object();
    if (obj == NULL) {
        return NULL;
    }

    snek_object_t **elements = calloc(size, sizeof(snek_object_t *));
    if (elements == NULL) {
        free(obj);
        return NULL;
    }

    obj->kind = ARRAY;
    obj->data.v_array = (snek_array_t){.size = size, .elements = elements};

    return obj;
}

bool snek_array_set(snek_object_t *snek_obj, size_t index,
                    snek_object_t *value) {
    if (snek_obj == NULL || value == NULL) {
        return false;
    }
    if (snek_obj->kind != ARRAY) {
        return false;
    }
    if (index >= snek_obj->data.v_array.size) {
        return false;
    }
    if (snek_obj->data.v_array.elements[index] != NULL) {
        refcount_dec(snek_array_get(snek_obj, index));
    }
    snek_obj->data.v_array.elements[index] = value;
    refcount_inc(value);
    return true;
}

snek_object_t *snek_array_get(snek_object_t *array, size_t index) {
    if (array == NULL) {
        return NULL;
    }

    if (array->kind != ARRAY) {
        return NULL;
    }

    if (index >= array->data.v_array.size) {
        return NULL;
    }

    return array->data.v_array.elements[index];
}

snek_object_t *new_snek_vector3(snek_object_t *x, snek_object_t *y,
                                snek_object_t *z) {
    if (x == NULL || y == NULL || z == NULL) {
        return NULL;
    }
    snek_object_t *obj = _new_snek_object();
    if (obj == NULL) {
        return NULL;
    }
    obj->kind = VECTOR3;
    obj->data.v_vector3 = (snek_vector_t){.x = x, .y = y, .z = z};
    refcount_inc(x);
    refcount_inc(y);
    refcount_inc(z);
    return obj;
}

snek_object_t *new_snek_integer(int value) {
    snek_object_t *obj = _new_snek_object();
    if (obj == NULL) {
        return NULL;
    }

    obj->kind = INTEGER;
    obj->data.v_int = value;
    return obj;
}

snek_object_t *new_snek_float(float value) {
    snek_object_t *obj = _new_snek_object();
    if (obj == NULL) {
        return NULL;
    }

    obj->kind = FLOAT;
    obj->data.v_float = value;
    return obj;
}

snek_object_t *new_snek_string(char *value) {
    snek_object_t *obj = _new_snek_object();
    if (obj == NULL) {
        return NULL;
    }

    int len = strlen(value);
    char *dst = malloc(len + 1);
    if (dst == NULL) {
        free(obj);
        return NULL;
    }

    strcpy(dst, value);

    obj->kind = STRING;
    obj->data.v_string = dst;
    return obj;
}
