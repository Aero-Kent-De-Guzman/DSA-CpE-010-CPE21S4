#include <iostream>

class Node
{
    public:
        std::string name;
        Node* next;
};

void display(Node* head)
{
    if (head == NULL) {
        std::cout << "The Queue is currently EMPTY!" << std::endl;
        return;
    }
    
    while (head != NULL)
    {
        std::cout << head->name << std::endl;
        head = head->next;
    }
    std::cout << std::endl;
}

Node* push(Node* prevNode, std::string addedData)
{
    Node* newPtr = new Node;
    newPtr->name = addedData;
    newPtr->next = NULL;

    if (prevNode == NULL) {
        return newPtr;
    }

    prevNode->next = newPtr;
    return newPtr;
}

Node* pop(Node* head)
{
    if (head == NULL)
    {
        std::cout << "The Queue is currently EMPTY!" << std::endl;
        return NULL;
    }

    Node* temp = head;
    std::cout << "Popping the value : " << head->name << std::endl;
    head = head->next;
    delete temp;

    return head;
}

int main()
{
    Node* s1 = new Node;
    Node* s2 = new Node;
    Node* s3 = new Node;
    Node* head = s1;

    s1->next = s2;
    s2->next = s3;

    s1->name = "Monty C. Python";
    s2->name = "Von E. Chavalier";
    s3->name = "Ranni T. Thirty";

    s3 = push(s3, "Ryan Von Gasoline");
    display(head);

    head = pop(head);
    display(head);
    
    head = pop(head);
    display(head);

    head = pop(head);
    display(head);

    head = pop(head);
    display(head);
    
    std::cout << std::endl;

    head = push(NULL, "Rodrigo L. Emmanuel");
    display(head);

    return 0;
}