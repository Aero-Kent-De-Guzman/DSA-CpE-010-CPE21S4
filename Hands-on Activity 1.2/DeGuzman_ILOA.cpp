#include <iostream>
using namespace std;

class OOPactivity1 {
  public:
  //Create a function that will take two numbers and display the sum.
  void numSum(int num1, int num2) {
    int sum = num1 + num2;
      cout << "The sum of " << num1 << " and " << num2 << " is " << sum << "\n";
  }

  //Create a function that will return whether variable A is greater than variable B.
  void GreatOrLess(int num1, int num2) {
    if (num1 < num2) {
        cout << num2 << " is greater than " << num1 << "\n";
    } else {
        cout << num1 << " is greater than " << num2 << "\n";
    }
  }


// Create a function that will take two Boolean values and dislay the result of all logical operations then return true if it is was a success.
  bool displayLogics (bool num1, bool num2) {
    bool AND   = num1 && num2;
    bool OR    = num1 || num2;
    bool XOR   = num1 ^ num2;
    bool NOTA  = !num1;
    bool NOTB  = !num2;

    cout << "\n\nlogic operations for the two numbers are (1 TRUE / 0 FALSE) : ";
    cout << "\nAND " << AND << "\n";
    cout << "OR " << OR << "\n";
    cout << "XOR " << XOR << "\n";
    cout << "NotA " << NOTA << "\n";
    cout << "NotB " << NOTB << "\n";

    return true;
  }

};

int main() {
    OOPactivity1 cs;
    int x,y;

    cout << "Please enter number 1 : ";
    cin >> x;
    cout << "Please enter number 2 : ";
    cin >> y;
    cs.numSum(x,y);
    cs.GreatOrLess(x,y);
    cs.displayLogics(x,y);
    return 0;
}