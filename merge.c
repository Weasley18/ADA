#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int count = 0;
// Merge two sorted subarrays a[low..mid] and a[mid+1..high]
void merge(int a[], int low, int mid, int high) {
    int i = low;
    int j = mid + 1;
    int k = 0;
    int temp[10000];
    // Merge elements into temp[]
    while (i <= mid && j <= high) {
        count++;
        if (a[i] < a[j]) {
            temp[k++] = a[i++];
        } else {
            temp[k++] = a[j++];
        }
    }
    // Copy any remaining elements from left half
    while (i <= mid) {
        temp[k++] = a[i++];
    }
    // Copy any remaining elements from right half
    while (j <= high) {
        temp[k++] = a[j++];
    }
    // Copy merged elements back into original array
    for (i = low, j = 0; j < k; i++, j++) {
        a[i] = temp[j];
    }
}
// Recursive merge sort
void merge_sort(int a[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        merge_sort(a, low, mid);
        merge_sort(a, mid + 1, high);
        merge(a, low, mid, high);
    }
}
int main() {
    int a[10000];
    int n, i;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    srand((unsigned)time(NULL));
    printf("Original elements:\n");
    for (i = 0; i < n; i++) {
        a[i] = rand();
        printf("%d ", a[i]);
    }
    printf("\n\n");
    merge_sort(a, 0, n - 1);
    printf("After sorting:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n\n");
    printf("Number of basic operations = %d\n", count);
    return 0;
}
