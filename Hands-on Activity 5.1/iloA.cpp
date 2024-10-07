#include <iostream>
#include <queue>

void display(std::queue <std::string> x)
{
    while (!x.empty())
    {
        std::cout << " + " << x.front() << std::endl;
        x.pop();
    }
    std::cout << std::endl;
}

int main()
{
    std::queue <std::string> students;
    std::string tempName;
    std::string array[4] = {"Monty C. Python", "Von E. Chavalier", "Ranni T. Thirty",
                      "Hark K. Salamandar"};
    for(int x; x < 4; x++)
    {
        students.push(array[x]);
    }
    
    std::cout << "Current Student Names : " << std::endl;
    display(students);
    
    return 0;
}