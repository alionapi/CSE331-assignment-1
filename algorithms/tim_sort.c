#include "../algorithms/sort.h"
#include <stdlib.h>
#include <string.h>

#define MIN_MERGE 32

int min_run_length(int n) {
    int r = 0;
    while (n >= MIN_MERGE) {
        r |= (n & 1);
        n >>= 1;
    }
    return n + r;
}
void insertion_sort_tim(int arr[], int left, int right) {
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
void merge_tim(int arr[], int l, int m, int r) {
    int len1 = m - l + 1, len2 = r - m;
    int *left = (int*)malloc(len1 * sizeof(int));
    int *right = (int*)malloc(len2 * sizeof(int));

    if (!left || !right) {
        if (left) free(left);
        if (right) free(right);
        return;
    }

    for (int i = 0; i < len1; i++)
        left[i] = arr[l + i];
    for (int i = 0; i < len2; i++)
        right[i] = arr[m + 1 + i];

    int i = 0, j = 0, k = l;
    while (i < len1 && j < len2) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }
    while (i < len1) {
        arr[k] = left[i];
        k++;
        i++;
    }
    while (j < len2) {
        arr[k] = right[j];
        k++;
        j++;
    }
    free(left);
    free(right);
}
void tim_sort(int *arr, int size) {
    if (size <= 1) return;
    int min_run = min_run_length(size);
    for (int i = 0; i < size; i += min_run) {
        insertion_sort_tim(arr, i, (i + min_run - 1 < size - 1) ? (i + min_run - 1) : (size - 1));
    }
    for (int run_size = min_run; run_size < size; run_size = 2 * run_size) {
        for (int left = 0; left < size; left += 2 * run_size) {
            int mid = left + run_size - 1;
            if (mid >= size - 1) break;

            int right = (left + 2 * run_size - 1 < size - 1) ? (left + 2 * run_size - 1) : (size - 1);

            // Merge sub array arr[left...mid] & arr[mid+1...right]
            merge_tim(arr, left, mid, right);
        }
    }
}

//the core idea is a hybrid of insertion and merge sorts

//time complexity
//worst: O(n log n)
//best: O(n)
//is known to be a stable sort