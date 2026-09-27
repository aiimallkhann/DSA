#include <iostream>
using namespace std;
int main(){
	int a = 10;
	int* x = nullptr;
	cout << x << endl;
	x = &a;
	cout << x << endl;
	cout << *x << endl;
	
	return 0;
}