#include "../algorithms/sort.h"

// Cocktail Shaker Sort (Bidirectional Bubble Sort)
void cocktail_sort(int *arr, int size) {
    if (size <= 1) return;

    int swapped = 1;
    int start = 0;
    int end = size - 1;

    while (swapped) {
        // Reset swapped flag for forward pass
        swapped = 0;
        // Forward pass (like bubble sort)
        for (int i = start; i < end; i++) {
            if (arr[i] > arr[i + 1]) {
                // Swap elements
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                swapped = 1;
            }
        }
        // If nothing moved, array is sorted
        if (!swapped) break;
        // Decrease end point for backward pass
        end--;
        // Reset swapped flag for backward pass
        swapped = 0;
        // Backward pass, from right to left
        for (int i = end - 1; i >= start; i--) {
            if (arr[i] > arr[i + 1]) {
                // Swap elements
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                swapped = 1;
            }
        }
        // Increase start point for next forward pass
        start++;
    }
}
//time complexity:
//worst: O(n^2)
//best: O(n) (if already sorted)
//average: O(n^2)
//space: O(1) in-place