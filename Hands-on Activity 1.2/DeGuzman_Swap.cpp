//Create a C++ program to swap the two numbers in different variables.
#include <iostream>
using namespace std;

void numSwap(int &num1, int &num2) {
  int num3 = num1;
  num1 = num2;
  num2 = num3;
};

void numDisplay(int x, int y) {
  cout << "number 1 is : " << x << "\n";
  cout << "number 2 is : " << y << "\n";
};

int main(){
  int no1,no2;
  cout << "please input number 1 : ";
  cin >> no1;
  cout << "please input number 2 : ";
  cin >> no2;
  numDisplay(no1,no2);
  numSwap(no1,no2);
  numDisplay(no1,no2);
  return 0;
}
