#ifndef STACK
#define STACK

#define MAX_STACK_SIZE 100

struct Stack {
    int* data; 
    int count;
    int capacity;
};
void init_stack(struct Stack* stack, int initial_capacity);

int stack_size(const struct Stack* stack);

void push_int_to_stack(struct Stack* stack, int element);

int pop_stack(struct Stack* stack);

int* expand_data(int* data, int capacity);

void add_int_to_stack(struct Stack* stack, int element);

void stack_free_data(struct Stack* stack);

#endif