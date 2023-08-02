#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

void init_stack(struct Stack* stack, int initial_capacity){
    stack->data = (int*)malloc(initial_capacity * sizeof(int));
    stack->count = 0;
    stack->capacity = initial_capacity;
}

int stack_size(const struct Stack* stack) {
    return stack->count;
}

void push_int_to_stack(struct Stack* stack, int element) {
    if(stack->capacity > stack->count){
        add_int_to_stack(stack, element);
        return;
    }

    int* new_data = expand_data(stack->data, stack->capacity);

    if(new_data == NULL) {
        printf_s("Memory allocation error");
        return;
    }

    stack->data = new_data;
    stack->capacity++;
    add_int_to_stack(stack, element);
} 

void add_int_to_stack(struct Stack* stack, int element)
{
    stack->data[stack->count] = element;
    stack->count++;
};

int* expand_data(int* data, int capacity){
    if(capacity < MAX_STACK_SIZE) {
        capacity++;
        int* new_data = (int*)realloc(data, capacity * sizeof(int));
        if (new_data != NULL) {
            return new_data;
        }
    }
    return NULL;
}

int pop_stack(struct Stack* stack) {
    if (stack->count < 1){
        return NULL;
    }

    int result = stack->data[stack->count - 1];

    stack->count--;
    stack->data[stack->count] = NULL;

    return result;
}

void stack_free_data(struct Stack* stack) {
    free(stack->data);
}