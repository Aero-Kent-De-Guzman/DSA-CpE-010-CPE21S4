#include <iostream>
#include <cmath>

class Triangle{
private:
double totalAngle, angleA, angleB, angleC;
public:
Triangle(double A, double B, double C);
void setAngles(double A, double B, double C);
const bool validateTriangle();
};

Triangle::Triangle(double A, double B, double C) {
angleA = A;
angleB = B;
angleC = C;
totalAngle = A+B+C;
}

void Triangle::setAngles(double A, double B, double C) {
angleA = A;
angleB = B;
angleC = C;
totalAngle = A+B+C;
}

const bool Triangle::validateTriangle() {
return (totalAngle <= 180);
}

int perimeter(int a, int b, int c) {
  int sum = a+b+c;
  return sum;
}

int area(int base, int height) {
  int value = (base * height) / 2;
  return value;
}

void classify(double a, double b, double c) {
  double a2 = a * a;
  double b2 = b * b;
  double c2 = c * c;
  double angle_A2 = b2 + c2 - a2;
  double angle_B2 = a2 + c2 - b2;
  double angle_C2 = a2 + b2 - c2;

  if (angle_A2 < 0 || angle_B2 < 0 || angle_C2 < 0) {
    std::cout << "\ntype : OBTUSE";
  } else if (angle_A2 > 0 && angle_B2 > 0 && angle_C2 > 0) {
    std::cout << "\ntype : ACUTE";
  } else {
    std::cout << "\ntype : OTHERS";
  }
}

int main(){
//driver code
Triangle set1(40, 30, 110);
int x,y,z,b,h;
if(set1.validateTriangle()){
  std::cout << "The shape is a valid triangle.\n";
  std::cout << "Please insert the sides.";
  std::cin >> x >> y >> z;
  std::cout << "Please input the base of your triangle : ";
  std::cin >> b;
  std::cout << "Please input the height of your triangle : ";
  std::cin >> h;
  std::cout << "The Perimeter is : " << perimeter(x,y,z);
  std::cout << "\nThe Area is : " << area(b,h);  
  classify(x,y,z);
} else {
std::cout << "The shape is NOT a valid triangle.\n";
}
return 0;
}
