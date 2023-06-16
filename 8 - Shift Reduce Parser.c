#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define STACK_SIZE 100

// Stack implementation
typedef struct {
    char data[STACK_SIZE];
    int top;
} Stack;

// Initialize an empty stack
void initStack(Stack* stack) {
    stack->top = -1;
}

// Push an element onto the stack
void push(Stack* stack, char c) {
    stack->data[++stack->top] = c;
}

// Pop the top element from the stack
char pop(Stack* stack) {
    return stack->data[stack->top--];
}

// Return the top element of the stack without removing it
char top(Stack* stack) {
    return stack->data[stack->top];
}

// Perform the shift operation by pushing the input onto the stack
void shift(Stack* stack, const char* input) {
    push(stack, *input);
    printf("Shifted: %c\n", *input);
}

// Perform the reduce operation by popping elements from the stack based on the grammar rules
void reduce(Stack* stack) {
    char symbol = top(stack);
    if (symbol == 'c') {
        pop(stack);  // Pop 'c'
        pop(stack);  // Pop 'b'
        pop(stack);  // Pop 'a'
        push(stack, 'E');  // Push 'E'
        printf("Reduced: cba -> E\n");
    } else if (symbol == 'd') {
        pop(stack);  // Pop 'd'
        pop(stack);  // Pop 'E'
        push(stack, 'E');  // Push 'E'
        printf("Reduced: dE -> E\n");
    } else {
        printf("Invalid reduction.\n");
    }
}

// Perform the shift-reduce parsing process
bool parse(const char* input) {
    Stack stack;
    initStack(&stack);

    int length = strlen(input);
    int index = 0;

    while (index < length) {
        if (top(&stack) == 'E' && input[index] == 'd') {
            reduce(&stack);
        } else {
            shift(&stack, &input[index++]);
        }
    }

    while (top(&stack) != 'E') {
        reduce(&stack);
    }

    return stack.top == 0 && top(&stack) == 'E';
}

int main() {
    const char* input = "cdba";
    if (parse(input)) {
        printf("Input %s is accepted.\n", input);
    } else {
        printf("Input %s is not accepted.\n", input);
    }
    return 0;
}
