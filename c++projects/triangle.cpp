#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    cout << "enter the sides of triangle" << endl;
    int a, b, c;
    cin >> a >> b >> c;
     int sides[3] = {a, b, c};
     int n = sizeof(sides) / sizeof(sides[0]);
     sort(sides, sides + n);
    if (sides[0] + sides[1]  > sides[2]) {
     cout << "Triangle is valid" << endl;
    }
    else 
     cout << "Triangle is invalid" << endl;
    
	return 0;
}