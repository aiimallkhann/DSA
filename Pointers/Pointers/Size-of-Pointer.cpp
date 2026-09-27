#include <iostream>
using namespace std;
int main(){
	double a = 0.02;
	double* x = &a;
	char b = 'b';
	char* y = &b;
	bool c = false;
	bool* z = &c;
	
	cout << "Value of \"a\" " << *x << endl;
	cout << "Size of Pointer \"x\" " << sizeof(x) << endl;
	cout << "Value of \"b\" " << *y << endl;
	cout << "Size of Pointer \"y\" " << sizeof(y) << endl;
	cout << "Value of \"c\" " << *z << endl;
	cout << "Size of Pointer \"z\" " << sizeof(z) << endl;
	
	
	return 0;
}