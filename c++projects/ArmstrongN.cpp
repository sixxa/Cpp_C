#include <iostream>
using namespace std;

int main() {
  int  num, digit, sum;
  cout << "Armstrong numbers  are: " << endl;
  for(int i = 0; i <= 1000; i++) {
    num = i;
    sum = 0;
    while(num > 0) {
      digit = num % 10;
      sum = sum + (digit*digit*digit);
      num /= 10;
    }
    if(sum == i) {
      cout << i << ", ";
    }
  }
  return 0;
}