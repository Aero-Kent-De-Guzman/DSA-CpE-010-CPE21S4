#include <iostream>
#include <cstdlib> // for generating random integers
#include <time.h> // will be used for our seeding function
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

    // LINEAR SEARCH
    std::cout << "Please Insert a value to locate : ";
    std::cin >> x;
    linearSearch(dataset,max_size,x);

    //create linked list for linear search
    Node<char> *name1 = new_node('A');
    Node<char> *name2 = new_node('E');
    Node<char> *name3 = new_node('R');
    Node<char> *name4 = new_node('O');

    //linked list
    Node<char> *head = name1;
    name1->next = name2;
    name2->next = name3;
    name3->next = name4;
    name4->next = NULL;

    // LINEAR SEARCH with Linked List
    std::cout << "First Name : ";
    displayLL(head);
    std::cout << "\nPlease Insert a char to locate : ";
    std::cin >> y;
    linearLS(head, y);
}