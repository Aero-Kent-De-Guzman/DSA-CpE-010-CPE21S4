#include <iostream>

class Node
{
    public:
        std::string name;
        Node* next;
};

void display(Node* head)
{
    while (head != NULL)
    {
        std::cout << head -> name << std::endl;
        head = head -> next;
    }
    std::cout << std::endl;
}

Node* push(Node* prevNode, std::string addedData)
{
    Node* newPtr = new Node;
    Node* backPtr = prevNode;
    newPtr -> name = addedData;
    newPtr -> next = NULL;
    backPtr -> next = newPtr;
    backPtr = newPtr;
    return prevNode;
}

Node* pushNew(Node* prevNode, std::string addedData)
{
    Node* newPtr = new Node;
    Node* backPtr = prevNode;
    newPtr -> name = addedData;
    newPtr -> next = NULL;
    backPtr -> next = newPtr;
    backPtr = newPtr;
    return prevNode;
}

int main()
{
    Node* s1 = new Node;
    Node* s2 = new Node;
    Node* s3 = new Node;
    Node* head = s1;

    s1 -> next = s2;
    s2 -> next = s3;

    s1 -> name = "Monty C. Python";
    s2 -> name = "Von E. Chavalier";
    s3 -> name = "Ranni T. Thirty";

    
    // Inserting an item into a non-empty queue
    push(s3,"Ryan Von Gasoline");
    display(head);
    // Inserting an item into an empty queue
    
    return 0;
}
