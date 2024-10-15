#include <iostream>
#include <cstdlib>
#include <time.h>
#include "searching.h"
#include "nodes.h"

// Problem 1. Suppose you are doing a sequential search of the list [15, 18, 2, 19, 18, 0, 8, 14, 19, 14]. Utilizing
// both a linked list and an array approach to the list, use sequential search and identify how many comparisons
// would be necessary to find the key ‘18’?

// Problem 2. Modify your sequential search algorithm so that it returns the count of repeating instances for a
// given search element ‘k’. Test on the same list given in problem 1. 

int main() {
    int list[] = {15, 18, 2, 19, 18, 0, 8, 14, 19, 14};
    int listSize, x;
    listSize = sizeof(list) / sizeof(list[0]);
    
    std::cout << "Current Dataset : " << std::endl;
    for(int i = 0; i < listSize; i++){
        std::cout << list[i] << " ";
    }
    std::cout << std::endl;
    
    // ARRAY
    std::cout << "Please Insert a value to locate : ";
    std::cin >> x;
    linearIntSearch_End(list, listSize, x);

    // LINKED LIST
    Node<int> *int1 = new_node(15);
    Node<int> *int2 = new_node(18);
    Node<int> *int3 = new_node(2);
    Node<int> *int4 = new_node(19);
    Node<int> *int5 = new_node(18);
    Node<int> *int6 = new_node(0);
    Node<int> *int7 = new_node(8);
    Node<int> *int8 = new_node(14);
    Node<int> *int9 = new_node(19);
    Node<int> *int10 = new_node(14);

    //linked list
    Node<int> *head = int1;
    int1->next = int2;
    int2->next = int3;
    int3->next = int4;
    int4->next = int5;
    int5->next = int6;
    int6->next = int7;
    int7->next = int8;
    int8->next = int9;
    int9->next = int10;
    int10->next = NULL;


    // LINEAR SEARCH with Linked List
    displayIntLL(head);
    std::cout << "\nPlease insert the int to locate : ";
    std::cin >> x;
    linearIntLS_End(head, x);

    return 0;
}