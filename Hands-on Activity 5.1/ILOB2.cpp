#include <iostream>
#include <string>

class Node {
public:
    std::string data;
    Node* next;
};

class ARRAY {
private:
    std::string name;
    Node* head;

public:
    // Constructor
    ARRAY(std::string firstName) : name(firstName), head(nullptr) {
        std::cout << "Constructor Called for " << name << std::endl;
    }

    // Destructor
    ~ARRAY() {
        std::cout << "Destructor Called for " << name << std::endl;
        Clear();
    }

    void Empty() {
        if (head == nullptr) {
            std::cout << "The Queue is currently EMPTY!" << std::endl;
            return;
        }

        std::cout << "Queue contents: " << std::endl;
        Node* current = head;
        while (current != nullptr) {
            std::cout << current -> data << std::endl;
            current = current -> next;
        }
        std::cout << std::endl;
    }

    void Size() {
        int size = 0;
        Node* current = head;
        while (current != nullptr) {
            size++;
            current = current -> next;
        }
        std::cout << "The size of the Array-Queue is: " << size << std::endl;
    }

    void Enqueue(std::string addedData) {
        Node* newPtr = new Node;
        newPtr->data = addedData;
        newPtr->next = nullptr;

        if (head == nullptr) {
            head = newPtr;
            std::cout << "\tAdded in the entry: " << addedData << std::endl;
        } else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newPtr;
            std::cout << "\tAdded in the entry: " << addedData << std::endl;
        }
    }

    void Dequeue() {
        if (head == nullptr) {
            std::cout << "The Array-Queue is currently EMPTY!" << std::endl;
            return;
        }

        Node* temp = head;
        std::cout << "\nRemoving the last name entry: " << head->data << std::endl;
        head = head->next;
        delete temp;
    }

    void Clear() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        std::cout << "The Queue is now EMPTY!" << std::endl;
    }

    void Front() {
        if (head == nullptr) {
            std::cout << "There were no name entry detected..." << std::endl;
            return;
        }
        std::cout << "Front of the Array-Queue: " << head -> data << std::endl;
    }

    void Back() {
        if (head == nullptr) {
            std::cout << "There were no name entry detected..." << std::endl;
            return;
        }
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        std::cout << "Back of the Array-Queue: " << current -> data << std::endl;
    }
};

int main() {
    ARRAY nameList[] = {ARRAY("List 1"), ARRAY("List 2"), ARRAY("List 3")};

    nameList[0].Enqueue("John");
    nameList[0].Enqueue("Peter");
    nameList[0].Enqueue("Jackson");

    nameList[0].Size();
    nameList[0].Empty();
    nameList[0].Front();
    nameList[0].Back();

    nameList[0].Dequeue();
    nameList[0].Size();
    nameList[0].Empty();
    nameList[0].Front();
    nameList[0].Back();

    nameList[0].Dequeue();
    nameList[0].Size();
    nameList[0].Empty();
    nameList[0].Front();
    nameList[0].Back();

    nameList[0].Enqueue("Emmanuel");
    nameList[0].Size();
    nameList[0].Empty();
    nameList[0].Front();
    nameList[0].Back();

    nameList[0].Dequeue();
    nameList[0].Size();
    nameList[0].Empty();
    nameList[0].Front();
    nameList[0].Back();

    nameList[0].Dequeue();
    nameList[0].Size();
    nameList[0].Empty();
    nameList[0].Front();
    nameList[0].Back();

    return 0;
}