#include<iostream>

class Node{
public:
    char data;
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
    char tempVal;
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
    char topChar = 0;
    Node *tempHead = head;
    Node *charDelimeter = NULL;
    Node *temp = charDelimeter;

    std::cout << "Stack contents: ";
    while (tempHead != NULL)
    {
        std::cout << tempHead->data;
        tempHead = tempHead->next;
    }
    std::cout << std::endl;

    tempHead = head;

    while (tempHead != NULL)
    {
        bool charOpener = (tempHead->data == '(' || 
                           tempHead->data == '[' || 
                           tempHead->data == '{');
        bool charCloser = (tempHead->data == ')' ||
                           tempHead->data == ']' ||
                           tempHead->data == '}');

        if (charOpener)
        {
            std::cout << "Opener Delimiter Noted: " << tempHead->data << std::endl;
            Node *newNode = new Node;
            newNode->data = tempHead->data;
            newNode->next = charDelimeter;
            charDelimeter = newNode;
        }
        else if (charCloser)
        {
            if (charDelimeter == NULL)
            {
                std::cout << "ERROR 111! Closing Delimiter detected without Opener!" << std::endl;
                return;
            }

            if ((charDelimeter->data == '(' && tempHead->data == ')') ||
                (charDelimeter->data == '[' && tempHead->data == ']') ||
                (charDelimeter->data == '{' && tempHead->data == '}'))
            {
                std::cout << "Closing Delimiter Noted: " << tempHead->data << std::endl;
                charDelimeter = charDelimeter->next;
                delete temp;
            }
            else
            {
                std::cout << "ERROR 121! Closing Delimiter detected without matching Opener!" << std::endl;
                return;
            }
        }
        tempHead = tempHead->next;
    }

    if (charDelimeter != NULL)
    {
        std::cout << "ERROR 131! Multiple Opener Delimiter detected without Closer!" << std::endl;
        while (charDelimeter != NULL)
        {
            Node *temp = charDelimeter;
            charDelimeter = charDelimeter->next;
            delete temp;
        }
    }
}


int main(){
    char x;
    while(x != ';')
    {
        std::cout << "Enter a Value | ; to exit" << std::endl;
        std::cin >> x;
        push(x);
    }
    pop();
    Display();
    return 0;
}