#include <iostream>
using namespace std;

int main()
{
    cout << 2<< endl;
	for(int i =3 ; i < 1000; i+=2){
		bool prime = true;

		for(int j = 3; j < i/2; j+=2){
			if(i % j == 0){
				prime = false;
				break;
			}
		}

		if(prime == true){
			cout << i<< endl;
		}
	}
	return 0;
}
