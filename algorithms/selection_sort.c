#include "../algorithms/sort.h"

void selection_sort(int *arr, int size) {
    if (size <= 1) return;

    int i, j, min_idx;
    for (i = 0; i < size - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < size; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            int temp = arr[min_idx];
            arr[min_idx] = arr[i];
            arr[i] = temp;
        }
    }
}

// core idea is to repeatedly find the smallest element and put it in the front

//avg time complexity is O(n^2)