#include <iostream>
using namespace std;

int main() {
    int arr[6] = {1, 2, 3, 4, 5};
    int element = 9;
    for (int i = 5; i > 0; i--) {
        arr[i] = arr[i-1];
    }
    arr[0] = element;
    for (int i = 0; i < 6; i++) {
        cout << arr[i];
    }
    return 0;
}