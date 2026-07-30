#include <iostream>
#include <vector>
using namespace std;

// void print (int arr[], int n) {
//     for (int i = 0; i < n; i++) {
//         cout << arr[i] << " ";
//     }
//     cout << endl;
//     arr[2] = 55;
// }

int main() {
    int arr[3] = {1, 2, 3};
    // cout << arr[2];
    // cout << endl << *(arr + 2);
    // print (arr, 3);
    // cout << arr[2];

    vector<int> vector;
    vector.push_back(4);
    vector.push_back(2);
    vector.push_back(1);
    vector.push_back(6);
    vector.push_back(5);
    vector.pop_back();
    int size = vector.size();
    for (int i = 0; i < size; i++) {
        cout << vector[i] << " ";
    } cout << endl;
    cout << vector.front();
    cout << endl;
    cout << vector.back();

    return 0;
}