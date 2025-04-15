#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>
#include "algorithms/sort.h"

#define MAX_ELEMENTS 1000000
#define NUM_RUNS 10
#define NUM_SIZES 4
#define NUM_DATA_TYPES 4

int read_data(const char *filename, int *arr, int max_size) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error opening file: %s\n", filename);
        return 0;
    }
    int count = 0;
    while (count < max_size && fscanf(file, "%d", &arr[count]) == 1) {
        count++;
    }
    fclose(file);
    return count;
}

void copy_array(int *src, int *dest, int size) {
    for (int i = 0; i < size; i++) {
        dest[i] = src[i];
    }
}
int is_sorted(int *arr, int size) {
    for (int i = 1; i < size; i++) {
        if (arr[i] < arr[i-1]) {
            return 0;
        }
    }
    return 1;
}
long get_microseconds() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec * 1000000 + tv.tv_usec;
}
double run_sort_test(void (*sort_func)(int*, int), int *data, int size, int *success) {
    int *test_array = (int*)malloc(size * sizeof(int));
    if (!test_array) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    copy_array(data, test_array, size);
    long start_time = get_microseconds();
    sort_func(test_array, size);
    long end_time = get_microseconds();

    *success = is_sorted(test_array, size);

    double elapsed_time = (end_time - start_time) / 1000.0;

    free(test_array);
    return elapsed_time;
}

int main() {
    int *data = (int*)malloc(MAX_ELEMENTS * sizeof(int));
    if (!data) {
        printf("Failed to allocate memory for input data\n");
        return 1;
    }

    void (*sort_functions[12])(int*, int) = {

        merge_sort,
        heap_sort,
        bubble_sort,
        insertion_sort,
        selection_sort,
        quick_sort,

        library_sort,
        tim_sort,
        cocktail_sort,
        comb_sort,
        tournament_sort,
        intro_sort
    };

    const char *algorithm_names[12] = {
        "Merge Sort",
        "Heap Sort",
        "Bubble Sort",
        "Insertion Sort",
        "Selection Sort",
        "Quick Sort",
        "Library Sort",
        "Tim Sort",
        "Cocktail Shaker Sort",
        "Comb Sort",
        "Tournament Sort",
        "Introsort"
    };

    int sizes[NUM_SIZES] = {1000, 10000, 100000, 1000000};

    const char *data_types[NUM_DATA_TYPES] = {"random", "sorted", "reversed", "partial"};

    printf("Sorting Algorithm Performance Analysis\n");
    printf("======================================\n\n");

    // Open a file to save detailed results
    FILE *results_file = fopen("sorting_results.csv", "w");
    if (!results_file) {
        printf("Error opening results file\n");
        free(data);
        return 1;
    }

    fprintf(results_file, "Algorithm,Data Type,Size,Mean Time (ms)\n");

    for (int size_idx = 0; size_idx < NUM_SIZES; size_idx++) {
        int size = sizes[size_idx];

        printf("Testing with data size: %d\n", size);
        printf("----------------------------\n");

        for (int type_idx = 0; type_idx < NUM_DATA_TYPES; type_idx++) {
            const char *data_type = data_types[type_idx];
e
            char filename[100];
            sprintf(filename, "data/%s_%d.txt", data_type, size);

            printf("Dataset: %s\n", filename);
            int num_elements = read_data(filename, data, size);
            if (num_elements == 0) {
                printf("Failed to read data or empty file\n");
                continue;
            }
            printf("Elements read: %d\n", num_elements);

            for (int algo_idx = 0; algo_idx < 12; algo_idx++) {
                double total_time = 0.0;
                int success = 1;

                // if (size > 10000 && (algo_idx == 2 || algo_idx == 3 || algo_idx == 4)) {
                //     printf("Skipping %s for large dataset (too slow)\n", algorithm_names[algo_idx]);
                //     fprintf(results_file, "%s,%s,%d,SKIPPED\n",
                //             algorithm_names[algo_idx], data_type, size);
                //     continue;
                // }
                // if (size > 50000 && (algo_idx == 6 || algo_idx == 8 || algo_idx == 10)) {  // Library Sort, Cocktail Sort, Tournament
                //     printf("Skipping %s for very large dataset (too slow)\n", algorithm_names[algo_idx]);
                //     fprintf(results_file, "%s,%s,%d,SKIPPED\n",
                //             algorithm_names[algo_idx], data_type, size);
                //     continue;
                // }

                for (int run = 0; run < NUM_RUNS; run++) {
                    int run_success = 0;
                    double time = run_sort_test(sort_functions[algo_idx], data, num_elements, &run_success);

                    if (!run_success) {
                        success = 0;
                        printf("Warning: %s failed to correctly sort the data on run %d\n",
                               algorithm_names[algo_idx], run + 1);
                    }
                    total_time += time;
                }
                double mean_time = total_time / NUM_RUNS;

                printf("  %s: %.2f ms %s\n", algorithm_names[algo_idx], mean_time,
                       success ? "" : "(FAILED!)");

                fprintf(results_file, "%s,%s,%d,%.2f\n",
                        algorithm_names[algo_idx], data_type, size, mean_time);
            }
            printf("\n");
        }
        printf("\n");
    }
    fclose(results_file);
    free(data);
    printf("Analysis complete! Detailed results saved to sorting_results.csv\n");
    return 0;
}