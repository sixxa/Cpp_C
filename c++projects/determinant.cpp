#include <iostream>
using namespace std;



int main() {
    
    int m[3][3] = {}; 

      cout <<"enter 9 elements"<<endl;
    for (int i = 0; i <3; i++) {
      for (int j = 0; j <3; j++){
        cin >> m[i][j];
      }
      
    }

    for(int i= 0; i < 3; i++) {
     for(int j = 0; j < 3; j++) {
      cout << m[i][j] << " ";
    }
    cout << endl;
  } 


     int det = 0;

    for (int i = 0; i < 3; i++) {
        int di = 1;
        int antiDi = 1;

        for (int j = 0; j < 3; j++) {
            di *= m[j][(i + j) % 3];
            antiDi *= m[j][(i - j + 3) % 3];
        }

        det += (di - antiDi);
    }

   
    cout << "Determinant is: " << det <<endl;

    return 0;
}