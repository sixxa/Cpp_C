#include <iostream>
using namespace std;

int main(){
  float c;
  float f;
  int choice;
  cout << "enter what you want to convert c or f if c write 1 if f write 2"<<endl;
  cin >> choice;
  if(choice == 1){
  cout << "Enter temperature in Celsius\n";
  cin >> c;
   f = ((c * 9/5)+32);
  cout << "Temperature in Fahrenheit: " << f;
  } else if (choice == 2){
    cout << "Enter temperature in Fahrenheit\n";
    cin >> f;
     c = ((f - 32) * 5 / 9);
    cout << "Temperature in Celsius: " << c;
  } else 
  cout << "Invalid input\n";
  return 0;
}