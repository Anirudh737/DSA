#include <stdio.h>
#include <stdlib.h>
#include<string.h>

#define STACKSIZE 100

typedef struct
{
    int data[STACKSIZE];
    int top;
} Stack;

void push(Stack* stack, int value) {
    if (stack->top < STACKSIZE) {
        stack->data[stack->top++] = value;
    } else {
        printf("Stack overflow!\n");
    }
}

int pop(Stack* stack) {
    if (stack->top > 0) {
        return stack->data[--stack->top];
    } else {
        printf("Stack underflow!\n");
        return -1; // Return a sentinel value to indicate an error
    }
}

int main() {
    Stack stack;
    stack.top = 0; // Initialize stack top

    FILE* file = fopen("commands.txt", "r");
    if (file == NULL) {
        printf("Failed to open the file.\n");
        return 1;
    }

    int value;
    char operation[4];

    while (fscanf(file, "%3s %d", operation, &value) == 2) {
        if (strcmp(operation, "PUSH") == 0) {
            push(&stack, value);
        } else if (strcmp(operation, "POP") == 0)
        {
            int poppedValue = pop(&stack);
            printf("Popped value: %d\n", poppedValue);
        }
    }
    fclose(file);
    return 0;
}

