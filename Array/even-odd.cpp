#include <iostream>
using namespace std;
int main() {
    int arr[5] = {10, 20, 30, 40 ,51};
    int even, odd = 0;
    for (int i = 0; i < 5; i++) {
        if (arr[i] % 2 == 0) {
            even++;
            cout << arr[i] << " is even." << endl;
        } else {
            odd++;
            cout << arr[i] << " is odd." << endl;
        }
    }

    return 0;
}