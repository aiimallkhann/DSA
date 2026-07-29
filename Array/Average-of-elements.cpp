#include <iostream>
using namespace std;
int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    int sum = 0;
    int average = 0;
    int elements = sizeof(arr)/sizeof(arr[0]);
    for (int i = 0; i < 5; i++) {
        sum += arr[i];
    }
    average = sum / (elements);
    cout << "Sum of array = " << sum << endl;
    cout << "Average of array = " << average << endl;

    return 0;
}