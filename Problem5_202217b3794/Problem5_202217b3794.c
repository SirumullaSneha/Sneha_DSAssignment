#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

int main() {
    int queue[MAX_SIZE], choice, front = 0, rear = 0, value;

    printf("Queue using Array\n");
    printf("1. Insertion\n");
    printf("2. Deletion\n");
    printf("3. Display\n");
    printf("4. Exit\n");

    while (1) {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (rear == MAX_SIZE) {
                    printf("Queue is full!\n");
                } else {
                    printf("Enter the value to be inserted: ");
                    scanf("%d", &value);
                    queue[rear++] = value;
                }
                break;

            case 2:
                if (front == rear) {
                    printf("Queue is empty!\n");
                } else {
                    value = queue[front++];
                    printf("Deleted Element: %d\n", value);
                }
                break;

            case 3:
                if (front == rear) {
                    printf("Queue is empty!\n");
                } else {
                    printf("Queue elements:\n");
                    for (int i = front; i < rear; i++) {
                        printf("%d\n", queue[i]);
                    }
                }
                break;

            case 4:
                printf("Exiting from program.\n");
                return 0;

            default:
                printf("Invalid choice! Please enter a valid menu option.\n");
                break;
        }
    }

    return 0;
}
