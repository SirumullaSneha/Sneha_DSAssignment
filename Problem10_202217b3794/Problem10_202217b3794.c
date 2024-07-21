#include <stdio.h>

// Function to merge two subarrays of a[].
// First subarray is a[beg..mid]
// Second subarray is a[mid+1..end]
void merge(int a[], int beg, int mid, int end) {
    int i, j, k;
    int n1 = mid - beg + 1; // Size of LeftArray
    int n2 = end - mid;     // Size of RightArray

    // Create temporary arrays
    int LeftArray[n1], RightArray[n2];

    // Copy data to temporary arrays LeftArray[] and RightArray[]
    for (i = 0; i < n1; i++)
        LeftArray[i] = a[beg + i];
    for (j = 0; j < n2; j++)
        RightArray[j] = a[mid + 1 + j];

    // Merge the temporary arrays back into a[l..r]
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = beg; // Initial index of merged subarray

    while (i < n1 && j < n2) {
        if (LeftArray[i] <= RightArray[j]) {
            a[k] = LeftArray[i];
            i++;
        } else {
            a[k] = RightArray[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of LeftArray[], if any
    while (i < n1) {
        a[k] = LeftArray[i];
        i++;
        k++;
    }

    // Copy the remaining elements of RightArray[], if any
    while (j < n2) {
        a[k] = RightArray[j];
        j++;
        k++;
    }
}

// Function to implement merge sort
void mergeSort(int a[], int beg, int end) {
    if (beg < end) {
        int mid = beg + (end - beg) / 2; // Avoids overflow for large values of beg and end
        mergeSort(a, beg, mid); // Sort first half
        mergeSort(a, mid + 1, end); // Sort second half
        merge(a, beg, mid, end); // Merge the sorted halves
    }
}

// Function to print an array
void printArray(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

// Main function to test the mergeSort function
int main() {
    int a[] = {12, 31, 25, 8, 32, 17, 40, 42};
    int n = sizeof(a) / sizeof(a[0]);

    printf("Before sorting array elements are - \n");
    printArray(a, n);

    mergeSort(a, 0, n - 1);

    printf("After sorting array elements are - \n");
    printArray(a, n);

    return 0;
}
