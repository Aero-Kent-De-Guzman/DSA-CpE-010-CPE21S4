#include<iostream>

const size_t maxCap= 100;
char stack[maxCap]; //stack with max of 100 elements
char top = -1, i, newData, topChar;
int Errors = 0;
bool open;

void push();
void pop();
void Top();
void Display();
bool isEmpty();

int main(){
    int choice;
    std::cout << "Reminder, operations are reversed!\nEnter number of max elements for new stack: ";
    std::cin >> i;
    
    while(true){
        std::cout << "Stack Operations: " << std::endl;
        std::cout << "1. PUSH, 2. POP, 3. TOP, 4. isEMPTY, 5. DISPLAY" << std::endl;
        std::cin >> choice;
    
        switch(choice){
            case 1: push();
                break;
            case 2: pop();
                break;
            case 3: Top();
                break;
            case 4: std::cout << isEmpty() << std::endl;
                break;
            case 5: Display();
                break;    
            default: std::cout << "Invalid Choice." << std::endl;
                break;
        }
    }
    
    return 0;
}

bool isEmpty(){
    if(top==-1) return true;
    return false;
}

void push(){
    bool charOpener = (newData == ')' || newData == ']' || newData == '}');
    bool charCloser = (newData == '(' || newData == '[' || newData == '{');

    //check if full -> if yes, return error
    if(top == i-1){
        std::cout << "Stack Overflow." << std::endl;
        return;
    }
    
    std::cout << "New Value: " << std::endl;
    std::cin >> newData;
    stack[++top] = newData;
    
    if (charOpener) {
        std::cout << "Opener Delimiter Noted" << std::endl;
        open = 1;
        topChar = newData;
    } else if (charCloser) {
        if (open != 1) {
            std::cout << "ERROR! Unmatched closing delimiter detected!" << std::endl;
            return;
        }
        if ((topChar == ')' && newData == '(') ||
            (topChar == ']' && newData == '[') ||
            (topChar == '}' && newData == '{')) 
        {
            std::cout << "Closing Delimiter Noted" << std::endl;
        }
    }
}

void pop(){
    //check if empty -> if yes, return error
    if(isEmpty()){
        std::cout << "Stack Underflow." << std::endl;
        return;
    }
    
    //display the top value
    std::cout << "Popping: " << stack[top];
    //decrement top value from stack
    top--;
}

void Top(){
    if(isEmpty()) {
        std::cout << "Stack is Empty." << std::endl;
        return;
    }
    
    std::cout << "The element on the top of the stack is " << stack[top] << std::endl;
}

void Display() {
    int errorCount = 0;
    char topChar = 0;
    bool openDelimiter = false;

    if (isEmpty()) {
        std::cout << "Stack is Empty." << std::endl;
        return;
    }

    std::cout << "Stack contents: ";
    for (int i = top; i >= 0; i--) {
        std::cout << stack[i] << ' ';
    }
    std::cout << std::endl;

    for (int i = 0; i <= top; i++) {
        char currentChar = stack[i];

        bool charOpener = (currentChar == '(' ||
                           currentChar == '[' ||
                           currentChar == '{');
        bool charCloser = (currentChar == ')' ||
                           currentChar == ']' ||
                           currentChar == '}');

        if (charOpener) {
            std::cout << "Opener Delimiter Noted: " << currentChar << std::endl;
            topChar = currentChar;
            openDelimiter = true;
        } else if (charCloser) {
            if (!openDelimiter) {
                std::cout << "ERROR 111! Closing Delimiter detected without Opener!" << std::endl;
                errorCount++;
            }

            if ((topChar == '(' && currentChar == ')') ||
                (topChar == '[' && currentChar == ']') ||
                (topChar == '{' && currentChar == '}')) {
                std::cout << "Closing Delimiter Noted: " << currentChar << std::endl;
                openDelimiter = false;
                topChar = 0;
            } else {
                std::cout << "ERROR 121! Mismatched closing delimiter!" << std::endl;
                errorCount++;
            }
        }
    }

    if (openDelimiter) {
        std::cout << "ERROR 131! Multiple Opener Delimiter detected without Closer!" << std::endl;
        errorCount++;
    }
    std::cout << "Total Errors: " << errorCount << std::endl;
}