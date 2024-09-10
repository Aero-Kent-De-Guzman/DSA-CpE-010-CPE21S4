#include <iostream>
using namespace std;

// formula is °F = (K − 273.15) × 1.8 + 32

float KtoF(float K) {
  float F = (K - 273.15) * 1.8 + 32;
  return F;
};

int main(){
  float kelvin;
  cout << "Please input how many kelvins : ";
  cin >> kelvin;
  cout << KtoF(kelvin);
  return 0;
}
