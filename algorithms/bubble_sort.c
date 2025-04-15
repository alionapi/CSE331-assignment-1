#include "../algorithms/sort.h"

void bubble_sort(int *arr, int size) {
    if (size <= 1) return;
    int i, j;
    int swapped;
    for (i = 0; i < size - 1; i++) {
        swapped = 0;
        // Last i elements are already in place
        for (j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }
        // If no swapping occurred in this pass, array is sorted
        if (swapped == 0)
            break;
    }
}
//worst time complexity is O(n^2)
//best time complexity is O(n)
