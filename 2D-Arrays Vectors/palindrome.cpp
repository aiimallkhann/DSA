#include <iostream>
using namespace std;
int main() {
    int x = 12;
    int res = x;
    int mod;
    int rev = 0;
    int result = x;

    while (result != 0) {
        mod = result % 10;
        rev = rev * 10 + mod;
        result = result / 10;
    }

    if (rev == x) {
        cout << x << " is a palindrome." << endl;
    } else {
        cout << x << " is not a plaindrome." << endl;
    }

    return 0;
}