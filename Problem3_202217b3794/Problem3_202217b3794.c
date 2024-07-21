#include <stdio.h>
#include <stdlib.h>  // For exit()
                      //202217b3794- SIRUMULLA SNEHA
#define MAX_SIZE 100  

int stack[MAX_SIZE];
int top = -1;
int stack_size;

void push(void);
void pop(void);
void display(void);

int main() {
    printf("\n Enter the size of STACK [MAX=100]: ");
    scanf("%d", &stack_size);

    if (stack_size <= 0 || stack_size > MAX_SIZE) {
        printf("\n Invalid stack size. Setting default size to %d.\n", MAX_SIZE);
        stack_size = MAX_SIZE;
    }

    printf("\n\t STACK OPERATIONS USING ARRAY");
    printf("\n\t--------------------------------");
    printf("\n\t 1.PUSH\n\t 2.POP\n\t 3.DISPLAY\n\t 4.EXIT");

    int choice;
    do {
        printf("\n Enter the Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("\n\t EXIT POINT\n");
                exit(0);  // Exit the program
            default:
                printf("\n\t Please Enter a Valid Choice (1/2/3/4)\n");
        }
    } while (choice != 4);

    return 0;
}

void push() {
    if (top >= stack_size - 1) {
        printf("\n\tSTACK is full. Cannot push.\n");
    } else {
        int x;
        printf(" Enter a value to be pushed: ");
        scanf("%d", &x);
        top++;
        stack[top] = x;
    }
}

void pop() {
    if (top <= -1) {
        printf("\n\t Stack is empty. Cannot pop.\n");
    } else {
        printf("\n\t The popped element is %d\n", stack[top]);
        top--;
    }
}

void display() {
    if (top >= 0) {
        printf("\n The elements in STACK are:\n");
        for (int i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    } else {
        printf("\n The STACK is empty.\n");
    }
}
