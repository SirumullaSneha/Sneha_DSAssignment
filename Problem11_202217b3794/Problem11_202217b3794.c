#include <stdio.h>

// Function to perform linear search
int linearSearch(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            return i; // Return index of target element found
        }
    }
    return -1; // Return -1 if target element is not found
}

// Main function to test linearSearch function
int main() {
    int arr[] = {10, 2, 8, 5, 17};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 8;
    
    // Perform linear search
    int result = linearSearch(arr, n, target);
    
    // Print result based on search
    if (result == -1) {
        printf("Element not found in the array.\n");
    } else {
        printf("Element found at index: %d\n", result);
    }
    
    return 0;
}
