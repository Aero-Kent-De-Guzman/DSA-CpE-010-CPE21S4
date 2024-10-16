#ifndef SEARCHING_H
#define SEARCHING_H
#include <iostream>
#include "nodes.h"

void linearSearch(int dataset[], int x, int datavalue) {
    for (int i = 0; i < x; i++) {
        if (dataset[i] == datavalue) {
            std::cout << "Searching is Successful! Item " << datavalue << " found at index " << i << std::endl;
            return;
        }
    }
    std::cout << "Searching is Unsuccessful. Item not found..." << std::endl;
}

void linearIntSearch(int dataset[], int x, int datavalue) {
    int count = 1;
    for (int i = 0; i < x; i++) {
        count++;
        if (dataset[i] == datavalue) {
            std::cout << "Searching is Successful! Item " << datavalue << " found at index " << i << std::endl;
            return;
        }
    }
    std::cout << "Searching is Unsuccessful. Item not found..." << std::endl;
}

void linearIntSearch_End(int dataset[], int x, int datavalue) {
    int count = 1, instances = 0;
    bool indentifier = 1;
    indentifier = 0;
    for (int i = 0; i < x; i++) {
        count++;
        if (dataset[i] == datavalue) {
            std::cout << "Searching is Successful! Item " << datavalue << " found at index " << i << std::endl;
            instances++;
            indentifier = 1;
        }
    }
    
    if (indentifier == 1) {
        std::cout << datavalue << " was repeated " << instances << " times" << std::endl;
        return;
    }

    std::cout << "Searching is Unsuccessful. Item not found..." << std::endl;
}

Node<char>* linearLS(Node<char> *head, char LLdata) {
    while (head != NULL) {
        if (head -> data == LLdata) {
            std::cout << LLdata << " was found. Searching is Successful!" << std::endl;
            return head;
        }
        head = head->next;
    }
    std::cout << "\nSearching is Unsuccessful. Item not found..." << std::endl;
    return NULL;
}

Node<int>* linearIntLS(Node<int> *head, int LLdata) {
    int count = 1;
    while (head != NULL) {
        if (head -> data == LLdata) {
            std::cout << LLdata << " was found. Searching is Successful!" << std::endl;
            std::cout << "It took a total amount of " << count << " to find it." << std::endl;
            return head;
        }
        count++;
        head = head->next;
    }
    std::cout << "\nSearching is Unsuccessful. Item not found..." << std::endl;
    return NULL;
}

Node<int>* linearIntLS_End(Node<int> *head, int LLdata) {
    int count = 1, instances = 0;
    bool indentifier = 1;
    indentifier = 0;
    while (head != NULL) {
        if (head -> data == LLdata) {
            std::cout << LLdata << " was found. Searching is Successful!" << std::endl;
            instances++;
            indentifier = 1;
        }
        count++;
        head = head->next;
    }

    if (indentifier == 1) {
        std::cout << LLdata << " was repeated " << instances << " times" << std::endl;
        return head;
    }

    std::cout << "\nSearching is Unsuccessful. Item not found..." << std::endl;
    return NULL;
}

void displayLL(Node<char> *head) {
    while (head != NULL) {
        std::cout << head -> data << ' ';
        head = head -> next;
    }
}

void displayIntLL(Node<int> *head) {
    while (head != NULL) {
        std::cout << head -> data << ' ';
        head = head -> next;
    }
}

void binarySearch(int arr[], int n, int no) {
    int low = 0, up = n - 1;
    
    while (low <= up) {
        int mid = (low + up) / 2;
        
        if (arr[mid] == no) {
            std::cout << "Search element is found!" << std::endl;
            return;
        } 
        else if (no < arr[mid]) {
            up = mid - 1;
        } 
        else {
            low = mid + 1;
        }
    }
    
    std::cout << "Search element is not found." << std::endl;
}

void binarySearch_Modified(int arr[], int n, int no) {
    int low = 0, up = n - 1;
    int count = 0;
    
    while (low <= up) {
        count++;
        int mid = (low + up) / 2;
        
        if (arr[mid] == no) {
            std::cout << "Search value detected!" << std::endl;
            std::cout << "It took a total of " << count << " to find it." << std::endl;
            return;
        } 
        else if (no < arr[mid]) {
            up = mid - 1;
        } 
        else {
            low = mid + 1;
        }
    }
    
    std::cout << "Search value it not found." << std::endl;
}

void binarySearch_Recursive(int arr[], int low, int up, int no, int &count) {
    if (low > up) {
        std::cout << "Search value is not found." << std::endl;
        return;
    }

    count++;
    int mid = (low + up) / 2;

    if (arr[mid] == no) {
        std::cout << "Search value detected!" << std::endl;
        std::cout << "It took a total of " << count << " comparisons to find it." << std::endl;
        return;
    } 
    else if (no < arr[mid]) {
        binarySearch_Recursive(arr, low, mid - 1, no, count);
    } 
    else {
        binarySearch_Recursive(arr, mid + 1, up, no, count);
    }
}

Node<int>* getMiddle(Node<int>* head, Node<int>* tail) {
    if (head == nullptr) {
        return nullptr;
    }

    Node<int>* slow = head;
    Node<int>* fast = head;

    while (fast != tail && fast->next != tail) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    return slow;
}

Node<int>* binaryLS(Node<int>* list, int intdata) {
    Node<int>* head = list;
    Node<int>* tail = nullptr;

    while (head != tail) {
        Node<int>* mid = getMiddle(head, tail);

        if (mid->data == intdata) {
            std::cout << "The data was found: " << mid->data << std::endl;
            return mid;
        } else if (mid->data > intdata) {
            tail = mid;
        } else {
            head = mid->next;
        }
    }

    std::cout << "Input int data was not in the list..." << std::endl;
    return nullptr;
}

#endif