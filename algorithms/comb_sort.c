#include "../algorithms/sort.h"
int get_next_gap(int gap) {
    // Shrink gap by shrink factor (commonly 1.3)
    gap = (gap * 10) / 13;
    // Gap should be at least 1
    if (gap < 1)
        return 1;
    return gap;
}
void comb_sort(int *arr, int size) {
    if (size <= 1) return;
    // Initialize gap as array size
    int gap = size;
    // Initialize swapped as true to make sure first iteration happens
    int swapped = 1;
    // Keep running while gap > 1 or if a swap occurred in last iteration
    while (gap > 1 || swapped) {
        // Find next gap
        gap = get_next_gap(gap);
        // Initialize swapped as false so that we can check if swap happened
        swapped = 0;
        // Compare all elements with current gap
        for (int i = 0; i < size - gap; i++) {
            if (arr[i] > arr[i + gap]) {
                // Swap
                int temp = arr[i];
                arr[i] = arr[i + gap];
                arr[i + gap] = temp;
                swapped = 1;
            }
        }
    }
}

//this sort improves on buble sort by eliminationg small values ("turtles") near the end of the list
//it starts with a large gap and shrinks it over time

//time complexity:
//worst: O(n^2)
//average: O(n log n)
//space: O(1)
//is not considered a stable sort