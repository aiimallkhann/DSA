#include <iostream>
using namespace std;

int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    int element = 8;
    int index = 2;
    for (int i = 4; i > 2; i--) {
        arr[i] = arr[i - 1];
    }
    arr[index] = element;
    for (int i = 0; i < 5; i++) {
        cout << arr[i];
    }
    return 0;
}