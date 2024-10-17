#include <iostream>
#include <cstdlib>
#include "algorithm.h"

const int max_size = 100;

int generateRand(int arr[] ,int max) {
    for(int i = 0; i < max; i++){
        arr[i] = rand() % 100;
    }
    return *arr;
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
    
    // Bubble Sort Algorithm

    std::cout << "Original Dataset 1 : " << std::endl;
    generateRand(set1, max_size);
    showSet(set1, max_size);

    std::cout << "\n\nSorted Dataset 1 using BubbleSort : " << std::endl;
    bubbleSort(set1, max_size);
    showSet(set1, max_size);

    // Selection Sort Algorithm

    std::cout << "\n\nOriginal Dataset 2 : " << std::endl;
    generateRand(set2, max_size);
    showSet(set2, max_size);
  
    std::cout << "\n\nSorted Dataset 2 using Selection Sort : " << std::endl;
    selectionSort(set2, max_size);
    showSet(set2, max_size);

    // Insertion Sort Algorithm

    std::cout << "\n\nOriginal Dataset 3 : " << std::endl;
    generateRand(set3, max_size);
    showSet(set3, max_size);

    std::cout << "\n\nSorted Dataset 3 using Insertion Sort : " << std::endl;
    selectionSort(set3, max_size);
    showSet(set3, max_size);

    return 0;
}