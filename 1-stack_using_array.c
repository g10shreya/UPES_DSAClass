#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int stack[MAX], top = -1, maxSize;

// Function to insert an element in the stack
void push(int value) {
    if (top == maxSize - 1) {
        printf("Stack Overflow! Cannot insert %d\n", value);
    } else {
        top++;
        stack[top] = value;
        printf("%d inserted into the stack.\n", value);
    }
}

// Function to delete an element from the stack
void pop() {
    if (top == -1) {
        printf("Stack Underflow! The stack is empty.\n");
    } else {
        printf("%d deleted from the stack.\n", stack[top]);
        top--;
    }
}

// Function to print the stack
void printStack() {
    if (top == -1) {
        printf("The stack is empty.\n");
    } else {
        printf("Stack elements: ");
        for (int i = 0; i <= top; i++) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice, value;

    // Ask for the stack size
    printf("Enter the size of the stack: ");
    scanf("%d", &maxSize);

    if (maxSize > MAX) {
        printf("Max stack size allowed is %d. Setting stack size to %d.\n", MAX, MAX);
        maxSize = MAX;
    }

    while (1) {
        // Display menu options
        printf("\n*** Stack Menu ***\n");
        printf("1. Insert in stack\n");
        printf("2. Delete from stack\n");
        printf("3. Print the stack\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                push(value);
                break;

            case 2:
                pop();
                break;

            case 3:
                printStack();
                break;

            case 4:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
