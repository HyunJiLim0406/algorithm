#include <iostream>

using namespace std;
typedef long long ll;

ll gcd(ll A, ll B) { //유클리드 호제법
    ll tmp;
    if (A < B)
        swap(A, B);
    while (B) {
        tmp = A % B;
        A = B;
        B = tmp;
    }
    return A;
}

int main() {
    ll A, B;

    cin >> A >> B;
    cout << (A * B) / gcd(A, B);
}