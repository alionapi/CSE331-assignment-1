#include "../algorithms/sort.h"
#include <stdlib.h>
#include <math.h>

// Simpler implementation of Introsort
// This avoids recursion depth issues and complex implementations

static void intro_insertion_sort(int arr[], int left, int right) {
    for (int i = left + 1; i <= right; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= left && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

static int intro_partition(int arr[], int low, int high) {
    int mid = low + (high - low) / 2;
    int pivot = arr[mid];

    int temp = arr[mid];
    arr[mid] = arr[high];
    arr[high] = temp;

    int i = low;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            // Swap arr[i] and arr[j]
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
        }
    }

    temp = arr[i];
    arr[i] = arr[high];
    arr[high] = temp;

    return i;
}
static void intro_heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        intro_heapify(arr, n, largest);
    }
}
static void intro_heap_sort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        intro_heapify(arr, n, i);

    // Extract elements one by one
    for (int i = n - 1; i > 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        intro_heapify(arr, i, 0);
    }
}

void intro_sort_helper(int arr[], int low, int high, int depth_limit) {

    while (high - low > 10) {
        if (depth_limit == 0) {

            intro_heap_sort(arr + low, high - low + 1);
            return;
        }

        depth_limit--;

        int pivot = intro_partition(arr, low, high);

        if (pivot - low < high - pivot) {
            intro_sort_helper(arr, low, pivot - 1, depth_limit);
            low = pivot + 1;
        } else {
            intro_sort_helper(arr, pivot + 1, high, depth_limit);
            high = pivot - 1;
        }
    }

    intro_insertion_sort(arr, low, high);
}

void intro_sort(int *arr, int size) {
    if (size <= 1) return;

    int max_depth = (int)(2 * log(size) / log(2));

    intro_sort_helper(arr, 0, size - 1, max_depth);
}

//the core idea is hybrid of quick, heap, insertion sorts
//it switches to heap sort if recursion goes too deep

//time complexity:
//worst: O(n log n)
//best: O(n log n)
// is not a stable sort