#include <iostream>
using namespace std;

int main() {
    int arr[6] = {1, 2, 3, 4, 5};
    int element = 7;

    arr[5] = element;

    for (int i = 0; i < 6; i++) {
        cout << arr[i];
    }
    return 0;
}