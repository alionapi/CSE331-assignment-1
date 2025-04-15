#include "../algorithms/sort.h"

int partition(int arr[], int low, int high) {
    int pivot = arr[high];

    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++; // increment index of smaller element
            // Swap elements at i and j
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return (i + 1);
}

void quick_sort_recursive(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quick_sort_recursive(arr, low, pi - 1);
        quick_sort_recursive(arr, pi + 1, high);
    }
}
void quick_sort(int *arr, int size) {
    if (size <= 1) return;
    quick_sort_recursive(arr, 0, size - 1);
}

//time complexity:
// worst: O(n^2)
// best: O(n log n)
// average: O(n log n)