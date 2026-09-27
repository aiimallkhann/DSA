#include <iostream>
using namespace std;
int main(){
	int x = 5;
	int* y = &x;
	int** z = &y;
	cout << "Value of x = " << x << endl;
	cout << "Address of x = " << y << endl;
	cout << "Changing value of x using z pointer: \n";
	cout << "** z = 10;\n";
	**z = 10;
	cout << "Changed Value of x = " << **z << endl;
	
	return 0;
}