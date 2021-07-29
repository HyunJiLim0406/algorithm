#include <iostream>
#include <cmath>

using namespace std;
typedef long long ll;

ll gcd(ll a, ll b) {
    ll tmp;
    if (a < b)
        swap(a, b);
    while (b) {
        tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}

int main() {
    ll a, b;

    cin >> a >> b;
    ll mul = a * b;
    ll line = sqrt(mul);
    while (line % a != 0)
        line--;
    while (line) {
        if (mul % line == 0 && gcd(line, mul / line) == a) //최대공약수 확인
            break;
        line -= a;
    }
    cout << line << ' ' << mul / line;
}