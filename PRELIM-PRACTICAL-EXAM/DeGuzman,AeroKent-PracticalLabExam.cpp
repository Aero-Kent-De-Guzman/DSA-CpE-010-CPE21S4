/*******************************************************************************
6. Write a C++ program to get the length of the array. Original array:
numbers = [5,3,2,1,1].
*******************************************************************************/

#include <iostream>
using namespace std;

int main()
{   
    int x = 5;
    int numbers[5] = {5,4,3,2,1}, arrayLength;
    for(int i = 0; i < x; i++)
    {
        arrayLength += 1;
    }
    cout << "The total size of the array 'numbers' is : " << arrayLength;
    return 0;
}