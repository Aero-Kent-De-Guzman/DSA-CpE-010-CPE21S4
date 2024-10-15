#include <iostream>
#include <cstdlib> // for generating random integers
#include <time.h> // will be used for our seeding function
#include <algorithm> // Contains the sort function to make sorting the list easier...
#include "searching.h"
#include "nodes.h"

const int max_size = 50;

int main()
{
    //generate random values
    int dataset[max_size];
    int x;
    char y;

    srand(time(0));
    for(int i = 0; i < max_size; i++){
        dataset[i] = rand();
    }

    //show your datasets content
    std::cout << "Current Dataset : " << std::endl;
    for(int i = 0; i < max_size; i++){
        std::cout << dataset[i] << " ";
    }
    std::cout << std::endl;

    // BINARY SEARCH
    std::sort(dataset, dataset + max_size);
    std::cout << "\nSorted Dataset: " << std::endl;
    for(int i = 0; i < max_size; i++) {
        std::cout << dataset[i] << " ";
    }

    std::cout << std::endl;
    std::cout << "Please Insert a value to locate : ";
    std::cin >> x;
    binarySearch(dataset,max_size,x);

    // Create linked list for binary search
    char choice = 'y';
    int count = 0; 
    int newData;
    Node<int> *temp = nullptr;
    Node<int> *head = nullptr;

    while (choice != 'n') {
        std::cout << "Enter data: ";
        std::cin >> newData;

        Node<int> *node = new_node(newData);
        node->next = nullptr;

        if (count == 0) {
            head = node;
            std::cout << "Successfully added " << head->data << " to the list.\n";
        } else {
            temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = node;
            std::cout << "Successfully added " << node->data << " to the list.\n";
        }
        count++;

        std::cout << "Continue? (y/n): ";
        std::cin >> choice;

        if (choice == 'n') {
            break;
        } else if (choice != 'y') {
            std::cout << "Invalid input. Please enter 'y' or 'n'.\n";
        }
    }

    Node<int> *currNode = head;
    std::cout << "Current List: ";
    while (currNode != nullptr) {
        std::cout << currNode->data << " ";
        currNode = currNode->next;
    }
    std::cout << std::endl;

    std::cout << "Please insert a value to locate in the linked list: ";
    std::cin >> x;
    binaryLS(head, x);

    return 0;
}