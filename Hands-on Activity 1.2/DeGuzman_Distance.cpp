//Create a C++ program to swap the two numbers in different variables.
#include <iostream>
#include <cmath>
using namespace std;

// formula is distance = sqrt( (x2-x1)^2 + (y2-y1)^2 )

double pointDistance(double x1, double x2, double y1, double y2) {
  double xValue = x2 - x1;
  double yValue = y2 - y1;
  double x = pow(xValue, 2);
  double y = pow(yValue, 2);
  double output = sqrt(x + y);
  return output;
};

int main(){
  double x1, x2, y1, y2;
  cout << "please input the coordinates for the first point : ";
  cin >> x1 >> y1;
  cout << "please input the coordinates for the first point : ";
  cin >> x2 >> y2;
  double distance = pointDistance(x1,x2,y1,y2);
  cout << "The distance of (" << x1 << "," << y1 << ") & (" << x2 << ","  << y2 << ") is " << distance;
  return 0;
}
