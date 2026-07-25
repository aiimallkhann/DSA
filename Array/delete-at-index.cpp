#include <iostream>
using namespace std;

int main() {
    int arr[5] = {1, 2, 3, 4, 5};

    for (int i = 2; i < 4; i++) {
        arr[i] = arr[i + 1];
    }

    cout << arr[2];

    for (int i = 0; i < 4; i++) {
        cout << arr[i];
    }
    return 0;
}