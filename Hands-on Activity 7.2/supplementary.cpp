#include <iostream>
#include <cstdlib>
#include "supplementary.h"

const int max_size = 100;

void genRand(int arr[], int max) {
    for(int i = 0; i < max; i++) {
        arr[i] = (rand() % 5000) + 1;
    }
}

void showSet(int arr[], int max) {
    for(int i = 0; i < max; i++){
        std::cout << arr[i] << " ";
    }
}

int main() {

    // PROBLEM 1
    // Can we sort the left sub list and right sub list from the
    // partition method in quick sort using other sorting
    // algorithms? Demonstrate an example.

    int arrayOne[max_size];
    std::cout << "Original Randomized Array One : " << std::endl;
    genRand(arrayOne, max_size);
    showSet(arrayOne, max_size);
    std::cout << "\n\nSorted using quicksort & mergesort combination: " << std::endl;
    quicksort_mergesort(arrayOne, 0, max_size - 1);
    showSet(arrayOne, max_size);

    // PROBLEM 2
    // Suppose we have an array which consists of {4, 34, 29, 48,
    // 53, 87, 12, 30, 44, 25, 93, 67, 43, 19, 74}. What sorting 
    // algorithm will give you the fastest time performance? Why 
    // can merge sort and quick sort have O(N • log N) for their 
    // time complexity?

    int arrayTwo[] = {4, 34, 29, 48, 53, 87, 12, 30, 44, 25, 93, 67, 43, 19, 74};
    int totalSize = sizeof(arrayTwo) / sizeof(arrayTwo[0]);
    std::cout << "\n\nOriginal Randomized Array Two : " << std::endl;
    showSet(arrayTwo, totalSize);
    std::cout << "\n\nSorted Array Two using QuickSort: " << std::endl;
    quicksort(arrayTwo, 0, totalSize);
    showSet(arrayTwo, totalSize);

    return 0;
}