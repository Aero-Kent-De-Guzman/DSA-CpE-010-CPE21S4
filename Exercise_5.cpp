#include <iostream>
#include <stack>
#include <queue>
using namespace std;
stack<string> pl;
queue<string> lrt;

void display(stack<string> pl)
{
    while(!pl.empty())
    {
        cout << pl.top() << endl;
        pl.pop();
    }
}

void displayBottom(stack<string> pl)
{
    while(pl.size() != 1)
    {
        pl.pop();
    }
    cout << pl.top() << endl;
}

void displayReversed(queue<string> lrt)
{
    string x;
    x = lrt.back();
    lrt.back() = lrt.front();
    lrt.back() = x;
    while(!lrt.empty())
    {
        cout << lrt.front() << endl;
        lrt.pop();
    }
}

void limiter(stack<string> pl)
{
    if (pl.size() > 3)
    {
        cout << "stack is already full! deleting latest..." << endl;
        while(pl.size() != 3)
        {
            pl.pop();
        }
    } else {
        cout << "stack is full" << endl;
    }
}

int main()
{
    cout << "Push elements into stacks:" << endl;
    // add items to the stacks
    pl.push("C++");
    pl.push("Java");
    pl.push("Python");
    // cout << "Initial stack:" << endl;
    display(pl);
    cout << "\n" << "Final stack:" << endl;
    displayBottom(pl);
    
    limiter(pl);

    string burger[3] = {};
    for(int x = 0; x < 3; x++)
    {
        burger[x] = pl.top();
        pl.pop();
        lrt.push(burger[x]);
    }
    
    cout << "\n" << "Reversed stack:" << endl;
    displayReversed(lrt);
    return 0;
}