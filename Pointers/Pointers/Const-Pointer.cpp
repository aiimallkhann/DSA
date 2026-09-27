#include <iostream>
using namespace std;
int main(){
	const int x = 5;
	const int* y = &x;
	int a = 10;
	const int* b = &a;
	const int q = 6;
	const int* u = &q;
	cout << "Value of x = " << x << endl;
	cout << "Address of x = " << y << endl;
	cout << "Value of a = " << a << endl;
	cout << "Adress of a = " << b << endl;
	cout << "Value of q = " << q << endl;
	cout << "Address of q = " << u << endl;
	
	return 0;
}