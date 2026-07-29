#include <iostream>
using namespace std;
int main() {
    int arr [5] = {100, 2, 3, 4, 5};
    int largetst = 0;
    int sec_larg = 0;
    for (int i = 0; i < 5; i++) {
        if (largetst < arr[i]) {
            sec_larg = largetst;
            largetst = arr[i];
        } else if (sec_larg > largetst || sec_larg < arr[i]) {
            sec_larg = arr[i];
        }
    }
    cout << "Largest = " << largetst << endl;
    cout << "Second largest = " << sec_larg << endl;

    return 0;
}