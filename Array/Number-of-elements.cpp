#include <iostream>
using namespace std;
int main() {
    int arr[6] = {1, 2, 5, 3, 4, 5};
    cout << sizeof(arr)/ sizeof(arr[0]);

    return 0;
}