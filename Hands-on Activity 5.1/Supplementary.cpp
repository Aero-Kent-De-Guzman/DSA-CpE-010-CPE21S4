#include <iostream>

class Node
{
    public:
        int data;
        Node* next;
};

class Job
{
    public:
        int page;
        int id;
        std::string username;
};

class Printer
{
  public:
    void showJob(Node* head)
    {
        if (head == NULL) {
            std::cout << "All of the jobs are now complete..." << std::endl;
            return;
        }

        while (head != NULL)
        {
            std::cout << head->data << std::endl;
            head = head->next;
        }
        std::cout << std::endl;
    }

    Node* addJob(Node* head, int addedData)
    {
        Node* newPtr = new Node;
        newPtr->data = addedData;
        newPtr->next = NULL;

        if (head == NULL) {
            return newPtr;
        }

        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newPtr;
        return head;
    }

    Node* doJob(Node* head)
    {
        if (head == NULL)
        {
            std::cout << "All of the jobs are now complete..." << std::endl;
            return NULL;
        }

        Node* temp = head;
        std::cout << "Doing current job user ID: " << head->data << std::endl;
        head = head->next;
        delete temp;

        return head;
    }
};

int main()
{
    Printer printer;
    Job user1, user2, user3, user4;
    Node* jobQueue = NULL;
    
    user1.username = "Monty C. Python";
    user1.id = 101;
    user1.page = 12;
    
    user2.username = "Von E. Chavalier";
    user2.id = 102;
    user2.page = 50;
    
    user3.username = "Ranni T. Thirty";
    user3.id = 103;
    user3.page = 33;
    
    user4.username = "Ryan V. Gasoline";
    user4.id = 104;
    user4.page = 24;
    
    std::cout << "\nEmployee 1 : \n" << std::endl;
    std::cout << " NAME: \t" << user1.username << std::endl;
    std::cout << " ID: \t" << user1.id << std::endl;
    std::cout << " PAGE: \t" << user1.page << std::endl;
    
    std::cout << "\nEmployee 2 : \n" << std::endl;
    std::cout << " NAME: \t" << user2.username << std::endl;
    std::cout << " ID: \t" << user2.id << std::endl;
    std::cout << " PAGE: \t" << user2.page << std::endl;
    
    std::cout << "\nEmployee 3 : \n" << std::endl;
    std::cout << " NAME: \t" << user3.username << std::endl;
    std::cout << " ID: \t" << user3.id << std::endl;
    std::cout << " PAGE: \t" << user3.page << std::endl;

    std::cout << "\nEmployee 4 : \n" << std::endl;
    std::cout << " NAME: \t" << user4.username << std::endl;
    std::cout << " ID: \t" << user4.id << std::endl;
    std::cout << " PAGE: \t" << user4.page << std::endl;
    
    std::cout << std::endl;
    
    std::cout << "Adding jobs..." << std::endl;
    jobQueue = printer.addJob(jobQueue, user1.id);
    printer.showJob(jobQueue);
    std::cout << "Adding jobs..." << std::endl;
    jobQueue = printer.addJob(jobQueue, user2.id);
    printer.showJob(jobQueue);
    std::cout << "Adding jobs..." << std::endl;
    jobQueue = printer.addJob(jobQueue, user3.id);
    printer.showJob(jobQueue);
    std::cout << "Adding jobs..." << std::endl;
    jobQueue = printer.addJob(jobQueue, user4.id);
    printer.showJob(jobQueue);
    
    jobQueue = printer.doJob(jobQueue);
    printer.showJob(jobQueue);
    
    jobQueue = printer.doJob(jobQueue);
    printer.showJob(jobQueue);
    
    jobQueue = printer.doJob(jobQueue);
    printer.showJob(jobQueue);
    
    jobQueue = printer.doJob(jobQueue);
    printer.showJob(jobQueue);

    return 0;
}