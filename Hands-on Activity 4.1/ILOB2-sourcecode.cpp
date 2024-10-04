#include<iostream>

class Node{
public:
    int data;
    Node *next;
};

Node *head=NULL,*tail=NULL;

void push(int newData){
    Node *newNode = new Node;
    newNode->data = newData;
    newNode->next = head;
    
    if(head==NULL){
        head = tail = newNode;
    } else {
        newNode->next = head;
        head = newNode;
    }
}

int pop(){
    int tempVal;
    Node *temp;
    if(head == NULL){
        head = tail = NULL;
        std::cout << "Stack Underflow." << std::endl;
        return -1;
    } else {
        temp = head;
        tempVal = temp->data;
        head = head->next;
        delete(temp);
        return tempVal;
    }
}

void Top(){
    if(head==NULL){
        std::cout << "Stack is Empty." << std::endl;
        return;
    } else {
        std::cout << "Top of Stack: " << head->data << std::endl;
    }
}

void Display()
{
    int tempVal;
    Node *temp;
    while(head != NULL)
    {
        std::cout << head->data << std::endl;
        temp = head;
        tempVal = temp->data;
        head = head->next;
        delete(temp);
    }
}

int main(){

    push(1);
    std::cout<<"After the first PUSH top of stack is :";
    Top();
    push(5);
    
    std::cout<<"\nAfter the second PUSH top of stack is :";
    Top();
    
    std::cout<<"\nDISPLAYING the current stack :\n";
    Display();
    
    pop();
    std::cout<<"\nAfter the first POP operation, top of stack is: ";
    Top();
    pop();
    
    std::cout<<"\nAfter the second POP operation, top of stack : ";
    Top();
    pop();
    
    std::cout<<"\nDISPLAYING the current stack :\n";
    Display();
    
    return 0;
}















