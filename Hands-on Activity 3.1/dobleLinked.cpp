#include<iostream>
#include<utility>

class Node
{
    public:
        char data;
        Node *next;
        Node *prev;
};

// The function for the Linked List Traversal
void listTraversal(Node* n)
{
    while(n != nullptr)
    {
        std::cout << n->data;
        n = n -> next;
    }
    std::cout << std::endl;
}

// The function for the Insertion at Head
Node* InsertionAtHead(Node* head, char n) {
    Node *newHead = new Node;
    newHead -> data = n;
    newHead -> next = head;
    newHead -> prev = nullptr;
    
    if (head != nullptr) {
        head -> prev = newHead;
    }
    
    return newHead;
}

// The function for the Insertion at any part of the list
Node* InsertionAtAny(Node* head) {
    Node* current = head;
    Node* newNode = new Node;
    char x, n;
    std::cout << "Please enter a character to input: ";
    std::cin >> n;
    std::cout << "Please enter a character between the heads and tails: ";
    std::cin >> x;

    if (head == nullptr) {
        std::cout << "Previous node cannot be null." << std::endl;
        return head;
    }

    while (current != nullptr && current->data != x) {
        current = current->next;
    }

    if (current == nullptr) {
        std::cout << "Node with data '" << x << "' not found." << std::endl;
        delete newNode;
        return head;
    }

    newNode->data = n;
    newNode->next = current->next;
    newNode->prev = current;

    if (current->next != nullptr) {
        current->next->prev = newNode;
    }
    
    current->next = newNode;

    return head;
}

// The function for the Insertion at the end
Node* InsertionAtTails(Node* head) {
    char x, n;
    std::cout << "Please enter a character to input: ";
    std::cin >> n;
    std::cout << "Please enter a character which will place the new character after it: ";
    std::cin >> x;

    Node* newNode = new Node;
    newNode->data = n;
    newNode->next = nullptr;

    if (head == nullptr) {
        std::cout << "List is empty. Inserting as head." << std::endl;
        newNode->prev = nullptr;
        return newNode;
    }

    Node* current = head;
    while (current != nullptr && current->data != x) {
        current = current->next;
    }

    if (current == nullptr) {
        std::cout << "Node with data '" << x << "' not found. Insertion failed." << std::endl;
        delete newNode;
        return head;
    }

    newNode->next = current->next;
    newNode->prev = current;

    if (current->next != nullptr) {
        current->next->prev = newNode;
    }
    
    current->next = newNode;

    return head;
}

// The function to delete a node...
Node* NodeDeletion(Node* head) {
    char x;
    std::cout << "Please enter the character to delete: ";
    std::cin >> x;

    if (head == nullptr) {
        std::cout << "List is empty, nothing was changed..." << std::endl;
        return head;
    }

    if (head->data == x) {
        Node* temp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        }
        delete temp;
        return head;
    }

    Node* current = head;
    while (current != nullptr && current->data != x) {
        current = current->next;
    }

    if (current == nullptr) {
        std::cout << "Node with '" << x << "' was not found..." << std::endl;
        return head;
    }

    Node* temp = current;
    if (current->prev != nullptr) {
        current->prev->next = current->next;
    }
    if (current->next != nullptr) {
        current->next->prev = current->prev;
    }
    delete temp;

    return head;
}

int main()
{
  //step 1
  Node *head = new Node;
  Node *second = new Node;
  Node *third = new Node;
  Node *fourth = new Node;
  Node *fifth = new Node;
  Node *last = new Node;

  //step 2 omitted...
  
  //step 3
  head->data = 'C';
  head->next = second;

  second->data = 'P';
  second->next = third;

  third->data = 'E';
  third->next = fourth;

  fourth->data = '1';
  fourth->next = fifth;

  fifth->data = '0';
  fifth->next = last;
  
  //step 4
  last->data = '1';
  last->next = nullptr;
  
  std::cout << "List Traversal" << std::endl;
  listTraversal(head);

  std::cout << "\nInsertion at Head" << std::endl;
  listTraversal(head = InsertionAtHead(head,'G'));

  std::cout << "\nInsertion at any point" << std::endl;
  head = InsertionAtAny(head);
  listTraversal(head);

  std::cout << "\nInsertion at Tails" << std::endl;
  head = InsertionAtTails(head);
  listTraversal(head);

  std::cout << "\nDeletion of a Node" << std::endl;
  head = NodeDeletion(head);
  head = NodeDeletion(head);
  listTraversal(head);
}