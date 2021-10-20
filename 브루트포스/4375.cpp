#include <iostream>

using namespace std;

int main() {
    long long input;

    while (cin >> input) {
        int digit = 1;
        long long num = 1;
        while (num % input) {
            num %= input; //오버플로우 방지
            num = 10 * num + 1;
            digit++;
        }
        cout << digit << '\n';
    }
}