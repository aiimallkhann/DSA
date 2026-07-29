#include <iostream>
using namespace std;
int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    int brr[5];
    int n = 0;
    for (int i = 4; i >= 0; i--) {
        brr[n] = arr[i];
        n++;
    }
    for (int i = 0; i < 5; i++) {
        cout << brr[i];
    }
    return 0;
}