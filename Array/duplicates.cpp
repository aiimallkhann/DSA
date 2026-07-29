#include <iostream>
using namespace std;
int main() {
    int arr [5] = {1, 2, 2, 2, 5};
    int duplicates = 0;
    int num = 1;
    for (int i = 0; i < 5; i++) {
        if (num == arr[i]) {
            duplicates++;
        }
    }
    if (duplicates > 1) {
        cout << "Given element " << num << " is a duplicate which occurs " << duplicates << " times\n";
    } else {
        cout << "Given element " << num << " is not a duplicate.";
    }
}