#include "../algorithms/sort.h"
#include <stdlib.h>
#include <limits.h>

void tournament_sort(int *arr, int size) {
    if (size <= 1) return;
    int *temp = (int*)malloc(size * sizeof(int));
    if (!temp) return;
    int *result = (int*)malloc(size * sizeof(int));
    if (!result) {
        free(temp);
        return;
    }
    for (int i = 0; i < size; i++) {
        temp[i] = arr[i];
    }
    for (int i = 0; i < size; i++) {
        int min_idx = 0;
        for (int j = 1; j < size; j++) {
            if (temp[j] < temp[min_idx]) {
                min_idx = j;
            }
        }
        result[i] = temp[min_idx];
        temp[min_idx] = INT_MAX;
    }
    for (int i = 0; i < size; i++) {
        arr[i] = result[i];
    }
    free(temp);
    free(result);
}

//the core idea is it builds a tree where each node is the winner of a comparison between two children

//time complexity is: O(n log n)
//is not actually a stable short
//space: O(n)

// PSEUDOCSODE:
//build a binary tree comparing elements
//extract the winner (the smallest)
//rebuild the teree with remaining elements
//repeat until empty