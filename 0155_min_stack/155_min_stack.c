typedef struct {
    int val;
    int min;
} data_t;

typedef struct {
    int capacity;
    int size;
    data_t *buf;
} MinStack;

#define MIN(a, b) ((a) < (b) ? (a) : (b))

//initializes the stack object.
MinStack* minStackCreate() {
    const int initialCapacity = 100;
    MinStack* obj = malloc(sizeof(MinStack));
    obj->capacity = initialCapacity;
    obj->size = 0;
    obj->buf = (data_t *)malloc(sizeof(data_t) * obj->capacity);
    return obj;
}

//pushes the element val onto the stack
void minStackPush(MinStack* obj, int val) {
    if (obj->size == obj->capacity) {
        obj->capacity *= 2; // double the capacity
        obj->buf = (data_t *)realloc(obj->buf, sizeof(data_t) * obj->capacity);
    }

    int currentMin = (obj->size == 0) ? val : MIN(val, obj->buf[obj->size - 1].min);
    obj->buf[obj->size++] = (data_t){ .val = val, .min = currentMin };
}

//removes the element on the top of the stack.
void minStackPop(MinStack* obj) {
    if (obj->size > 0) {
        obj->size--;
    }
}

// gets the top element of the stack.
int minStackTop(MinStack* obj) {
    if (obj->size > 0) {
        return obj->buf[obj->size - 1].val;
    }
    return -1; // or some error code
}

//retrieves the minimum element in the stack.
int minStackGetMin(MinStack* obj) {
    if (obj->size > 0) {
        return obj->buf[obj->size - 1].min;
    }
    return -1; // or some error code
}

//free obj
void minStackFree(MinStack* obj) {
    free(obj->buf);
    free(obj);
}
