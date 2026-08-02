#include <iostream>
#include <cmath>
using namespace std;
int main() {
    int x = 10;
    if (x < 0) {
        cout << false;
        return false;
    } else {
        int res = x;
        int mod;
        int rev = 0;
        int result = x;

        while (result != 0) {
            mod = result % 10;
            rev = rev * 10 + mod;
            result = result / 10;
        } if (rev == x){cout << true; return true;} else{cout << false; return false;}
    }

    return 0;
}