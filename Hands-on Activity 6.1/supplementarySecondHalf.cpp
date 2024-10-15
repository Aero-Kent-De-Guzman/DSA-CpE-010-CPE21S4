#include <iostream>
#include <cstdlib> // for generating random integers
#include <time.h> // will be used for our seeding function
#include <algorithm> // Contains the sort function to make sorting the list easier...
#include "searching.h"
#include "nodes.h"

// Problem 3. Suppose you have the following sorted list [3, 5, 6, 8, 11, 12, 14, 15, 17, 18] and are using the
// binary search algorithm. If you wanted to find the key 8, draw a diagram that shows how the searching works
// per iteration of the algorithm. Prove that your drawing is correct by implementing the algorithm and showing a
// screenshot of the code and the output console. 

// Problem 4. Modify the binary search algorithm so that the algorithm becomes recursive. Using this new
// recursive binary search, implement a solution to the same problem for problem 3. 


int main() {
    int list[] = {3, 5, 6, 8, 11, 12, 14, 15, 17, 18};
    int listSize, x, low = 0, up, count = 0;
    listSize = sizeof(list) / sizeof(list[0]);
    up = listSize - 1;

    
    std::cout << "Current Dataset : " << std::endl;
    for(int i = 0; i < listSize; i++){
        std::cout << list[i] << " ";
    }
    std::cout << std::endl;
    
    std::cout << "Please Insert a value to locate : ";
    std::cin >> x;
    binarySearch_Modified(list, listSize, x);
    std::cout << "Please Insert a value to locate for recursive : ";
    std::cin >> x;
    binarySearch_Recursive(list, low, up, x, count);
}