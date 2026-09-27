#include <iostream>
using namespace std;
int main(){
	int x = 5;
	int* y = &x;
	int** z = &y;
	cout << "Value of \"x\" " << x << endl;
	**z = 3;
	cout << "Address of \"x\" " << y << endl;
	cout << "Changed Value of \"x\" " << **z << endl; 
	
	return 0;
}