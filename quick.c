#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int count = 0;

// Partition function: places the pivot in its correct position
int partition(int a[], int low, int high) {
    int pivot = a[low];
    int i = low + 1;
    int j = high;
    int temp;
    while (1) {
        // Move i rightward until an element > pivot is found
        while (i <= high && a[i] <= pivot) {
            i++;
            count++;
        }
        // Move j leftward until an element ≤ pivot is found
        while (j > low && a[j] > pivot) {
            j--;
            count++;
        }
        count += 2;  // for the two while checks above
        if (i < j) {
            // Swap a[i] and a[j]
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        } else {
            // Place pivot in its correct spot
            temp = a[low];
            a[low] = a[j];
            a[j] = temp;
            return j;
        }
    }
}
// Quicksort recursion
void quicksort(int a[], int low, int high) {
    if (low < high) {
        int pivotIndex = partition(a, low, high);
        quicksort(a, low, pivotIndex - 1);
        quicksort(a, pivotIndex + 1, high);
    }
}
int main() {
    int a[10000];
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    // Generate random elements
    srand((unsigned)time(NULL));
    printf("Original elements:\n");
    for (int i = 0; i < n; i++) {
        a[i] = rand();
        printf("%d ", a[i]);
    }
    printf("\n\n");
    // Sort the array
    quicksort(a, 0, n - 1);
    // Print sorted array
    printf("After sorting:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n\n");
    // Print the number of basic operations
    printf("Number of basic operations = %d\n", count);
    return 0;
}
