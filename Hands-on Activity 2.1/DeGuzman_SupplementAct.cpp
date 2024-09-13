#include <iostream>
#include <string>
using namespace std;

// Problem 1: Create a class for the fruit and the vegetable classes. Each class must have a constructor,
// deconstructor, copy constructor and copy assignment operator. They must also have all relevant attributes
// (such as name, price and quantity) and functions (such as calculate sum).

class FOOD {
  private:
    string food;
    double price;
    int    amount;

  public:
    // Constructor
    FOOD(string foodName, double foodPrice, int foodAmount) {
      food = move(foodName);
      price = foodPrice;
      amount = foodAmount;
      cout << "Constructor Called";
    }

    // Destructor
    ~FOOD() {
      cout << "Destructor Called" << endl;
    }

    // Copy Constructor
    FOOD(const FOOD &copyFOOD) {
      cout << "Copy Constructor";
      food = copyFOOD.food;
      price = copyFOOD.price;
      amount = copyFOOD.amount;
    }

    void printDetails() const {
      cout << food << ", " << price << ", " << amount << "\n";
    }

    double foodPrice() const {
      return price;
    }
};

// Function to calculate the total sum of all FOOD objects in an array.
double foodSum(FOOD** groceryList, int size) {
  double sum = 0.0;
  for(int i = 0; i < size; ++i) {
    sum += groceryList[i]->foodPrice();
  }
  return sum;
}

// Driver Code
int main() {
  const int x = 4;
  FOOD* GroceryList[x]; // Problem 3: Create a function TotalSum that will calculate the sum of all objects listed in Jenna’s Grocery List.

  for(int n = 0; n < x; ++n) {
    string name;
    double price;
    int amount;

    cout << "Please input the name, price, and amount of fruit or vegetable #" << (n + 1) << ": ";
    cin >> name >> price >> amount;

    GroceryList[n] = new FOOD(name, price, amount);
  }

  cout << "\nJenna's Grocery List\n";
  for (int n = 0; n < x; ++n) {
    GroceryList[n]->printDetails();
  }

  double sum = foodSum(GroceryList, x);
  cout << "The total price of the Groceries is : " << sum;

  cout << "\nJenna's Grocery List without Lettuce\n";
  for (int n = 0; n < x-1; ++n) {
    GroceryList[n]->printDetails();
  }

  return 0;
}