
#include <stdio.h>

                 //202217b3794- SIRUMULLA SNEHA
#define MAX 20  // Maximum size for the array

// Global variables
int b[MAX];  // Array to hold list elements
int n = 0;   // Current number of elements in the list

// Function prototypes
void create();
void insertion();
void deletion();
void search();
void display();

void main_menu()
{
    printf("\n Main Menu");
    printf("\n 1. Create\n 2. Delete\n 3. Search\n 4. Insert\n 5. Display\n 6. Exit\n");
    printf("\n Enter your Choice: ");
}

void main()
{
    int ch;
    char g = 'y';

    do
    {
        main_menu();
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            create();
            break;
        case 2:
            deletion();
            break;
        case 3:
            search();
            break;
        case 4:
            insertion();
            break;
        case 5:
            display();
            break;
        case 6:
            printf("\n Exiting the program...\n");
            break;
        default:
            printf("\n Invalid choice! Please enter a number between 1 to 6.\n");
        }

        if (ch != 6)
        {
            printf("\n Do you want to continue (y/n)? ");
            scanf(" %c", &g);  // Space before %c to consume newline
        }

    } while (g == 'y' || g == 'Y');
}

void create()
{
    printf("\n Enter the number of elements to create: ");
    scanf("%d", &n);

    if (n > MAX)
    {
        printf("\n Maximum size exceeded. Setting size to %d.\n", MAX);
        n = MAX;
    }

    printf("\n Enter the elements:\n");
    for (int i = 0; i < n; i++)
    {
        printf(" Element %d: ", i + 1);
        scanf("%d", &b[i]);
    }
}

void deletion()
{
    int pos;
    if (n == 0)
    {
        printf("\n The list is empty. Deletion not possible.\n");
        return;
    }

    printf("\n Enter the position to delete (0 to %d): ", n - 1);
    scanf("%d", &pos);

    if (pos < 0 || pos >= n)
    {
        printf("\n Invalid position! Deletion failed.\n");
        return;
    }

    for (int i = pos; i < n - 1; i++)
    {
        b[i] = b[i + 1];
    }
    n--;

    printf("\n Element at position %d deleted successfully.\n", pos);
}

void search()
{
    int e;
    if (n == 0)
    {
        printf("\n The list is empty. Search not possible.\n");
        return;
    }

    printf("\n Enter the element to search: ");
    scanf("%d", &e);

    for (int i = 0; i < n; i++)
    {
        if (b[i] == e)
        {
            printf(" Element %d found at position %d.\n", e, i);
            return;  // Exit function after finding the first occurrence
        }
    }

    printf(" Element %d not found in the list.\n", e);
}

void insertion()
{
    int pos, p;

    if (n == MAX)
    {
        printf("\n List is full. Insertion not possible.\n");
        return;
    }

    printf("\n Enter the position to insert (0 to %d): ", n);
    scanf("%d", &pos);

    if (pos < 0 || pos > n)
    {
        printf("\n Invalid position! Insertion failed.\n");
        return;
    }

    printf("\n Enter the element to insert: ");
    scanf("%d", &p);

    for (int i = n; i > pos; i--)
    {
        b[i] = b[i - 1];
    }
    b[pos] = p;
    n++;

    printf("\n Element %d inserted at position %d.\n", p, pos);
}

void display()
{
    if (n == 0)
    {
        printf("\n The list is empty.\n");
        return;
    }

    printf("\n Elements in the list:\n");
    for (int i = 0; i < n; i++)
    {
        printf(" %d", b[i]);
    }
    printf("\n");
}
