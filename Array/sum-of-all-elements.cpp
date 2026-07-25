#include <iostream>
using namespace std;

int main() {
    int arr[5];
    int sum = 0;
    for (int i = 0; i < 5; i++) {
        cout << "Give " << (i + 1) << " element of array: ";
        cin >> arr[i];
    }
    cout << "Elements of array are:\n";
    for (int i = 0; i < 5; i++) {
        cout << arr[i];
    }
    for (int i = 0; i < 5; i++) {
        sum += arr[i];
    }
    cout << "\nThe sum of all the elements in the array is: " << sum;
    return 0;
}