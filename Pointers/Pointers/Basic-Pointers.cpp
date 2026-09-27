#include <iostream>
using namespace std;
int main(){
	int x = 10;
	int* y = &x;
	cout << "Address of \"x\" " << y << endl;
	cout << "Value of \"x\" " << *y << endl;
	
	return 0;
}