#include <iostream>
using namespace std;
int main() {
    int arr [4];
    int target = 9;
    cout << "Taking input:" << endl;
    for (int i = 0; i < 4; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < 4; i++) {
        for (int j = i + 1; j < 4; j++) {
            if ((arr[i] + arr[j]) == target) {
                cout << i << " " << j;
            }
        }
    }

    return 0;
}