 #include <iostream>;
 #include<cmath>;
 using namespace std;
  
   int main(int argc, char  **argv) {
float a, b, c, dis, x1, x2, realPart, imaginaryPart;
cout << "enter a , b ,c" << endl;
cin >>a>>b>>c;
dis = pow(b,2)-4*a*c;

  if (dis>0) {
    x1= (-b+sqrt(dis)) / 2*a;
    x2= (-b-sqrt(dis)) / 2*a;
    cout<<x1<<endl;
    cout<<x2<<endl;
  }
  else if(dis=0) {
    x1=x2= -b / 2*a;
    cout<<x1<<endl;
  }
  else {
        realPart = -b/(2*a);
        imaginaryPart =sqrt(-dis)/(2*a);
        cout << "Roots are complex and different."  << endl;
        cout << "x1 = " << realPart << "+" << imaginaryPart << " i" << endl;
        cout << "x2 = " << realPart << "-" << imaginaryPart << " i" << endl;

  }


if (x1 >0 && x1<10 && x2 >0 && x2<10){
    cout<<x1<<endl;
    cout<<x2<<endl;
}
else{
    cout << "bleh";
}
  

   }