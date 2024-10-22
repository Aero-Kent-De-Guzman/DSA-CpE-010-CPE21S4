#include <iostream>
#include <cstdlib>
#include "algorithm.h"

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
    int set1[max_size];
    int set2[max_size];
    int set3[max_size];

    // Shell Sort
    std::cout << "\nArray 1 original values" << std::endl;
    genRand(set1, max_size);
    showSet(set1, max_size);

    std::cout << std::endl;
    std::cout << "\nArray 1 Shell Sorted" << std::endl;    
    shellSort(set1, max_size);
    showSet(set1, max_size);
    
    std::cout << std::endl;
    // Merge Sort
    std::cout << "\nArray 2 original values" << std::endl;
    genRand(set2, max_size);
    showSet(set2, max_size);

    std::cout << std::endl;
    std::cout << "\nArray 2 Merge Sorted" << std::endl;
    MergeSort(set2, 0, max_size);
    showSet(set2, max_size);

    std::cout << std::endl;    
    // Quick Sort
    std::cout << "\nArray 3 original values" << std::endl;    
    genRand(set3, max_size);
    showSet(set3, max_size);

    std::cout << std::endl;
    std::cout << "\nArray 3 Quick Sorted" << std::endl;    
    quicksort(set3, 0, max_size);
    showSet(set3, max_size);

    return 0;
}