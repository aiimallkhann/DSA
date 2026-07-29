#include <iostream>
using namespace std;
int main() {
    int arr [5] = {1, 2, 2, 2, 5};
    int occurance = 0;
    int num = 2;
    for (int i = 0; i < 5; i++) {
        if (num == arr[i]) {
            occurance++;
        }
    }
    cout << "Occurance of 2 = " << occurance;
}