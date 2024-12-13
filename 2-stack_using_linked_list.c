#include <stdio.h>
#include <stdlib.h>

// Define the structure for the stack node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation error!\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Function to push an element onto the stack
void push(struct Node** top, int value) {
    struct Node* newNode = createNode(value);
    newNode->next = *top;
    *top = newNode;
    printf("%d pushed onto the stack.\n", value);
}

// Function to pop an element from the stack
void pop(struct Node** top) {
    if (*top == NULL) {
        printf("Stack Underflow! The stack is empty.\n");
        return;
    }
    struct Node* temp = *top;
    printf("%d popped from the stack.\n", temp->data);
    *top = (*top)->next;
    free(temp);
}

// Function to print the stack
void printStack(struct Node* top) {
    if (top == NULL) {
        printf("The stack is empty.\n");
        return;
    }
    printf("Stack elements: ");
    struct Node* temp = top;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Node* top = NULL;  // Initialize the stack as empty
    int choice, value;

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
                push(&top, value);
                break;

            case 2:
                pop(&top);
                break;

            case 3:
                printStack(top);
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
