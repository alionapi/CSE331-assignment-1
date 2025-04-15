# CSE331-assignment-1
Overview

This repository contains implementations and analysis of 12 sorting algorithms as part of the CSE331 Introduction to Algorithms course assignment. The project explores both conventional and contemporary sorting methods, evaluating their performance across different input types and sizes.

Algorithms Implemented

Conventional Sorting Algorithms

Merge Sort: Divide-and-conquer algorithm with consistent O(n log n) performance
Heap Sort: In-place comparison-based sort using binary heap structure
Bubble Sort: Simple comparison sort with O(n²) time complexity
Insertion Sort: Builds sorted array one item at a time
Selection Sort: In-place comparison sort that selects minimum element in each pass
Quick Sort: Efficient divide-and-conquer algorithm with O(n log n) average case

Contemporary Sorting Algorithms

Library Sort: Gap-based variant of insertion sort with improved performance
Tim Sort: Hybrid algorithm combining merge sort and insertion sort
Cocktail Shaker Sort: Bidirectional variation of bubble sort
Comb Sort: Improvement over bubble sort using gap sequence
Tournament Sort: Tree-based selection algorithm
Introsort: Hybrid algorithm combining quicksort, heapsort, and insertion sort


Test Data
Four types of input data were generated and tested:

Random: Fully randomized values
Sorted: Strictly increasing order
Reverse Sorted: Strictly decreasing order
Partially Sorted: 80% sorted, 20% random shuffled

Input sizes range from 1,000 to 100,000 elements to test scaling behavior.
Key Findings

Introsort and Tim Sort consistently demonstrated superior performance across different input types
Classical O(n²) algorithms (Bubble, Insertion, Selection) performed adequately for small inputs but scaled poorly
Quick Sort excelled with random data but struggled with sorted/reversed inputs
Contemporary algorithms generally outperformed their conventional counterparts
Algorithm adaptivity to input characteristics proved more important than pure theoretical complexity

Performance Highlights

Fastest Overall: Introsort (0.07ms on 1000 random elements)
Best for Sorted Data: Insertion Sort, Bubble Sort (near instantaneous)
Most Consistent: Tim Sort, Merge Sort (reliable across all input types)
Most Scalable: Introsort, Quick Sort, Tim Sort (maintained reasonable performance at 100k elements)



C compiler (used CLion IDE)
Python 3.x for data generation
Standard libraries only (no external dependencies)
