#include <iostream>

using namespace std;

int main() {
    int X, cnt = 0;

    cin >> X;
    while (X != 0) {
        cnt += (X % 2);
        X /= 2;
    }
    cout << cnt;
}