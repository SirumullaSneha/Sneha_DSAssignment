#include <stdio.h>

// Function to perform selection sort
void selection_sort(int arr[], int n) {
    int i, j, min_idx;

    // Iterate through the array
    for (i = 0; i < n-1; i++) {
        // Find the index of the minimum element in unsorted array
        min_idx = i;
        for (j = i+1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }

        // Swap the found minimum element with the first element of the unsorted array
        if (min_idx != i) {
            int temp = arr[i];
            arr[i] = arr[min_idx];
            arr[min_idx] = temp;
        }
    }
}

// Function to print an array
void print_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Main function to test the selection_sort function
int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    print_array(arr, n);

    selection_sort(arr, n);

    printf("Sorted array: ");
    print_array(arr, n);

    return 0;
}
