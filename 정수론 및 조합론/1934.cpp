#include <iostream>

using namespace std;

int gcd(int a, int b) { //유클리드 호제법으로 최대공약수 구함
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
        cout << (A * B) / gcd(A, B) << '\n'; //함수로 구한건 최대공약수니까 최소공배수로 변환
    }
}