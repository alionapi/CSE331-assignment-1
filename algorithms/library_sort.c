#include "../algorithms/sort.h"
#include <stdlib.h>
#include <string.h>

void library_sort(int *arr, int size) {
    if (size <= 1) return;

    double epsilon = 1.0;
    int capacity = (int)((1 + epsilon) * size);

    int *sorted = (int*)malloc(capacity * sizeof(int));
    if (!sorted) return;

    for (int i = 0; i < capacity; i++) {
        sorted[i] = -1;
    }

    sorted[0] = arr[0];
    int num_sorted = 1;

    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = num_sorted - 1;

        while (j >= 0 && sorted[j] > key) {
            j--;
        }
        j++;

        int slot = j;
        while (slot < capacity && sorted[slot] != -1) {
            slot++;
        }
        if (slot >= capacity) {
            int *new_sorted = (int*)malloc(capacity * sizeof(int));
            if (!new_sorted) {
                free(sorted);
                return;
            }

            for (int k = 0; k < capacity; k++) {
                new_sorted[k] = -1;
            }
            int pos = 0;
            for (int k = 0; k < capacity; k++) {
                if (sorted[k] != -1) {
                    new_sorted[pos] = sorted[k];
                    pos += 2;
                    if (pos >= capacity) pos = 1;
                }
            }

            free(sorted);
            sorted = new_sorted;
            j = 0;
            while (j < capacity && sorted[j] != -1 && sorted[j] < key) {
                j++;
            }
            slot = j;
            while (slot < capacity && sorted[slot] != -1) {
                slot++;
            }

            if (slot >= capacity) {
                for (int k = i; k < size; k++) {
                    insertion_sort(arr, size);
                    free(sorted);
                    return;
                }
            }
        }
        for (int k = slot; k > j; k--) {
            sorted[k] = sorted[k-1];
        }
        sorted[j] = key;
        num_sorted++;
    }
    int index = 0;
    for (int i = 0; i < capacity && index < size; i++) {
        if (sorted[i] != -1) {
            arr[index++] = sorted[i];
        }
    }

    free(sorted);
}

//the core idea is that it is a variant of insertion sort with gaps between elements
//it mimics how human insert items into sorted shelves
//leaving room for future inserts

//time complexity:
//worst: O(n^2)
//average: O(n log n)
//space: O(n) extra space is for holding gaps