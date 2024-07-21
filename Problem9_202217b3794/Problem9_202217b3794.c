#include <stdio.h>

// Function to perform insertion sort
void insertion_sort(int a[], int n) {
    int i, j, key;
    for (i = 1; i < n; i++) {
        key = a[i];
        j = i - 1;

        // Move elements of a[0..i-1], that are greater than key, to one position ahead of their current position
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = key;
    }
}

// Function to print an array
void print_array(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

// Main function to test the insertion_sort function
int main() {
    int a[] = {12, 31, 25, 8, 32, 17};
    int n = sizeof(a) / sizeof(a[0]);

    printf("Before sorting array elements are - \n");
    print_array(a, n);

    insertion_sort(a, n);

    printf("After sorting array elements are - \n");
    print_array(a, n);

    return 0;
}
