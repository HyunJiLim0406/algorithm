#include <iostream>

using namespace std;

int gcd(int a, int b) { //유클리드 호제법(?)으로 최대공약수 구함
    int temp, n;

    if (a < b) {
        temp = a;
        a = b;
        b = temp;
    }
    while (b != 0) {
        n = a % b;
        a = b;
        b = n;
    }
    return a;
}

int main() {
    int T, A, B;

    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> A >> B;
        cout << (A * B) / gcd(A, B) << '\n';
    }
}