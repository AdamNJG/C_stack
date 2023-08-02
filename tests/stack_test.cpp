#include <gtest/gtest.h>
#include "stack.h" 

TEST(stack_tests, init_stack) {
    Stack stack;
    init_stack(&stack, 3);

    EXPECT_EQ(stack.capacity, 3);
    EXPECT_EQ(stack.count, 0);
    ASSERT_TRUE(stack.data != nullptr);
}

TEST(stack_tests, push_element_to_stack) {
    Stack stack;
    init_stack(&stack,1);
    push_int_to_stack(&stack, 1);  
    
    EXPECT_EQ(stack.count, 1);
    EXPECT_EQ(stack.data[0], 1);
}

TEST(stack_tests, push_element_to_stack_at_capacity_unused_capacity){
    Stack stack;
    init_stack(&stack, 100);
    push_int_to_stack(&stack, 3);

    EXPECT_EQ(stack.capacity, 100);
    EXPECT_EQ(stack.count, 1);
    EXPECT_EQ(pop_stack(&stack), 3);
}

TEST(stack_tests, pop_element_from_stack) {
    Stack stack;
    init_stack(&stack,1);
    push_int_to_stack(&stack, 1);

    EXPECT_EQ(pop_stack(&stack), 1);
}

TEST(stack_tests, pop_element_from_stack_empty_stack) {
    Stack stack;
    init_stack(&stack,1);

    EXPECT_EQ(pop_stack(&stack), NULL);
}

TEST(stack_tests, expand_data_valid) {
    int capacity = 11;
    int* data = (int*)malloc(capacity * sizeof(int));

    int* new_data = expand_data(data, capacity);
    int new_capacity = capacity + 1;
    ASSERT_TRUE(new_data != nullptr); 
    EXPECT_EQ(sizeof(*new_data) * new_capacity, sizeof(int) * new_capacity);
}

TEST(stack_tests, expand_data_past_max) {
    int capacity = 101;
    int* data = (int*)malloc(capacity * sizeof(int));

    int* new_data = expand_data(data, capacity);
    ASSERT_TRUE(new_data == nullptr); 
}

TEST(stack_tests, multiple_elements_keep_order) {
    Stack stack;
    init_stack(&stack,0);
    push_int_to_stack(&stack, 1);
    push_int_to_stack(&stack, 4);
    push_int_to_stack(&stack, 5);

    EXPECT_EQ(pop_stack(&stack), 5); 
    EXPECT_EQ(pop_stack(&stack), 4);
    EXPECT_EQ(pop_stack(&stack), 1);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

/*
A stack is a simple data structure that follows the Last-In-First-Out (LIFO) principle. 
It supports two main operations: push (add an element to the top) and pop (remove the top element).

Test Case: Create an empty stack and check its size. x
Test Case: Push an element to the stack and check if it's at the top. x
Test Case: Pop an element from the stack and check if it's the correct one. x
Test Case: Push multiple elements to the stack and check their order after popping.
Test Case: Check if popping from an empty stack returns an error or a default value.
*/