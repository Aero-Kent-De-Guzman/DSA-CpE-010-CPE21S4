#ifndef SUPPLEMENTARY_H
#define SUPPLEMENTARY_H
#include <iostream>
#include <algorithm>

void merge_modified(int arr[], int left[], int leftSize, int right[], int rightSize) {
    int int1 = 0, int2 = 0, int3 = 0;
    while (int1 < leftSize && int2 < rightSize) {
        if (left[int1] <= right[int2]) {
            arr[int3++] = left[int1++];
        } else {
            arr[int3++] = right[int2++];
        }
    }
    while (int1 < leftSize) {
        arr[int3++] = left[int1++];
    }
    while (int2 < rightSize) {
        arr[int3++] = right[int2++];
    }
}

void MergeSort_modified(int array[], int left, int right) {
    if (left >= right) {
        return;
    }
    int mid = left + (right - left) / 2;
    MergeSort_modified(array, left, mid);
    MergeSort_modified(array, mid + 1, right);

    int leftArr[mid - left + 1], rightArr[right - mid];
    for (int i = 0; i <= mid - left; i++) {
        leftArr[i] = array[left + i];
    }
    for (int i = 0; i < right - mid; i++) {
        rightArr[i] = array[mid + 1 + i];
    }
    merge_modified(array, leftArr, mid - left + 1, rightArr, right - mid);
}

int partition_modified(int array[], int low, int high) {
    int pivot = array[high];
    int x = low - 1;
    for (int i = low; i < high; i++) {
        if (array[i] < pivot) {
            x++;
            std::swap(array[x], array[i]);
        }
    }
    std::swap(array[x + 1], array[high]);
    return x + 1;
}

void quicksort_mergesort(int array[], int low, int high) {
    if (low < high) {
        int pivot = partition_modified(array, low, high);
        MergeSort_modified(array, low, pivot - 1);
        MergeSort_modified(array, pivot + 1, high);
    }
}

// QUICK SORT from algorithm.h

int partition(int array[], int low, int high) {
    int pivot = array[high];
    int x = low - 1;
    for (int i = low; i < high; i++) {
        if (array[i] < pivot) {
            x++;
            std::swap(array[x], array[i]);
        }
    }
    std::swap(array[x + 1], array[high]);
    return x + 1;
}

void quicksort(int array[], int low, int high) {
    if (low < high) {
        int pivot = partition(array, low, high);
        quicksort(array, low, pivot - 1);
        quicksort(array, pivot + 1, high);
    }
}

#endif