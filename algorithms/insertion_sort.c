#include "../algorithms/sort.h"

void insertion_sort(int *arr, int size) {
    if (size <= 1) return;

    int i, key, j;
    for (i = 1; i < size; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

//core idea is to pick an element, then insert that element into a sorted part of the array
//works by building a sorted array one element at a time
//starts from the second element of the given array

//time compexity:
// worst: O(n^2)
//best: O(n)