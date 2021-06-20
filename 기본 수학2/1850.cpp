#include <iostream>

using namespace std;
typedef long long ll;

ll gcd(ll x, ll y) { //유클리드 호제법
    ll tmp;

    if (x < y)
        swap(x, y);
    while (y != 0) {
        tmp = x % y;
        x = y;
        y = tmp;
    }
    return x;
}

int main() {
    ll A, B;

    cin >> A >> B;
    ll num = gcd(A, B);
    while (num--) //최대 공약수의 수만큼 1 출력
        cout << 1;
}